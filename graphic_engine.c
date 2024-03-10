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
#include <string.h>

#include "command.h"
#include "libscreen.h"
#include "space.h"
#include "types.h"

#define WIDTH_MAP 48
#define WIDTH_DES 29
#define WIDTH_BAN 23
#define HEIGHT_MAP 15
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
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, obj_loc = NO_ID, char_loc = NO_ID;
  int i, blankcounter, hp;
  Space *space_act = NULL;
  char *obj, *charac;
  char str[MAX_STRING];
  CommandNum last_cmd = UNKNOWN;
  extern char *cmd_to_str[N_CMD][N_CMDT];
  Set *set = NULL;
  

  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID)
  {

    space_act = game_get_space(game, id_act);
    id_back = space_get_north(space_act);
    id_next = space_get_south(space_act);

    set = space_get_objects(game_get_space(game, id_back));
    if (set != NULL)
      obj = graphic_engine_print_objects(set);
    else
      obj = "           ";

    charac= graphic_engine_print_characters(game, id_back);

    if (id_back != NO_ID)
    {
      if ((int)id_back >= 100)
      {
        sprintf(str, "  |      %s%2d|", charac, (int)id_back);
      }
      else
      {
        sprintf(str, "  |      %s %2d|", charac, (int)id_back);
      }
      screen_area_puts(ge->map, str);
      sprintf(str, "  |               |");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |%s|", obj);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +---------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "          ^");
      screen_area_puts(ge->map, str);
    }

    set = space_get_objects(game_get_space(game, id_act));
    if (set != NULL)
      obj = graphic_engine_print_objects(set);
    else
      obj = "           ";

    charac= graphic_engine_print_characters(game, id_act);

    if (id_act != NO_ID)
    {
      sprintf(str, "  +---------------+");
      screen_area_puts(ge->map, str);
      if ((int)id_act >= 100)
      {
        sprintf(str, "  | m0^  %s%2d|", charac, (int)id_act);
      }
      else
      {
        sprintf(str, "  | m0^  %s %2d|", charac, (int)id_act);
      }
      screen_area_puts(ge->map, str);
      sprintf(str, "  |               |");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |%s|", obj);
      
      screen_area_puts(ge->map, str);
      sprintf(str, "  +---------------+");
      screen_area_puts(ge->map, str);
    }

    set = space_get_objects(game_get_space(game, id_next));
    if (set != NULL)
      obj = graphic_engine_print_objects(set);
    else
      obj = "           ";

    charac= graphic_engine_print_characters(game, id_next);

    if (id_next != NO_ID)
    {
      sprintf(str, "          v");
      screen_area_puts(ge->map, str);
      sprintf(str, "  +---------------+");
      screen_area_puts(ge->map, str);
      if ((int)id_next >= 100)
      {
        sprintf(str, "  |      %s%2d|", charac, (int)id_next);
      }
      else
      {
        sprintf(str, "  |      %s %2d|", charac, (int)id_next);
      }
      screen_area_puts(ge->map, str);
      sprintf(str, "  |               |");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |%s|", obj);
      screen_area_puts(ge->map, str);
    }
  }

  /* Paint in the description area */
  screen_area_clear(ge->descript);

  sprintf(str, "  Objects:");
  screen_area_puts(ge->descript, str);

  for (i = blankcounter = 0; i < MAX_OBJECTS; i++)
  {
    if ((obj_loc = game_get_object_location(game, object_get_id(game->objects[i]))) != NO_ID)
    {
      blankcounter++;
      sprintf(str, "    O%d: %d", (int)object_get_id(game->objects[i]), (int)obj_loc);
      screen_area_puts(ge->descript, str);
    }
  }
  for(i = 0; i<MAX_OBJECTS - blankcounter; i++){
    screen_area_puts(ge->descript, " ");
  }

  sprintf(str, "  Characters:");
  screen_area_puts(ge->descript, str);

  for (i = blankcounter = 0; i < game->n_characters; i++)
  {
    if ((char_loc = game_get_character_location(game, character_get_id(game->characters[i]))) != NO_ID)
    {
      blankcounter++;
      hp = character_get_health(game->characters[i]);
      if (character_get_friendly(game->characters[i]) == TRUE)
      {
        if(hp <= 0){
          sprintf(str, "     ^0m  : %d (DEAD)", (int)char_loc);
        }else{
          sprintf(str, "     ^0m  : %d (%d)", (int)char_loc, hp);
        }
        screen_area_puts(ge->descript, str);
      }
      else if (character_get_friendly(game->characters[i]) == FALSE)
      {
        if(hp <= 0){
          sprintf(str, "     /\\oo/\\: %d (DEAD)", (int)char_loc);
        }else{
          sprintf(str, "     /\\oo/\\: %d (%d)", (int)char_loc, hp);
        }
        screen_area_puts(ge->descript, str);
      }
    }
  }

  for(i = 0; i<MAX_CHARACTERS - blankcounter; i++){
    screen_area_puts(ge->descript, " ");
  }
  screen_area_puts(ge->descript, " ");

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

  else if (player_get_object(game->player) == NO_ID)
  {
    sprintf(str, "  Player has no object");
    screen_area_puts(ge->descript, str);
  }

  screen_area_puts(ge->descript, " ");

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
  sprintf(str, "     next or n, back or b, take or t, drop or d, left o l, rigth o r, attack o a, chat o c, exit o e");
  screen_area_puts(ge->help, str);

  /* Paint in the feedback area */
  last_cmd = command_get_cmd(game_get_last_command(game));
  sprintf(str, " %s (%s): ", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
  if(last_cmd != UNKNOWN && last_cmd != NO_CMD){
    if(command_get_cmd_status(game_get_last_command(game))== ERROR){
      strcat(str, "ERROR");
    }else{
      strcat(str, "OK");
    }
  }
  screen_area_puts(ge->feedback, str);

  if(player_get_health(game_get_player(game)) == 0){
      sprintf(str, "GAME OVER");
      screen_area_puts(ge->feedback, str);
    }

  /* Dump to the terminal */
  screen_paint();
  if(game_get_finished(game) == FALSE)
    printf("prompt:> ");
}

char *graphic_engine_print_objects(Set *set)
{
  int i;
  int max;

  char *str = malloc(sizeof(char) * 100);
  char *all = malloc(sizeof(char) * 100);

  if (set == NULL)
  {
    return NULL;
  }
  str[0] = '\0';
  all[0] = '\0';
  max = SCREEN_LIMIT;

  if (set_get_n_ids(set) <= 0)
  {
    strcpy(all, "           ");
  }
  else
  {
    for (i = 0; i < set_get_n_ids(set); i++)
    {
      sprintf(str, "O%ld", (long)set_return_id(set, i));

      if (i == 0)
      {
        strcpy(all, str);
      }
      else
      {
        if (strlen(str) + 2 + strlen(all) <= max - 3)
        {
          strcat(all, ", ");
          strcat(all, str);
        }
        else
        {
          if (strlen(str) + 2 + strlen(all) <= max && i==(long)set_get_n_ids(set)-1 )
          {
            strcat(all, ", ");
            strcat(all, str);
          }
          else
          {
            if(strlen(str) + 2 + strlen(all) <= max && i<(long)set_get_n_ids(set)-1)
            strcat(all, "...");
          }
          break;
        }
      }
    }
  }

  for (i = strlen(all); i < max; i++)
  {
    strcat(all, " ");
  }
  free(str);
  return all;
}

char *graphic_engine_print_characters(Game *game, Id id_location)
{
  int i; 
  char *print;
  
  print = malloc(sizeof(char) * 100);

  if(print==NULL){
    return NULL;
  }

  if (game == NULL)
  {
    return NULL;
  }

  if (game->n_characters <=0)
  {
    strcpy(print, "      ");
  }
  else
  {
    for (i = 0; i <game->n_characters; i++)
    {
      if(game_get_character_location(game, character_get_id(game->characters[i]))== id_location){

        if(character_get_friendly(game->characters[i])==FALSE){
          strcpy(print, "/\\oo/\\");
        }else{
          strcpy(print, "^0m   ");
        }

        return print;
      }
      else {
        strcpy(print, "      ");
      }
    }
  }
  return print;
}
