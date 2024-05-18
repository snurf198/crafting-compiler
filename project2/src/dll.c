#include "include/dll.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_null.h>

DLL_NODE* init_DLL_NODE(char chr) {
  DLL_NODE* node = malloc(sizeof(DLL_NODE));
  
  node->next = NULL;
  node->prev = NULL;
  node->chr = chr;

  return node;
}

void init_DLL(DLL* dll) {
  dll->head = init_DLL_NODE('\0');
  dll->tail = init_DLL_NODE('\0');

  dll->head->next = dll->tail;
  dll->tail->prev = dll->head;
}


int insert_elem(DLL* dll, int index, char chr) {
  DLL_NODE* temp_node = dll->head;
  DLL_NODE* new_node = init_DLL_NODE(chr);

  for (int i = 0; i < index; i++) {
    temp_node = temp_node->next;

    if (temp_node == dll->tail) {
      return -1;
    }
  }

  new_node->prev = temp_node;
  new_node->next = temp_node->next;
  temp_node->next->prev = new_node;
  temp_node->next = new_node;

  return 1;
}

int push_back(DLL* dll, char chr) {
  DLL_NODE* temp_node = dll->tail->prev;
  DLL_NODE* new_node = init_DLL_NODE(chr);

  new_node->prev = temp_node;
  new_node->next = temp_node->next;
  temp_node->next->prev = new_node;
  temp_node->next = new_node;

  return 1;
}

char get(DLL* dll, int index) {
  DLL_NODE* temp_node = dll->head;

  if (temp_node == NULL) {
    return '\0';
  }

  for (int i = 0; i < index - 1; i++) {
    temp_node = temp_node->next;

    if (temp_node == NULL) {
      return '\0';
    }
  }

  return temp_node->chr;
}

int remove_elem(DLL* dll, int index) {
  DLL_NODE* temp_node = dll->head->next;

  for (int i = 0; i < index; i++) {
    temp_node = temp_node->next;

    if (temp_node == dll->tail) {
      return -1;
    }
  }

  temp_node->prev->next = temp_node->next;
  temp_node->next->prev = temp_node->prev;

  free(temp_node);

  return 1;
}

void print_dll(DLL* dll) {
  DLL_NODE* node = dll->head;

  while(node != NULL) {
    printf("%c", node->chr);
    node = node->next;
  }

  printf("\n");
}

int len_of(DLL* dll) {
  int size = 0;
  DLL_NODE* node = dll->head->next;

  while(node != NULL) {
    size++;
    node = node->next;
  }

  return size;
}

