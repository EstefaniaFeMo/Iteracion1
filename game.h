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

/**Macro with the maximum number of spaces*/
#define MAX_SPACES 100
/**Macro with the id of player and object when they are initialized*/
#define ID_PLAYER 0
#define ID_OBJECT 0
/*Macro with the maximum number of objects*/
#define MAX_OBJECTS 5
/*Macro with the maximum number of players*/
#define MAX_CHARACTERS 4


/**
 * @brief Game
 *
 * This struct contains all the information related to the data of the game.
 */
typedef struct _Game {
  Object *objects[MAX_OBJECTS];/*!< Array with different objects */
  Player *player;/*!< Information of the player */
  Player *characters[MAX_CHARACTERS];
  Space *spaces[MAX_SPACES];/*!< Array with different spaces */
  int n_spaces; /*!< Number of spaces*/
  int n_objects; /*!< Number of objects*/
  int n_characters; /*!< Number of characters*/
  Command last_cmd; /*!< Command to modify the location: no actions, exit, next or back */
  Bool finished; /*!< Boolean variable whcih indicates with the values TRUE/FALSE whether the program has finished or not */
} Game;



/**
 * @brief It creates and initializes the game 
 * @author Profesores PPROG, Estefanía Fenoy Montes
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
 * @author Profesores PPROG, Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct that initiales it
 * @param filename a pointer with the name of a file of text which will be read to download the spaces 
 * @return status==OK, variable booleana que indica el correcto funcionamiento de la función.
 * @return status==ERROR, variable booleana que indica el erróneo funcionamiento de la función.
 */
Status game_create_from_file(Game *game, char *filename);

/**
 * @brief It receives as arguments the current game session and the command that the user wants to execute. Then this command is set 
 * as the last command and then starts a switch. As long as the command is UNKNOWN it doesn't do anything. Wether it is EXIT
 * it doesn't do anything. If it is NEXT it changes the position to the south. Finally, provided the command is BACK it changes
 * the position to the north.
 * @author Profesores PPROG, Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct that contains the information of the current game session
 * @param cmd the command which will be executed 
 * @return status==OK, if the function has worked correctly
 */
Status game_actions_update(Game *game, Command cmd);

/**
 * @brief It destroys the game by freeing the spaces, the object and the player, then it sets them as NULL.
 * @author Profesores PPROG, Estefanía Fenoy Montes
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
 * @author Profesores PPROG, Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct that contains the information of the current game session
 * @param cmd the command which will be executed 
 * @return NULL if the ID is not declared, or doesn't match with any of the ID of the spaces. 
 * @return game->spaces[i] if the spaces[i] ID match with the given ID.
 */
Space *game_get_space(Game *game, Id id);

/**
 * @brief The function returns the value of the variable player_location of the current game
 * @author Profesores PPROG, Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct that contains the information of the current game session 
 * @return game->player_location. Always return the value of the variable.
 */
Id game_get_player_location(Game *game);

/**
 * @brief It receives as arguments the current game session and sets the value of the 
 * variable player_location with the given ID.
 * @author Profesores PPROG, Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct that contains the information of the current game session
 * @param id is the id of the position of the space in which we want the player to be moved.
 * @return status==ERROR, if the ID is not declared.
 * @return status==OK, if the ID has been set correctly.
 */
Status game_set_player_location(Game *game, Id id);

/**
 * @brief The function returns the Id of the space in which is tge given object
 * @author Profesores PPROG, Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct that contains the information of the current game session 
 * @param object an identifier of the object whose space is going to be returned
 * @return the id of the space in which the given object is
 */
Id game_get_object_location(Game *game, Id object);

/**
 * @brief It sets the given object of the game into the given space
 * @author Profesores PPROG, Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct that contains the information of the current game session
 * @param space is the id of the position of the space in which we want the object to be moved.
 * @param object an identifier of the object that wants to be set in the given space
 * @return status==ERROR, if the ID is not declared.
 * @return status==OK, if the ID has been set correctly.
 */
Status game_set_object_location(Game *game, Id space, Id object);

/**
 * @brief The function returns the last command executed of the current game
 * @author Profesores PPROG, Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct that contains the information of the current game session 
 * @return game->last_cmd. Always return the value of the variable.
 */
Command game_get_last_command(Game *game);

/**
 * @brief It receives as arguments the current game session and a command, which sets this command as the
 * last executed command
 * @author Profesores PPROG, Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct that contains the information of the current game session
 * @param command is the command that we want to set as the last command
 * @return status==OK, always return OK.
 */
Status game_set_last_command(Game *game, Command command);

/**
 * @brief The function returns TRUE if the game is finished and FALSE if not.
 * @author Profesores PPROG, Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct that contains the information of the current game session 
 * @return game->finished. Always return the value of the variable.
 */
Bool game_get_finished(Game *game);

/**
 * @brief It receives as arguments the current game session and a boolean value, then sets the state
 * of the game if it's finished or not
 * @author Profesores PPROG, Estefanía Fenoy Montes
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
 * @author Profesores PPROG, Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct that contains the information of the current game session
 */
void game_print(Game *game);

/*Function that was private, make it public to have it in game_reader*/
/**
 * @brief It adds a new space in the last position available of the array and increases the number of spaces by one
 * @author Profesores PPROG, Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct, Game and it uses it to add a new space in the array game->spaces
 * @param space a pointer to the space that will be added
 * @return status==OK, if the function has worked correctly
 * @return status==ERROR, if a mistken has happened
 */
Status game_add_space(Game *game, Space *space);

#endif
