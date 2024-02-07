/**
 * @brief It defines the game update through user actions
 *
 * @file game.h
 * @author Profesores PPROG
 * @version 3.5
 * @date 26-01-2024
 * @copyright GNU Public License
 */

#ifndef GAME_ACTIONS_H
#define GAME_ACTIONS_H

#include "command.h"
#include "game.h"
#include "types.h"

Status game_actions_update(Game *game, Command cmd);

#endif
