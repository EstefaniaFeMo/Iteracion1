/**
 * @brief It tests character module
 *
 * @file character_test.c
 * @author Caremn Gómez Escobar
 * @version 3.0
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#include "character.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "character_test.h"
#include "test.h"

#define MAX_TESTS 28 /*!<Macro with the maximum number of tests*/

/**
 * @brief Main function for CHARACTER unit tests.
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
    printf("Running all test for module Character:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

  if (all || test == 1) test1_character_create();
  if (all || test == 2) test2_character_create();
  if (all || test == 3) test1_character_set_name();
  if (all || test == 4) test2_character_set_name();
  if (all || test == 5) test3_character_set_name();
  if (all || test == 6) test1_character_set_health();
  if (all || test == 7) test2_character_set_health();
  if (all || test == 8) test3_character_set_health();
  if (all || test == 9) test1_character_set_friendly();
  if (all || test == 10) test2_character_set_friendly();
  if (all || test == 11) test3_character_set_friendly();
  if (all || test == 12) test1_character_set_message();
  if (all || test == 13) test2_character_set_message();
  if (all || test == 14) test3_character_set_message();
  if (all || test == 15) test1_character_print_message();
  if (all || test == 16) test2_character_print_message();
  if (all || test == 17) test1_character_print();
  if (all || test == 18) test2_character_print();
  if (all || test == 19) test3_character_print();
  if (all || test == 20) test1_character_get_name();
  if (all || test == 21) test2_character_get_name();
  if (all || test == 22) test1_character_get_health();
  if (all || test == 23) test2_character_get_health();
  if (all || test == 24) test1_character_get_friendly();
  if (all || test == 25) test2_character_get_friendly();
  if (all || test == 26) test1_character_get_message();
  if (all || test == 27) test2_character_get_message();
  if (all || test == 28) test1_character_get_id();
  if (all || test == 29) test2_character_get_id();
  if (all || test == 30) test2_character_destroy();
  if (all || test == 31) test2_character_destroy();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

/** Test function for character_create setting */
void test1_character_create(){
  int result;
  Character *character;
  character = character_create(2);
  result = character != NULL;
  PRINT_TEST_RESULT(result);
  character_destroy(character);
}

/** Test function for character_create setting */
void test2_character_create(){
  Character *character;
  character = character_create(1);
  PRINT_TEST_RESULT(character_get_id(character) == 1);
  character_destroy(character);
}

/** Test function for character_get_id setting */
void test1_character_get_id(){
  Character *character;
  character = character_create(25);
  PRINT_TEST_RESULT(character_get_id(character) == 25);
  character_destroy(character);
}

/** Test function for character_get_id setting */
void test2_character_get_id(){
  Character *character = NULL;
  PRINT_TEST_RESULT(character_get_id(character) == NO_ID);
}

/** Test function for character_set_name setting */
void test1_character_set_name(){
  Character *character;
  character = character_create(5);
  PRINT_TEST_RESULT(character_set_name(character, "hola") == OK);
  character_destroy(character);
}

/** Test function for character_set_name setting */
void test2_character_set_name(){
  Character *character = NULL;
  PRINT_TEST_RESULT(character_set_name(character, "hola") == ERROR);
}

/** Test function for character_set_name setting */
void test3_character_set_name() {
  Character *character;
  character = character_create(5);
  PRINT_TEST_RESULT(character_set_name(character, NULL) == ERROR);
  character_destroy(character);
}

/** Test function for character_get_name setting */
void test1_character_get_name() {
  Character *character;
  character = character_create(1);
  character_set_name(character, "adios");
  PRINT_TEST_RESULT(strcmp(character_get_name(character), "adios") == 0);
  character_destroy(character);
}

/** Test function for character_get_name setting */
void test2_character_get_name(){
  Character *character = NULL;
  PRINT_TEST_RESULT(character_get_name(character) == NULL);
}

/** Test function for character_set_health setting */
void test1_character_set_health(){
  Character *character;
  character = character_create(1);
  PRINT_TEST_RESULT(character_set_health(character, 4) == OK);
  character_destroy(character);
}

/** Test function for character_set_health setting */
void test2_character_set_health(){
  Character *character=NULL;
  PRINT_TEST_RESULT(character_set_health(character, 4) == ERROR);
}

/** Test function for character_set_health setting */
void test3_character_set_health(){
  Character *character;
  character = character_create(1);
  PRINT_TEST_RESULT(character_set_health(character, -1) == ERROR);
  character_destroy(character);
}

/** Test function for character_get_health setting */
void test1_character_get_health(){
  Character *character;
  character = character_create(2);
  character_set_health(character, 4);
  PRINT_TEST_RESULT(character_get_health(character) == 4);
  character_destroy(character);
}

/** Test function for character_get_health setting */
void test2_character_get_health(){
  Character *character=NULL;
  PRINT_TEST_RESULT(character_get_health(character) == -1);
}

/** Test function for character_set_friendly setting */
void test1_character_set_friendly(){
  Character *character;
  character = character_create(1);
  PRINT_TEST_RESULT(character_set_friendly(character, TRUE) == OK);
  character_destroy(character);
}

/** Test function for character_set_friendly setting */
void test2_character_set_friendly(){
  Character *character=NULL;
  PRINT_TEST_RESULT(character_set_friendly(character, TRUE) == ERROR);
}

/** Test function for character_set_friendly setting */
void test3_character_set_friendly(){
  Character *character;
  character = character_create(1);
  PRINT_TEST_RESULT(character_set_friendly(character, FALSE) == OK);
  character_destroy(character);
}

/** Test function for character_get_friendly setting */
void test1_character_get_friendly(){
  Character *character;
  character = character_create(2);
  character_set_friendly(character, TRUE);
  PRINT_TEST_RESULT(character_get_friendly(character) == TRUE);
  character_destroy(character);
}

/** Test function for character_get_friendly setting */
void test2_character_get_friendly(){
  Character *character=NULL;
  PRINT_TEST_RESULT(character_get_friendly(character) == FALSE);
}

/** Test function for character_set_message setting */
void test1_character_set_message(){
  Character *character;
  character = character_create(1);
  PRINT_TEST_RESULT(character_set_message(character, "hola") == OK);
  character_destroy(character);
}

/** Test function for character_set_message setting */
void test2_character_set_message(){
  Character *character = NULL;
  PRINT_TEST_RESULT(character_set_message(character, "hola") == ERROR);
}

/** Test function for character_set_message setting */
void test3_character_set_message() {
  Character *character;
  character = character_create(1);
  PRINT_TEST_RESULT(character_set_message(character, NULL) == ERROR);
  character_destroy(character);
}

/** Test function for character_get_message setting */
void test1_character_get_message() {
  Character *character;
  character = character_create(1);
  character_set_message(character, "adios");
  PRINT_TEST_RESULT(strcmp(character_get_message(character), "adios") == 0);
  character_destroy(character);
}

/** Test function for character_get_message setting */
void test2_character_get_message(){
  Character *character = NULL;
  PRINT_TEST_RESULT(character_get_message(character) == NULL);
}

/** Test function for character_print_message setting */
void test1_character_print_message(){
  Character *character;
  character = character_create(1);
  character_set_message(character, "adios");
  PRINT_TEST_RESULT(character_print_message(character) == OK);
  character_destroy(character);
}

/** Test function for character_print_message setting */
void test2_character_print_message(){
  Character *character = NULL;
  PRINT_TEST_RESULT(character_print_message(character) == ERROR);
}

/** Test function for character_print setting */
void test1_character_print(){
  Character *character;
  character = character_create(1);
  character_set_friendly(character, FALSE);
  PRINT_TEST_RESULT(character_print(character) == OK);
  character_destroy(character);
}

/** Test function for character_print setting */
void test2_character_print(){
  Character *character;
  character = character_create(1);
  character_set_friendly(character, TRUE);
  PRINT_TEST_RESULT(character_print(character) == OK);
  character_destroy(character);
}

/** Test function for character_print setting */
void test3_character_print(){
  Character *character = NULL;
  PRINT_TEST_RESULT(character_print(character) == ERROR);
}

/** Test function for character_destroy setting */
void test1_character_destroy(){
  Character *character;
  character=character_create(5);
  PRINT_TEST_RESULT(character_destroy(character)==OK);
}

/** Test function for character_destroy setting */
void test2_character_destroy(){
  Character *character=NULL;
  PRINT_TEST_RESULT(character_destroy(character)==ERROR);
}

