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
 * @brief It recives a pointer to Game in the case that the command that the function that calls this one is unknown,
 * and stops the game. 
 * @author Carmen Gómez Escobar.
 *
 * @param game a pointer to the struct called Game and uses it as an argument in the called functions.
 */
void game_actions_unknown(Game *game);

/**
 * @brief It recives a pointer to Game in the case that the command that the function that calls this one is exit,
 * and exits the game. 
 * @author Carmen Gómez Escobar.
 *
 * @param game a pointer to the struct called Game and uses it as an argument in the called functions.
 */
void game_actions_exit(Game *game);

/**
 * @brief It recives a pointer to Game in the case that the command that the function that calls this one is next,
 * and calls to a function that reads which is the sapce below and sends the player there. 
 * @author Carmen Gómez Escobar.
 *
 * @param game a pointer to the struct called Game and uses it as an argument in the called functions.
 */
void game_actions_next(Game *game);

/**
 * @brief It recives a pointer to Game in the case that the command that the function that calls this one is back,
 * and calls to a function that reads which is the sapce above and sends the player there. 
 * @author Carmen Gómez Escobar.
 *
 * @param game a pointer to the struct called Game and uses it as an argument in the called functions.
 */
void game_actions_back(Game *game);

/**
 * @brief It recives a pointer to Game in the case that the command that the function that calls this one is take,
 * and checks if the player and the object are in the same location, and if they are, the player takes the object.
 * @author Carmen Gómez Escobar.
 *
 * @param game a pointer to the struct called Game and uses it as an argument in the called functions.
 */
void game_actions_take(Game *game);

/**
 * @brief It recives a pointer to Game in the case that the command that the function that calls this one is drop,
 * and checks if the player has an object and drops it. 
 * @author Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct called Game and uses it as an argument in the called functions.
 */
void game_actions_drop(Game *game);

/**
   Game actions implementation
*/

/** game_actions_update recives the new command and for each type of command, calls a new function. At the end it
 * will update the status. */
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

/**
   Calls implementation for each action
*/

/** game_actions_unknown recives a pointer to Game in the case that the command that the function that calls this one is unknown. */
void game_actions_unknown(Game *game) {}

/** game_actions_exit recives a pointer to Game in the case that the command that the function that calls this one is exit.
 */
void game_actions_exit(Game *game) {}

/** game_actions_next recives a pointer to Game in the case that the command that the function that calls this one is next,
 * and calls to a function that reads which is the sapce below and sends the player there. */
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

/** game_actions_back recives a pointer to Game in the case that the command that the function that calls this one is back,
 * and calls to a function that reads which is the sapce above and sends the player there. */
void game_actions_back(Game *game)
{
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id)
  {
    return;
  }

  current_id = space_get_north(game_get_space(game, space_id));
  if (current_id != NO_ID)
  {
    game_set_player_location(game, current_id);
  }

  return;
}

/** game_actions_take ecives a pointer to Game in the case that the command that the function that calls this one is take,
 * and checks if the player and the object are in the same location, and if they are, the player takes the object.*/
void game_actions_take(Game *game)
{
  if(game_get_player_location(game->player)==game_get_object_location(game->object)){
    player_get_object(game->player);
  }

  return;
}

/** game_actions_drop if the player has an object drops it in the current location of the playe*/
void game_actions_drop(Game *game)
{
  if(player_get_object(game->player)){
    game_set_object_location(game, game_get_player_location(game));
  }

  return;
}
