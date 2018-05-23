 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMESIZE 20

typedef struct entry {
  int id;
  char* name;
  char* type;
  int value;
  int initialise;
  int profondeur;
  struct entry* next;
} entry;

entry* tab_symbols;

int add_symbol(char name[NAMESIZE], char* type,  int value, int initialise, int profondeur);

void symbol_initialise(int address);

int return_val(char name[NAMESIZE], int profondeur);

int delete_symbol(char nameArg[NAMESIZE], int profArg);

int* find_symbol(char nameArg[NAMESIZE], int profondeur);

void add_temporary_symbol();

int delete_symbol_address(int address);

int get_last_address();

void print_table();


//[0-9]+("e"[+-][0-9]+)?	{ yylval.nb = (int) atof(yytext); return tINTNR; };  


