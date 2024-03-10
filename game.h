/**
 * @brief It defines the game interface 
 *
 * @file game.h
 * @author Profesores PPROG, Estefanía Fenoy Montes
 * @version 3.5
 * @date 06-02-2024
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "types.h"
#include "object.h"
#include "player.h"
#include "character.h"


#define MAX_SPACES 100 /*!<Macro with the maximum number of spaces*/

#define ID_PLAYER 0 /*!<Macro with the id of player */
#define ID_OBJECT 0 /*!<Macro with the id of the object when it is initialized*/
#define ID_CHARACTER1 0 /*!<Macro with the id of the character when it is initialized*/
#define ID_CHARACTER2 1 /*!<Macro with the id of the character when it is initialized*/

#define MAX_OBJECTS 5 /*!<Macro with the maximum number of objects*/

#define MAX_CHARACTERS 2 /*!<Macro with the maximum number of players*/


/**
 * @brief Game
 *
 * This struct contains all the information related to the data of the game.
 */
typedef struct _Game {
  Object *objects[MAX_OBJECTS];/*!< Array with different objects */
  Player *player;/*!< Information of the player */
  Character *characters[MAX_CHARACTERS];
  Space *spaces[MAX_SPACES];/*!< Array with different spaces */
  int n_spaces; /*!< Number of spaces*/
  int n_objects; /*!< Number of objects*/
  int n_characters; /*!< Number of characters*/
  Command *last_cmd; /*!< Command to modify the location: no actions, exit, next or back */
  Bool finished; /*!< Boolean variable whcih indicates with the values TRUE/FALSE whether the program has finished or not */
} Game;



/**
 * @brief It creates and initializes the game 
 * @author Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct: Game, which will be initilized
 * @return status==OK, if the function has worked correctly
 * @return status==ERROR, if a mistken has happened
 */
Status game_create(Game *game);

/**
 * @brief It creates the game. If there were a problem, it would return ERROR. Then, it loads the spaces with the information
 * of the file passed as an argument to the function. If there were a problem, it would return ERROR. Next, the player and the 
 * object are located in the first space
 * @author Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct that initiales it
 * @param filename a pointer with the name of a file of text which will be read to download the spaces 
 * @return status==OK, variable booleana que indica el correcto funcionamiento de la función.
 * @return status==ERROR, variable booleana que indica el erróneo funcionamiento de la función.
 */
Status game_create_from_file(Game *game, char *filename);

/**
 * @brief It destroys the game by freeing the spaces, the object and the player, then it sets them as NULL.
 * @author Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct: Game, which contains the information of the current game session
 * @return status==OK, if the function has worked correctly
 */
Status game_destroy(Game *game);

/**
 * @brief It gets as arguments the current game session and an ID, which is used to get the position
 * of the ID. First, it checks if the given ID is initialized but not set, if this is the case returns NULL.
 * If not, it compares every space ID from the array game->spaces[] with the given ID. In case it matches,
 * the function returns the value of the space. If the ID doesn't match with any ID, returns NULL.
 * @author Profesores PPROG
 *
 * @param game a pointer to the struct that contains the information of the current game session
 * @param cmd the command which will be executed 
 * @return NULL if the ID is not declared, or doesn't match with any of the ID of the spaces. 
 * @return game->spaces[i] if the spaces[i] ID match with the given ID.
 */
Space *game_get_space(Game *game, Id id);

Player *game_get_player(Game *game);

/**
 * @brief The function returns the value of the variable player_location of the current game
 * @author Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct that contains the information of the current game session 
 * @return game->player_location. Always return the value of the variable.
 */
Id game_get_player_location(Game *game);

/**
 * @brief It receives as arguments the current game session and sets the value of the 
 * variable player_location with the given ID.
 * @author Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct that contains the information of the current game session
 * @param id is the id of the position of the space in which we want the player to be moved.
 * @return status==ERROR, if the ID is not declared.
 * @return status==OK, if the ID has been set correctly.
 */
Status game_set_player_location(Game *game, Id id);

/**
 * @brief The function returns the Id of the space in which is the given object
 * @author Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct that contains the information of the current game session 
 * @param object an identifier of the object whose space is going to be returned
 * @return the id of the space in which the given object is
 */
Id game_get_object_location(Game *game, Id object);

/**
 * @brief It sets the given object of the game into the given space
 * @author Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct that contains the information of the current game session
 * @param space is the id of the position of the space in which we want the object to be moved.
 * @param object an identifier of the object that wants to be set in the given space
 * @return status==ERROR, if the ID is not declared.
 * @return status==OK, if the ID has been set correctly.
 */
Status game_set_object_location(Game *game, Id space, Id object);

Character *game_get_character(Game *game, Id id);

/**
 * @brief The function returns the Id of the space in which is the given character
 * @author Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct that contains the information of the current game session 
 * @param character an identifier of the character whose space is going to be returned
 * @return the id of the space in which the given character is
 */
Id game_get_character_location(Game *game, Id character);

/**
 * @brief It sets the given character in the given space
 * @author Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct that contains the information of the current game session
 * @param space is the id of the position of the space in which we want the chaarcter to be moved.
 * @param caharcter an identifier of the character that wants to be set in the given space
 * @return status==ERROR, if the ID is not declared.
 * @return status==OK, if the ID has been set correctly.
 */
Status game_set_character_location(Game *game, Id space, Id character);

/**
 * @brief The function returns the last command executed of the current game
 * @author Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct that contains the information of the current game session 
 * @return game->last_cmd. Always return the value of the variable.
 */
Command *game_get_last_command(Game *game);

/**
 * @brief It receives as arguments the current game session and a command, which sets this command as the
 * last executed command
 * @author Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct that contains the information of the current game session
 * @param command is the command that we want to set as the last command
 * @return status==OK, always return OK.
 */
Status game_set_last_command(Game *game, Command *command);

/**
 * @brief The function returns TRUE if the game is finished and FALSE if not.
 * @author Profesores PPROG
 *
 * @param game a pointer to the struct that contains the information of the current game session 
 * @return game->finished. Always return the value of the variable.
 */
Bool game_get_finished(Game *game);

/**
 * @brief It receives as arguments the current game session and a boolean value, then sets the state
 * of the game if it's finished or not
 * @author Profesores PPROG
 *
 * @param game a pointer to the struct that contains the information of the current game session
 * @param finished is a boolean value to indicate if the game is finished or not.
 * @return status==OK, always return OK.
 */
Status game_set_finished(Game *game, Bool finished);

/**
 * @brief It prints the current game session. First prints the header which are only a straight line.
 * Then it starts to print all the spaces and last gives the information of the player and object 
 * location.
 * @author Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct that contains the information of the current game session
 */
void game_print(Game *game);

/*Function that was private, make it public to have it in game_reader*/
/**
 * @brief It adds a new space in the last position available of the array and increases the number of spaces by one
 * @author Profesores PPROG
 *
 * @param game a pointer to the struct, Game and it uses it to add a new space in the array game->spaces
 * @param space a pointer to the space that will be added
 * @return status==OK, if the function has worked correctly
 * @return status==ERROR, if a mistken has happened
 */
Status game_add_space(Game *game, Space *space);

/**
 * @brief It adds a new object in the last position available of the array and increases the number of objects by one
 * @author Carmen Gómez Escobar
 *
 * @param game a pointer to the struct.
 * @param object a pointer to the object that will be added
 * @return status==OK, if the function has worked correctly
 * @return status==ERROR, if a mistken has happened
 */
Status game_add_object(Game *game, Object *object);

/**
 * @brief It adds a new character in the last position available of the array and increases the number of characters by one
 * @author Carmen Gómez Escobar
 *
 * @param game a pointer to the struct.
 * @param object a pointer to the character that will be added
 * @return status==OK, if the function has worked correctly
 * @return status==ERROR, if a mistken has happened
 */
Status game_add_character(Game *game, Character *character);

/**
 * @brief It gives the ID of the position of the given parameter
 * @author Profesores PPROG
 *
 * @param game a pointer to the struct, Game and it uses it to get access to the game->spaces IDs
 * @param position the position we want to get the id
 * @return the ID of the space at the position given.
 */
Id game_get_space_id_at(Game *game, int position);

Character *game_create_predesigned_characters(Game *game, Id location, Bool friendly, Id id, char *name, char *message);

#endif

