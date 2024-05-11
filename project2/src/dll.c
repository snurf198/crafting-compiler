#include "include/dll.h"
#include <stdio.h>

void init_DLL(DLL* dll) {
  dll->head = NULL;
  dll->tail = NULL;
}

DLL_NODE init_DLL_NODE(char chr) {
  DLL_NODE node = {
    .next = NULL,
    .prev = NULL,
    .chr = chr
  };

  return node;
}

int insert_elem(DLL* dll, int index, char chr) {
  DLL_NODE* temp_node = dll->head;

  if (temp_node == NULL) {
    return -1;
  }

  for (int i = 0; i < index - 1; i++) {
    temp_node = temp_node->next;

    if (temp_node == NULL) {
      return -1;
    }
  }

  DLL_NODE new_node = init_DLL_NODE(chr);

  new_node.prev = temp_node->prev;
  new_node.next = temp_node;
  temp_node->prev = &new_node;

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
  return 1;
}

void print_dll(DLL* dll) {
  DLL_NODE* node = dll->head;

  while(node != NULL) {
    printf("%c", node->chr);
    node = node->next;
  }
}

