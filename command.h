/**
 * @brief It implements the command interpreter interface
 *
 * @file command.h
 * @author Profesores PPROG, Carmen Gómez Escobar
 * @version 3.5
 * @date 6-02-2024
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H

#include "types.h"

#define N_CMDT 2 /*!<Macro with the number of the command types*/
#define N_CMD 11 /*!<Macro with the number of possible commands*/

/**
 * @brief CommandType
 *
 * This struct defines the posible types of commands, CMDS or CMDL.
 */
typedef enum
{
    CMDS,
    CMDL
} CommandType;

/**
 * @brief Command
 *
 * This struct defines the possible values of the commands, NO_CMD, UNKNOWN, EXIT, NEXT, 
 * BACK, TAKE, DROP, LEFT, RIGHT, ATTACK, CHAT.
 */
typedef enum
{
    NO_CMD = -1,
    UNKNOWN,
    EXIT,
    NEXT,
    BACK,
    TAKE,
    DROP, 
    LEFT, 
    RIGTH,
    ATTACK,
    CHAT,
} CommandNum;

typedef struct _Command Command;

Command * command_create();

/**
 * @brief  It reads a command recived from the user input and gives the asociated value defined in the Command struct.
 * @author Carmen Gómez Escobar
 *
 * @return  cmd, a Command variable whcich value is the asociated command to the word recived.
 */
Command *command_get_user_input();

CommandNum command_get_cmd(Command *command);

char* command_get_args(Command* command);

Status command_destroy(Command *command);

Status command_get_cmd_status(Command *command);

Status command_set_cmd_status(Command *command, Status status);
#endif
