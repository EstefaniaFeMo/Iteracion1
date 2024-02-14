/**
 * @brief It implements the command interpreter interface
 *
 * @file command.h
 * @author Profesores PPROG, Carmen Gómez Escobar
 * @version 3.5
 * @date 26-01-2024
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H

#define N_CMDT 2
#define N_CMD 7

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
 * BACK, TAKE, or DROP.
 */
typedef enum
{
    NO_CMD = -1,
    UNKNOWN,
    EXIT,
    NEXT,
    BACK,
    TAKE,
    DROP
} Command;

/**
 * @brief  It reads a command recived from the user input and gives the asociated value defined in the Command struct.
 * @author Profesores PPROG, Carmen Gómez Escobar
 *
 * @return  cmd, a Command variable whcich value is the asociated command to the word recived.
 */
Command command_get_user_input();

#endif
