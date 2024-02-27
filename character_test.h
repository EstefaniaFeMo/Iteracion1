/** 
 * @brief It declares the tests for the space module
 * 
 * @file space_test.h
 * @author Profesores Pprog
 * @version 2.0 
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#ifndef CHARACTER_TEST_H
#define CHARACTER_TEST_H

/**
 * @test Test function for character_create
 * @pre Character ID 
 * @post Non NULL pointer to character 
 */
void test1_character_create();

/**
 * @test Test function for character_create
 * @pre Character ID 
 * @post Character_ID == Supplied Character Id
 */
void test2_character_create();

/**
 * @test Test function for character_get_id
 * @pre pointer to character and character id
 * @post Character_ID 
 */
void test1_character_get_id();

/**
 * @test Test function for character_get_id
 * @pre pointer to character= NULL 
 * @post NO_ID
 */
void test2_character_get_id();

/**
 * @test Test function for character_set_name setting
 * @pre String with space name
 * @post Ouput==OK 
 */
void test1_character_set_name();

/**
 * @test Test function for character_set_name setting
 * @pre pointer to character= NULL
 * @post Ouput==ERROR
 */
void test2_character_set_name();

/**
 * @test Test function for character_set_name setting
 * @pre pointer to space_name =NULL (point to character= NON NULL)
 * @post Ouput==ERROR
 */
void test3_character_set_name();

/**
 * @test Test function for character_get_name setting
 * @pre pointer to character
 * @post Ouput==0
 */
void test1_character_get_name();

/**
 * @test Test function for character_get_name setting
 * @pre pointer to character= NULL
 * @post Ouput==NULL
 */
void test2_character_get_name();

/**
 * @test Test function for character_set_health setting
 * @pre pointer to character and his points of life
 * @post Ouput==OK
 */
void test1_character_set_health();

/**
 * @test Test function for character_set_health setting
 * @pre pointer to character= NULL
 * @post Ouput==ERROR
 */
void test2_character_set_health();

/**
 * @test Test function for character_set_health setting
 * @pre invalid value for points of life (point to character= NON NULL)
 * @post Ouput==ERROR
 */
void test3_character_set_health();

/**
 * @test Test function for character_get_health  setting
 * @pre pointer to character
 * @post Ouput==4
 */
void test1_character_get_health();

/**
 * @test Test function for character_get_health setting
 * @pre pointer to character= NULL
 * @post Ouput==ERROR
 */
void test2_character_get_health();

/**
 * @test Test function for character_set_friendly setting
 * @pre pointer to character and boolean value= TRUE
 * @post Ouput==OK
 */
void test1_character_set_friendly();

/**
 * @test Test function for  character_set_friendly setting
 * @pre pointer to character= NULL
 * @post Ouput==ERROR
 */
void test2_character_set_friendly();

/**
 * @test Test function for character_set_friendly setting
 * @pre pointer to character_friendly =NULL (point to character= NON NULL)
 * @post Ouput==ERROR
 */
void test3_character_set_friendly();

/**
 * @test Test function for character_get_friendly setting
 * @pre pointer to character
 * @post Ouput==TRUE
 */
void test1_character_get_friendly();

/**
 * @test Test function for character_get_friendly setting
 * @pre pointer to character= NULL
 * @post Ouput==ERROR
 */
void test2_character_get_friendly();

/**
 * @test Test function for character_set_message setting
 * @pre pointer to character
 * @post Ouput==OK
 */
void test1_character_set_message();

/**
 * @test Test function for character_set_message setting
 * @pre pointer to character= NULL
 * @post Ouput==ERROR
 */
void test2_character_set_message();

/**
 * @test Test function for character_set_message setting
 * @pre pointer to character_message =NULL (point to character= NON NULL)
 * @post Ouput==ERROR
 */
void test3_character_set_message();
/**
 * @test Test function for character_get_message setting
 * @pre pointer to character
 * @post Ouput==OK
 */
void test1_character_get_message();

/**
 * @test Test function for character_get_message setting
 * @pre pointer to character= NULL
 * @post Ouput==ERROR
 */
void test2_character_get_message();

/**
 * @test Test function for character_print_message setting
 * @pre pointer to character
 * @post Ouput==OK
 */
void test1_character_print_message();

/**
 * @test Test function for character_print_message setting
 * @pre pointer to character= NULL
 * @post Ouput==ERROR
 */
void test2_character_print_message();

/**
 * @test Test function for character_print setting
 * @pre pointer to character
 * @post Ouput==OK
 */
void test1_character_print();

/**
 * @test Test function for character_print setting
 * @pre pointer to character= NULL
 * @post Ouput==ERROR
 */
void test2_character_print();

#endif