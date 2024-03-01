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
    if(set==NULL || id==NO_ID){
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
/** set_del deletes in the array of IDs the ID given as a parameter
 */
Status set_del(Set *set, Id id){
    int i, flag, j;
    /* Error control */
    if(set==NULL || set->n_ids>MAX_NUM_IDS || set->n_ids<=0 || id==NO_ID){
        return ERROR;
    }
    /*This loop finds if there given id is in the array with the use of the variable flag*/
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
    /*It restructurates the array having the position of the Id that will be deleted
    moving the following IDs one position back*/
    for(j=i+1; j<set->n_ids; j++, i++){
        set->ids[i]=set->ids[j];
    }

    /*The last ID that will be duplicated is set as NO_ID and the number of IDs will be decrease by one*/
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
        fprintf(stdout, " 02%d: %ld\n", i+1, set->ids[i]);
    }
    return OK;
}

/** set_check_id  checks if the given Id is in the set*/
Bool set_check_id(Set * set, Id id){
    int i, flag;
    /* Error control */
    if(set==NULL || id==NO_ID){
        return FALSE;
    }
    for(i=flag=0; i<set->n_ids; i++){
        if(set->ids[i]==id){
            flag=1;
            break;
        }
    }
    if(!flag){
        return FALSE;
    }
    return TRUE;
}
/*set_return_id returns and identifier of the ID which is in the given position*/
Id set_return_id(Set *set, int position){
    if(set==NULL || position<0){
        return NO_ID;
    }
    return set->ids[position];
}