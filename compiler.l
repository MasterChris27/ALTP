%{
#include "rule.tab.h"

%}

%%

int		return tINT;
string	return tSTRING;
"{"		return tACO;
"}"		return tACC;
const	return tCONST;
"+"		return tADD;
"-"		return tSUBTRACT;
"/"		return tDIVIDE;
"*"		return tMULTIPLY;
"="		return tEQUAL;
">"     return tCHECKHIGHER;
"=="	return tCHECKEQ;
"("		return tPO;
")"		return tPC;
[ \t\n] ;
","		return tVIRGULE;
"$"		return tDOLLAR;
";"		return tFINSTR;
if		return tIF;
else	return tELSE;
while	return tWHILE;
for		return tFOR;
"++"	return tPLUSPLUS;
"--"	return tMINUSMINUS;
"<" 	return tLESS;
"<=" 	return tLESSEQUAL;
">="	return tMOREEQUAL;




[0-9]+  {
						yylval.nb = atoi(yytext);
						return tINTNR;

		};

printf return tPRINTF;

main return tMAIN;

[a-zA-Z][_a-zA-Z0-9]* {
						yylval.str = strdup(yytext);
				return tVAR;
					  };

