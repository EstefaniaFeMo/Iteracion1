/**
 * @brief It tests inventory module
 *
 * @file inventory_test.c
 * @author Estefanía Fenoy Montes
 * @version 3.0
 * @date 19-03-2021
 * @copyright GNU Public License
 */

#include "inventory.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inventory_test.h"
#include "test.h"


/**
 * @brief Main function for INVENTORY unit tests.
 *
 * You may execute ALL or a SINGLE test
 *   1.- No parameter -> ALL test are executed
 *   2.- A number means a particular test (the one identified by that number)
 *       is executed
 *
 */
int main(int argc, char **argv) {
  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Running all test for module Space:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

  if (all || test == 1) test1_inventory_create();
  if (all || test == 2) test2_inventory_create();
  if (all || test == 3) test1_inventory_destroy();
  if (all || test == 4) test2_inventory_destroy();
  if (all || test == 5) test1_inventory_set_max_objects();
  if (all || test == 6) test2_inventory_set_max_objects();
  if (all || test == 7) test1_inventory_get_max_objects();
  if (all || test == 8) test2_inventory_get_max_objects();
  if (all || test == 9) test1_inventory_check_object();
  if (all || test == 10) test2_inventory_check_object();
  if (all || test == 11) test3_inventory_check_object();
  if (all || test== 12)  test1_inventory_add_object();
  if (all || test == 13) test2_inventory_add_object();
  if (all || test == 14) test3_inventory_add_object();
  if (all || test == 15) test1_inventory_get_object_id();
  if (all || test == 16) test2_inventory_get_object_id();
  if (all || test == 17) test1_inventory_del_object();
  if (all || test == 18) test2_inventory_del_object();
  if (all || test == 19) test3_inventory_del_object();
  if (all || test == 20) test4_inventory_del_object();
  if (all || test == 21) test1_inventory_print();  
  if (all || test == 22) test2_inventory_print(); 
  if (all || test == 23) test1_inventory_get_objects();
  if (all || test == 24) test2_inventory_get_objects();
  if (all || test == 25) test1_inventory_is_full();
  if (all || test == 26) test2_inventory_is_full();
  if (all || test == 27) test3_inventory_is_full(); 
  if (all || test == 28) test4_inventory_is_full();                   
  if (all || test == 29) test1_inventory_is_empty();
  if (all || test == 30) test2_inventory_is_empty();
  if (all || test == 31) test3_inventory_is_empty(); 

  PRINT_PASSED_PERCENTAGE;

  return 1;
}
/** Test function for inventory_create setting */
void test1_inventory_create() {
  int result;
  Inventory *i;
  i = inventory_create();
  result = i != NULL;
  PRINT_TEST_RESULT(result);
  inventory_destroy(i);
}

/** Test function for inventory_create setting */
void test2_inventory_create() {
  Inventory *i;
  i = inventory_create();
  PRINT_TEST_RESULT(inventory_get_max_objects(i) == 0);
  inventory_destroy(i);
}

/** Test function for test1_inventory_set_max_objects setting */
void test1_inventory_set_max_objects() {
  Inventory *i;
  i = inventory_create();
  PRINT_TEST_RESULT(inventory_set_max_objects(i, 2) == OK);
  inventory_destroy(i);
}

/** Test function for test2_inventory_set_max_objects setting */
void test2_inventory_set_max_objects() {
  Inventory *i=NULL;
  PRINT_TEST_RESULT(inventory_set_max_objects(i, 2) == ERROR);
}

/** Test function for test1_inventory_get_max_objects setting */
void test1_inventory_get_max_objects() {
  Inventory *i;
  i = inventory_create();
  inventory_set_max_objects(i, 5);
  PRINT_TEST_RESULT(inventory_get_max_objects(i) == 5);
  inventory_destroy(i);
}

/** Test function for test2_inventory_get_max_objects setting */
void test2_inventory_get_max_objects() {
  Inventory *i=NULL;
  PRINT_TEST_RESULT(inventory_get_max_objects(i) == -1);
}

/** Test function for inventory_check_object setting */
void test1_inventory_check_object() {
  Inventory *i;
  i = inventory_create();
  PRINT_TEST_RESULT(inventory_check_object(i, 5) == FALSE);
  inventory_destroy(i);
}

/** Test function for inventory_check_object setting */
void test2_inventory_check_object() {
  Inventory *i;
  i = inventory_create();
  inventory_set_max_objects(i, 1);
  inventory_add_object(i, 25);
  PRINT_TEST_RESULT(inventory_check_object(i, 25) == TRUE);
  inventory_destroy(i);
}

/** Test function for inventory_check_object setting */
void test3_inventory_check_object() {
  Inventory *i = NULL;
  PRINT_TEST_RESULT(inventory_check_object(i, 30) == FALSE);
}

/** Test function for inventory_get_object_id setting */
void test1_inventory_get_object_id() {
  Inventory *i;
  i = inventory_create();
  inventory_set_max_objects(i, 1);
  inventory_add_object(i, 12);
  PRINT_TEST_RESULT(inventory_get_object_id(i, 0) == 12);
  inventory_destroy(i);
}

/** Test function for inventory_get_object_id setting */
void test2_inventory_get_object_id() {
  Inventory *i = NULL;
  PRINT_TEST_RESULT(inventory_get_object_id(i, 0) == NO_ID);
}

/** Test function for inventory_add_object setting */
void test1_inventory_add_object(){
  Inventory *i;
  i=inventory_create();
  inventory_set_max_objects(i, 1);
  PRINT_TEST_RESULT(inventory_add_object(i, 4)==OK);
  inventory_destroy(i);
}

/** Test function for inventory_add_object setting */
void test2_inventory_add_object(){
  Inventory *i=NULL;
  PRINT_TEST_RESULT(inventory_add_object(i, 4)==ERROR);
}

/** Test function for inventory_add_object setting */
void test3_inventory_add_object(){
  Inventory *i;
  i=inventory_create();
  PRINT_TEST_RESULT(inventory_add_object(i, NO_ID)==ERROR);
  inventory_destroy(i);
}

/** Test function for inventory_del_object setting */
void test1_inventory_del_object(){
  Inventory *i;
  i=inventory_create();
  inventory_set_max_objects(i, 1);
  inventory_add_object(i, 3);
  PRINT_TEST_RESULT(inventory_del_object(i, 3)==OK);
  inventory_destroy(i);
}

/** Test function for inventory_del_object setting */
void test2_inventory_del_object(){
  Inventory *i;
  i=inventory_create();
  inventory_add_object(i, 3);
  PRINT_TEST_RESULT(inventory_del_object(i, 2)==ERROR);
  inventory_destroy(i);
}

/** Test function for inventory_del_object setting */
void test3_inventory_del_object(){
  Inventory *i=NULL;
  PRINT_TEST_RESULT(inventory_del_object(i, 3)==ERROR);
}

/** Test function for inventory_del_object setting */
void test4_inventory_del_object(){
  Inventory *i;
  i=inventory_create();
  PRINT_TEST_RESULT(inventory_del_object(i, NO_ID)==ERROR);
  inventory_destroy(i);
}

/** Test function for inventory_destroy setting */
void test1_inventory_destroy(){
  Inventory *i;
  i=inventory_create();
  PRINT_TEST_RESULT(inventory_destroy(i)==OK);
}

/** Test function for inventory_destroy setting */
void test2_inventory_destroy(){
  Inventory *i=NULL;
  PRINT_TEST_RESULT(inventory_destroy(i)==ERROR);
}

/** Test function for inventory_print setting */
void test1_inventory_print(){
  Inventory *i;
  i=inventory_create();
    inventory_set_max_objects(i, 1);
    inventory_add_object(i,5);
  PRINT_TEST_RESULT(inventory_print(i)==OK);
  inventory_destroy(i);
}

/** Test function for inventory_print setting */
void test2_inventory_print(){
  Inventory *i=NULL;
  PRINT_TEST_RESULT(inventory_print(i)==ERROR);
}

/** Test function for inventory_get_objects setting */
void test1_inventory_get_objects(){
  Inventory *i;
  i=inventory_create();
  PRINT_TEST_RESULT(inventory_get_objects(i)!=NULL);
  inventory_destroy(i);
}

/** Test function for inventory_get_objects setting */
void test2_inventory_get_objects(){
  Inventory *i=NULL;
  PRINT_TEST_RESULT(inventory_get_objects(i)==NULL);
  inventory_destroy(i);
}

/** Test function for inventory__is_full setting */
void test1_inventory_is_full(){
  Inventory *i;
  i=inventory_create();
  inventory_set_max_objects(i, 1);
  inventory_add_object(i, 5);
  PRINT_TEST_RESULT(inventory_is_full(i)==TRUE);
  inventory_destroy(i);
}

/** Test function for inventory__is_full setting */
void test2_inventory_is_full(){
  Inventory *i;
  i=inventory_create();
  inventory_set_max_objects(i, 2);
  inventory_add_object(i, 5);
  PRINT_TEST_RESULT(inventory_is_full(i)==FALSE);
  inventory_destroy(i);
}

/** Test function for inventory__is_full setting */
void test3_inventory_is_full(){
  Inventory *i;
  i=inventory_create();
  PRINT_TEST_RESULT(inventory_is_full(i)==TRUE);
  inventory_destroy(i);
}

/** Test function for inventory__is_full setting */
void test4_inventory_is_full(){
  Inventory *i=NULL;
  PRINT_TEST_RESULT(inventory_is_full(i)==TRUE);
}

/** Test function for inventory__is_empty setting */
void test1_inventory_is_empty(){
  Inventory *i;
  i=inventory_create();
  inventory_set_max_objects(i, 1);
  PRINT_TEST_RESULT(inventory_is_empty(i)==TRUE);
  inventory_destroy(i);
} 

/** Test function for inventory__is_empty setting */
void test2_inventory_is_empty(){
  Inventory *i;
  i=inventory_create();
  PRINT_TEST_RESULT(inventory_is_empty(i)==FALSE);
  inventory_destroy(i);
}

/** Test function for inventory__is_empty setting */
void test3_inventory_is_empty(){
  Inventory *i=NULL;
  PRINT_TEST_RESULT(inventory_is_empty(i)==FALSE);
}








