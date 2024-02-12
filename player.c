/**
 * @brief It defines the game interface for the players control, decribing its location, name, identification and the carried object. It also creates and destroys players
 *
 * @file player.c
 * @author Estefania Fenoy Montes, Carmen Gómez Escobar
 * @version 3.5
 * @date 14-02-2024
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
    Id location;
    Bool object; /*!< Whether the player has an object or not */
};

/**
 * @brief It creates a new player, reserving dynamic memory and initializing its variables
 * @author Carmen Gómez Escobar
 *
 * @param id the identification number of the player which is going to be created
 * @return a new player and its variables initialized
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

    /* Initialization of an empty space*/
    newPlayer->id = id;
    newPlayer->name[0] = '\0';
    newPlayer->object = FALSE;

    return newPlayer;
}

/**
 * @brief It destroys a player and releases the reserved memory
 * @author Carmen Gómez Escobar
 *
 * @param player a pointer to the player that will be destroyed
 * @return OK, if everything went well
 * @return ERROR, if it was some mistake
 */
Status player_destroy(Player *player)
{
    if (!player)
    {
        return ERROR;
    }

    free(player);
    player = NULL;
    return OK;
}

/**
 * @brief It gets the id of a player
 * @author Carmen Gómez Escobar
 *
 * @param player a pointer to the player in order to access to the ID
 * @return the ID of player
 */
Id player_get_id(Player *player)
{
    if (!player)
    {
        return NO_ID;
    }
    return player->id;
}

/**
 * @brief It sets the name of a player
 * @author Carmen Gómez Escobar
 *
 * @param player a pointer to the player
 * @param name a string with the name of the player
 * @return OK, if everything went well
 * @return ERROR, if it was some mistake
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

/**
 * @brief It gets the name of a player
 * @author Carmen Gómez Escobar
 *
 * @param player a pointer to the player that allows access to its name
 * @return  a string with the name of the player
 */
const char *player_get_name(Player *player)
{
    if (!player)
    {
        return NULL;
    }
    return player->name;
}

/**
 * @brief It sets the new object carried by the player.
 * @author Carmen Gómez Escobar
 *
 * @param player a pointer to the player that allows access to its name
 * @param id a long variable with the position
 * @return OK if everything worked, ERROR if something went wrong
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

/**
 * @brief It changes the localization of the player.
 * @author Carmen Gómez Escobar
 *
 * @param player a pointer to the player that allows access to its name
 * @return the id of the player
 */
Id player_get_location(Player *player)
{
    if (!player)
    {
        return NO_ID;
    }
    return player->location;
}

/**
 * @brief It sets the new object carried by the player.
 * @author Carmen Gómez Escobar
 *
 * @param player a pointer to the player that allows access to its name
 * @param id a long variable with the position
 * @return OK if everything worked, ERROR if something went wron
 */
Status player_set_object(Player *player, Bool value)
{
    if (!player)
    {
        return ERROR;
    }
    player->object = value;

    return OK;
}

/**
 * @brief It changes the position of the object in order to be with the player the player
 * @author Carmen Gómez Escobar
 *
 * @param player a pointer to the player that allows access to its name
 * @return FALSE if there is no object, TRUE if there is an object
 */
Bool player_get_object(Player *player)
{
    if (!player)
    {
        return FALSE;
    }
    return player->object;
}

/**
 * @brief It prints the players ID and name
 * @author Carmen Gómez Escobar
 *
 * This function shows the information of player: id and name of the space.
 * @param player a pointer to the palyer
 * @return OK, if everything went well
 * @return ERROR, if it was some mistake
 */
Status player_print(Player *player)
{
    /* Error Control */
    if (!player)
    {
        return ERROR;
    }

    /* Print the id and the name of the player */
    fprintf(stdout, "--> Player (Id: %ld; Name: %s)\n", player->id, player->name);

     /* Print the location and the name of the player */
    fprintf(stdout, "--> Player (Location link: %ld)\n", player->location);

    /*Indication that the function has worked correctly*/
    return OK;
}
