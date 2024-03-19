/**
 * @brief It implements the inventory module
 *
 * @file inventory.c
 * @author Estefanía Fenoy Montes
 * @version 3.5
 * @date 18-03-2024
 * @copyright GNU Public License
 */

#include "inventory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Inventory
 *
 * This struct stores all the information of an inventory.
 */
struct _Inventory
{
    Set * objs;
    int max_objs;
  
};
/** inventory_create allocates memory for a new inentory and initializes its members */
Inventory *inventory_create()
{
    Inventory *inventory = NULL;

    inventory = (Inventory *)malloc(sizeof(Inventory));
    if (inventory == NULL)
    {
        return NULL;
    }

    /* Initialization of an empty inventory*/
    inventory->objs = set_create();
    inventory->max_objs = 0;

    return inventory;
}

/** inventory_destroy destroys an inventory, freeing the allocated memory */
Status inventory_destroy(Inventory *inventory)
{
  if (!inventory)
  {
    return ERROR;
  }
  if(set_destroy(inventory->objs)==ERROR){
      return ERROR;
  }

  free(inventory);
  
  return OK;
}

/*inventory_get_max_objects obtains the number of maximum objects in the inventory*/
int inventory_get_max_objects(Inventory * inventory){
  if(!inventory){
    return -1;
  }
  return inventory->max_objs;
}
/*inventory_set_max_objects sets the number of maximum objects in the inventory*/
Status inventory_set_max_objects(Inventory * inventory, int max){
  if(!inventory || max<=0){
    return ERROR;
  }
  inventory->max_objs=max;
  return OK;
  
}

/** inventory_add_object adds the ID of an object in the set of objects of the inventory */
Status inventory_add_object(Inventory *inventory, Id object)
{
  if (!inventory || set_get_n_ids(inventory->objs)>=inventory->max_objs)
  {
    return ERROR;
  }
  if(set_add(inventory->objs, object)==ERROR){
    return ERROR;
  }
  return OK;
}

/** inventory_del_object deletes the ID of an object in the set of objects of the inventory */
Status inventory_del_object(Inventory *inventory, Id object)
{
  if (!inventory)
  {
    return ERROR;
  }
  if(set_del(inventory->objs, object)==ERROR){
    return ERROR;
  }
  return OK;
}

/** inventory_get_object obtains the set of objets in the given inventory*/
Set *inventory_get_objects(Inventory *inventory){
  if(!inventory){
    return NULL;
  }
  return inventory->objs;
}

/** inentory_get_object_id gets the identifier of a particular object that is in the given inventory with the given position*/
Id inventory_get_object_id(Inventory *inventory, int position)
{
  if (!inventory || position<0)
  {
    return NO_ID;
  }
  return set_return_id(inventory->objs, position);
}

/*inventory_check_objects checks if the given identifier of the object is in the given inventory*/
Bool inventory_check_object(Inventory * inventory, Id object){
  if(inventory==NULL || object==NO_ID){
    return FALSE;
  }
  if(set_check_id(inventory->objs, object)==FALSE){
    return FALSE;
  }
  return TRUE;
}

/*inventory_is_full checks whether the given inventory is full*/
Bool inventory_is_full(Inventory * inventory){
  if(!inventory){
    return TRUE;
  }
  else if(set_get_n_ids(inventory->objs)==inventory->max_objs && inventory_is_empty(inventory)==FALSE){
    return TRUE;
  }
  return FALSE;
}

/*inventory_is_empty checks whether the given inventory is empty*/
Bool inventory_is_empty(Inventory * inventory){
  if(!inventory || inventory->max_objs<=0){
    return FALSE;
  }
  else if(set_get_n_ids(inventory->objs)==0){
    return TRUE;
  }
  return FALSE;
}
/** inventory_print prints the inventory information */
Status inventory_print(Inventory *inventory)
{

  /* Error Control */
  if (!inventory)
  {
    return ERROR;
  }

  /* 1. Print maximum number of objects which can be in the backpack */
  fprintf(stdout, "Maximum number of objects: %d\n", inventory->max_objs);


  /* 3. Print the IDs of the objects */
  fprintf(stdout, "Objects: \n");
  if (set_print(inventory->objs)==OK);
  else
  {
    fprintf(stdout, "---> No object.\n");
  }

  return OK;
}