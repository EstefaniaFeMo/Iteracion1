/**
 * @brief It defines the object interface, allowing the manage of objects
 *
 * @file object.h
 * @author Estefanía Fenoy Montes
 * @version 3.5
 * @date 08-02-2024
 * @copyright GNU Public License
 */
#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

/**
 * @brief Object
 *
 * This struct contains all the information of an object.
 */
typedef struct _Object Object;

/**
 * @brief It creates a new object, allocating memory and initializing its variables
 * @author Estefanía Fenoy Montes
 *
 * @param id the identification number for the new object which is going to be created
 * @return a new object initialized
 */
Object *object_create(Id id);

/**
 * @brief It destroys an object and releases the allocated memory
 * @author Estefanía Fenoy Montes
 *
 * @param object a pointer to the object that will be destroyed
 * @return OK, if everything goes well or ERROR in case there was some mistake
 */
Status object_destroy(Object *object);

/**
 * @brief It gets the id of an object
 * @author Estefanía Fenoy Montes
 *
 * @param object a pointer to the object in order to access to the ID
 * @return the ID of object
 */
Id object_get_id(Object *object);

/**
 * @brief It sets the name of an object
 * @author Estefanía Fenoy Montes
 *
 * @param object a pointer to the object
 * @param name a string with the name that will be set
 * @return OK, if everything goes well or ERROR in case there was some mistake
 */
Status object_set_name(Object *object, char *name);

/**
 * @brief It gets the name of an object
 * @author Estefanía Fenoy Montes
 *
 * @param object a pointer to the object in order to access to the name
 * @return  a string with the name of the object
 */
const char *object_get_name(Object *object);

/**
 * @brief It prints the object ID and name
 * @author Estefanía Fenoy Montes
 *
 * This function shows the information of object: id and name of the space.
 * @param object a pointer to the object
 * @return OK, if everything goes well or ERROR in case there was some mistake
 */
Status object_print(Object *object);

#endif