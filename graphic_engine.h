/**
 * @brief It defines the textual graphic engine interface
 *
 * @file graphic_engine.h
 * @author Profesores PPROG, Carmen Gómez Escobar, Estefanía Fenoy Montes
 * @version 3.5
 * @date 07-02-2024
 * @copyright GNU Public License
 */

#ifndef GRAPHIC_ENGINE_H
#define GRAPHIC_ENGINE_H

#include "game.h"
#include "set.h"

#define MAX_STRING 255 /*!<Indicates the maximum number of characters*/

#define SCREEN_LIMIT 15 /*!<Indicates the maximum number of chars that fits in the area */

#define SCREEN_CENTER 5 /*!<Indicates the number of lines in blank to centralise the actual position cage */

#define THREE_DIGITS 100 /*!<Indicates the first number of 3 digits*/

#define MAX_OBJECTS_DESC 5 /*!<Indicates the number of objects that can be in the description*/
/**
 * @brief Graphic_engine
 *
 * This struct defines five pointers which type is Area, resulting the five posible areas of the game
 */
typedef struct _Graphic_engine Graphic_engine;

/**
 * @brief It reserves di¡ynamic memeory for the structure called Graphic_engine if it hasn't been previously done
 *  it also reserves dynamic memory for the variables contained in it such as map, descript, banner, help and feedback
 * @author Carmen Gómez Escobar
 *
 * @return ge a structure and it's members
 */
Graphic_engine *graphic_engine_create();

/**
 * @brief It checks if the dynamic memory reserve has been done correctly, and if not, destroys al the areas
 *  and frees the memory of the structure
 * @author Carmen Gómez Escobar
 *
 * @param ge it points to a structure called Graphic_engine
 */
void graphic_engine_destroy(Graphic_engine *ge);

/**
 * @brief It paints all the areas after having cleared the area and having checked if the player was
 * @author Estefanía Fenoy Montes
 *
 * @param game it points to a structure called Game y and uses it to define the space that a function will afterwards add
 * @param ge a pointer to the structure Graphic_engine
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

/**
 * @brief It paints all the objects in a determinated space
 * @author Estefanía Fenoy Montes
 *
 * @param set it points to a set of objects y and uses it to check if the space should be printed in that space or not
 * @return char a string whit the objects
 */
char* graphic_engine_print_objects(Set *set);

/**
 * @brief It paints all the characters in a determinated space
 * @author Carmen Gómez Escobar
 *
 * @param game it points to the game structure where the characters are located
 * @param id the id of the space in which the characters should be printed
 * @return char a string whit the characters
 */
char *graphic_engine_print_characters(Game *game, Id id);

/**
 * @brief It prints all the objects in the description area
 * @author Estefanía Fenoy Montes
 *
 * @param game it points to the game structure where the objects are located
 * @param ge a pointer to the structure Graphic_engine
 */
void graphic_engine_print_object_desc(Game *game, Graphic_engine *ge);

/**
 * @brief It prints all the characters in the description area
 * @author Estefanía Fenoy Montes
 *
 * @param game it points to the game structure where the characters are located
 * @param ge a pointer to the structure Graphic_engine
 */
void graphic_engine_print_character_desc(Game *game, Graphic_engine *ge);

#endif

