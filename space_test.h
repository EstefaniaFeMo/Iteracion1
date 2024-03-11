/** 
 * @brief It declares the tests for the space module
 * 
 * @file space_test.h
 * @author Profesores Pprog, Estefanía Fenoy Montes
 * @version 2.0 
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#ifndef SPACE_TEST_H
#define SPACE_TEST_H

#define MAX_TESTS 47 /*!<Indicates the maximum number of possible tests*/
/**
 * @test Test space creation
 * @pre Space ID 
 * @post Non NULL pointer to space 
 */
void test1_space_create();

/**
 * @test Test space creation
 * @pre Space ID 
 * @post Space_ID == Supplied Space Id
 */
void test2_space_create();

/**
 * @test Test function for space_name setting
 * @pre String with space name
 * @post Ouput==OK 
 */
void test1_space_set_name();

/**
 * @test Test function for space_name setting
 * @pre pointer to space = NULL 
 * @post Output==ERROR
 */
void test2_space_set_name();

/**
 * @test Test function for space_name setting
 * @pre pointer to space_name = NULL (point to space = NON NULL) 
 * @post Output==ERROR
 */
void test3_space_set_name();
void test1_space_set_north();
void test2_space_set_north();
void test3_space_set_north();
void test4_space_set_north();
void test1_space_set_south();
void test2_space_set_south();
void test3_space_set_south();
void test4_space_set_south();
void test1_space_set_east();
void test2_space_set_east();
void test3_space_set_east();
void test4_space_set_east();
void test1_space_set_west();
void test2_space_set_west();
void test3_space_set_west();
void test4_space_set_west();
void test1_space_set_object();
void test2_space_set_object();
void test3_space_set_object();
void test1_space_get_name();
void test2_space_get_name();
void test1_space_get_north();
void test2_space_get_north();
void test1_space_get_south();
void test2_space_get_south();
void test1_space_get_east();
void test2_space_get_east();
void test1_space_get_west();
void test2_space_get_west();
void test1_space_check_object();
void test2_space_check_object();
void test3_space_check_object();
void test1_space_get_object_id();
void test2_space_get_object_id();
void test1_space_del_object();
void test2_space_del_object();
void test3_space_del_object();
void test4_space_del_object();
void test1_space_set_character();
void test2_space_set_character();
void test3_space_set_character();
void test1_space_get_character();
void test2_space_get_character();
void test1_space_destroy();
void test2_space_destroy();
void test1_space_print();
void test2_space_print();
void test1_space_get_objects();
void test2_space_get_objects();

#endif
