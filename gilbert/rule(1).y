%{
	#include <stdio.h>
	#include "table.c";
	int yylex(void);
	void yyerror(char*);

char *type;
int profondeur = 0;
%}


%token INT
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
%token tCHECKNEQ
%token tPO
%token tPC
%token tTAB
%token tVIRGULE
%token tNL
%token tDOLLAR
%token tFINSTR
%token tEXPNO
%token tDECNO
%token tINTNR
%token tWHILE
%token tPRINTF
%token tMAIN
%token tVAR
%token tANOTHERVAR
%token tIF
%token tELSE
%token tWHILE
%token tFOR
%token tSTRING


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



INSTR: tINT { type = "int"; } declarations tFINSTR {printf("assigning found\n");};
declarations: multideclaration declarations | lastdeclaration ;
multideclaration : tVAR tVIRGULE {printf("declaring variables\n");
								add_symbole($1, type, 0, 0, profondeur);
								print_table();

 									};
lastdeclaration: tVAR {printf("declaring single variable\n");
					   add_symbole($1, type, 0, 0, profondeur);
						print_table();};


//arithmetics

 INSTR: Calcul {printf("Count Instr\n");};

 Calcul:
 		tVAR tEQUAL Expression {
					int a = find_symbol($1);
					int b = get_last_address();
					printf("LOAD r1 %d\n", b);
					printf("STORE %d, r1\n", a);
					delete_symbol_address(b);
			}
  | tVAR tPLUSPLUS {
					int a = find_symbol($1);
					printf("LOAD r1 %d\n", a);
					printf("AFC r2, 1\n");
					printf("ADD r1,r2\n");
					printf("STORE %d,r1\n", a);

			}
	| tVar tMINUSMINUS {
					int a = find_symbol($1);
					printf("LOAD r1 %d\n", a);
					printf("AFC r2, 1\n");
					printf("SUB r1,r2\n");
					printf("STORE %d,r1\n", a);

	}
	| tVAR tEQUAL tPLUS Expression {
					int a = find_symbol($1);
					int b = get_last_address();
					printf("LOAD r0 %d\n", a);
					printf("LOAD r1 %d\n", b);
					printf("ADD r0, r1\n");
					printf("STORE %d, r1\n", a);
	}
	| tVar tEQUAL tSUBTRACT  Expression {
					int a = find_symbol($1);
					int b = get_last_address();
					printf("LOAD r0 %d\n", a);
					printf("LOAD r1 %d\n", b);
					printf("SUB r0, r1\n");
					printf("STORE %d, r1\n", a);
	}

 INSTR:tVAR tEQUAL Expression tFINSTR {printf("Count Instr\n");};

 Expression :
 			Expression tADD Expression {
				 	int a = get_last_address();
					int b = a-128,
					printf("LOAD r1 %d\n", a);
					printf("LOAD r2 %d\n", b);
					printf("ADD r1, r2 %d\n", a);
					printf("STORE %d, r1\n", b);
					delete_symbol_address(a);//a

 }	  | Expression tSUBTRACT Expression {
				 int a = get_last_address();
			 	 int b = a-128,
			 	 printf("LOAD r1 %d\n", a);
			 	 printf("LOAD r2 %d\n", b);
			 	 printf("SUB r1, r2 %d\n", a);
			 	 printf("STORE %d, r1\n", b);
			 	 delete_symbol_address(a);


 } 		| Expression tDIVIDE Expression {
				 int a = get_last_address();
				 int b = a-128,
				 printf("LOAD r1 %d\n", a);
				 printf("LOAD r2 %d\n", b);
				 printf("DIV r1, r2 %d\n", a);
				 printf("STORE %d, r1\n", b);
				 delete_symbol_address(a);


 }		| Expression tMULTIPLY Expression {
	 			int a = get_last_address();
				int b = a-128,
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















 //print f

INSTR: tPRINTF tPO tVAR tPC tFINSTR {printf("instruction printf\n\n\n");};




// IF    NO " ; " at the end !!!!

INSTR : tIF condition BODY
       | tIF condition BODY tELSE BODY 	   {printf("instruction if found\n");
                                             };
condition : tPO tVAR operation compare tPC
		  | tPO tPC operation compare tPC;


// check for //conditions;
operation: tCHECKEQ | tCHECKHIGHER;
compare: tVAR|tINTNR;


//while
	INSTR : tWHILE condition BODY {printf("instruction while found\n");
                                      }; // tRECHECK ?




// for

	INSTR : tFOR forDetail Body ;   //tRECHECK

forDetail : tPO init tFINSTR condition tFINSTR increment   					tPC; // does condition from if work ?

init: tINT tVAR tEQUAL tINTNR tINTNR
increment : tVAR++|tVAR-- ; // tVAR += better ?





//functions
// int|string|void return tTYPE
INSTR : type tVAR tPO args tPC BODY tFINSTR;
//treat the return
type : tINT|tSTRING;
args     : firstArg args | lastArg;
firstArg : argument tVIRGULE ;
lastARg  : argument;
argument : type tVAR
		 | tVAR
		 | tINTNR
		 | tSTR | ;   //any type of arguments






declarations: multideclaration declarations | lastdeclaration ;
multideclaration : tVAR tVIRGULE {printf("declaring variables\n");};
lastdeclaration: tVAR {printf("declaring single vqriqble\n");};








/*
declarations: decl mdecl
			| singledecl ;                          //declaring variables
singledecl : tVAR;
mdecl: decl mdecl | {printf("declaring variables\n");};
decl: tVAR tVIRGULE {printf("declaring variables\n");};
*/
//INSTR: tVAR tEQUAL tINTNR {printf("assigning values")};              //assigning them


/*
declarations: multideclaration singledeclaration
			| singledeclaration ;                          //declaring variables
singledeclaration: tVAR {printf("declaring variables\n");};
multideclaration : tVAR tVIRGULE {printf("declaring variables\n");};

*/



/*
declarations: declaration declarations | ;                          //declaring variables
declaration: tVAR tVIRGULE {printf("declaring variables\n");};
 */

/*AFC r1,2
store @i,r1

*/


/*
INSTR: tINT tVAR tEQUAL tDECNO expres tFINSTR {printf("Addition decimals");}
	| tINT tVAR tEQUAL tEXPNO expres tFINSTR{printf("Addition decimals");};
expres:  tADD|tDIVIDE|tMULTIPLY|tSUBTRACT tDECNO|tEXPNO {printf(expressionfound)}; // add parantheses

*/



%%


int main() {
yyparse();
}
