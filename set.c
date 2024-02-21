/**
 * @brief It implements the set module
 *
 * @file set.c
 * @author Estefanía Fenoy Montes
 * @version 3.5
 * @date 20-02-2024
 * @copyright GNU Public License
 */
#include "set.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Set
 *
 * This struct contains all the information of a set.
 */
struct _Set
{
    Id ids[MAX_NUM_IDS]; /*!< An array with the ids of the members of the set */
    int n_ids; /*!< Number of IDs in the set */
};

/** set_create allocates memory for a new set and initializes its members
 */
Set * set_create(){
    Set *newSet=NULL;
    int i;


    newSet=(Set*)malloc(sizeof(Set));

    /* Error control of the reserve */
    if(newSet==NULL){
        return NULL;
    }

    newSet->n_ids=0;
    for(i=0; i<MAX_NUM_IDS; i++){
        newSet->ids[i]=NO_ID;
    }
    
    return newSet;
}

/** set_destroy destroys the set that has been created, releasig the memory used
 */
Status set_destroy(Set *set){
    /* Error control */
    if (!set)
    {
        return ERROR;
    }

    free(set);

    set = NULL;

    return OK;
}
Status set_add(Set *set, Id id){
    if(set==NULL){
        return ERROR;
    }
    if(set->n_ids>=MAX_NUM_IDS){
        return ERROR;
    }
    set->ids[set->n_ids-1]= id;
    set->n_ids++;
    return OK;
}

