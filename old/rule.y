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

multideclaration : tVAR tVIRGULE {printf("declaring variables\n");
								add_symbol($1, type, 0, profondeur);};


lastdeclaration: tVAR {printf("declaring single variable\n");
					   add_symbol($1, type, 0, profondeur);};

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
					printf("welcome, tVAR: %s\n", $1);
					int a = find_symbol($1, profondeur);
					int b = get_last_index();
					printf("LOAD r1 %d\n", b);
					instruction("LOAD", b);
					printf("STORE %d, r1\n", a);
					delete_symbol();} 

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

    | tVAR tEQUAL tSUBTRACT Expression {
					int a = find_symbol($1, profondeur);
					int b = get_last_index();
					printf("LOAD r1 %d\n", b);
					printf("MUL r1,-1\n");
					printf("STORE %d, r1\n", a);
					delete_symbol();}


;


Expression :
 			Expression tADD Expression {
				 	int a = get_last_index();
					int b = a-1; //+ or -
					printf("LOAD r1 %d\n", a);
					printf("LOAD r2 %d\n", b);
					printf("ADD(r1, r2) %d\n", a);
					printf("STORE %d, r1\n", b);
					delete_symbol();//a

 }	  | Expression tSUBTRACT Expression {
				 int a = get_last_index();
			 	 int b = a-1;
			 	 printf("LOAD r1 %d\n", a);
			 	 printf("LOAD r2 %d\n", b);
			 	 printf("SUB r1, r2 %d\n", a);
			 	 printf("STORE %d, r1\n", b);
			 	 delete_symbol();


 } 		| Expression tDIVIDE Expression {
				 int a = get_last_index();
				 int b = a-1;
				 printf("LOAD r1 %d\n", a);
				 printf("LOAD r2 %d\n", b);
				 printf("DIV r1, r2 %d\n", a);
				 printf("STORE %d, r1\n", b);
				 delete_symbol();


 }		| Expression tMULTIPLY Expression {
	 			int a = get_last_index();
				int b = a-1;
				printf("LOAD r1 %d\n", a);
				printf("LOAD r2 %d\n", b);
				printf("MUL r1, r2 %d\n", a);
				printf("STORE %d, r1\n", b);
				delete_symbol();

 }
 		  | tVAR {
				printf("tvar calcs\n\n\n\n");
				add_temporary_symbol();
				print_table();
	//			printf("AFC r1, %d\n", return_val($1, profondeur));  // check command
				printf("STORE %d, r1\n", get_last_index());//+ BASE memory
			}
			| tINTNR {
				printf("intnrcalca : %s \n\n\n\n", $1);
				add_temporary_symbol();
				print_table();
	//			printf("AFC r1, %d\n", $1);  ///check command
				printf("STORE %d, r1\n", get_last_index());
			}

			| tPO Expression tPC  ;


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
}


