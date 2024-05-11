#include "../include/dll.h"
#include <assert.h>
#include <stdio.h>
#include <sys/_types/_null.h>

DLL_NODE init_DLL_NODE_test(char chr) {
  DLL_NODE node = {
    .next = NULL,
    .prev = NULL,
    .chr = chr
  };

  return node;
}

void test_get() {
  DLL dll;
  init_DLL(&dll);

  DLL_NODE* temp_node = dll.head;
  DLL_NODE new_node = init_DLL_NODE_test('h');

  dll.head = &new_node;
  dll.tail = &new_node;

  char result = get(&dll, 0);

  assert(result == 'h');
}

void test_insert_elem() {
  DLL dll;
  init_DLL(&dll);

  int success = insert_elem(&dll, 0, 'h');

  assert(success == 1);
}

void test_print_ddl() {
  DLL dll;
  init_DLL(&dll);
}

int main() {
  test_get();
  test_insert_elem();
}