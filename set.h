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

/**
 * @brief It adds in the array of IDs in the last position of it the given ID 
 * when the parameters are appropiate and if the capacity of the array is not full.
 * @author Estefanía Fenoy Montes
 *
 * @param set a pointer to the set which contains the array with Ids and in which the given ID will be added.
 * @param id and ID with the identifier that will be added into the array.
 * @return OK, if everything goes well or ERROR in case there was some mistake
 */
Status set_add(Set *set, Id id);

/**
 * @brief It deletes in the array of IDs  the given ID when the parameters are appropiate and if ID is part of the array.
 * @author Estefanía Fenoy Montes
 *
 * @param set a pointer to the set which contains the array with Ids and in which the given ID will be deleated.
 * @param id and ID with the identifier that will be desleated of the array.
 * @return OK, if everything goes well or ERROR in case there was some mistake
 */
Status set_del(Set *set, Id id);

/**
 * @brief It prints all the set information
 * @author Estefanía Fenoy Montes
 *
 * This fucntion shows in order the IDs of the array and the number of these.
 * @param set a pointer to the set that will be printed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status set_print(Set *set);

/**
 * @brief It checks if the given Id is part of the array of IDs of the set
 * @author Estefanía Fenoy Montes
 *
 * @param set a pointer to the set that cantains the array of IDs 
 * @param id an identifier with the ID that will be checked if it is in the array
 * @return TRUE, if the ID is part of the set or FALSE if not or if there had been
 */
Bool set_check_id(Set * set, Id id);

/**
 * @brief It obtains the array of IDs in the set
 * @author Estefanía Fenoy Montes
 *
 * @param set a pointer to the set that cantains the array of IDs 
 * @return the array of IDs of the set
 */
Id * set_get_ids(Set *set);


#endif