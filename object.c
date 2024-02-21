/**
 * @brief It defines the object interface, allowing the manage of objects
 *
 * @file object.c
 * @author Estefanía Fenoy Montes
 * @version 3.5
 * @date 08-02-2024
 * @copyright GNU Public License
 */
#include "object.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Object
 *
 * This struct contains all the information of an object.
 */
struct _Object
{
    Id id;                    /*!< Id of the object, it must be unique */
    char name[WORD_SIZE + 1]; /*!< Name of the object */
};

/** object_create allocates memory for a new object and initializes its members
 */
Object *object_create(Id id)
{
    Object *newObject = NULL;

    /* Error control */
    if (id == NO_ID)
        return NULL;

    newObject = (Object *)malloc(sizeof(Object));
    
    /* Error control of the reserve */
    if (newObject == NULL)
    {
        return NULL;
    }

    
    newObject->id = id;
    newObject->name[0] = '\0';

    return newObject;
}

/** object_destroy destroys the object that has been created
 */
Status object_destroy(Object *object)
{
    /* Error control */
    if (!object)
    {
        return ERROR;
    }

    free(object);

    object = NULL;

    return OK;
}

/** object_get_id obtains the ID of the object
 */
Id object_get_id(Object *object)
{
    /* Error control */
    if (!object)
    {
        return NO_ID;
    }
    return object->id;
}

/** object_set_name changes the name of the object to the name passed as an argument
 */
Status object_set_name(Object *object, char *name)
{
    /* Error control */
    if (!object || !name)
    {
        return ERROR;
    }
    /* Copy the name passed as a parameter to set it as the name of the object*/
    if (!strcpy(object->name, name))
    {
        /* Error control */
        return ERROR;
    }

    return OK;
}

/** object_get_id obtains the name of the object
 */
const char *object_get_name(Object *object)
{
    /* Error control */
    if (!object)
    {
        return NULL;
    }
    return object->name;
}

/** object_get_id prints the information of the object
 */
Status object_print(Object *object)
{
    /* Error Control */
    if (!object)
    {
        return ERROR;
    }


    fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, object->name);

    return OK;
}
