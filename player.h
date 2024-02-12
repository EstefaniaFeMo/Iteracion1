/**
 * @brief It defines the game interface for the creation, destruction and control of the players
 *
 * @file player.h
 * @author Estefania Fenoy Montes, Carmen Gómez Escobar
 * @version 3.5
 * @date 14-02-2024
 * @copyright GNU Public License
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

/**
 * @brief Player
 *
 * This struct contains all the information of a player.
 */
typedef struct _Player Player;

/**
 * @brief It creates a new player, reserving dynamic memory and initializing its variables
 * @author Carmen Gómez Escobar
 *
 * @param id the identification number of the player which is going to be created
 * @return a new player and its variables initialized
 */
Player *player_create(Id id);

/**
 * @brief It destroys a player and releases the reserved memory
 * @author Carmen Gómez Escobar
 *
 * @param player a pointer to the player that will be destroyed
 * @return OK, if everything went well
 * @return ERROR, if it was some mistake
 */
Status player_destroy(Player *player);

/**
 * @brief It gets the id of a player
 * @author Carmen Gómez Escobar
 *
 * @param player a pointer to the player in order to access to the ID
 * @return the ID of player
 */
Id player_get_id(Player *player);

/**
 * @brief It sets the name of a player
 * @author Carmen Gómez Escobar
 *
 * @param player a pointer to the player
 * @param name a string with the name of the player
 * @return OK, if everything went well
 * @return ERROR, if it was some mistake
 */
Status player_set_name(Player *player, char *name);

/**
 * @brief It gets the name of a player
 * @author Carmen Gómez Escobar
 *
 * @param player a pointer to the player that allows access to its name
 * @return  a string with the name of the player
 */
const char *player_get_name(Player *player);

/**
 * @brief It sets the new object carried by the player.
 * @author Carmen Gómez Escobar
 *
 * @param player a pointer to the player that allows access to its name
 * @param id a long variable with the position
 * @return a string with the name of the player
 */
Status player_set_object(Player *player, Bool value);

/**
 * @brief It changes the position of the object in order to be with the player the player
 * @author Carmen Gómez Escobar
 *
 * @param player a pointer to the player that allows access to its name
 * @return a string with the name of the player
 */
Bool player_get_object(Player *player);

/**
 * @brief It prints the players ID and name
 * @author Carmen Gómez Escobar
 *
 * This function shows the information of player: id and name of the space.
 * @param player a pointer to the palyer
 * @return OK, if everything went well
 * @return ERROR, if it was some mistake
 */
Status player_print(Player *player);

#endif