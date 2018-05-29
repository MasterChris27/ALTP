%{
	#include <stdio.h>
	#include "table.c"
	#include "interpreteur.c"
	
	#define YYDEBUG 0
	
	int yylex(void);
	void yyerror(char*);


char* type;
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
%token tMINUSEQUAL
%token tPLUSEQUAL
%token tRETURN


%left tADD tSUBTRACT
%left tMULTIPLY tDIVIDE

%type <nb>  tIF tWHILE tFOR tPO tPC tFINSTR 

%%

// the hardcoded 2 is 1 time happening as it is for the first case of the function
//might be a problem if we don have a function tough              same with the delete_symbol
Main: DeclFunction tMAIN tPO tPC Body {} ;

//adding type to the function
DeclFunction :vartype tVAR {
			int b=4 + get_latest_inst(); // we don't execute everytime the first 6 instructions
			

			add_symbol($2, type, 0, get_curr_prof()); 
			int a= get_last_index(); // we add 2 as we added 2 new instructions that should not be repeated , returns -1 so we have to add 3
			queue_instruction("AFC",1,b);

			queue_instruction("AFC",14,a);
			queue_instruction("ADD",14,15); 
			queue_instruction("STORE",14,1);// we store at @14 the val b 

			queue_instruction("TMPJMP",1,1); 
			//printf("Debug %s\n\n",$1);
			
			prof_increment();}// we increment the prof so that we never use the variable stored in lvl 0


	   	tPO Params tPC FuncBody tFINSTR {
			edit_instruction(4,"JMP",get_latest_inst(),0);//works good until now
			queue_instruction("AFC",15,0);} // we put the context back to 0

	      | ; // no function


Params :{		
			prof_increment();	
			int z=get_last_index();  //we increment it always so that for the 2nd function the r15 will be 1+current index i think
			queue_instruction("AFC",1,z); // as we store the function name 
			queue_instruction("ADD",15,1); // we store it in register 15
			}
	 Param NextParam | ;
NextParam : tVIRGULE Param | ;
Param :	vartype tVAR { 
			add_symbol($2, type, 0, get_curr_prof()); }
	| tVAR  {		
			prof_increment();
			int a= find_symbol($1, get_curr_prof()); 
			add_symbol($1, type, 0, get_curr_prof());

			int b= get_last_index();

	 		queue_instruction("LOAD", 1, a);// we copy the value  in r1

			queue_instruction("AFC",14,b);
			//queue_instruction("ADD",14,15); 

			queue_instruction("STORE", 14, 1); };

//adaugam variabilele scriem apoi instructiunile in functie de numele lor dupa care le stergem . 
// Cand apelam functia acestea vor fi create in ultimul nivel dupa care vom folosi numele oferite in declararea parametrilor

FuncBody : tACO FuncInstr  tACC;

FuncInstr : FuncInstrs FuncInstr
	    | FuncInstrs
	    | ;
FuncInstrs : Instructions| RetVal;  
	// can add tRETURN to the function , used tSTRING in place of return
RetVal : tSTRING tINTNR tFINSTR {  //we create a temp variable wich has the value of the return
					//print_table();
				//delete_all_var(get_curr_prof());
				prof_decrement();
				//we want to store the variable at a lower level so we can retrieve it afterwards in the Calcul !
					//print_table();
					add_symbol("fRet", "int", 0, get_curr_prof());
					int a= get_last_index();
					queue_instruction("AFC",1,$2);

					queue_instruction("AFC",14,a);
					queue_instruction("ADD",14,15); 
							queue_instruction("STORE",14,1);

					queue_instruction("RET",1,1); 
					delete_symbol();  // there might be a problem with deleting the variable here

					/* if it is an expression we need to decrement the prof so that the expression gets saved to another depth and then make the delete all var function search to delete only those particular variables*/
		};

Body: tACO Instruction tACC; // add here the get_curr_prof()

Instruction : Instructions Instruction 
	   | Instructions 
	   | ;

Instructions: 
	   Calcul 
	 | For 
     | While
     | Print
     | Declaration
     | If ;

Declaration: vartype Declarations tFINSTR ;


Declarations: Multideclaration Declarations
			| Lastdeclaration ;

Multideclaration : tVAR tVIRGULE {add_symbol($1, type, 0,get_curr_prof());}
		| tVAR tEQUAL tINTNR tVIRGULE {
			int b=get_curr_prof();
		    add_symbol($1, type, 0, b);
		// we could change add symbol to return the address
		    int a = find_symbol($1, get_curr_prof());
		    queue_instruction("AFC", 1, $3);

		    queue_instruction("AFC",14,a);
		    queue_instruction("ADD",14,15); 


		    queue_instruction("STORE", 14, 1); 

};



Lastdeclaration: tVAR {add_symbol($1, type, 0, get_curr_prof());}
		| tVAR tEQUAL tINTNR {

				 add_symbol($1, type, 0, get_curr_prof());

		// we could change add symbol to return the address
				 int a = find_symbol($1, get_curr_prof());
				 queue_instruction("AFC", 1, $3);
		
				 queue_instruction("AFC",14,a);
				 queue_instruction("ADD",14,15); 

				 queue_instruction("STORE", 14, 1); 
		queue_instruction("PRT",15,2);
		queue_instruction("PRT",15,1);
		queue_instruction("PRT",15,0);	

};


vartype : tINT { type = "int"; }
     | tCONST { type = "const"; };


Print: tPRINTF tPO tVAR tPC tFINSTR {printf("Print not supported\n");};




If : tIF{prof_increment();} tPO Condition tPC{
		int a = get_last_index(); //condition-index

		queue_instruction("AFC",14,a);
		queue_instruction("ADD",14,15); 
		queue_instruction("LOAD", 10, 14);

		queue_instruction("TMP", 1, 1);
		$1 = get_latest_inst();
		delete_symbol();
		
	} Body {
		queue_instruction("TMP", 1, 1);
		edit_instruction($1, "JMPC" , get_latest_inst(), 10);
		//queue_instruction("AFC", 11, -1);
		//queue_instruction("MUL", 10, 11);
		//queue_instruction("TMP", 1, 1);
		$1 = get_latest_inst();
		
	} Else {	
		//edit_instruction($1, "JMPC" , get_latest_inst(), 10);
		edit_instruction($1, "JMP" , get_latest_inst(), 10);
		delete_all_var(get_curr_prof());
		prof_decrement();
				
}

	;

Else: tELSE Body
	//| tELSE If
 	| ;


Condition : 	

	  Expression tCHECKEQ Expression {

		printf("we are in condition after finding it at depth %d \n\n", get_curr_prof());
		int a = get_last_index();
		int b = a-1;
		
		queue_instruction("AFC",14,a);
		queue_instruction("ADD",14,15); 
		queue_instruction("LOAD", 1, 14);

		queue_instruction("AFC",14,b);
		queue_instruction("ADD",14,15); 
		queue_instruction("LOAD", 2, 14);

		queue_instruction("EQU", 2, 1);
	
		queue_instruction("AFC",14,b);
		queue_instruction("ADD",14,15); 
		queue_instruction("STORE", 14, 2);
		delete_symbol();
	}
	| Expression tLESS Expression {
		int a = get_last_index();
		int b = a-1;

		queue_instruction("AFC",14,a);
		queue_instruction("ADD",14,15); 
		queue_instruction("LOAD", 1, 14);

		queue_instruction("AFC",14,b);
		queue_instruction("ADD",14,15); 
		queue_instruction("LOAD", 2, 14);
		queue_instruction("INF", 2, 1);

		queue_instruction("AFC",14,b);
		queue_instruction("ADD",14,15); 
		queue_instruction("STORE", 14, 2);
		delete_symbol();
	}
	| Expression tCHECKHIGHER Expression {
		int a = get_last_index();
		int b = a-1;

		queue_instruction("AFC",14,a);
		queue_instruction("ADD",14,15); 
		queue_instruction("LOAD", 1, 14);

		queue_instruction("AFC",14,b);
		queue_instruction("ADD",14,15); 
		queue_instruction("LOAD", 2, 14);
		queue_instruction("SUP", 2, 1);

		queue_instruction("AFC",14,b);
		queue_instruction("ADD",14,15);
		queue_instruction("STORE", 14, 2);
		delete_symbol();
	}
	| Expression tLESSEQUAL Expression {
		int a = get_last_index();
		int b = a-1;
		queue_instruction("AFC",14,a);
		queue_instruction("ADD",14,15);
		queue_instruction("LOAD", 1, 14);

		queue_instruction("AFC",14,b);
		queue_instruction("ADD",14,15);
		queue_instruction("LOAD", 2, 14);
		queue_instruction("INFE", 2, 1);

		queue_instruction("AFC",14,b);
		queue_instruction("ADD",14,15);
		queue_instruction("STORE", 14, 2);
		delete_symbol();
	}
	| Expression tMOREEQUAL Expression {
		int a = get_last_index(); // right arg
		int b = a-1;			// left arg
		queue_instruction("AFC",14,a);
		queue_instruction("ADD",14,15);
		queue_instruction("LOAD", 1, 14);

		queue_instruction("AFC",14,b);
		queue_instruction("ADD",14,15);
		queue_instruction("LOAD", 2, 14);

		queue_instruction("SUPE", 2, 1);

		queue_instruction("AFC",14,b);
		queue_instruction("ADD",14,15);
		queue_instruction("STORE", 14, 2);
		delete_symbol();
	};




//while
While : tWHILE {
	prof_increment();
	$1 = get_latest_inst(); /* Hop to here to retry condition */
	//printf("$1 in while is : : %d\n", $1);
	} tPO Condition tPC {

	int a = get_last_index(); //condition-index after all conditions

	queue_instruction("AFC",14,a);
	queue_instruction("ADD",14,15);
	queue_instruction("LOAD", 10, 14); // add in place of 10 , 5+ prof

	queue_instruction("TMP", 1, 1); //we add the unedited JMPC
	$3 = get_latest_inst();         
	delete_symbol();

	} Body {
		queue_instruction("JMP", $1, 1);
		edit_instruction($3, "JMPC" , get_latest_inst(), 10);

		delete_all_var(get_curr_prof());
		prof_decrement();

	} 

; 

For :   tFOR tPO {
			prof_increment();}  //incrementing the depth
	DeclCalc {
		    	$1 = get_latest_inst();}  

	Condition tFINSTR{
	   		int a = get_last_index(); //condition-index after all conditions
			queue_instruction("AFC",14,a);
			queue_instruction("ADD",14,15);
			queue_instruction("LOAD", 10, 14);} // add in place of 10 , 5+ prof

	tVAR tPLUSPLUS tPC  {
			$2= find_symbol($9, get_curr_prof());
			queue_instruction("TMP", 1, 1); //we add the unedited JMPC 
			$7 = get_latest_inst();         
			delete_symbol();}
	Body {	
			//we add here the code for incrementing but targeting the variable that has to be targeted
			queue_instruction("AFC",14,$2);
			queue_instruction("ADD",14,15);
			queue_instruction("LOAD", 1, 14);

			queue_instruction("AFC", 2, 1);
			queue_instruction("ADD", 1, 2);
			queue_instruction("STORE", 14, 1); //$2
			//we updated the value of the value incremented and now we can jump to the condition
			queue_instruction("JMP", $1, 1);
			edit_instruction($7, "JMPC" , get_latest_inst(), 10);


			delete_all_var(get_curr_prof());
			prof_decrement();}


    | 	tFOR tPO {
			prof_increment();}  // incrementing the depth
	DeclCalc {
		        $1 = get_latest_inst();}
	Condition tFINSTR{
	   		int a = get_last_index(); //condition-index after all conditions

			queue_instruction("AFC",14,a);
			queue_instruction("ADD",14,15);
			queue_instruction("LOAD", 10, 14);} // add in place of 10 , 5+ prof
	tVAR tMINUSMINUS tPC  {
			$2= find_symbol($9, get_curr_prof());
			queue_instruction("TMP", 1, 1); //we add the unedited JMPC 
			$7 = get_latest_inst();         
			delete_symbol();}
	Body {
	
			queue_instruction("AFC",14,$2); // we store in r14 value of $2
			queue_instruction("ADD",14,15);
			queue_instruction("LOAD", 1,14);

			queue_instruction("AFC", 2, 1);  // increment part
 			queue_instruction("SUB", 1, 2);

			queue_instruction("STORE", 14, 1); // $2

			queue_instruction("JMP", $1, 1);
			edit_instruction($7, "JMPC" , get_latest_inst(), 10);


			delete_all_var(get_curr_prof());
			prof_decrement(); };


DeclCalc : Declaration |Calcul;












 Calcul:  // we always have the result in the last temp variable
	 	  tVAR tEQUAL Expression tFINSTR {
				 int a = find_symbol($1, get_curr_prof());
				 int b = get_last_index();

				 queue_instruction("AFC",14,b);
				 queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 1, 14);

				 queue_instruction("AFC",14,a);
				 queue_instruction("ADD",14,15);
				 queue_instruction("STORE", 14, 1);
				 delete_symbol();} 

		| tVAR tEQUAL tSUBTRACT Expression tFINSTR {
				 int a = find_symbol($1, get_curr_prof());
				 int b = get_last_index();

				queue_instruction("AFC",14,b);
				queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 1, 14);
				 queue_instruction("AFC", 2, -1);
				 queue_instruction("MUL", 1, 2);

			 	 queue_instruction("AFC",14,a);
			 	 queue_instruction("ADD",14,15);
				 queue_instruction("STORE", 14, 1);
				 delete_symbol();} 

		| tVAR tPLUSPLUS tFINSTR {
				 int a = find_symbol($1, get_curr_prof());

				 queue_instruction("AFC",14,a);
			 	 queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 1, 14);

				 queue_instruction("AFC", 2, 1);
				 queue_instruction("ADD", 1, 2);

				 queue_instruction("STORE", 14, 1);}

		| tVAR tMINUSMINUS tFINSTR {
				 int a = find_symbol($1, get_curr_prof());
				 queue_instruction("AFC",14,a);
				 queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 1, 14);

				 queue_instruction("AFC", 2, 1);
				 queue_instruction("SUB", 1, 2);

				 queue_instruction("STORE", 14, 1);}

		| tVAR tMINUSEQUAL Expression tFINSTR {
				 int a = find_symbol($1, get_curr_prof());
				 int b = get_last_index();

				 queue_instruction("AFC",14,a);
				 queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 1, 14);

				 queue_instruction("AFC",14,b);
				 queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 2, 14);

				 queue_instruction("SUB", 1, 2);

				 queue_instruction("AFC",14,a);
				 queue_instruction("ADD",14,15);
				 queue_instruction("STORE", 14, 1);
				 delete_symbol();}

		| tVAR tPLUSEQUAL Expression tFINSTR{
				 int a = find_symbol($1, get_curr_prof());
				 int b = get_last_index();

				queue_instruction("AFC",14,a);
				queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 1, 14);

				queue_instruction("AFC",14,b);
				queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 2, 14);

			   	 queue_instruction("ADD", 1, 2);

				queue_instruction("AFC",14,a);
				queue_instruction("ADD",14,15);
				 queue_instruction("STORE", 14, 1);
				 delete_symbol();}
;


Expression :
 	     Expression tADD Expression {
				 int a = get_last_index();
				 int b = a-1;

				queue_instruction("AFC",14,a);
				queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 1, 14);

				queue_instruction("AFC",14,b);
				queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 2, 14);

				 queue_instruction("ADD", 1, 2);
			     queue_instruction("STORE", 14, 1);
				 delete_symbol(); }	  

		| Expression tSUBTRACT Expression {
				 int a = get_last_index();
			 	 int b = a-1;

				queue_instruction("AFC",14,a);
				queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 1, 14);

				queue_instruction("AFC",14,b);
				queue_instruction("ADD",14,15);
			 	 queue_instruction("LOAD", 2, 14);

				 queue_instruction("SUB", 1, 2);
				 queue_instruction("STORE", 14, 1);
			 	 delete_symbol(); }

 		| Expression tDIVIDE Expression {
				 int a = get_last_index();
				 int b = a-1;

				queue_instruction("AFC",14,a);
				queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 1, 14);

				queue_instruction("AFC",14,b);
				queue_instruction("ADD",14,15);
			 	 queue_instruction("LOAD", 2, 14);

				 queue_instruction("DIV", 1, 2);
				 queue_instruction("STORE", 14, 1);
				 delete_symbol(); }		

		| Expression tMULTIPLY Expression {
		 		 int a = get_last_index();
				 int b = a-1;
				queue_instruction("AFC",14,a);
				queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 1, 14);

				queue_instruction("AFC",14,b);
				queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 2, 14);

				 queue_instruction("MUL", 1, 2);
				 queue_instruction("STORE", 14, 1);
				 delete_symbol(); }

 		| tVAR {
				add_temporary_symbol();
				int a=find_symbol($1, get_curr_prof());
				int b=get_last_index();
				queue_instruction("AFC",14,a);
				queue_instruction("ADD",14,15);
	 			queue_instruction("LOAD", 1, 14);

				queue_instruction("AFC",14,b);
				queue_instruction("ADD",14,15);
				queue_instruction("STORE", 14, 1); }

		| tINTNR {
				add_temporary_symbol();
				int a=get_last_index();
				queue_instruction("AFC", 1, $1);

				queue_instruction("AFC",14,a);
				queue_instruction("ADD",14,15);
				queue_instruction("STORE",14, 1); }
		| Function {

				//we always have the result in the last var ? 
			 }

		| tPO tSUBTRACT tINTNR tPC {
				add_temporary_symbol();
				int a= get_last_index();
				queue_instruction("AFC", 1, $3);
				queue_instruction("AFC", 2, -1);
				queue_instruction("MUL", 1, 2);

				queue_instruction("AFC",14,a);
				queue_instruction("ADD",14,15);
				queue_instruction("STORE", 14, 1); }

		| tPO Expression tPC  


			;


Function : tVAR tPO{} Param tPC{
	
		queue_instruction("CALL",find_symbol($1,0),0);
		prof_decrement();} ;

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

	printAllInst();
	printf("\n\n");
//sprint_table();
	execute_all_instructions();

	//print_table();

	for(int i=0; i<=get_last_index(); i++){

		printf("var: %s, value: %d\n", get_variable_name(i), get_memory_value(i));
	}
}



