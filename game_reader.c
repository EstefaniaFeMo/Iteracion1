/**
 * @brief It implements the game interface and all the associated calls
 * for each command in order to read the possible spaces and elements of the game
 *
 * @file game_reader.c
 * @author Profesores PPROG, Estefanía Fenoy Montes
 * @version 3.5
 * @date 04-02-2024
 * @copyright GNU Public License
 */
#include "game_reader.h"
#include "space.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*game_reader_load_spaces downloads the spaces defined in a file
*/
Status game_reader_load_spaces(Game *game, char *filename)
{
  /*Initialization of the variables*/
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Space *space = NULL;
  Status status = OK;
  /* Error control of the filename */
  if (!filename)
  {
    return ERROR;
  }
  /*Open the file*/
  file = fopen(filename, "r");
  /*Error control*/
  if (file == NULL)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#s:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      west = atol(toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west);
#endif
      /*Create a space with the constructor with the given id */
      space = space_create(id);
      if (space != NULL)
      {
        /*Set the values saved on the variables before*/
        space_set_name(space, name);
        space_set_north(space, north);
        space_set_east(space, east);
        space_set_south(space, south);
        space_set_west(space, west);
        game_add_space(game, space);
      }
    }
  }

  /* Error control of the file */
  if (ferror(file))
  {
    status = ERROR;
  }
  /*Close the file*/
  fclose(file);
  /*Indicate that the function has worked correctly with OK or if there has been a problem
  returning ERROR*/
  return status;
}
