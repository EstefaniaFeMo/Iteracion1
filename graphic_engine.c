/**
 * @brief It defines a textual graphic engine
 *
 * @file graphic_engine.c
 * @author Profesores PPROG, Carmen Gómez Escobar
 * @version 3.5
 * @date 07-02-2024
 * @copyright GNU Public License
 */

#include "graphic_engine.h"

#include <stdio.h>
#include <stdlib.h>

#include "command.h"
#include "libscreen.h"
#include "space.h"
#include "types.h"

#define WIDTH_MAP 48
#define WIDTH_DES 29
#define WIDTH_BAN 23
#define HEIGHT_MAP 13
#define HEIGHT_BAN 1
#define HEIGHT_HLP 2
#define HEIGHT_FDB 3

/**
 * @brief Graphic_engine
 *
 * This struct defines five pointers which type is Area, resulting the five posible areas of the game: the map, the description, the banner, a field fot help
 * and the feedback
 */
struct _Graphic_engine
{
  Area *map, *descript, *banner, *help, *feedback;
};

/** graphic_engine_create reserves di¡ynamic memeory for the structure called Graphic_engine if it hasn't been previously done
 *  it also reserves dynamic memory for the variables contained in it such as map, descript, banner, help and feedback
 */
Graphic_engine *graphic_engine_create()
{
  static Graphic_engine *ge = NULL;

  if (ge)
  {
    return ge;
  }

  screen_init(HEIGHT_MAP + HEIGHT_BAN + HEIGHT_HLP + HEIGHT_FDB + 4, WIDTH_MAP + WIDTH_DES + 3);
  ge = (Graphic_engine *)malloc(sizeof(Graphic_engine));
  if (ge == NULL)
  {
    return NULL;
  }

  ge->map = screen_area_init(1, 1, WIDTH_MAP, HEIGHT_MAP);
  ge->descript = screen_area_init(WIDTH_MAP + 2, 1, WIDTH_DES, HEIGHT_MAP);
  ge->banner = screen_area_init((int)((WIDTH_MAP + WIDTH_DES + 1 - WIDTH_BAN) / 2), HEIGHT_MAP + 2, WIDTH_BAN, HEIGHT_BAN);
  ge->help = screen_area_init(1, HEIGHT_MAP + HEIGHT_BAN + 2, WIDTH_MAP + WIDTH_DES + 1, HEIGHT_HLP);
  ge->feedback = screen_area_init(1, HEIGHT_MAP + HEIGHT_BAN + HEIGHT_HLP + 3, WIDTH_MAP + WIDTH_DES + 1, HEIGHT_FDB);

  return ge;
}

/** graphic_engine_destroy checks if the dynamic memory reserve has been done correctly, and if not, destroys al the areas
 *  and frees the memory of the structure
 */
void graphic_engine_destroy(Graphic_engine *ge)
{
  if (!ge)
    return;

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);

  screen_destroy();
  free(ge);
}

/** graphic_engine_paint_game paints all the areas after having cleared the area and having checked if the player was
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game)
{
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, obj_loc = NO_ID;
  Space *space_act = NULL;
  char obj = '\0';
  char str[MAX_STRING];
  CommandNum last_cmd = UNKNOWN;
  extern char *cmd_to_str[N_CMD][N_CMDT];

  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID)
  {
    space_act = game_get_space(game, id_act);
    id_back = space_get_north(space_act);
    id_next = space_get_south(space_act);

    if (game_get_object_location(game) == id_back)
      obj = 'O' +;
    else
      obj = ' ';

    if (id_back != NO_ID)
    {
      if((int)id_back >= 100){
        sprintf(str, "  |        %2d|", (int)id_back);
      }else{
        sprintf(str, "  |         %2d|", (int)id_back);
      }
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %c     |", obj);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "        ^");
      screen_area_puts(ge->map, str);
    }

    if (game_get_object_location(game) == id_act)
      obj = '*';
    else
      obj = ' ';

    if (id_act != NO_ID)
    {
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      if((int)id_act >= 100){
        sprintf(str, "  | m0^    %2d|", (int)id_act);
      }else{
        sprintf(str, "  | m0^     %2d|", (int)id_act);
      }
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %c     |", obj);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
    }

    if (game_get_object_location(game) == id_next)
      obj = '*';
    else
      obj = ' ';

    if (id_next != NO_ID)
    {
      sprintf(str, "        v");
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      if((int)id_next >= 100){
        sprintf(str, "  |        %2d|", (int)id_next);
      }else{
        sprintf(str, "  |         %2d|", (int)id_next);
      }
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %c     |", obj);
      screen_area_puts(ge->map, str);
    }
  }

  /* Paint in the description area */
  screen_area_clear(ge->descript);


  if ((id_act = game_get_player_location(game)) != NO_ID)
  {
    sprintf(str, "  Player: %d (%d)", (int)id_act, player_get_health(game->player));
    screen_area_puts(ge->descript, str);
  }

  if (player_get_object(game->player) != NO_ID)
  {
    sprintf(str, "  Player object: %d", (int)player_get_object(game->player)); /*In futures iterations perhaps there'll be changes to have the ID of the object since there'd be more objects*/
    screen_area_puts(ge->descript, str);
  }

  else if(player_get_object(game->player) == NO_ID){
    sprintf(str, "  Player has no object");
    screen_area_puts(ge->descript, str);
  }

  if ((obj_loc = game_get_object_location(game)) != NO_ID)
  {
    sprintf(str, "  Object location:%d", (int)obj_loc);
    screen_area_puts(ge->descript, str);
  }

 if (command_get_cmd(game_get_last_command(game)) == CHAT && command_get_cmd_status(game_get_last_command(game)) == OK)
  {
    sprintf(str, "  Message: %s", character_get_message(game_get_character(game, space_get_character(space_act)))); /*In futures iterations perhaps there'll be changes to have the ID of the object since there'd be more objects*/
    screen_area_puts(ge->descript, str);
  }

  /* Paint in the banner area */
  screen_area_puts(ge->banner, "    The anthill game ");

  /* Paint in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "     next or n, back or b, take or t, drop or d, exit or e, left o l, rigth o r, attak o a, chat o c");
  screen_area_puts(ge->help, str);

  /* Paint in the feedback area */
  last_cmd = command_get_cmd(game_get_last_command(game));
  sprintf(str, " %s (%s)", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);

  if(command_get_cmd_status(game_get_last_command(game))==ERROR){
    sprintf(str, "ERROR");
  }
  else if(command_get_cmd_status(game_get_last_command(game))==OK){
    sprintf(str, "OK");
  }
  screen_area_puts(ge->feedback, str);

  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}
