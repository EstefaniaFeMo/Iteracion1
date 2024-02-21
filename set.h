/**
 * @brief It defines the set interface, allowing the manage of sets
 *
 * @file set.h
 * @author Estefanía Fenoy Montes
 * @version 3.5
 * @date 20-02-2024
 * @copyright GNU Public License
 */
#ifndef SET_H
#define SET_H
/*Macro with the maximum value of ID's*/
#define MAX_NUM_IDS  8

#include "types.h"
/**
 * @brief Set
 *
 * This struct contains all the information of the set, the ID's of the members and the number of these.
 */
typedef struct _Set Set;


/**
 * @brief It creates a new set, allocating memory and initializing its variables
 * @author Estefanía Fenoy Montes
 *
 * @param ids an array with the identification number of each member in the set, which is going to be created
 * @return a new set initialized
 */
Set * set_create();

/**
 * @brief It destroys a set and releasing the allocated memory
 * @author Estefanía Fenoy Montes
 *
 * @param set a pointer to the set that will be destroyed
 * @return OK, if everything goes well or ERROR in case there was some mistake
 */
Status object_destroy(Set *set);




#endif