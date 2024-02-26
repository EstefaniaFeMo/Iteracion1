/**
 * @brief It defines the space interface
 *
 * @file space.h
 * @author Profesores PPROG, Estefanía Fenoy Montes
 * @version 3.5
 * @date 12-02-2024
 * @copyright GNU Public License
 */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"
#include "set.h"

typedef struct _Space Space;

/**
 * @brief It creates a new space, allocating memory and initializing its members
 * @author Profesores PPROG
 *
 * @param id the identification number for the new space
 * @return a new space, initialized
 */
Space *space_create(Id id);

/**
 * @brief It destroys a space, freeing the allocated memory
 * @author Profesores PPROG
 *
 * @param space a pointer to the space that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_destroy(Space *space);

/**
 * @brief It gets the id of a space
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @return the id of space
 */
Id space_get_id(Space *space);

/**
 * @brief It sets the name of a space
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @param name a string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_name(Space *space, char *name);

/**
 * @brief It gets the name of a space
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @return  a string with the name of the space
 */
const char *space_get_name(Space *space);

/**
 * @brief It sets the id of the space located at the north
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @param id the id number of the space located at the north
 * @return OK, if everything goes well or ERROR if there was some mistake
 */

Status space_set_north(Space *space, Id id);

/**
 * @brief It gets the id of the space located at the north
 * @author Profesores PPROG, Estefanía Fenoy Montes
 *
 * @param space a pointer to the space
 * @return the id number of the space located at the north
 */
Id space_get_north(Space *space);

/**
 * @brief It sets the id of the space located at the south
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @param id the id number of the space located at the south
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_south(Space *space, Id id);

/**
 * @brief It gets the id of the space located at the south
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @return the id number of the space located at the south
 */
Id space_get_south(Space *space);

/**
 * @brief It sets the id of the space located at the east
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @param id the id number of the space located at the east
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_east(Space *space, Id id);

/**
 * @brief It gets the id of the space located at the east
 * @author Profesores PPROG
 * @param space a pointer to the space
 * @param id the id number of the space located at the west
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_west(Space *space, Id id);

/**
 * @brief It gets the id of the space located at the west
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @return the id number of the space located at the west
 */
Id space_get_west(Space *space);

/**
 * @brief It sets the ID of an object in the set of objects of space
 * @author Profesores PPROG, Estefanía Fenoy Montes
 *
 * @param space a pointer to the space
 * @param object an identifier of the object that will be added in the set of objects of space
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_object(Space *space, Id object);

/**
 * @brief It gets the array of ids of the objects in the given space
 * @author Profesores PPROG, Estefanía Fenoy Montes
 *
 * @param space a pointer to the space
 * @return the array of IDs of the object which is in the space
 */
Id * space_get_objects(Space *space);
/**
 * @brief It gets the ID of the character in the given space
 * @author Estefanía Fenoy Montes
 *
 * @param space a pointer to the space
 * @return the ID of the character which is in the space
 */
Id space_get_character(Space * space);

/**
 * @brief It sets the ID of a character in the given space
 * @author Estefanía Fenoy Montes
 *
 * @param space a pointer to the space
 * @param character an identifier of the character that will be added in the space
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_character(Space *space, Id character);


/**
 * @brief It prints the space information
 * @author Profesores PPROG
 *
 * This fucntion shows the id and name of the space, the spaces that surrounds it and wheter it has an object or not.
 * @param space a pointer to the space
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_print(Space *space);

#endif
