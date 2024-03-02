/**
 * @brief It implements the game interface and all the associated calls
 * for each command
 *
 * @file game.c
 * @author Profesores PPROG, Estefanía Fenoy Montes
 * @version 06-02-2024
 * @copyright GNU Public License
 */

#include "game.h"
#include "game_reader.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
   Private functions
*/
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

/**
 * @brief It gives the ID of the position of the given parameter
 * @author Profesores PPROG, Estefanía Fenoy Montes
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
  /* Initializes all variables*/
  /* Loop to initialize all the spaces of game*/
  for (i = 0; i < MAX_SPACES; i++)
  {
    game->spaces[i] = NULL;
  }
  game->n_spaces = 0;
  /* Loop to initialize all the objects of game*/
  for (i = 0; i < MAX_OBJECTS; i++)
  {
    game->objects[i] = NULL;
  }
  game->n_objects = 0;
  /* Loop to initialize all the players of game*/
  for (i = 0; i < MAX_CHARACTERS; i++)
  {
    game->characters[i] = NULL;
  }
  game->n_characters = 0;

  game->player = NULL;
  game->last_cmd = NO_CMD;
  game->finished = FALSE;

  return OK;
}

/** game_create_from_file creates the game and loads the spaces from the file passed in the function as an argument
 */
Status game_create_from_file(Game *game, char *filename)
{
  int i;
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

  /* Creates the player, all the objects and the characters with the id 0 */
  game->player = player_create(ID_PLAYER);
  /*Puede que haya que verlo en función de lo que se haga en gamer_reader*/
  for(i=0; i<game->n_objects; i++){
    game->objects[i]= object_create(ID_OBJECT);
  }
  for(i=0; i<game->n_characters; i++){
    game->characters[i]= character_create(ID_CHARACTER);
  }

  /* The player, the objects, and the characters are located in the first space */
  game_set_player_location(game, game_get_space_id_at(game, 0));
  for(i=0; i<game->n_objects; i++){
    game_set_object_location(game, game_get_space_id_at(game, 0), object_get_id(game->objects[i]));
  }
  for(i=0; i<game->n_characters; i++){
    game_set_character_location(game, game_get_space_id_at(game, 0), character_get_id(game->objects[i]));
  }
  


  return OK;
}

/** game_destroy frees the spaces that have been created and set them as NULL and frees the object and player
 */
Status game_destroy(Game *game)
{
  int i = 0;
  /*Loop to free the spaces and set them as NULL*/
  for (i = 0; i < game->n_spaces; i++)
  {
    space_destroy(game->spaces[i]);
  }
  /*Destroys the object and the player from the game and set them as NULL*/
  for(i=0; i<game->n_objects; i++){
    object_destroy(game->objects[i]);
  }
  for(i=0; i<game->n_characters; i++){
    character_destroy(game->characters[i]);
  }
  player_destroy(game->player);

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

/*game_get_player_location returns the value of the variable player_location of the current game
*/
Id game_get_player_location(Game *game)
{
  return player_get_location(game->player);
}

/*game_set_player_location sets the value of the variable player_location with the given ID.
*/
Status game_set_player_location(Game *game, Id id)
{
  /* Error control */
  if (id == NO_ID)
  {
    return ERROR;
  }
  /* Error control */
  if (player_set_location(game->player, id) == ERROR)
  {
    return ERROR;
  }

  return OK;
}

/*game_get_object_location returns the value of the ID location of a given object in the current game
*/
Id game_get_object_location(Game *game, Id object)
{
  long i, j;
  if(object == NO_ID){
    return NO_ID;
  }
  for (i = 0; i < game->n_spaces; i++)
  {
    for(j=0; j<game->n_objects; j++){
      if(space_get_object_id(game->spaces[i], j)==object){
        return space_get_id(game->spaces[i]);
      }
    }
  }
  return NO_ID;
}

/*game_set_object_location sets the value of the variable object_location with the given ID in the given space.
*/
Status game_set_object_location(Game *game, Id space, Id object)
{
  int i;
  /* Error control */
  if (space == NO_ID || object == NO_ID)
  {
    return ERROR;
  }

    if(space_set_object(game_get_space(game, space), object)){
      return ERROR;
    }

  return OK;
}

/*game_get_character_location returns the ID of the space in which the given character is
*/
Id game_get_character_location(Game *game, Id character)
{
  long i;
  if(character == NO_ID){
    return NO_ID;
  }
  for (i = 0; i < game->n_spaces; i++)
  {
      if(space_get_character(game->spaces[i])==character){
        return space_get_id(game->spaces[i]);
      }
  }
  return NO_ID;
}
/*game_set_character_location sets the value of the variable character_location with the given ID in the given space.
*/
Status game_set_character_location(Game *game, Id space, Id character)
{
  int i;
  Space *s;
  /* Error control */
  if (space == NO_ID || character == NO_ID )
  {
    return ERROR;
  }
  s=game_get_space(game, space);
  /*Checks if in fact there is a character in the given space*/
  if(space_get_character(s)!=NO_ID){
    return ERROR;
  }
  if(space_set_character(s, character)==ERROR){
    return ERROR;
  }
  return OK;
}
/*game_get_last_command returns the last command executed
*/
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

  return OK;
}

/*game_print prints the current game session
*/
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
  printf("=> Objects:\n");
  for(i=0; i<game->n_objects; i++){
    object_print(game->objects[i]);
  }
  printf("=> Characters:\n");
  for(i=0; i<game->n_characters; i++){
    character_print(game->characters[i]);
  }

  
  printf("=> Player location: %ld\n", game_get_player_location(game));
}

/**
   Implementation of private functions
*/

/*game_add_space adds a new space in the game->spaces array 
*/
Status game_add_space(Game *game, Space *space)
{
  /*Error control*/
  if ((space == NULL) || (game->n_spaces >= MAX_SPACES))
  {
    return ERROR;
  }

  game->spaces[game->n_spaces] = space;
  game->n_spaces++;


  return OK;
}

/*game_get_space_id_at returns the id of a position
*/
Id game_get_space_id_at(Game *game, int position)
{
  /*Error control*/
  if (position < 0 || position >= game->n_spaces)
  {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}
