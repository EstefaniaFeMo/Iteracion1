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
 * @post a new pointer to set
 */
void test1_set_create();

/**
 * @test Test function for checking if set_create inizialites correctly the set id
 * @pre a pointer to set
 * @post Output== NO_ID
 */
void test2_set_create();

/**
 * @test Test function for set_destroy settings
 * @pre pointer to set
 * @post Output== OK
 */
void test1_set_destroy();

/**
 * @test Test function for set_destroy settings
 * @pre NULL pointer to set
 * @post Output== ERROR
 */
void test2_set_destroy();

/**
 * @test Test function for set_add settings
 * @pre NULL pointer to set
 * @post Output== ERROR
 */
void test1_set_add();

/**
 * @test Test function for set_add setting
 * @pre NULL pointer to set
 * @post Output== ERROR
 */
void test2_set_add();

/**
 * @test Test function for set_return_id setting
 * @pre NULL pointer to set
 * @post Output== ERROR
 */
void test1_set_return_id();

/**
 * @test Test function for set_return_id setting
 * @pre NULL pointer to set
 * @post Output== ERROR
 */
void test2_set_return_id();

/**
 * @test Test function for set_return_id setting
 * @pre NULL pointer to set
 * @post Output== ERROR
 */
void test3_set_return_id();

/**
 * @test Test function for set_del setting
 * @pre NULL pointer to set
 * @post Output== ERROR
 */
void test1_set_del();

/**
 * @test Test function for set_del setting
 * @pre NULL pointer to set
 * @post Output== ERROR
 */
void test2_set_del();

/**
 * @test Test function for set_del setting
 * @pre NULL pointer to set
 * @post Output== ERROR
 */
void test3_set_del();

/**
 * @test Test function for set_del setting
 * @pre NULL pointer to set
 * @post Output== ERROR
 */
void test4_set_del();

/**
 * @test Test function for set_check_id setting
 * @pre NULL pointer to set
 * @post Output== ERROR
 */
void test1_set_check_id();

/**
 * @test Test function for set_check_id setting
 * @pre NULL pointer to set
 * @post Output== ERROR
 */
void test2_set_check_id();

/**
 * @test Test function for set_check_id setting
 * @pre NULL pointer to set
 * @post Output== ERROR
 */
void test3_set_check_id();

/**
 * @test Test function for set_print setting
 * @pre NULL pointer to set
 * @post Output== ERROR
 */
void test1_set_print();

/**
 * @test Test function for set_print setting
 * @pre NULL pointer to set
 * @post Output== ERROR
 */
void test2_set_print();

/**
 * @test Test function for set_print setting
 * @pre NULL pointer to set
 * @post Output== ERROR
 */
void test3_set_print();

/**
 * @test Test function for set_get_n_ids setting
 * @pre NULL pointer to set
 * @post Output== ERROR
 */
void test1_set_get_n_ids();

/**
 * @test Test function for set_get_n_ids setting
 * @pre NULL pointer to set
 * @post Output== ERROR
 */
void test2_set_get_n_ids();

#endif