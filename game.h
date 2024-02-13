/**
 * @brief It defines the game interface 
 *
 * @file game.h
 * @author Estefanía Fenoy Montes
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
#define ID_PLAYER 0
#define ID_OBJECT 0


/**
 * @brief Game
 *
 * This struct contains all the information related to the data of the game.
 */


typedef struct _Game {
  Object *object;/*!< Information of the object */
  Player *player;/*!< Information of the player */
  Space *spaces[MAX_SPACES];/*!< Array condiferentes espacios */
  int n_spaces; /*!< Numero de espacios*/
  Command last_cmd; /*!< Comando para modificar la locación: NO, salida, siguiente o atrás */
  Bool finished; /*!< Variable booleane que indica con valores TRUE/ FALSE la finalización del programa*/
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
 * @brief It receives as arguments the current game session and the command that the user wants to execute. Then this command is set 
 * as the last command and then starts a switch. As long as the command is UNKNOWN it doesn't do anything. Wether it is EXIT
 * it doesn't do anything. If it is NEXT it changes the position to the south. Finally, provided the command is BACK it changes
 * the position to the north.
 * @author Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct that contains the information of the current game session
 * @param cmd the command which will be executed 
 * @return status==OK, if the function has worked correctly
 */
Status game_actions_update(Game *game, Command cmd);

/**
 * @brief 
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
 * @author Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct that contains the information of the current game session
 * @param cmd the command which will be executed 
 * @return NULL if the ID is not declared, or doesn't match with any of the ID of the spaces. 
 * @return game->spaces[i] if the spaces[i] ID match with the given ID.
 */
Space *game_get_space(Game *game, Id id);

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
 * @brief The function returns the value of the variable object_location of the current game
 * @author Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct that contains the information of the current game session 
 * @return game->object_location. Always return the value of the variable.
 */
Id game_get_object_location(Game *game);

/**
 * @brief It receives as arguments the current game session and sets the value of the 
 * variable object_location with the given ID.
 * @author Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct that contains the information of the current game session
 * @param id is the id of the position of the space in which we want the object to be moved.
 * @return status==ERROR, if the ID is not declared.
 * @return status==OK, if the ID has been set correctly.
 */
Status game_set_object_location(Game *game, Id id);

/**
 * @brief The function returns the last command executed of the current game
 * @author Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct that contains the information of the current game session 
 * @return $(CC) $(CFLAGS) -c $<
game->last_cmd. Always return the value of the variable.
 */
Command game_get_last_command(Game *game);

/**
 * @brief It receives as arguments the current game session and a command, which sets this command as the
 * last executed command#include "types.h"
 * @author Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct that contains the information of the current game session
 * @param command is the command that we want to set as the last command
 * @return status==OK, always return OK.
 */
Status game_set_last_command(Game *game, Command command);

/**
 * @brief The function returns TRUE if the game is finished and FALSE if not.
 * @author Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct that contains the information of the current game session 
 * @return game->finished. Always return the value of the variable.
 */
Bool game_get_finished(Game *game);

/**
 * @brief It receives as arguments the current game session and a boolean value, then sets the state
 * of the game if it's finished or not
 * @author Estefanía Fenoy Montes
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
 * @author Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct, Game and it uses it to add a new space in the array game->spaces
 * @param space a pointer to the space that will be added
 * @return status==OK, if the function has worked correctly
 * @return status==ERROR, if a mistken has happened
 */
Status game_add_space(Game *game, Space *space);

#endif
