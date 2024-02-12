/**
 * @brief It implements the game update through user actions
 *
 * @file game_actions.c
 * @author Estefanía Fenoy Montes, Carmen Gómez Escobar
 * @version 3.5
 * @date 26-01-2024
 * @copyright GNU Public License
 */

#include "game_actions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"

/**
   Private functions
*/

/**
 * @brief Carga los espacios definidos en un fichero
 * @author Estefania Fenoy Montes, Carmen Gómez Escobar
 *
 * @param game un puntero a una estructura, Game y la utiliza para definir el espacio que manda a la función que lo añade
 * @param filename un puntero al fichero
 * @return status= OK si todo ha funcionado correctamente
 * @return status= ERROR si se ha producido algún fallo
 */

void game_actions_unknown(Game *game);

/**
 * @brief Carga los espacios definidos en un fichero
 * @author Estefania Fenoy Montes, Carmen Gómez Escobar
 *
 * @param game un puntero a una estructura, Game y la utiliza para definir el espacio que manda a la función que lo añade
 * @param filename un puntero al fichero
 * @return status= OK si todo ha funcionado correctamente
 * @return status= ERROR si se ha producido algún fallo
 */

void game_actions_exit(Game *game);

/**
 * @brief Carga los espacios definidos en un fichero
 * @author Estefania Fenoy Montes, Carmen Gómez Escobar
 *
 * @param game un puntero a una estructura, Game y la utiliza para definir el espacio que manda a la función que lo añade
 * @param filename un puntero al fichero
 * @return status= OK si todo ha funcionado correctamente
 * @return status= ERROR si se ha producido algún fallo
 */

void game_actions_next(Game *game);

/**
 * @brief Carga los espacios definidos en un fichero
 * @author Estefania Fenoy Montes, Carmen Gómez Escobar
 *
 * @param game un puntero a una estructura, Game y la utiliza para definir el espacio que manda a la función que lo añade
 * @param filename un puntero al fichero
 * @return status= OK si todo ha funcionado correctamente
 * @return status= ERROR si se ha producido algún fallo
 */

void game_actions_back(Game *game);

/**
 * @brief It recives a pointer to Game in the case that the command that the function that calls this one is take,
 * and checks if the player and the object are in the same location, and if they are, the player takes the object.
 * @author Estefania Fenoy Montes, Carmen Gómez Escobar
 *
 * @param game a pointer to the struct called Game.
 */
void game_actions_take(Game *game);

/**
 * @brief It recives a pointer to Game in the case that the command that the function that calls this one is drop,
 * the function makes the player drop the object.
 * @author Estefania Fenoy Montes, Carmen Gómez Escobar
 *
 * @param game a pointer to the struct called Game.
 */
void game_actions_drop(Game *game);

/**
   Game actions implementation
*/

/**
 * @brief It recives the new command and for each type of command, calls a new function. At the end it
 * will update the status
 * @author Estefania Fenoy Montes, Carmen Gómez Escobar.
 *
 * @param game a pointer to the struct called Game and uses it as an argument in the called functions.
 * @param cmd a variable type Command with the command.
 * @return Status= OK sif everything has worked out
 */
Status game_actions_update(Game *game, Command cmd)
{
  game_set_last_command(game, cmd);

  switch (cmd)
  {
  case UNKNOWN:
    game_actions_unknown(game);
    break;

  case EXIT:
    game_actions_exit(game);
    break;

  case NEXT:
    game_actions_next(game);
    break;

  case BACK:
    game_actions_back(game);
    break;

   case DROP:
    game_actions_drop(game);
    break;

  case TAKE:
    game_actions_take(game);
    break;

  default:
    break;
  }

  return OK;
}

  default:
    break;
  }

  return OK;
}

/**
   Calls implementation for each action
*/

/**
 * @brief It recives a pointer to Game in the case that the command that the function that calls this one is unknown.
 * @author Estefania Fenoy Montes, Carmen Gómez Escobar
 *
 * @param game a pointer to the struct called Game.
 */
void game_actions_unknown(Game *game) {}

/**
 * @brief It recives a pointer to Game in the case that the command that the function that calls this one is exit.
 * @author Estefania Fenoy Montes, Carmen Gómez Escobar
 *
 * @param game a pointer to the struct called Game.
 */
void game_actions_exit(Game *game) {}

/**
 * @brief It recives a pointer to Game in the case that the command that the function that calls this one is next,
 * and calls to a function that reads which is the sapce below and sends the player there.
 * @author Estefania Fenoy Montes, Carmen Gómez Escobar
 *
 * @param game a pointer to the struct called Game.
 */
void game_actions_next(Game *game)
{
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID)
  {
    return;
  }

  current_id = space_get_south(game_get_space(game, space_id));
  if (current_id != NO_ID)
  {
    game_set_player_location(game, current_id);
  }

  return;
}

/**
 * @brief It recives a pointer to Game in the case that the command that the function that calls this one is back,
 * and calls to a function that reads which is the sapce above and sends the player there.
 * @author Estefania Fenoy Montes, Carmen Gómez Escobar
 *
 * @param game a pointer to the struct called Game.
 */
void game_actions_back(Game *game)
{
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id)
  {
    return;
  }

  current_id = space_get_north(game_get_space(game, game_get_player_location(game)));
  if (current_id != NO_ID)
  {
    game_set_player_location(game, current_id);
  }

  return;
}

/**
 * @brief It recives a pointer to Game in the case that the command that the function that calls this one is take,
 * and checks if the player and the object are in the same location, and if they are, the player takes the object.
 * @author Estefania Fenoy Montes, Carmen Gómez Escobar
 *
 * @param game a pointer to the struct called Game.
 */
void game_actions_take(Game *game)
{

  return;
}
