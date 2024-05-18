#include "../include/dll.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_null.h>

DLL_NODE* init_DLL_NODE_test(char chr) {
  DLL_NODE* node = malloc(sizeof(DLL_NODE));
  
  node->next = NULL;
  node->prev = NULL;
  node->chr = chr;

  return node;
}

void test_get() {
  DLL dll;
  init_DLL(&dll);

  DLL_NODE* temp_node = dll.head;
  DLL_NODE* new_node = init_DLL_NODE_test('h');

  dll.head = new_node;
  dll.tail = new_node;

  char result = get(&dll, 0);

  assert(result == 'h');
}

void test_insert_elem() {
  DLL dll;
  init_DLL(&dll);

  int success = insert_elem(&dll, 0, 'h');

  assert(success == 1);
}

void test_print_dll() {
  DLL dll;
  init_DLL(&dll);

  insert_elem(&dll, 0, 'o');
  insert_elem(&dll, 1, 'l');
  insert_elem(&dll, 1, 'l');
  insert_elem(&dll, 2, 'e');
  insert_elem(&dll, 1, 'h');

  print_dll(&dll); // ohlel
}

void test_get_dll() {
  DLL dll;
  init_DLL(&dll);

  insert_elem(&dll, 0, 'o');
  insert_elem(&dll, 1, 'l');
  insert_elem(&dll, 1, 'l');
  insert_elem(&dll, 2, 'e');
  insert_elem(&dll, 1, 'h');

  assert(get(&dll, 4) == 'e');
}

void test_push_back() {
  DLL dll;
  init_DLL(&dll);

  push_back(&dll, 'h');
  push_back(&dll, 'e');
  push_back(&dll, 'l');
  push_back(&dll, 'l');
  push_back(&dll, 'o');

  print_dll(&dll); //hello
}

void test_remove_elem() {
  DLL dll;
  init_DLL(&dll);

  push_back(&dll, 'h');
  push_back(&dll, 'e');
  push_back(&dll, 'l');
  push_back(&dll, 'l');
  push_back(&dll, 'o');

  remove_elem(&dll, 0);
  remove_elem(&dll, 3);
  remove_elem(&dll, 1);

  print_dll(&dll); //el
}

int main() {
  test_get();
  test_insert_elem();
  test_print_dll();
  test_push_back();
  test_remove_elem();
}