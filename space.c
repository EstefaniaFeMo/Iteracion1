/**
 * @brief It implements the space module
 *
 * @file space.c
 * @author Profesores PPROG, Estefanía Fenoy Montes, Carmen Gómez Escobar
 * @version 3.5
 * @date 04-03-2024
 * @copyright GNU Public License
 */

#include "space.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Space
 *
 * This struct stores all the information of a space.
 */
struct _Space
{
  Id id;                    /*!< Id number of the space, it must be unique */
  char name[WORD_SIZE + 1]; /*!< Name of the space */
  Id north;                 /*!< Id of the space at the north */
  Id south;                 /*!< Id of the space at the south */
  Id east;                  /*!< Id of the space at the east */
  Id west;                  /*!< Id of the space at the west */
  Set * objects;            /*!< Set with the IDs of the objects*/
  Id character;             /*!< Id of the character that is in the space */
};

/** space_create allocates memory for a new space and initializes its members */
Space *space_create(Id id)
{
  Space *newSpace = NULL;

  /* Error control */
  if (id == NO_ID)
    return NULL;

  newSpace = (Space *)malloc(sizeof(Space));
  if (newSpace == NULL)
  {
    return NULL;
  }

  /* Initialization of an empty space*/
  newSpace->id = id;
  newSpace->name[0] = '\0';
  newSpace->north = NO_ID;
  newSpace->south = NO_ID;
  newSpace->east = NO_ID;
  newSpace->west = NO_ID;
  newSpace->objects = set_create();
  newSpace->character = NO_ID;
  return newSpace;
}

/** space_destroy destroys a space, freeing the allocated memory */
Status space_destroy(Space *space)
{
  if (!space)
  {
    return ERROR;
  }
  if(set_destroy(space->objects)==ERROR){
      return ERROR;
  }
    space->objects = NULL;

  free(space);
  
  return OK;
}

/** space_get_id gets the id of a space */
Id space_get_id(Space *space)
{
  if (!space)
  {
    return NO_ID;
  }
  return space->id;
}

/** space_set_name sets the name of a space */
Status space_set_name(Space *space, char *name)
{
  if (!space || !name)
  {
    return ERROR;
  }

  if (!strcpy(space->name, name))
  {
    return ERROR;
  }
  return OK;
}

/** space_get_name gets the name of a space */
const char *space_get_name(Space *space)
{
  if (!space)
  {
    return NULL;
  }
  return space->name;
}

/** space_set_north sets the id of the space located at the north */
Status space_set_north(Space *space, Id id)
{
  if (!space || id == NO_ID)
  {
    return ERROR;
  }
  space->north = id;
  return OK;
}

/** space_get_north gets the id of the space located at the north */
Id space_get_north(Space *space)
{
  if (!space)
  {
    return NO_ID;
  }
  return space->north;
}

/** space_set_south sets the id of the space located at the south */
Status space_set_south(Space *space, Id id)
{
  if (!space || id == NO_ID)
  {
    return ERROR;
  }
  space->south = id;
  return OK;
}

/** space_get_south gets the id of the space located at the south */
Id space_get_south(Space *space)
{
  if (!space)
  {
    return NO_ID;
  }
  return space->south;
}

/** space_set_east sets the id of the space located at the east */
Status space_set_east(Space *space, Id id)
{
  if (!space || id == NO_ID)
  {
    return ERROR;
  }
  space->east = id;
  return OK;
}

/** space_get_east gets the id of the space located at the east */
Id space_get_east(Space *space)
{
  if (!space)
  {
    return NO_ID;
  }
  return space->east;
}

/** space_set_west sets the id of the space located at the west */
Status space_set_west(Space *space, Id id)
{
  if (!space || id == NO_ID)
  {
    return ERROR;
  }
  space->west = id;
  return OK;
}

/** space_get_west gets the id of the space located at the west */
Id space_get_west(Space *space)
{
  if (!space)
  {
    return NO_ID;
  }
  return space->west;
}

/** space_set_object sets the ID of an object in the set of objects of the space */
Status space_set_object(Space *space, Id object)
{
  if (!space)
  {
    return ERROR;
  }
  if(set_add(space->objects, object)==ERROR){
    return ERROR;
  }
  return OK;
}
/** space_del_object deletes the ID of an object in the set of objects of the space */
Status space_del_object(Space *space, Id object)
{
  if (!space)
  {
    return ERROR;
  }
  if(set_del(space->objects, object)==ERROR){
    return ERROR;
  }
  return OK;
}
/** space_get_object obtains the set of objets in the given space*/
Set *space_get_objects(Space *space){
  if(!space){
    return NULL;
  }
  return space->objects;
}

/** space_get_object_id gets the identifier of a particular object that is in the space 
 * with the given position*/
Id space_get_object_id(Space *space, int position)
{
  if (!space || position<0)
  {
    return NO_ID;
  }
  return set_return_id(space->objects, position);

}
/*space_set_character sets the given ID of the character to the space*/
Status space_set_character(Space *space, Id character){
  if(!space || character==NO_ID){
    return ERROR;
  }
  space->character = character;
  return OK;
}
/*space_get_character obtains the ID of the character which is in the given space*/
Id space_get_character(Space * space){
  if(!space){
    return NO_ID;
  }
  return space->character;
}
/** space_print prints the space information 
*/
Status space_print(Space *space)
{
  Id idaux = NO_ID;

  /* Error Control */
  if (!space)
  {
    return ERROR;
  }

  /* 1. Print the id and the name of the space */
  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);

  /* 2. For each direction, print its link */
  idaux = space_get_north(space);
  if (NO_ID != idaux)
  {
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  }
  else
  {
    fprintf(stdout, "---> No north link.\n");
  }
  idaux = space_get_south(space);
  if (NO_ID != idaux)
  {
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  }
  else
  {
    fprintf(stdout, "---> No south link.\n");
  }
  idaux = space_get_east(space);
  if (NO_ID != idaux)
  {
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  }
  else
  {
    fprintf(stdout, "---> No east link.\n");
  }
  idaux = space_get_west(space);
  if (NO_ID != idaux)
  {
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  }
  else
  {
    fprintf(stdout, "---> No west link.\n");
  }

  /* 3. Print the IDs of the objects */
  fprintf(stdout, "Objects: \n");
  if (set_print(space->objects)==OK);
  else
  {
    fprintf(stdout, "---> No object.\n");
  }

  return OK;
}
/*space_check_objects checks if the given identifier of the object is in the given space*/
Bool space_check_object(Space * space, Id object){
  if(space==NULL || object==NO_ID){
    return FALSE;
  }
  if(set_check_id(space->objects, object)==FALSE){
    return FALSE;
  }
  return TRUE;
}

