typedef struct _DLL_NODE {
  struct _DLL_NODE* next;
  struct _DLL_NODE* prev;
  char chr;
} DLL_NODE;

typedef struct _DLL {
  DLL_NODE* head;
  DLL_NODE* tail;
} DLL;

void init_DLL(DLL* dll);
int insert_elem(DLL* dll, int index, char chr);
char get(DLL* dll, int index);
int remove_elem(DLL* dll, int index);
void print_dll(DLL* dll);
