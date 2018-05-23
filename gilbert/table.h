

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
