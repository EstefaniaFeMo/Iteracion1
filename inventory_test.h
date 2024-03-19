/** 
 * @brief It declares the tests for the inventory module
 * 
 * @file inventory_test.h
 * @author Estefanía Fenoy Montes
 * @version 2.0 
 * @date 19-03-2021
 * @copyright GNU Public License
 */

#ifndef INVENTORY_TEST_H
#define INVENTORY_TEST_H

#define MAX_TESTS 32 /*!<Indicates the maximum number of possible tests*/

/**
 * @test Test inventory creation
 * @pre a pointer to inventory
 * @post Non NULL pointer to inventory
 */
void test1_inventory_create();

/**
 * @test Test inventory creation
 * @pre a pointer to inventory
 * @post inventory_max_objects == initial maximum value of objects == 0
 */
void test2_inventory_create();

/**
 * @test Test function for inventory_set_max_objects setting
 * @pre Pointer to inventory = NON NULL
 * @post Ouput==OK 
 */
void test1_inventory_set_max_objects();

/**
 * @test Test function for inventory_set_max_objects setting
 * @pre pointer to inventory = NULL 
 * @post Output==ERROR
 */
void test2_inventory_set_max_objects();

/**
 * @test Test function for inventory_get_max_objects setting
 * @pre integer with the maximum objetcs in the inventory(point to inventory = NON NULL)
 * @post maximum number of objects in the inventory == given maximum
 */
void test1_inventory_get_max_objects();

/**
 * @test Test function for inventory_get_max_objects setting
 * @pre pointer to inventory = NULL 
 * @post maximum number of objects in the inventory == -1 (indicating ERROR)
 */
void test2_inventory_get_max_objects();

/**
 * @test Test function for inventory_check_object setting
 * @pre Pointer to inventory = NON NULL
 * @post Output==FALSE
 */
void test1_inventory_check_object();

/**
 * @test Test function for inventory_check_object setting
 * @pre a maximum number of objects in the inventory, the identifier of a nex object that will be added(point to inventory = NON NULL)
 * @post Output==TRUE
 */
void test2_inventory_check_object();

/**
 * @test Test function for inventory_check_object setting
 * @pre pointer to inventory = NULL
 * @post Output==FALSE
 */
void test3_inventory_check_object();

/**
 * @test Test function for inventory_get_object_id setting
 * @pre a maximum number of objects in the inventory, the identifier of a new object that will be added(point to inventory = NON NULL)
 * @post the Id of the object in the first position == given Id
 */
void test1_inventory_get_object_id() ;

/**
 * @test Test function for inventory_get_object_id setting
 * @pre pointer to inventory = NULL
 * @post Output == NO_ID
 */
void test2_inventory_get_object_id() ;


/**
 * @test Test function for inventory_add_object setting
 * @pre a maximum number of objects in the inventory, id of an object = 4 (point to inventory = NON NULL) 
 * @post Output==OK
 */
void test1_inventory_add_object();

/**
 * @test Test function for inventory_add_object setting
 * @pre pointer to inventory = NULL
 * @post Output==ERROR
 */
void test2_inventory_add_object();

/**
 * @test Test function for inventory_add_object setting
 * @pre the object has NO_ID (point to inventory = NON NULL)
 * @post Output==ERROR
 */
void test3_inventory_add_object();

/**
 * @test Test function for inventory_del_object setting
 * @pre identifier of an object which we want to delete and that it is in the inventory (point to inventory = NON NULL)
 * @post Output == OK
 */
void test1_inventory_del_object();

/**
 * @test Test function for inventory_del_object setting
 * @pre identifier of an object which we want to delete but it is not in the inventory(point to inventory = NON NULL)
 * @post Output == ERROR
 */
void test2_inventory_del_object();

/**
 * @test Test function for inventory_del_object setting
 * @pre pointer to inventory = NULL
 * @post Output == ERROR
 */
void test3_inventory_del_object();

/**
 * @test Test function for inventory_del_object setting
 * @pre object has NO_ID (point to inventory = NON NULL)
 * @post Output == ERROR
 */
void test4_inventory_del_object();

/**
 * @test Test function for inventory_destroy setting
 * @pre point to inventory = NON NULL
 * @post Output == OK
 */
void test1_inventory_destroy();

/**
 * @test Test function for inventory_destroy setting
 * @pre pointer to inventory NULL
 * @post Output == ERROR
 */
void test2_inventory_destroy();

/**
 * @test Test function for inventory_print setting
 * @pre a maximum number of objects in the inventory, the identifier of a new object that will be added (point to inventory = NON NULL)
 * @post Output == OK
 */
void test1_inventory_print();

/**
 * @test Test function for inventory_print setting
 * @pre pointer to inventory NULL
 * @post Output == ERROR
 */
void test2_inventory_print();

/**
 * @test Test function for inventory_get_object setting
 * @pre point to inventory = NON NULL
 * @post The set of object of the inventory != NULL
 */
void test1_inventory_get_objects();

/**
 * @test Test function for inventory_get_object setting
 * @pre pointer to inventory NULL
 * @post Output == NULL
 */
void test2_inventory_get_objects();

/**
 * @test Test function for inventory_is_full setting
 * @pre a maximum number of objects in the inventory (that is the same number of the objects that there will be in the inventory), the identifier of a new object that will be added (point to inventory = NON NULL)
 * @post Output == TRUE
 */
void test1_inventory_is_full();

/**
 * @test Test function for inventory_is_full setting
 * @pre a maximum number of objects in the inventory (that is more that the number of the objects that there will be in the inventory), the identifier of a new object that will be added (point to inventory = NON NULL)
 * @post Output == FALSE
 */
void test2_inventory_is_full();

/**
 * @test Test function for inventory_is_full setting
 * @pre point to inventory = NON NULL
 * @post Output == TRUE
 */
void test3_inventory_is_full();

/**
 * @test Test function for inventory_is_full setting
 * @pre point to inventory = NULL
 * @post Output == TRUE
 */
void test4_inventory_is_full();

/**
 * @test Test function for inventory_is_empty setting
 * @pre a maximum number of objects in the inventory(point to inventory = NON NULL)
 * @post Output == TRUE
 */
void test1_inventory_is_empty();

/**
 * @test Test function for inventory_is_empty setting
 * @pre Pointer to inventory = NON NULL
 * @post Output == FALSE
 */
void test2_inventory_is_empty();

/**
 * @test Test function for inventory_is_empty setting
 * @pre Pointer to inventory = NULL
 * @post Output == FALSE
 */
void test3_inventory_is_empty();

#endif