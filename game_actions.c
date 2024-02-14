/**
 * @brief It implements the game update through user actions
 *
 * @file game_actions.c
 * @author Profesores PPROG, Estefanía Fenoy Montes, Carmen Gómez Escobar
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
 * @brief recives a pointer to Game in the case that the command that the function that calls this one is unknown.
 * @author Estefania Fenoy Montes, Carmen Gómez Escobar
 *
 * @param game a pointer to the struct called Game.
 */
void game_actions_unknown(Game *game);

/**
 * @brief recives a pointer to Game in the case that the command that the function that calls this one is exit.
 * @author Estefania Fenoy Montes, Carmen Gómez Escobar
 *
 * @param game a pointer to the struct called Game.
 */
void game_actions_exit(Game *game);

/**
 * @brief recives a pointer to Game in the case that the command that the function that calls this one is next,
 * and calls to a function that reads which is the sapce below and sends the player there.
 * @author Estefania Fenoy Montes, Carmen Gómez Escobar
 *
 * @param game a pointer to the struct called Game.
 */

void game_actions_next(Game *game);

/**
 * @brief recives a pointer to Game in the case that the command that the function that calls this one is back,
 * and calls to a function that reads which is the sapce above and sends the player there.
 * @author Estefania Fenoy Montes, Carmen Gómez Escobar
 *
 * @param game a pointer to the struct called Game.
 */

void game_actions_back(Game *game);

/**
 * @brief It recives a pointer to Game in the case that the command that the function that calls this one is take,
 * and checks if the player and the object are in the same location, and if they are, the player takes the object.
 * @author Estefania Fenoy Montes
 *
 * @param game a pointer to the struct called Game.
 */
void game_actions_take(Game *game);

/**
 * @brief In case there is an object that has been taken by the player, the object is dropped in the location of
 * the object.
 * @author Estefania Fenoy Montes
 *
 * @param game a pointer to the struct called Game which contains the current information of the game session.
 */
void game_actions_drop(Game *game);

/**
   Game actions implementation
*/

/**
 * @brief It recives the new command and for each type of command, calls a new function. At the end it will update the status
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

/**
   Calls implementation for each action
*/

/** game_actions_unknown recives a pointer to Game in the case that the command that the function that calls this one is unknown.
 */
void game_actions_unknown(Game *game) {}

/** game_actions_exit recives a pointer to Game in the case that the command that the function that calls this one is exit.
 */
void game_actions_exit(Game *game) {}

/** game_actions_next recives a pointer to Game in the case that the command that the function that calls this one is next,
 * and calls to a function that reads which is the sapce below and sends the player there.
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

/** game_actions_back recives a pointer to Game in the case that the command that the function that calls this one is back,
 * and calls to a function that reads which is the sapce above and sends the player there.
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

  current_id = space_get_north(game_get_space(game, space_id));
  if (current_id != NO_ID)
  {
    game_set_player_location(game, current_id);
  }

  return;
}

/** game_actions_take if there is an object in the same space of player, the player takes that object 
*/
void game_actions_take(Game *game)
{
  Id player_location = game_get_player_location(game);

  int position = game_get_space_position(game, player_location);

  Id object_id = object_get_id(game->object);
  if (object_id == NO_ID)
  {
    return;
  }

  if (player_location == game_get_object_location(game))
  {
    player_set_object(game->player, object_id);
    space_set_object(game->spaces[position], NO_ID);
  }

  return;
}
/** game_actions_drop if the player has an object drops it in the current location of the player
*/
void game_actions_drop(Game *game)
{
  Id player_location = game_get_player_location(game);
  int position = game_get_space_position(game, player_location);

  Id object_id = object_get_id(game->object);
  if (object_id == NO_ID)
  {
    return;
  }

  if (player_get_object(game->player) != NO_ID)
  {
    player_set_object(game->player, NO_ID);
    space_set_object(game->spaces[position], object_id);
  }
  return;
}
