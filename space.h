/**
 * @brief It defines the space interface
 *
 * @file space.h
 * @author Profesores PPROG, Estefanía Fenoy Montes
 * @version 3.5
 * @date 04-03-2024
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
 *
 * @param space a pointer to the space
 * @return the id number of the space located at the east
 */
Id space_get_east(Space* space);

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
 * @author Estefanía Fenoy Montes
 *
 * @param space a pointer to the space
 * @param object an identifier of the object that will be added in the set of objects of space
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_object(Space *space, Id object);

/**
 * @brief It deletes the ID of an object in the set of objects of space
 * @author Estefanía Fenoy Montes
 *
 * @param space a pointer to the space
 * @param object an identifier of the object that will be deleted in the set of objects of space
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_del_object(Space *space, Id object);

/**
 * @brief It obtains the set of objets in the given space
 * @author Estefanía Fenoy Montes
 *
 * @param space a pointer to the space
 * @return space->objects, the set of objects in the space
 */
Set *space_get_objects(Space *space);

/**
 * @brief It sets the ID of a particular object which is in the set of objects of the given space
 * by its position
 * @author Estefanía Fenoy Montes
 *
 * @param space a pointer to the space
 * @param position an int that indicates the position in the array of objects of the given space
 * @return the Id of an object which is in the given space
 */
Id space_get_object_id(Space *space, int position);
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

/**
 * @brief It checks if the given object is in the given space
 * @author Estefanía Fenoy Montes
 *
 * @param space a pointer to the space
 * @param object the identifier of the object that will be checked if it is in the space
 * @return TRUE, if the given object is in the space, FALSE in case of error or if the object is not 
 * in the given space
 */
Bool space_check_object(Space * space, Id object);

#endif
