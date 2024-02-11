/**
 * @brief It defines the game update through user actions
 *
 * @file game_actions.h
 * @author Estefanía Fenoy Montes, Carmen Gómez Esocbar
 * @version 3.5
 * @date 08-02-2024
 * @copyright GNU Public License
 */

#ifndef GAME_ACTIONS_H
#define GAME_ACTIONS_H

#include "command.h"
#include "game.h"
#include "types.h"

/**
 * @brief It recives the new command and for each type of command, calls a new function. At the end it
 * will update the status.
 * @author Estefania Fenoy Montes, Carmen Gómez Escobar.
 *
 * @param game a pointer to the struct called Game and uses it as an argument in the called functions.
 * @param cmd a variable type Command with the command.
 * @return Status= OK sif everything has worked out
 */
Status game_actions_update(Game *game, Command cmd);

#endif
