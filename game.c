/**
 * @brief It implements the game interface and all the associated calls
 * for each command
 *
 * @file game.c
 * @author Estefanía Fenoy Montes, Carmen Gómez Escobar
 * @version 06-02-2024
 * @copyright GNU Public License
 */

#include "game.h"
#include "object.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
   Private functions
*/
/**
 * @brief It adds a new space in the last position available of the array and increases the number of spaces by one
 * @author Estefanía Fenoy Montes, Carmen Gómez Escobar
 *
 * @param game a pointer to the struct, Game and it uses it to add a new space in the array game->spaces
 * @param space a pointer to the space that will be added
 * @return status==OK, if the function has worked correctly
 * @return status==ERROR, if a mistken has happened
 */
Status game_add_space(Game *game, Space *space);

/**
 * @brief It gives the ID of the position of the given parameter
 * @author Estefanía Fenoy Montes, Carmen Gómez Escobar
 *
 * @param game a pointer to the struct, Game and it uses it to get access to the game->spaces IDs
 * @param position the position we want to get the id
 * @return the ID of the space at the position given.
 */
Id game_get_space_id_at(Game *game, int position);

/**
   Game interface implementation
*/

/** game_create creates the game and initializes it
 */
Status game_create(Game *game)
{
  int i;
  /* Loop to initialize all the spaces of game*/
  for (i = 0; i < MAX_SPACES; i++)
  {
    game->spaces[i] = NULL;
  }

  /*The information of the struct game is initialized*/
  game->n_spaces = 0;
  game->player = NULL;
  game->object = NULL;
  game->last_cmd = NO_CMD;
  game->finished = FALSE;
  /*Indicate that the function has worked correctly*/
  return OK;
}

/** game_create_from_file creates the game and loads the spaces from the file passed in the function as an
 * argument
 */
Status game_create_from_file(Game *game, char *filename)
{
  /* Error control */
  if (game_create(game) == ERROR)
  {
    return ERROR;
  }
  /* Error control */
  if (game_reader_load_spaces(game, filename) == ERROR)
  {
    return ERROR;
  }

  /* The player and the object are located in the first space */
  game_set_player_location(game, game_get_space_id_at(game, 0));
  game_set_object_location(game, game_get_space_id_at(game, 0), object_get_id(game->object));

  /*Indicate that the function has worked correctly*/
  return OK;
}

/** game_destroy frees the spaces that have been created and set them as NULL
 */
Status game_destroy(Game *game)
{
  int i = 0;
  /*Loop to free the spaces and set them as NULL*/
  for (i = 0; i < game->n_spaces; i++)
  {
    space_destroy(game->spaces[i]);
  }

  /*Indicate that the function has worked correctly*/
  return OK;
}

/** game_get_space returns the space of the given ID
 */
Space *game_get_space(Game *game, Id id)
{
  int i = 0;
  /* Error control */
  if (id == NO_ID)
  {
    return NULL;
  }
  /*Loop to check the space which matches with the given ID*/
  for (i = 0; i < game->n_spaces; i++)
  {
    if (id == space_get_id(game->spaces[i]))
    {
      return game->spaces[i];
    }
  }
  /*If the ID is not equal to any space, return NULL*/
  return NULL;
}
/*game_get_player_location returns the value of the variable player_location of the current game*/
Id game_get_player_location(Game *game)
{
  Id player_id;

  player_id = player_get_location(game->player);

  return player_id;
}

/*game_set_player_location sets the value of the variable player_location with the given ID.*/
Status game_set_player_location(Game *game, Id id)
{
  /* Error control */
  if (id == NO_ID)
  {
    return ERROR;
  }
  /* Error control */
  if(player_get_location(game->player)==ERROR){
    return ERROR;
  }

  /*Indicate that the function has worked correctly*/
  return OK;
}

/*game_get_object_location returns the value of the ID location of the object in the current game*/
Id game_get_object_location(Game *game) {
  long i;
  for(i=0; i<game->n_spaces; i++){
    if(space_get_object(game->spaces[i])!=NO_ID){
      return space_get_id(game->spaces[i]);
    }
  }
   return NO_ID;
}

/*game_set_object_location sets the value of the variable object_location with the given ID.*/
Status game_set_object_location(Game *game, Id space_id, Id object_id)
{
  /* Error control */
  if (space_id == NO_ID)
  {
    return ERROR;
  }
  int i;
  for(i=0; i<game->n_spaces; i++){
    if(space_get_id(game->spaces[i])==space_id){
      space_set_object(game->spaces[i], object_id);
  /*Indicate that the function has worked correctly*/      
      return OK;
    }
  }

  return ERROR;
}
/*game_get_last_command returns the last command executed*/
Command game_get_last_command(Game *game) { return game->last_cmd; }

/*game_set_last_command sets the command given as the last one*/
Status game_set_last_command(Game *game, Command command)
{
  game->last_cmd = command;
  /*Indicate that the function has worked correctly*/
  return OK;
}

/*game_get_finished returns if the game has finished or not*/
Bool game_get_finished(Game *game) { return game->finished; }

/*game_set_finished sets the state of the game as finished*/
Status game_set_finished(Game *game, Bool finished)
{
  game->finished = finished;
  /*Indicate that the function has worked correctly*/
  return OK;
}

/*game_print prints the current game session*/
void game_print(Game *game)
{
  int i = 0;
  /*Print a header*/
  printf("\n\n-------------\n\n");

  /*Print all the spaces with a loop*/
  printf("=> Spaces: \n");
  for (i = 0; i < game->n_spaces; i++)
  {
    space_print(game->spaces[i]);
  }
  /*Print the object location*/
  printf("=> Object location: %d\n", (int)game_get_object_location(game));
  /*Print the player location*/
  printf("=> Player location: %d\n", (int)player_get_location(game->player));
}

/**
   Implementation of private functions
*/
/*game_add_space adds a new space in the game->spaces array */
Status game_add_space(Game *game, Space *space)
{
  /*Error control*/
  if ((space == NULL) || (game->n_spaces >= MAX_SPACES))
  {
    return ERROR;
  }
  /*Add the new space in the last position of the array*/
  game->spaces[game->n_spaces] = space;
  /*Increase by 1 the number of spaces*/
  game->n_spaces++;

  /*Indicate that the function has worked correctly*/
  return OK;
}

/*game_get_space_id_at returns the id of a position*/
Id game_get_space_id_at(Game *game, int position)
{
  /*Error control*/
  if (position < 0 || position >= game->n_spaces)
  {
    return NO_ID;
  }
  /*Call the getter of id for the given position*/
  return space_get_id(game->spaces[position]);
}
