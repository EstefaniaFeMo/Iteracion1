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
  if (all || test == 3) test1_set_destroy();
  if (all || test == 4) test2_set_destroy();
  if (all || test == 5) test1_set_add();
  if (all || test == 6) test2_set_add();
  if (all || test == 7) test1_set_return_id();
  if (all || test == 8) test2_set_return_id();
  if (all || test == 9) test3_set_return_id();
  if (all || test == 10) test1_set_del();
  if (all || test == 11) test2_set_del();
  if (all || test == 12) test3_set_del();
  if (all || test == 13) test4_set_del();
  if (all || test == 14) test1_set_check_id();
  if (all || test == 15) test2_set_check_id();
  if (all || test == 16) test3_set_check_id();
  if (all || test == 17) test1_set_print();
  if (all || test == 18) test2_set_print();
  if (all || test == 19) test3_set_print();
  if (all || test == 20) test1_set_get_n_ids();
  if (all || test == 21) test2_set_get_n_ids();
  PRINT_PASSED_PERCENTAGE;

  return 1;
}

/* Test set creation*/
void test1_set_create() {
  int result;
  Set *s;
  s = set_create();
  result = s != NULL;
  PRINT_TEST_RESULT(result);
  set_destroy(s);
}

/*Test function for checking if set_create inizialites correctly the set id*/
void test2_set_create() {
  Set *s;
  s = set_create();
  PRINT_TEST_RESULT(set_return_id(s, 1) == NO_ID);
  set_destroy(s);
}

/*Test function for set_destroy setting*/
void test1_set_destroy(){
  Set *s;
  s=set_create();
  PRINT_TEST_RESULT(set_destroy(s)==OK);
}

/*Test function for set_destroy setting*/
void test2_set_destroy(){
  Set *s=NULL;
  PRINT_TEST_RESULT(set_destroy(s)==ERROR);
}

/*Test function for set_add setting*/
void test1_set_add() {
  Set *s;
  s = set_create();
  PRINT_TEST_RESULT(set_add(s, 5) == OK);
  set_destroy(s);
}

/*Test function for set_add setting*/
void test2_set_add() {
  Set *s = NULL;
  PRINT_TEST_RESULT(set_add(s, 5) == ERROR);
}

/*Test function for set_return_id setting*/
void test1_set_return_id() {
  Set *s;
  s = set_create();
  set_add(s, 4);
  PRINT_TEST_RESULT(set_return_id(s, 0) == 4);
  set_destroy(s);
}

/*Test function for set_return_id setting*/
void test2_set_return_id() {
  Set *s = NULL;
  PRINT_TEST_RESULT(set_return_id(s, 0) == NO_ID);
}

/*Test function for set_return_id setting*/
void test3_set_return_id() {
  Set *s;
  s= set_create();
  PRINT_TEST_RESULT(set_return_id(s, -1) == NO_ID);
  set_destroy(s);
}

/*Test function for set_del setting*/
void test1_set_del(){
  Set *s;
  s=set_create();
  set_add(s, 6);
  PRINT_TEST_RESULT(set_del(s, 6) == OK);
  set_destroy(s);
}

/*Test function for set_del setting*/
void test2_set_del(){
    Set *s;
  s=set_create();
  set_add(s, 6);
  set_add(s, 4);
  PRINT_TEST_RESULT(set_del(s, 4) == OK);
  set_destroy(s);
}

/*Test function for set_del setting*/
void test3_set_del(){
  Set *s = NULL;
  PRINT_TEST_RESULT(set_del(s, 4) == ERROR);
}

/*Test function for set_del setting*/
void test4_set_del(){
    Set *s;
  s=set_create();
  set_add(s, 6);
  set_add(s, 4);
  PRINT_TEST_RESULT(set_del(s, 2) == ERROR);
  set_destroy(s);
}

/*Test function for set_check_id setting*/
void test1_set_check_id(){
  Set *s;
  s=set_create();
  set_add(s, 6);
  set_add(s, 4);
  PRINT_TEST_RESULT(set_check_id(s, 6) == TRUE);
  set_destroy(s);
}

/*Test function for set_check_id setting*/
void test2_set_check_id(){
  Set *s;
  s=set_create();
  set_add(s, 6);
  set_add(s, 4);
  PRINT_TEST_RESULT(set_check_id(s, 3) == FALSE);
  set_destroy(s);
}

/*Test function for set_check_id setting*/
void test3_set_check_id(){
  Set *s=NULL;
  PRINT_TEST_RESULT(set_check_id(s, 6) == FALSE);
}

/*Test function for set_print setting*/
void test1_set_print(){
  Set *s;
  s=set_create();
  set_add(s, 4);
  PRINT_TEST_RESULT(set_print(s)==OK);
  set_destroy(s);
}

/*Test function for set_print setting*/
void test2_set_print(){
  Set *s;
  s=set_create();
  PRINT_TEST_RESULT(set_print(s)==ERROR);
  set_destroy(s);
}

/*Test function for set_print setting*/
void test3_set_print(){
  Set *s=NULL;
  PRINT_TEST_RESULT(set_print(s)==ERROR);
}

/*Test function for set_get_n_ids setting*/
void test1_set_get_n_ids(){
  Set *s;
  s=set_create();
  set_add(s, 4);
  PRINT_TEST_RESULT(set_get_n_ids(s)==1);
  set_destroy(s);
}

/*Test function for set_get_n_ids setting*/
void test2_set_get_n_ids(){
  Set *s=NULL;
  PRINT_TEST_RESULT(set_get_n_ids(s)==-1);
} 
