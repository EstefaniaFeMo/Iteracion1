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

/**
 * @test Test function for space_set_north setting
 * @pre id of the space located at the north = 4 (point to space = NON NULL) 
 * @post Output==OK
 */
void test1_space_set_north();

/**
 * @test Test function for space_set_north setting
 * @pre pointer to space = NULL 
 * @post Output==ERROR
 */
void test2_space_set_north();

/**
 * @test Test function for space_set_south setting
 * @pre id of the space located at the south = 4 (point to space = NON NULL) 
 * @post Output==OK
 */
void test1_space_set_south();

/**
 * @test Test function for space_set_south setting
 * @pre pointer to space = NULL 
 * @post Output==ERROR
 */
void test2_space_set_south();

/**
 * @test Test function for space_set_east setting
 * @pre id of the space located at the east = 4 (point to space = NON NULL) 
 * @post Output==OK
 */
void test1_space_set_east();

/**
 * @test Test function for space_set_east setting
 * @pre pointer to space = NULL 
 * @post Output==ERROR
 */
void test2_space_set_east();

/**
 * @test Test function for space_set_west setting
 * @pre id of the space located at the west = 4 (point to space = NON NULL) 
 * @post Output==OK
 */
void test1_space_set_west();


/**
 * @test Test function for space_set_west setting
 * @pre pointer to space = NULL 
 * @post Output==ERROR
 */
void test2_space_set_west();

void test1_space_set_object();
void test2_space_set_object();
void test3_space_set_object();

/**
 * @test Test function for space_get_name setting
 * @pre string with a name of the space (point to space = NON NULL)
 * @post name of the space == given name
 */
void test1_space_get_name();
/**
 * @test Test function for space_get_name setting
 * @pre pointer to space = NULL
 * @post Output==NULL
 */
void test2_space_get_name();

/**
 * @test Test function for space_get_north setting
 * @pre identifier of the space located at the north (point to space = NON NULL)
 * @post the given id of the space in the nort == 4
 */
void test1_space_get_north();

/**
 * @test Test function for space_get_north setting
 * @pre pointer to space = NULL
 * @post Output==NO_ID
 */
void test2_space_get_north();

/**
 * @test Test function for space_get_south setting
 * @pre identifier of the space located at the south (point to space = NON NULL)
 * @post the given id of the space in the south == 2
 */
void test1_space_get_south();

/**
 * @test Test function for space_get_south setting
 * @pre pointer to space = NULL
 * @post Output==NO_ID
 */
void test2_space_get_south();

/**
 * @test Test function for space_get_east setting
 * @pre identifier of the space located at the east (point to space = NON NULL)
 * @post the given id of the space in the east == 1
 */
void test1_space_get_east();

/**
 * @test Test function for space_get_east setting
 * @pre pointer to space = NULL
 * @post Output==NO_ID
 */
void test2_space_get_east();

/**
 * @test Test function for space_get_west setting
 * @pre identifier of the space located at the west (point to space = NON NULL)
 * @post the given id of the space in the west == 6
 */
void test1_space_get_west();

/**
 * @test Test function for space_get_west setting
 * @pre pointer to space = NULL
 * @post Output==NO_ID
 */
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
