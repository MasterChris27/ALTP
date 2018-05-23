%%

int printf("int found\n");
\{ printf("{ found\n");
\} printf("} found\n");
const printf("const found\n");
\+? printf("add found\n");
\-? printf("subtract found\n");
["][.][""]  printf("string found");
\/? printf("divide found\n");
\*? printf("multiply found\n");
=? printf("equal found\n");
\( printf("parantheses ( found\n");
\) printf("parantheses ) found\n");
[ ] printf("space found\n");
\t printf("tab found\n") ;
, printf("virgule found\n") ;
\\n printf("new line found\n") ; 
\$+ printf("END of the line found\n") ; 
[;] printf("end of instruction found\n") ; 






[0-9]+[.][0-9]+[e][+-][0-9]+ printf(" exponential number found\n");

[0-9]+[.][0-9]+ printf(" decimal number found\n");


printf printf(" printf found\n");

main printf("main found\n");



[a-zA-Z][_a-zA-Z0-9]+ printf("variable name found\n");
[a-zA-Z][_a-zA-Z0-9]+[]*[,] printf("expecting another variable of same type\n");




