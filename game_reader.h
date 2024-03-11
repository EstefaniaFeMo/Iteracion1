/**
 * @brief It defines the game interface for the reading of spaces and other elements
 *
 * @file game_reader.h
 * @author Profesores PPROG, Carmen Gómez Escobar
 * @version 3.5
 * @date 04-02-2024
 * @copyright GNU Public License
 */
#ifndef GAMEREADER_H
#define GAMEREADER_H

#include "game.h"
#include "types.h"

/**
 * @brief It downloads the spaces defined in a file
 * @author Profesores PPROG
 *
 * @param game a pointer to the struct, Game and it uses it to define the space that makes the function to add it
 * @param filename a pointer to the file of text that is passed as an argument to the function
 * @return OK, if the function has worked correctly or ERROR, if a mistken has happened
 */
Status game_reader_load_spaces(Game *game, char *filename);

/**
 * @brief It downloads the objects defined in a file
 * @author Carmen Gómez Escobar
 *
 * @param game a pointer to the struct, Game and it uses it to define the object that makes the function to add it
 * @param filename a pointer to the file of text that is passed as an argument to the function
 * @return status==OK, if the function has worked correctly
 * @return status==ERROR, if a mistken has happened
 */
Status game_reader_load_objects(Game *game, char *filename);

#endif
