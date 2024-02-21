/**
 * @brief It defines the game interface for the creation, destruction and control of the players
 *
 * @file player.h
 * @author Carmen Gómez Escobar
 * @version 3.5
 * @date 10-02-2024
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
 * @return a pointer to a new player and its variables initialized
 */
Player *player_create(Id id);

/**
 * @brief It destroys a player and releases the reserved memory
 * @author Carmen Gómez Escobar
 *
 * @param player a pointer to the player that will be destroyed
 *  @return OK if everything worked, ERROR if something went wrong
 */
Status player_destroy(Player *player);

/**
 * @brief It gets the id of a player
 * @author Carmen Gómez Escobar
 *
 * @param player a pointer to the player in order to access to the ID
 * @return the id of the player
 */
Id player_get_id(Player *player);

/**
 * @brief It sets the name of a player
 * @author Carmen Gómez Escobar
 *
 * @param player a pointer to the player
 * @param name a string with the name of the player
 * @return OK if everything worked, ERROR if something went wrong
 */
Status player_set_name(Player *player, char *name);

/**
 * @brief It gets the name of a player
 * @author Carmen Gómez Escobar
 *
 * @param player a pointer to the player that allows access to its name
 * @return a string with the name of the player
 */
const char *player_get_name(Player *player);

/**
 * @brief It sets the new object carried by the player.
 * @author Carmen Gómez Escobar
 *
 * @param player a pointer to the player that allows access to its name
 * @param id a long variable with the position
 * @return OK if everything worked, ERROR if something went wrong
 */
Status player_set_location(Player *player, Id id);

/**
 * @brief It gets the location of the player.
 * @author Carmen Gómez Escobar
 *
 * @param player a pointer to the player that allows access to its name
 * @return the id of the player
 */
Id player_get_location(Player *player);

/**
 * @brief It sets the new object carried by the player.
 * @author Carmen Gómez Escobar
 *
 * @param player a pointer to the player that allows access to its name
 * @param id a long variable with the position
 * @return OK if everything worked, ERROR if something went wrong
 */
Status player_set_object(Player *player, Id object);

/**
 * @brief It gets the position of the object carried by the player
 * @author Carmen Gómez Escobar
 *
 * @param player a pointer to the player that allows access to its name
 * @return the id of the object
 */
Id player_get_object(Player *player);

/**
 * @brief It prints the players ID and name
 * @author Carmen Gómez Escobar
 *
 * This function shows the information of player: id and name of the space.
 * @param player a pointer to the palyer
 *  @return OK if everything worked, ERROR if something went wrong
 */
Status player_print(Player *player);

#endif
