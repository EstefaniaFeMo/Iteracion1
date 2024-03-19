/**
 * @brief It defines the inventory interface
 *
 * @file inventory.h
 * @author Estefanía Fenoy Montes
 * @version 3.5
 * @date 18-03-2024
 * @copyright GNU Public License
 */

#ifndef INVENTORY_H
#define IVENTORY_H

#include "types.h"
#include "set.h"

typedef struct _Inventory Inventory;

/**
 * @brief It creates a new inventory, allocating memory and initializing its members
 * @author Estefanía Fenoy Montes
 *
 * @return a new inventory, initialized
 */
Inventory *inventory_create();

/**
 * @brief It destroys an inventory, freeing the allocated memory
 * @author Estefanía Fenoy Montes
 *
 * @param inventory a pointer to the inventory that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status inventory_destroy(Inventory *inventory);

/**
 * @brief It gets the maximum number of ojects available in the inventory
 * @author Estefanía Fenoy Montes
 *
 * @param inventory a pointer to the inventory that stores all its information
 * @return an integer with the maximum number of objects
 */
int inventory_get_max_objects(Inventory * inventory);

/**
 * @brief It sets the maxium number of ojects available in the inventory
 * @author Estefanía Fenoy Montes
 *
 * @param inventory a pointer to the inventory that stores all its information
 * @param max an integer with the maximum that wants to be set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status inventory_set_max_objects(Inventory * inventory, int max);

/**
 * @brief It sets the ID of an object in the set of objects of the inventory
 * @author Estefanía Fenoy Montes
 *
 * @param inventory a pointer to the inventory that stores all its information
 * @param object an identifier of the object that will be added in the set of objects of inventory
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status inventory_add_object(Inventory *inventory, Id object);

/**
 * @brief It deletes the ID of an object in the set of objects of the inventory
 * @author Estefanía Fenoy Montes
 *
 * @param inventory a pointer to the inventory that stores all its information
 * @param object an identifier of the object that will be deleted in the set of objects of inventory
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status inventory_del_object(Inventory *inventory, Id object);

/**
 * @brief It obtains the set of objets in the given inventory
 * @author Estefanía Fenoy Montes
 *
 * @param inventory a pointer to the inventory that stores all its information
 * @return inventory->objs, the set of objects in the inventory
 */
Set *inventory_get_objects(Inventory *inventory);

/**
 * @brief It gets the ID of a particular object which is in the set of objects of the given inventory by its position
 * @author Estefanía Fenoy Montes
 *
 * @param inventory a pointer to the inventory that stores all its information
 * @param position an int that indicates the position in the array of objects of the given inventory
 * @return the Id of an object which is in the given inventory
 */
Id inventory_get_object_id(Inventory *inventory, int position);

/**
 * @brief It checks if the given object is in the given inventory
 * @author Estefanía Fenoy Montes
 *
 * @param inventory a pointer to the inventory that stores all its information
 * @param object the identifier of the object that will be checked if it is in the inventory
 * @return TRUE, if the given object is in the inventory, FALSE in case of error or if the object is not 
 * in the given inventory
 */
Bool inventory_check_object(Inventory * inventory, Id object);

/**
 * @brief It checks if the given inventory is full
 * @author Estefanía Fenoy Montes
 *
 * @param inventory a pointer to the inventory that stores all its information
 * @return TRUE, if the given inventory is full or in case of error, FALSE in case the inventory in not full
 */
Bool inventory_is_full(Inventory * inventory);

/**
 * @brief It checks if the given inventory is empty
 * @author Estefanía Fenoy Montes
 *
 * @param inventory a pointer to the inventory that stores all its information
 * @return FALSE, if the given inventory is not empty or in case of error, OK in case the inventory empty
 */
Bool inventory_is_empty(Inventory * inventory);

/**
 * @brief It prints the inventory information
 * @author Profesores PPROG
 *
 * This fucntion shows the maximum number of objects available in the inventory, and the IDs of the ojects contained on it.
 * @param inventory a pointer to the inventory that stores all its information
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status inventory_print(Inventory *inventory);






#endif