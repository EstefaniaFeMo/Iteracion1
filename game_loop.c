/**
 * @brief It defines the game loop
 *
 * @file game_loop.c
 * @author Profesores PPROG, Carmen Gómez Escobar
 * @version 3.5
 * @date 07-02-2024
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>

#include "command.h"
#include "game.h"
#include "game_actions.h"
#include "graphic_engine.h"

/**
 * @brief It starts the game, this function checks if the file has been read correctly and if the memory reserve of the pointer
 *  gengine has been done and if everything worked, the game starts.
 * @author Profesores PPROG, Carmen Gómez Escobar
 *
 * @param game a pointer to the struct called Game.
 * @param gengine a matix to the structure Graphic_engine.
 * @param file_name a pointer to the name of the file taht contains the spaces.
 * @return 1, if the file couldn't be open or if the dynamic memory reserved failed.
 * @return 0, if everythinf went fine.
 */
int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name);

/**
 * @brief It is the loop that makes the game keep going until the exit command is recived by the user input or tha function that
 *  indicates that the game is finished returns a TRUE value.
 * @author Profesores PPROG, Carmen Gómez Escobar
 *
 * @param game a type Game variable.
 * @param gengine a pointer to Graphic_engine.
 */
void game_loop_run(Game game, Graphic_engine *gengine);

/**
 * @brief It is the function that ends the game, calling to the functions that destroy the spaces and the structures.
 * @author Profesores PPROG, Carmen Gómez Escobar
 *
 * @param game a type Game variable.
 * @param gengine a pointer to Graphic_engine.
 */
void game_loop_cleanup(Game game, Graphic_engine *gengine);

/**
 * @brief It is the main function.
 */
int main(int argc, char *argv[])
{
  Game game;
  Graphic_engine *gengine;

  if (argc < 2)
  {
    fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]);
    return 1;
  }

  if (!game_loop_init(&game, &gengine, argv[1]))
  {
    game_loop_run(game, gengine);
    game_loop_cleanup(game, gengine);
  }

  return 0;
}

/** game_loop_init starts the game, this function checks if the file has been read correctly and if the memory reserve of the pointer
 *  gengine has been done and if everything worked, the game starts.
 */
int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name)
{
  if (game_create_from_file(game, file_name) == ERROR)
  {
    fprintf(stderr, "Error while initializing game.\n");
    return 1;
  }

  if ((*gengine = graphic_engine_create()) == NULL)
  {
    fprintf(stderr, "Error while initializing graphic engine.\n");
    game_destroy(game);
    return 1;
  }

  return 0;
}

/** game_loop_run is the loop that makes the game keep going until the exit command is recived by the user input or tha function that
 *  indicates that the game is finished returns a TRUE value.
 */
void game_loop_run(Game game, Graphic_engine *gengine)
{
  Command *command = NULL;

  while ((game_get_finished(&game) == FALSE))
  {
    graphic_engine_paint_game(gengine, &game);
    command = command_get_user_input();
    game_actions_update(&game, command);
  }
  graphic_engine_paint_game(gengine, &game);
  command_destroy(game_get_last_command(&game));
}

/**
 *  game_loop_cleanup ends the game, calling to the functions that destroy the spaces and the structures.
 */
void game_loop_cleanup(Game game, Graphic_engine *gengine)
{
  game_destroy(&game);
  graphic_engine_destroy(gengine);
}
