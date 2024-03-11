/**
 * @brief It defines the game update through user actions
 *
 * @file game_actions.h
 * @author Profesores PPROG, Carmen Gómez Escobar, Estefanía Fenoy Montes
 * @version 3.5
 * @date 08-02-2024
 * @copyright GNU Public License
 */

#ifndef GAME_ACTIONS_H
#define GAME_ACTIONS_H

#define MAX_RAND 10 /*!<Macro with the maximum value of the random number*/
#define MIN_RAND 0 /*!<Macro with the minimum value of the random number*/
#define NUM_PROB 5 /*!<Macro which indicates the probability of the attack succeeds */

#include "command.h"
#include "game.h"
#include "types.h"
#include "player.h"

/**
 * @brief It recives the new command and for each type of command, calls a new function. At the end it
 * will update the status.
 * @author Estefanía Fenoy Montes
 *
 * @param game a pointer to the struct called Game and uses it as an argument in the called functions.
 * @param command the structure of command which contains all the information related to the command.
 * @return OK sif everything has worked out, ERROR if there is some mistake
 */
Status game_actions_update(Game *game, Command *comamnd);

#endif
