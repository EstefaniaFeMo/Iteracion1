/**
 * @brief It defines the textual graphic engine interface
 *
 * @file graphic_engine.h
 * @author Profesores PPROG, Carmen Gómez Escobar
 * @version 3.5
 * @date 07-02-2024
 * @copyright GNU Public License
 */

#ifndef GRAPHIC_ENGINE_H
#define GRAPHIC_ENGINE_H

#include "game.h"

/**
 * @brief Graphic_engine
 *
 * This struct defines five pointers which type is Area, resulting the five posible areas of the game
 */
typedef struct _Graphic_engine Graphic_engine;

/**
 * @brief It reserves di¡ynamic memeory for the structure called Graphic_engine if it hasn't been previously done
 *  it also reserves dynamic memory for the variables contained in it such as map, descript, banner, help and feedback
 * @author Profesores PPROG, Carmen Gómez Escobar
 *
 * @return  ge, a strcuture and it's members
 */
Graphic_engine *graphic_engine_create();

/**
 * @brief It checks if the dynamic memory reserve has been done correctly, and if not, destroys al the areas
 *  and frees the memory of the structure
 * @author Profesores PPROG, Carmen Gómez Escobar
 *
 * @param ge it points to a structure called Graphic_engine
 */
void graphic_engine_destroy(Graphic_engine *ge);

/**
 * @brief It paints all the areas after having cleared the area and having checked if the player was
 * @author Profesores PPROG, Carmen Gómez Escobar
 *
 * @param game it points to a structure called Game y and uses it to define the space that a function will afterwards add
 * @param ge a pointer to the structure Graphic_engine
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

#endif
