%{
	#include <stdio.h>
	#include "table.c"
	int yylex(void);
	void yyerror(char*);

char* type;
int profondeur = 0;
%}



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




Main: tINT tMAIN tPO tPC BODY { printf("main found\n");};

BODY: tACO INSTRS tACC {printf("Body found\n");}; // add here the profondeur

INSTRS : INSTR INSTRS | INSTR ;

declarations: multideclaration declarations | lastdeclaration ;
multideclaration : tVAR tVIRGULE {printf("declaring variables\n");
								add_symbole($1, type, 0, 0, profondeur);
								print_table();

 									};
lastdeclaration: tVAR {printf("declaring single variable\n");
					   add_symbole($1, type, 0, 0, profondeur);
						print_table();};

//arithmetics

INSTR: Calcul {printf("Count Instr\n");}
	 | FORINSTR 
     | WHILEINSTR
     | PRINTINSTR
     | DECLARATIONINSTR
     | IFINSTR ;
		
DECLARATIONINSTR: tINT { type = "int"; } declarations tFINSTR {printf("assigning found\n");};

//symbol_initialise($1, profondeur);*
/*
INSTR:tVAR tEQUAL Expression tFINSTR{ 
	int a = find_symbol($1);
	int b = get_last_address();
	printf("LOAD r0 %d\n", a);
	printf("LOAD r1 %d\n", b);
	printf("STORE %d, r1\n", a); ///// nåååååååååååååååååååågot
	symbol_initialise($1, profondeur);
} ;
 */

 //print f

PRINTINSTR: tPRINTF tPO tVAR tPC tFINSTR {printf("instruction printf\n\n\n");};




// IF    NO " ; " at the end !!!!

IFINSTR : tIF condition BODY
      | tIF condition BODY tELSE BODY{ printf("instruction if found\n");};

condition : tPO tVAR operation compare tPC;
//		  | tPO tINTNR operation compare tPC;

// check for //conditions;
operation: tCHECKEQ | tCHECKHIGHER;
compare: tVAR|tINTNR;



//while
WHILEINSTR : tWHILE condition BODY {printf("instruction while found\n");}; // tRECHECK ?




// for

FORINSTR : tFOR forDetail BODY ;   //tRECHECK
forDetail : tPO init tFINSTR condition tFINSTR increment tPC; // does condition from if work ?
init: tINT tVAR tEQUAL tINTNR tINTNR;
increment : tVAR tPLUSPLUS |tVAR tMINUSMINUS ; // tVAR += better ?


//functions
// int|string|void return tTYPE
//INSTR : type tVAR tPO args tPC BODY tFINSTR;
//treat the return
/*
type : 
	tINT { type = "int"; } 
	|tSTRING { type = "string"; } ;
args     : firstArg args | lastArg;
firstArg : argument tVIRGULE ;
lastArg  : argument;
argument : type tVAR
		 | tVAR
		 | tINTNR
		 | tSTRING | ;   //any type of arguments

*/



 Calcul:
 		tVAR tEQUAL Expression {
					int a = find_symbol($1);
					int b = get_last_address();
					printf("LOAD r1 %d\n", b);
					printf("STORE %d, r1\n", a);
					delete_symbol_address(b);} 
  | 
	tVAR tPLUSPLUS {
					int a = find_symbol($1);
					printf("LOAD r1 %d\n", a);
					printf("AFC r2, 1\n");
					printf("ADD r1,r2\n");
					printf("STORE %d,r1\n", a);}
	| tVAR tMINUSMINUS {
					int a = find_symbol($1);
					printf("LOAD r1 %d\n", a);
					printf("AFC r2, 1\n");
					printf("SUB r1,r2\n");
					printf("STORE %d,r1\n", a);};


Expression :
 			Expression tADD Expression {
				 	int a = get_last_address();
					int b = a-128;
					printf("LOAD r1 %d\n", a);
					printf("LOAD r2 %d\n", b);
					printf("ADD r1, r2 %d\n", a);
					printf("STORE %d, r1\n", b);
					delete_symbol_address(a);//a

 }	  | Expression tSUBTRACT Expression {
				 int a = get_last_address();
			 	 int b = a-128;
			 	 printf("LOAD r1 %d\n", a);
			 	 printf("LOAD r2 %d\n", b);
			 	 printf("SUB r1, r2 %d\n", a);
			 	 printf("STORE %d, r1\n", b);
			 	 delete_symbol_address(a);


 } 		| Expression tDIVIDE Expression {
				 int a = get_last_address();
				 int b = a-128;
				 printf("LOAD r1 %d\n", a);
				 printf("LOAD r2 %d\n", b);
				 printf("DIV r1, r2 %d\n", a);
				 printf("STORE %d, r1\n", b);
				 delete_symbol_address(a);


 }		| Expression tMULTIPLY Expression {
	 			int a = get_last_address();
				int b = a-128;
				printf("LOAD r1 %d\n", a);
				printf("LOAD r2 %d\n", b);
				printf("MUL r1, r2 %d\n", a);
				printf("STORE %d, r1\n", b);
				delete_symbol_address(a);

 }
 		  | tVAR {
				add_temporary_symbol();
				printf("AFC r1, %d\n", get_value($1, profondeur));  // check command
				printf("STORE %d, r1\n", get_last_address());
			}
			| tINTNR {
				add_temporary_symbol();
				printf("AFC r1, %d\n", $1;  ///check command
				printf("STORE %d, r1\n", get_last_address());
			}

			| tPO Expression tPC  ;


%%


int main() {
yyparse();
}
