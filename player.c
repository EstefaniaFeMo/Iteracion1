/**
 * @brief It defines the game interface for the players control, decribing its location, name, identification and the carried object. It also creates and destroys players
 *
 * @file player.c
 * @author Carmen Gómez Escobar
 * @version 3.5
 * @date 10-02-2024
 * @copyright GNU Public License
 */

#include "player.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Player
 *
 * This struct stores all the information of a player.
 */
struct _Player
{
    Id id;                    /*!< Id number of the player, it must be unique */
    char name[WORD_SIZE + 1]; /*!< Name of the player */
    Id location;              /*!< Id of the location in which the player is */
    Id object;                /*!< Id of the object that player has */
    int health;               /*!< Number of point of life the player has */
};

/** player_create creates a new player, reserving dynamic memory and initializing its variables 
*/
Player *player_create(Id id)
{
    Player *newPlayer = NULL;

    /* Error control */
    if (id == NO_ID)
        return NULL;

    newPlayer = (Player *)malloc(sizeof(Player));
    if (newPlayer == NULL)
    {
        return NULL;
    }

    newPlayer->location = NO_ID;
    newPlayer->id = id;
    newPlayer->name[0] = '\0';
    newPlayer->object = NO_ID;
    newPlayer->health = PLAYER_HEALTH;

    return newPlayer;
}

/** player_destroy, destroys a player and releases the reserved memory 
*/
Status player_destroy(Player *player)
{
    if (!player)
    {
        return ERROR;
    }

    free(player);
    return OK;
}

/** player_get_id, gets the id of the player 
*/
Id player_get_id(Player *player)
{
    if (!player)
    {
        return NO_ID;
    }
    return player->id;
}

/** player_set_name, sets the name of the player 
*/
Status player_set_name(Player *player, char *name)
{
    if (!player || !name)
    {
        return ERROR;
    }

    if (!strcpy(player->name, name))
    {
        return ERROR;
    }
    return OK;
}

/** player_get_name, gets the name of the player 
*/
const char *player_get_name(Player *player)
{
    if (!player)
    {
        return NULL;
    }
    return player->name;
}

/** player_set_location, sets the location of the player 
*/
Status player_set_location(Player *player, Id id)
{
    if (!player || id == NO_ID)
    {
        return ERROR;
    }
    player->location = id;
    return OK;
}

/** player_get_location, gets the location of the player 
*/
Id player_get_location(Player *player)
{
    if (!player)
    {
        return NO_ID;
    }
    return player->location;
}
/** player_set_object, sets the new object carried by the player 
*/
Status player_set_object(Player *player, Id object)
{
    if (!player)
    {
        return ERROR;
    }
    player->object = object;

    return OK;
}

/** player_get_object, gets the position of the object carried by the player 
*/
Id player_get_object(Player *player)
{
    if (!player)
    {
        return NO_ID;
    }
    return player->object;
}
/** player_set_health sets the health of the player*/
Status player_set_health(Player *player, int health)
{
    if(!player || health<0){
        return ERROR;
    }
    player->health = health;
    return OK;
}

/** player_get_health gets the health of the player.*/
int player_get_health(Player *player)
{
    if(!player){
        return -1;
    }
    return player->health;
}

/** player_print, prints the id of the player 
*/
Status player_print(Player *player)
{
    /* Error Control */
    if (!player)
    {
        return ERROR;
    }


    fprintf(stdout, "--> Player (Id: %ld; Name: %s)\n", player->id, player->name);

    fprintf(stdout, "--> Player (Location link: %ld)\n", player->location);


    return OK;
}
