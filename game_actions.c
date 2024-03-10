/**
 * @brief It implements the game update through user actions
 *
 * @file game_actions.c
 * @author Profesores PPROG, Carmen Gómez Escobar, Estefania Fenoy Montes
 * @version 3.5
 * @date 08-02-2024
 * @copyright GNU Public License
 */

#include "game_actions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "game.h"

/**
   Private functions
*/

/**
 * @brief recives a pointer to Game in the case that the command that the function that calls this one is unknown.
 * @author Carmen Gómez Escobar
 *
 * @param game a pointer to the struct called Game.
 * @return OK, if everything goes well or ERROR in case there was some mistake
 */
Status game_actions_unknown(Game *game);

/**
 * @brief recives a pointer to Game in the case that the command that the function that calls this one is exit.
 * @author Carmen Gómez Escobar
 *
 * @param game a pointer to the struct called Game.
 * @return OK, if everything goes well or ERROR in case there was some mistake
 */
Status game_actions_exit(Game *game);

/**
 * @brief recives a pointer to Game in the case that the command that the function that calls this one is next,
 * and calls to a function that reads which is the space below and sends the player there.
 * @author Carmen Gómez Escobar
 *
 * @param game a pointer to the struct called Game.
 * @return OK, if everything goes well or ERROR in case there was some mistake
 */

Status game_actions_next(Game *game);

/**
 * @brief recives a pointer to Game in the case that the command that the function that calls this one is back,
 * and calls to a function that reads which is the space above and sends the player there.
 * @author Carmen Gómez Escobar
 *
 * @param game a pointer to the struct called Game.
 * @return OK, if everything goes well or ERROR in case there was some mistake
 */

Status game_actions_back(Game *game);

/**
 * @brief It recives a pointer to Game in the case that the command that the function that calls this one is take,
 * and checks if the player and the object are in the same location, and if they are, the player takes the object.
 * @author Estefania Fenoy Montes
 *
 * @param game a pointer to the struct called Game.
 * @param object an identifier of the object that we want to be taken
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_actions_take(Game *game, Id object);

/**
 * @brief In case there is an object that has been taken by the player, the object is dropped in the location of
 * the object.
 * @author Estefania Fenoy Montes
 *
 * @param game a pointer to the struct called Game which contains the current information of the game session.
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_actions_drop(Game *game);

/**
 * @brief recives a pointer to Game in the case that the command that the function that calls this one is left,
 * and calls to a function that reads which is the space located at the left and sends the player there.
 * @author Carmen Gómez Escobar
 *
 * @param game a pointer to the struct called Game.
 * @return OK, if everything goes well or ERROR in case there was some mistake
 */

Status game_actions_left(Game *game);

/**
 * @brief recives a pointer to Game in the case that the command that the function that calls this one is rigth,
 * and calls to a function that reads which is the space located at the rigth and sends the player there.
 * @author Carmen Gómez Escobar
 *
 * @param game a pointer to the struct called Game.
 * @return OK, if everything goes well or ERROR in case there was some mistake
 */

Status game_actions_rigth(Game *game);

/**
 * @brief recives a pointer to Game in the case that the command that the function that calls this one is attack,
 * and starts a figth with the character if it is not friendly.
 * @author Carmen Gómez Escobar
 *
 * @param game a pointer to the struct called Game.
 * @return OK, if everything goes well or ERROR in case there was some mistake
 */

Status game_actions_attack(Game *game);

/**
 * @brief In case that the character which is in the same space as the player is friendly this functions shows the message of this character.
 * @author Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct called Game.
 * @return OK, if everything goes well or ERROR in case there was some mistake
 */

Status game_actions_chat(Game *game);

/**
   Game actions implementation
*/

/**
 * @brief It recives the new command and for each type of command, calls a new function. At the end it will update the status
 */
Status game_actions_update(Game *game, Command *command)
{
  int i;
  CommandNum cmd = command_get_cmd(command);
  char *args = command_get_args(command);
  char *token = NULL;
  Bool take_arg;
  Status cmd_status;

  switch (cmd)
  {
  case UNKNOWN:
    game_actions_unknown(game);
    break;

  case EXIT:
    game_set_finished(game, TRUE);
    cmd_status = game_actions_exit(game);
    break;

  case NEXT:
    cmd_status = game_actions_next(game);
    break;

  case BACK:
    cmd_status = game_actions_back(game);
    break;

  case DROP:
    cmd_status = game_actions_drop(game);
    break;

  case TAKE:
    if (args[0] == 'O')
    {
      token = args + 1;
      i = 0;

      take_arg = TRUE;
      while (token[i] != '\0')
      {
        if (token[i] < '0' || token[i] > '9')
        {
          take_arg = FALSE;
          break;
        }
        i++;
      }
      if (take_arg == TRUE)
      {
        cmd_status = game_actions_take(game, atol(token));
      }
    }
    else
    {
      cmd_status = ERROR;
    }
    break;

  case LEFT:
    cmd_status = game_actions_left(game);
    break;

  case RIGTH:
    cmd_status = game_actions_rigth(game);
    break;

  case ATTACK:
    cmd_status = game_actions_attack(game);
    break;

  case CHAT:
    cmd_status = game_actions_chat(game);
    break;

  default:
    break;
  }
  command_set_cmd_status(command, cmd_status);
  game_set_last_command(game, command);
  return OK;
}

/**
   Calls implementation for each action
*/

/** game_actions_unknown recives a pointer to Game in the case that the command that the function that calls this one is unknown.
 */
Status game_actions_unknown(Game *game) { return OK; }

/** game_actions_exit recives a pointer to Game in the case that the command that the function that calls this one is exit.
 */
Status game_actions_exit(Game *game) { return OK; }

/** game_actions_next recives a pointer to Game in the case that the command that the function that calls this one is next,
 * and calls to a function that reads which is the sapce below and sends the player there.
 */
Status game_actions_next(Game *game)
{
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID)
  {
    return ERROR;
  }

  current_id = space_get_south(game_get_space(game, space_id));
  if (current_id == NO_ID)
  {
    return ERROR;
  }
    game_set_player_location(game, current_id);

  return OK;
}

/** game_actions_back recives a pointer to Game in the case that the command that the function that calls this one is back,
 * and calls to a function that reads which is the sapce above and sends the player there.
 */

Status game_actions_back(Game *game)
{
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id)
  {
    return ERROR;
  }
  current_id = space_get_north(game_get_space(game, space_id));
  if (current_id == NO_ID)
  {
    return ERROR;
  }
    game_set_player_location(game, current_id);
  return OK;
}

/** game_actions_take if there is an object in the same space of player, the player takes that object */
Status game_actions_take(Game *game, Id object)
{
  Space *s;
  Id player_location;

  if (object == NO_ID)
  {
    return ERROR;
  }
  
  if(player_get_object(game->player) != NO_ID){
    return ERROR;
  }

  player_location = game_get_player_location(game);
  s = game_get_space(game, player_location);

  if (space_check_object(s, object) == FALSE)
  {
    return ERROR;
  }

  player_set_object(game->player, object);
  space_del_object(s, object);

  return OK;
}
/** game_actions_drop if the player has an object drops it in the current location of the playe*/
Status game_actions_drop(Game *game)
{
  Id player_location = game_get_player_location(game);
  Id object = player_get_object(game->player);
  if (object == NO_ID)
  {
    return ERROR;
  }
  if (space_set_object(game_get_space(game, player_location), object) == ERROR)
  {
    return ERROR;
  }
  player_set_object(game->player, NO_ID);

  return OK;
}
/** game_actions_left recives a pointer to Game in the case that the command that the function that calls this one is left,
 * and calls to a function that reads which is the space located at the left and sends the player there.*/
Status game_actions_left(Game *game)
{
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id)
  {
    return ERROR;
  }

  current_id = space_get_west(game_get_space(game, space_id));
  if (current_id != NO_ID)
  {
    game_set_player_location(game, current_id);
  }
  else if(current_id==NO_ID){
    return ERROR;
  }

  return OK;
}

/** game_actions_rigth recives a pointer to Game in the case that the command that the function that calls this one is rigth,
 * and calls to a function that reads which is the space located at the rigth and sends the player there.*/
Status game_actions_rigth(Game *game)
{
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id)
  {
    return ERROR;
  }

  current_id = space_get_east(game_get_space(game, space_id));
  if (current_id != NO_ID)
  {
    game_set_player_location(game, current_id);
  }
  else if(current_id==NO_ID){
    return ERROR;
  }

  return OK;
}

/** game_actions_attack recives a pointer to Game in the case that the command that the function that calls this one is attcak,
 * and starts a figth with the character if it is not friendly.*/
Status game_actions_attack(Game *game)
{
  Id player_location = game_get_player_location(game);
  Character *c = NULL;
  int num= 0;

  srand(time (NULL));

  if (space_get_character(game_get_space(game, player_location)) == NO_ID)
  {
    return ERROR;
  }
  
  c = game_get_character(game, space_get_character(game_get_space(game, player_location)));
  
  if (character_get_friendly(c) == TRUE || character_get_health(c) <= 0)
  {
    return ERROR;
  }

  if (game_get_character_location(game, space_get_character(game_get_space(game, player_location))) == player_location){

    if(character_get_friendly(c) == FALSE){

      num= rand() % (MAX_RAND - MIN_RAND + 1) + MIN_RAND;
      if (num < 1)
      {
        player_set_health(game->player, player_get_health(game->player) - 1);
      }
      else if (num >= 1)
      {
        character_set_health(c, character_get_health(c) - 1);
      }
    }
  }

  if(player_get_health(game->player) <= 0)
  {
    game_set_finished(game, TRUE);
  }


  return OK;
}

/** game_actions_chat in case that the command executed is chat, it tests if the character which is in the same space of the player is friendly and if it is,
 * this character says its message
 */
Status game_actions_chat(Game *game)
{
  Id player_location = game_get_player_location(game);
  Character *c = NULL;
  if (space_get_character(game_get_space(game, player_location)) == NO_ID)
  {
    return ERROR;
  }
  c = game_get_character(game, space_get_character(game_get_space(game, player_location)));
  if (character_get_friendly(c) == FALSE)
  {
    return ERROR;
  }
  return OK;
}
