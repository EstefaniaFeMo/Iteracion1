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
/** set_add includes in the array of IDs the given ID
 */
Status set_add(Set *set, Id id){
    /* Error control */
    if(set==NULL){
        return ERROR;
    }
    /* Error control */
    if(set->n_ids>=MAX_NUM_IDS || set->n_ids<0){
        return ERROR;
    }
    set->ids[set->n_ids]= id;
    set->n_ids++;
    return OK;
}
/** set_del deleates in the array of IDs the ID given as a parameter
 */
Status set_del(Set *set, Id id){
    int i, flag, j;
    /* Error control */
    if(set==NULL || set->n_ids>MAX_NUM_IDS || set->n_ids<=0){
        return ERROR;
    }

    for(i=flag=0; i<set->n_ids; i++){
        if(set->ids[i]==id){
            flag=1;
            break;
        }
    }
    /* Error control that the given id is in the array */
    if(!flag){
        return ERROR;
    }

    for(j=i+1; j<set->n_ids; j++, i++){
        set->ids[i]=set->ids[j];
    }

    set->ids[i]=NO_ID;
    set->n_ids--;
    return OK;
}
/** set_print prints all the information of the given set
 */
Status set_print(Set *set){
    int i;
    /* Error control */
    if(set==NULL || set->n_ids>MAX_NUM_IDS || set->n_ids<=0){
        return ERROR;
    }
    for(i=0; i<set->n_ids; i++){
        fprintf(stdout, "Id %d de %d: %ld\n", i+1, set->n_ids, set->ids[i]);
    }
    return OK;
}
