/**
 * @brief It defines the game interface for the creation, destruction and control of the players
 *
 * @file character.h
 * @author Carmen Gómez Escobar
 * @version 3.5
 * @date 14-02-2024
 * @copyright GNU Public License
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#define CHARACTER_HEALTH 5

#include "types.h"

/**
 * @brief Character
 *
 * This struct contains all the information of a character.
 */
typedef struct _Character Character;

/**
 * @brief It creates a new character, reserving dynamic memory and initializing its variables
 * @author Carmen Gómez Escobar
 *
 * @param id the identification number of the character which is going to be created
 * @return a pointer to a new character and its variables initialized
 */
Character *character_create(Id id);

/**
 * @brief It destroys a character and releases the reserved memory
 * @author Carmen Gómez Escobar
 *
 * @param character a pointer to the character that will be destroyed
 *  @return OK if everything worked, ERROR if something went wrong
 */
Status character_destroy(Character *character);

/**
 * @brief It gets the id of a character
 * @author Carmen Gómez Escobar
 *
 * @param character a pointer to the character in order to access to the ID
 * @return the id of the character
 */
Id character_get_id(Character *character);

/**
 * @brief It sets the name of a character
 * @author Carmen Gómez Escobar
 *
 * @param character a pointer to the character
 * @param name a string with the name of the character
 * @return OK if everything worked, ERROR if something went wrong
 */
Status character_set_name(Character *character, char *name);

/**
 * @brief It gets the name of a character
 * @author Carmen Gómez Escobar
 *
 * @param character a pointer to the character that allows access to its name
 * @return a string with the name of the character
 */
const char *character_get_name(Character *character);

/**
 * @brief It sets the health of the character.
 * @author Carmen Gómez Escobar
 *
 * @param character a pointer to the character that allows access to its name
 * @param health the number of points of life a character has
 * @return OK if everything worked, ERROR if something went wrong
 */
Status character_set_health(Character *character, int health);

/**
 * @brief It gets the health of the character.
 * @author Carmen Gómez Escobar
 *
 * @param character a pointer to the character that allows access to its name
 * @return the points of life of the character
 */
int character_get_health(Character *character);

/**
 * @brief It sets whether the character is friendly or not
 * @author Carmen Gómez Escobar
 *
 * @param character a pointer to the character that allows access to its name
 * @param friendly a boolean value whit their relationship
 * @return OK if everything worked, ERROR if something went wrong
 */
Status character_set_friendly(Character *character, Bool friendly);

/**
 * @brief It gets whether the character is friendly or not
 * @author Carmen Gómez Escobar
 *
 * @param character a pointer to the character that allows access to its name
 * @return TRUE, if he is a friend, FALSE, if he is an enemy
 */
Bool character_get_friendly(Character *character);

/**
 * @brief It sets the message of the character
 * @author Carmen Gómez Escobar
 *
 * @param character a pointer to the character that allows access to its name
 * @param message a string ehit the message
 * @return OK if everything worked, ERROR if something went wrong
 */
Status character_set_message(Character *character, char *message);

/**
 * @brief It  gets the message of the character
 * @author Carmen Gómez Escobar
 *
 * @param character a pointer to the character that allows access to its name
 * @return a string whit the message
 */
const char *character_get_message(Character *character);

/**
 * @brief It prints the message of the character
 * @author Carmen Gómez Escobar
 *
 * This function shows the information of character: id and name of the space.
 *
 * @param character a pointer to the character
 * @return OK if everything worked, ERROR if something went wrong
 */
Status character_print_message(Character *character);

/**
 * @brief It prints the characters id, location and health.
 * @author Carmen Gómez Escobar
 *
 * This function shows the information of character: id and name of the space.
 *
 * @param character a pointer to the character
 * @return OK if everything worked, ERROR if something went wrong
 */
Status character_print(Character *character);

#endif
