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

%left tADD tSUBTRACT
%left tMULTIPLY tDIVIDE

%%

//$nr means the value of the nr entry

//add strings ????
//add while  !!!
//table of symboles  !!!
// some kind of calculus
// add functions  !!!!

// change the INSTRS




Main: tMAIN tPO tPC BODY { printf("main found\n");};

BODY: tACO INSTRS tACC {printf("Body found\n");}; // add here the profondeur

INSTRS : INSTR INSTRS 
	   | INSTR 
	   | ;

INSTR: Calcul tFINSTR {printf("Count Instr\n"); print_table();}
	 | FORINSTR 
     | WHILEINSTR
     | PRINTINSTR
     | DECLARATIONINSTR
     | IFINSTR 
	 ;

DECLARATIONINSTR: vartype declarations tFINSTR {printf("assigning found\n"); print_table();};


declarations: multideclaration declarations {printf("declaring more variables\n");}
			| lastdeclaration ;

multideclaration : tVAR tVIRGULE {add_symbol($1, type, 0, profondeur);};


lastdeclaration: tVAR {add_symbol($1, type, 0, profondeur);};

vartype : tINT { type = "int"; }
     | tCONST { type = "const"; };

		

 //print f

PRINTINSTR: tPRINTF tPO tVAR tPC tFINSTR {printf("instruction printf\n\n\n");};




// IF    NO " ; " at the end !!!!

IFINSTR : tIF condition BODY
      | tIF condition BODY tELSE BODY{ printf("instruction if found\n");};

condition : tPO tVAR operation compare tPC;
//		  | tPO tINTNR operation compare tPC;

// check for //conditions;
operation: tCHECKEQ 
         | tCHECKHIGHER;

compare: tVAR
       |tINTNR;



//while
WHILEINSTR : tWHILE condition BODY {printf("instruction while found\n");}; // tRECHECK ?




// for

FORINSTR : tFOR forDetail BODY ;   //tRECHECK
forDetail : tPO init tFINSTR condition tFINSTR increment tPC; // does condition from if work ?
init: tINT tVAR tEQUAL tINTNR tINTNR;
increment : tVAR tPLUSPLUS 
          |tVAR tMINUSMINUS ; // tVAR += better ?




 Calcul:
 		tVAR tEQUAL Expression {
					int a = find_symbol($1, profondeur);
					int b = get_last_index();
					printf("LOAD r1 %d\n", b);
					printf("STORE %d, r1\n", a);
					add_instruction("LOAD", 1, b);
					add_instruction("STORE", a, 1);
					delete_symbol();} 

    | tVAR tEQUAL tSUBTRACT Expression {
					int a = find_symbol($1, profondeur);
					int b = get_last_index();
					printf("LOAD r1 %d\n", b);
					printf("AFC r2, -1\n");
					printf("MUL r1, r2\n");
					printf("STORE %d, r1\n", a);
					add_instruction("LOAD", 1, b);
					add_instruction("AFC", 2, -1);
					add_instruction("MUL", 1, 2);
					add_instruction("STORE", a, 1);
					delete_symbol();} 

    | tVAR tPLUSPLUS {
					int a = find_symbol($1, profondeur);
					printf("LOAD r1 %d\n", a);
					printf("AFC r2, 1\n");
					printf("ADD r1,r2\n");
					printf("STORE %d,r1\n", a);
					add_instruction("LOAD", 1, a);
					add_instruction("AFC", 2, 1);
					add_instruction("ADD", 1, 2);
					add_instruction("STORE", a, 1);}

	| tVAR tMINUSMINUS {
					int a = find_symbol($1, profondeur);
					printf("LOAD r1 %d\n", a);
					printf("AFC r2, 1\n");
					printf("SUB r1,r2\n");
					printf("STORE %d,r1\n", a);
					add_instruction("LOAD", 1, a);
					add_instruction("AFC", 2, 1);
					add_instruction("SUB", 1, 2);
					add_instruction("STORE", a, 1);}

    | tVAR tSUBTRACT tEQUAL Expression {
					int a = find_symbol($1, profondeur);
					int b = get_last_index();
					add_instruction("LOAD", 1, a);
					add_instruction("LOAD", 2, b);
					add_instruction("SUB", 1, 2);
					add_instruction("STORE", a, 1);
					delete_symbol();}

	| tVAR tADD tEQUAL Expression {
					int a = find_symbol($1, profondeur);
					int b = get_last_index();
					add_instruction("LOAD", 1, a);
					add_instruction("LOAD", 2, b);
					add_instruction("ADD", 1, 2);
					add_instruction("STORE", a, 1);
					delete_symbol();}
;


Expression :
 			Expression tADD Expression {
					 	int a = get_last_index();
						int b = a-1;
						printf("LOAD r1 %d\n", a);
						printf("LOAD r2 %d\n", b);
						printf("ADD r1, r2 %d\n", a);
						printf("STORE %d, r1\n", b);
						add_instruction("LOAD", 1, a);
						add_instruction("LOAD", 2, b);
						add_instruction("ADD", 1, 2);
						add_instruction("STORE", b, 1);
						delete_symbol();//a

 }	  | Expression tSUBTRACT Expression {
				 int a = get_last_index();
			 	 int b = a-1;
			 	 printf("LOAD r1 %d\n", a);
			 	 printf("LOAD r2 %d\n", b);
			 	 printf("SUB r1, r2 %d\n", a);
			 	 printf("STORE %d, r1\n", b);
				 add_instruction("LOAD", 1, a);
			 	 add_instruction("LOAD", 2, b);
				 add_instruction("SUB", 1, 2);
				 add_instruction("STORE", b, 1);
			 	 delete_symbol();


 } 		| Expression tDIVIDE Expression {
				 int a = get_last_index();
				 int b = a-1;
				 printf("LOAD r1 %d\n", a);
				 printf("LOAD r2 %d\n", b);
				 printf("DIV r1, r2 %d\n", a);
				 printf("STORE %d, r1\n", b);
				 add_instruction("LOAD", 1, a);
			 	 add_instruction("LOAD", 2, b);
				 add_instruction("DIV", 1, 2);
				 add_instruction("STORE", b, 1);
				 delete_symbol();


 }		| Expression tMULTIPLY Expression {
	 			int a = get_last_index();
				int b = a-1;
				printf("LOAD r1 %d\n", a);
				printf("LOAD r2 %d\n", b);
				printf("MUL r1, r2 %d\n", a);
				printf("STORE %d, r1\n", b);
				add_instruction("LOAD", 1, a);
				add_instruction("LOAD", 2, b);
				add_instruction("MUL", 1, 2);
				add_instruction("STORE", b, 1);
				delete_symbol();

				 }
 		  | tVAR {
				add_temporary_symbol();
				printf("LOAD r1, %d\n", find_symbol($1, profondeur));
				printf("STORE %d, r1\n", get_last_index());
	 			add_instruction("LOAD", 1, find_symbol($1, profondeur));
				add_instruction("STORE", get_last_index(), 1);
				}


		  | tINTNR {
				add_temporary_symbol();
				printf("$1: %d\n", $1);
				printf("AFC r1, %d\n", $1);
				printf("STORE %d, r1\n", get_last_index());
				add_instruction("AFC", 1, $1);
				add_instruction("STORE", get_last_index(), 1);
			}

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


