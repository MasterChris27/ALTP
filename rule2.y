%{
	#include <stdio.h>
	#include "table.c"
	
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
%token tPLUS
%token tMINUS
%token tSLASH
%token tASTERISK
%token tEQUALSIGN
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

%left tPLUS tMINUS
%left tASTERISK tSLASH

%%

//$nr means the value of the nr entry

//add strings ????
//add while  !!!
//table of symboles  !!!
// some kind of calculus
// add functions  !!!!

// change the Instructions




Main: tMAIN tPO tPC Body { printf("rule.y: Main\n");};

Body: tACO Instructions tACC {printf("rule.y: Body\n");}; // add here the profondeur

Instructions : Instruction Instructions 
	   | Instruction 
	   | ;

Instruction: Arithmetic tFINSTR {printf("rule.y: Instruction Arithmetic\n"); print_table();}
	 | For {printf("rule.y: Instruction For\n"); print_table();}
     | While {printf("rule.y: Instruction While\n"); print_table();}
     | Print {printf("rule.y: Instruction Print\n"); print_table();}
     | Declaration {printf("rule.y: Instruction Declaration\n"); print_table();}
     | If {printf("rule.y: Instruction If\n"); print_table();} 
	 ;

Declaration: variable_type Declarations tFINSTR {printf("rule.y: Declaration\n"); print_table();};


Declarations: Multideclaration Declarations {printf("rule.y: Declarations\n");}
			| Lastdeclaration ;

Multideclaration : tVAR tVIRGULE {printf("rule.y: Multideclaration\n");
								add_symbol($1, type, 0, 0, profondeur);};


Lastdeclaration: tVAR {printf("rule.y: Lastdeclaration\n");
					   add_symbol($1, type, 0, 0, profondeur);};

variable_type : tINT { type = "int"; }
     | tCONST { type = "const"; };

		

 //print f

Print: tPRINTF tPO tVAR tPC tFINSTR {printf("rule.y: Print\n\n\n");};




// IF    NO " ; " at the end !!!!

If : tIF Condition Body
      | tIF Condition Body tELSE Body{ printf("rule.y: If\n");};

Condition : tPO tVAR Operation Compare tPC;
//		  | tPO tINTNR Operation Compare tPC;

// check for //conditions;
Operation: tCHECKEQ 
         | tCHECKHIGHER;

Compare: tVAR
       |tINTNR;



//while
While : tWHILE Condition Body {printf("rule.y: While\n");}; // tRECHECK ?




// for

For : tFOR forDetail Body ;   //tRECHECK
forDetail : tPO init tFINSTR Condition tFINSTR increment tPC; // does Condition from if work ?
init: tINT tVAR tEQUALSIGN tINTNR tINTNR;
increment : tVAR tPLUSPLUS 
          |tVAR tMINUSMINUS ; // tVAR += better ?




 Arithmetic:
 		tVAR tEQUALSIGN Expression {
					printf("welcome, tVAR: %s\n", $1);
					int a = find_symbol($1, profondeur);
					int b = get_last_address();
					printf("LOAD r1 %d\n", b);
					printf("STORE %d, r1\n", a);
					delete_symbol_address(b);} 

    | tVAR tPLUSPLUS {
					int a = find_symbol($1, profondeur);
					printf("LOAD r1 %d\n", a);
					printf("AFC r2, 1\n");
					printf("ADD r1,r2\n");
					printf("STORE %d,r1\n", a);}
	| tVAR tMINUSMINUS {
					int a = find_symbol($1, profondeur);
					printf("LOAD r1 %d\n", a);
					printf("AFC r2, 1\n");
					printf("SUB r1,r2\n");
					printf("STORE %d,r1\n", a);}

    | tVAR tEQUALSIGN tMINUS Expression {
					int a = find_symbol($1, profondeur);
					int b = get_last_address();
					printf("LOAD r1 %d\n", b);
					printf("MUL r1,-1\n");
					printf("STORE %d, r1\n", a);
					delete_symbol_address(b);}


;


Expression :
 			Expression tPLUS Expression {
				 	int a = get_last_address();
					int b = a-128;
					printf("LOAD r1 %d\n", a);
					printf("LOAD r2 %d\n", b);
					printf("ADD r1, r2 %d\n", a);
					printf("STORE %d, r1\n", b);
					delete_symbol_address(a);//a

 }	  | Expression tMINUS Expression {
				 int a = get_last_address();
			 	 int b = a-128;
			 	 printf("LOAD r1 %d\n", a);
			 	 printf("LOAD r2 %d\n", b);
			 	 printf("SUB r1, r2 %d\n", a);
			 	 printf("STORE %d, r1\n", b);
			 	 delete_symbol_address(a);


 } 		| Expression tSLASH Expression {
				 int a = get_last_address();
				 int b = a-128;
				 printf("LOAD r1 %d\n", a);
				 printf("LOAD r2 %d\n", b);
				 printf("DIV r1, r2 %d\n", a);
				 printf("STORE %d, r1\n", b);
				 delete_symbol_address(a);


 }		| Expression tASTERISK Expression {
	 			int a = get_last_address();
				int b = a-128;
				printf("LOAD r1 %d\n", a);
				printf("LOAD r2 %d\n", b);
				printf("MUL r1, r2 %d\n", a);
				printf("STORE %d, r1\n", b);
				delete_symbol_address(a);

 }
 		  | tVAR {
				printf("tvar calcs\n\n\n\n");
				add_temporary_symbol();
				print_table();
				printf("AFC r1, %d\n", return_val($1, profondeur));  // check command
				printf("STORE %d, r1\n", get_last_address());
			}
			| tINTNR {
				printf("intnrcalca : %s \n\n\n\n", $1);
				add_temporary_symbol();
				print_table();
				printf("AFC r1, %d\n", $1);  ///check command
				printf("STORE %d, r1\n", get_last_address());
			}

			| tPO Expression tPC  ;


%%


void yyerror(char *s) {
	fprintf(stderr, "error: %s\n", s);
	exit(1);
}

int Main() {

	//#if YYDEBUG
	//	yydebug = 1;
//	#endif




	yyparse();
}


