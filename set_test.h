/** 
 * @brief It declares the tests for the space module
 * 
 * @file space_test.h
 * @author Profesores Pprog
 * @version 2.0 
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#ifndef SET_TEST_H
#define SET_TEST_H

#define MAX_TESTS 22 /*!<Indicates the maximum number of possible tests*/
/**
 * @test Test set creation
 * @pre Non
 * @post 
 */
void test1_set_create();

void test2_set_create();

void test1_set_destroy();

void test2_set_destroy();

void test1_set_add();

void test2_set_add();

void test1_set_return_id();

void test2_set_return_id();

void test3_set_return_id();

void test1_set_del();

void test2_set_del();

void test3_set_del();

void test4_set_del();

void test1_set_check_id();

void test2_set_check_id();

void test3_set_check_id();

void test1_set_print();

void test2_set_print();

void test3_set_print();

void test1_get_n_ids();

void test2_get_n_ids();

#endif