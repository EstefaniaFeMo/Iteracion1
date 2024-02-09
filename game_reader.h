/**
 * @brief It defines the game interface for the reading of spaces and other elements
 *
 * @file game_reader.h
 * @author Estefanía Fenoy Montes, Carmen Gómez Escobar
 * @version 3.5
 * @date 04-02-2024
 * @copyright GNU Public License
 */
#ifndef GAMEREADER_H
#define GAMEREADER_H

#include "command.h"
#include "space.h"
#include "types.h"
#include "game.h"

/**
 * @brief It creates the game. If there were a problem, it would return ERROR. Then, it loads the spaces with the information
 * of the file passed as an argument to the function. If there were a problem, it would return ERROR. Next, the player and the
 * object are located in the first space
 * @author Estefanía Fenoy Montes, Carmen Gómez Escobar
 *
 * @param game a pointer to the struct that initiales it
 * @param filename a pointer with the name of a file of text which will be read to download the spaces
 * @return status==OK, variable booleana que indica el correcto funcionamiento de la función.
 * @return status==ERROR, variable booleana que indica el erróneo funcionamiento de la función.
 */
Status game_create_from_file(Game *game, char *filename);

#endif
