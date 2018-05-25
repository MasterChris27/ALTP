%{
	#include <stdio.h>
	#include "table.c"
	#include "interpreteur.c"
	
	#define YYDEBUG 0
	
	int yylex(void);
	void yyerror(char*);


char* type;
int profondeur = 0;
%}

%union {
	int nb;
	char* str;
}

%type <str> tVAR tINT
%type <nb> tINTNR

%token tINT
%token tACO
%token tACC
%token tCONST
%token tADD
%token tSUBTRACT
%token tDIVIDE
%token tMULTIPLY
%token tEQUAL
%token tPLUSPLUS   ///added, par ex i++
%token tMINUSMINUS ///added, par ex i--
%token tIF
%token tELSE
%token tCHECKEQ
%token tPO
%token tPC
%token tTAB
%token tVIRGULE
%token tDOLLAR
%token tFINSTR
%token tINTNR
%token tWHILE
%token tPRINTF
%token tMAIN
%token tVAR
%token tFOR
%token tSTRING
%token tCHECKHIGHER
%token tLESS
%token tLESSEQUAL
%token tMOREEQUAL

%left tADD tSUBTRACT
%left tMULTIPLY tDIVIDE

%type <nb>  tIF 

%%

//$nr means the value of the nr entry

//add strings ????
//add while  !!!
//table of symboles  !!!
// some kind of calculus
// add functions  !!!!

// change the Instruction




Main: tMAIN tPO tPC Body ;

Body: tACO Instruction tACC; // add here the profondeur

Instruction : Instructions Instruction 
	   | Instructions 
	   | ;

Instructions: 
	   Calcul 
	 | For 
     | While
     | Print
     | Declaration
     | If 
	 ;

Declaration: vartype Declarations tFINSTR ;


Declarations: Multideclaration Declarations
			| Lastdeclaration ;

Multideclaration : tVAR tVIRGULE {add_symbol($1, type, 0, profondeur);};


Lastdeclaration: tVAR {add_symbol($1, type, 0, profondeur);};

vartype : tINT { type = "int"; }
     | tCONST { type = "const"; };

		

 //print f

Print: tPRINTF tPO tVAR tPC tFINSTR {printf("Print not supported\n");};




// IF    NO " ; " at the end !!!!

If : tIF tPO Condition tPC{
		int a = get_last_index(); //condition-index
		queue_instruction("LOAD", 10, a);
		queue_instruction("TMP", 1, 1);
		$1 = get_latest_inst();
		
		printf("$1 innan: %d\n", $1);
		delete_symbol();
		
	} Body {
		printf("$1 efter: %d\n", $1);
		edit_instruction($1, "JMPC" , get_latest_inst(), 10);
		queue_instruction("AFC", 11, -1);
		queue_instruction("MUL", 10, 11);
		queue_instruction("TMP", 1, 1);
		$1 = get_latest_inst();
		
	} Else {	
		edit_instruction($1, "JMPC" , get_latest_inst(), 10);
				
}

	;

Else: tELSE Body
 	| ;

Condition : 	

	  Expression tCHECKEQ Expression {
		int a = get_last_index();
		int b = a-1;
		queue_instruction("LOAD", 1, a);
		queue_instruction("LOAD", 2, b);
		queue_instruction("EQU", 1, 2);
		queue_instruction("STORE", b, 1);
		delete_symbol();
	}
	| Expression tLESS Expression {
		int a = get_last_index();
		int b = a-1;
		queue_instruction("LOAD", 1, a);
		queue_instruction("LOAD", 2, b);
		queue_instruction("INF", 1, 2);
		queue_instruction("STORE", b, 1);
		delete_symbol();
	}
	| Expression tCHECKHIGHER Expression {
		int a = get_last_index();
		int b = a-1;
		queue_instruction("LOAD", 1, a);
		queue_instruction("LOAD", 2, b);
		queue_instruction("SUP", 1, 2);
		queue_instruction("STORE", b, 1);
		delete_symbol();
	}
	| Expression tLESSEQUAL Expression {
		int a = get_last_index();
		int b = a-1;
		queue_instruction("LOAD", 1, a);
		queue_instruction("LOAD", 2, b);
		queue_instruction("INFE", 1, 2);
		queue_instruction("STORE", b, 1);
		delete_symbol();
	}
	| Expression tMOREEQUAL Expression {
		int a = get_last_index();
		int b = a-1;
		queue_instruction("LOAD", 1, a);
		queue_instruction("LOAD", 2, b);
		queue_instruction("SUPE", 1, 2);
		queue_instruction("STORE", b, 1);
		delete_symbol();
	};

// check for //conditions;



//while
While : tWHILE tPO{
		int a=get_last_inst(); //before all conditions // we can put B or something but idk if it will compile
		 // we mark the beggining of the conditions
		 queue_instruction("AFC",12,a); // register 12
		}
		
		Condition tPC {
			int b = get_last_index(); //condition-index after all conditions
			queue_instruction("LOAD", 10, b); // add in place of 10 , 5+ prof
			queue_instruction("TMP", 1, 1); //we add the unedited JMPC
			int c = get_latest_inst();         
			printf("$1 innan: %d\n", c);
		 	queue_instruction("AFC",13,c); // register 13
			delete_symbol();}
		
			Body{
				int a= get_register_value(12);
				int c= get_register_value(13);
				printf("$1 efter: %d\n", a);
				queue_instruction("JMP", a, 1); //we always jump back before the conditions
				edit_instruction(c, "JMPC" , get_latest_inst(), 10); //we edit de JMPC from condition
	}; // tRECHECK ?



// for


For : tFOR tPO { /* ?! profondeur++;*/    }
	tINT tVAR { 
	int a = get_last_index();   //we mark the variable 
	} 
		tEQUAL tINTNR tFINSTR {
		int b=get_latest_inst();  //we mark the beggining of the conditions
		queue_instruction("AFC",12,b);
		} 
			Condition tFINSTR {
				queue_instruction("TMP",1,1);      //adding temporary JMPC
				int c=get_latest_inst();
				queue_instruction("AFC",13,c);
				}
					 increment tPC Body {  //we do the calculus in increment
					   int b=get_register_value(12);
					    int c =get_register_value(13);
					   queue_instruction("JMP",b,10);     //we always go back to the spot before conditions to check the new variable value
					   edit_instruction(c,"JMPC",get_latest_inst(),10);};  //we edit the unedited jmpc instruction

increment : | tVAR tPLUSPLUS  {
				 int x = find_symbol($1, profondeur);
				 queue_instruction("LOAD", 1, x);
				 queue_instruction("AFC", 2, 1);
				 queue_instruction("ADD", 1, 2);
				 queue_instruction("STORE", x, 1);}

		| tVAR tMINUSMINUS{
				 int y = find_symbol($1, profondeur);
				 queue_instruction("LOAD", 1, y);
				 queue_instruction("AFC", 2, 1);
				 queue_instruction("SUB", 1, 2);
				 queue_instruction("STORE", y, 1);};







 Calcul:
	 	  tVAR tEQUAL Expression tFINSTR {
				 int a = find_symbol($1, profondeur);
				 int b = get_last_index();
				 queue_instruction("LOAD", 1, b);
				 queue_instruction("STORE", a, 1);
				 delete_symbol();} 

		| tVAR tEQUAL tSUBTRACT Expression tFINSTR {
				 int a = find_symbol($1, profondeur);
				 int b = get_last_index();
				 queue_instruction("LOAD", 1, b);
				 queue_instruction("AFC", 2, -1);
				 queue_instruction("MUL", 1, 2);
				 queue_instruction("STORE", a, 1);
				 delete_symbol();} 

		| tVAR tPLUSPLUS tFINSTR {
				 int a = find_symbol($1, profondeur);
				 queue_instruction("LOAD", 1, a);
				 queue_instruction("AFC", 2, 1);
				 queue_instruction("ADD", 1, 2);
				 queue_instruction("STORE", a, 1);}

		| tVAR tMINUSMINUS tFINSTR {
				 int a = find_symbol($1, profondeur);
				 queue_instruction("LOAD", 1, a);
				 queue_instruction("AFC", 2, 1);
				 queue_instruction("SUB", 1, 2);
				 queue_instruction("STORE", a, 1);}

		| tVAR tSUBTRACT tEQUAL Expression tFINSTR {
				 int a = find_symbol($1, profondeur);
				 int b = get_last_index();
				 queue_instruction("LOAD", 1, a);
				 queue_instruction("LOAD", 2, b);
				 queue_instruction("SUB", 1, 2);
				 queue_instruction("STORE", a, 1);
				 delete_symbol();}

		| tVAR tADD tEQUAL Expression {
				 int a = find_symbol($1, profondeur);
				 int b = get_last_index();
				 queue_instruction("LOAD", 1, a);
				 queue_instruction("LOAD", 2, b);
			   	 queue_instruction("ADD", 1, 2);
				 queue_instruction("STORE", a, 1);
				 delete_symbol();}
;


Expression :
 	     Expression tADD Expression {
				 int a = get_last_index();
				 int b = a-1;
				 queue_instruction("LOAD", 1, a);
				 queue_instruction("LOAD", 2, b);
				 queue_instruction("ADD", 1, 2);
			     queue_instruction("STORE", b, 1);
				 delete_symbol(); }	  

		| Expression tSUBTRACT Expression {
				 int a = get_last_index();
			 	 int b = a-1;
				 queue_instruction("LOAD", 1, a);
			 	 queue_instruction("LOAD", 2, b);
				 queue_instruction("SUB", 1, 2);
				 queue_instruction("STORE", b, 1);
			 	 delete_symbol(); }

 		| Expression tDIVIDE Expression {
				 int a = get_last_index();
				 int b = a-1;
				 queue_instruction("LOAD", 1, a);
			 	 queue_instruction("LOAD", 2, b);
				 queue_instruction("DIV", 1, 2);
				 queue_instruction("STORE", b, 1);
				 delete_symbol(); }		

		| Expression tMULTIPLY Expression {
		 		 int a = get_last_index();
				 int b = a-1;
				 queue_instruction("LOAD", 1, a);
				 queue_instruction("LOAD", 2, b);
				 queue_instruction("MUL", 1, 2);
				 queue_instruction("STORE", b, 1);
				 delete_symbol(); }

 		| tVAR {
				add_temporary_symbol();
	 			queue_instruction("LOAD", 1, find_symbol($1, profondeur));
				queue_instruction("STORE", get_last_index(), 1); }

		| tINTNR {
				add_temporary_symbol();
				queue_instruction("AFC", 1, $1);
				queue_instruction("STORE", get_last_index(), 1); }

		| tPO tSUBTRACT tINTNR tPC {
				add_temporary_symbol();
				queue_instruction("AFC", 1, $3);
				queue_instruction("AFC", 2, -1);
				queue_instruction("MUL", 1, 2);
				queue_instruction("STORE", get_last_index(), 1); }

		| tPO Expression tPC  


			;


%%


void yyerror(char *s) {
	fprintf(stderr, "error: %s\n", s);
	exit(1);
}

int main() {

	//#if YYDEBUG
	//	yydebug = 1;
//	#endif




	yyparse();
	execute_all_instructions();
	print_table();
	for(int i=0; i<=get_last_index(); i++){
		printf("var: %s, value: %d\n", get_variable_name(i), get_memory_value(i));
	}
}


