/**
 * @brief It tests set module
 *
 * @file set_test.c
 * @author Estefanía Fenoy Montes
 * @version 3.0
 * @date 04-03-2021
 * @copyright GNU Public License
 */
#include "set.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "set_test.h"
#include "test.h"

#define MAX_TESTS 18 /*!<Indicates the maximum number of possible tests*/
int main(int argc, char **argv) {
  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Running all test for module Set:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

  if (all || test == 1) test1_set_create();
  if (all || test == 2) test2_set_create();
  if (all || test == 3) test1_set_add();
  if (all || test == 4) test2_set_add();
  if (all || test == 5) test1_set_return_id();
  if (all || test == 6) test2_set_return_id();
  if (all || test == 7) test3_set_return_id();
  if (all || test == 8) test1_set_del();
  if (all || test == 9) test2_set_del();
  if (all || test == 10) test3_set_del();
  if (all || test == 11) test4_set_del();
  if (all || test == 12) test1_set_check_id();
  if (all || test == 13) test2_set_check_id();
  if (all || test == 14) test3_set_check_id();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}
void test1_set_create() {
  int result;
  Set *s;
  s = set_create();
  result = s != NULL;
  PRINT_TEST_RESULT(result);
  set_destroy(s);
}
void test2_space_create() {
  Set *s;
  s = set_create();
  PRINT_TEST_RESULT(set_return_id(s, 1) == NO_ID);
  set_destroy(s);
}

void test1_set_add() {
  Set *s;
  s = space_create();
  PRINT_TEST_RESULT(set_add(s, 5) == OK);
  set_destroy(s);
}
void test2_set_add() {
  Set *s = NULL;
  PRINT_TEST_RESULT(set_add(s, 5) == ERROR);
}

void test1_set_return_id() {
  Set *s;
  s = space_create();
  set_add(s, 4);
  PRINT_TEST_RESULT(set_return_id(s, 0) == 4);
  set_destroy(s);
}
void test2_set_return_id() {
  Set *s = NULL;
  PRINT_TEST_RESULT(set_return_id(s, 0) == NO_ID);
}
void test3_set_return_id() {
  Set *s;
  s= set_create();
  PRINT_TEST_RESULT(set_return_id(s, -1) == NO_ID);
  set_destroy(s);
}
void test1_set_del(){
  Set *s;
  s=set_create();
  set_add(s, 6);
  PRINT_TEST_RESULT(set_del(s, 6) == OK);
  set_destroy(s);
}

void test2_set_del(){
    Set *s;
  s=set_create();
  set_add(s, 6);
  set_add(s, 4);
  PRINT_TEST_RESULT(set_del(s, 4) == OK);
  set_destroy(s);
}
void test3_set_del(){
  Set *s = NULL;
  PRINT_TEST_RESULT(set_del(s, 4) == ERROR);
}
void test4_set_del(){
    Set *s;
  s=set_create();
  set_add(s, 6);
  set_add(s, 4);
  PRINT_TEST_RESULT(set_del(s, 2) == ERROR);
  set_destroy(s);
}
void test1_set_check_id(){
  Set *s;
  s=set_create();
  set_add(s, 6);
  set_add(s, 4);
  PRINT_TEST_RESULT(set_check_id(s, 6) == TRUE);
  set_destroy(s);
}
void test2_set_check_id(){
  Set *s;
  s=set_create();
  set_add(s, 6);
  set_add(s, 4);
  PRINT_TEST_RESULT(set_check_id(s, 3) == FALSE);
  set_destroy(s);
}
void test3_set_check_id(){
  Set *s;
  PRINT_TEST_RESULT(set_check_id(s, 6) == FALSE);
}