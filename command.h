/**
 * @brief It implements the command interpreter interface
 *
 * @file command.h
 * @author Profesores PPROG, Estefanía Fenoy Montes, Carmen Gomez Escobar
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
    RIGHT,
    ATTACK,
    CHAT
} CommandNum;

typedef struct _Command Command;

/**
 * @brief  It creates the structure of command which conatins the type of command the argument which goes with 
 * the command and the status of the command (whether it is executed or not), initializing all its members
 * @author Estefanía Fenoy Montes
 *
 * @return  command, the Command structure with its values initialized.
 */
Command * command_create();

/**
 * @brief  It reads a command recived from the user input and gives the asociated values defining the Command struct.
 * @author Estefanía Fenoy Montes
 *
 * @return  command, the Command structure with its values changed.
 */
Command *command_get_user_input();

/**
 * @brief  It gets the type of command of the list.
 * @author Estefanía Fenoy Montes
 * @param command the command structure with its information.
 * @return  command->cmd, the command of the list of commands that will be executed.
 */
CommandNum command_get_cmd(Command *command);

/**
 * @brief  It gets the argument which goes with command of the list.
 * @author Estefanía Fenoy Montes
 * @param command the command structure with its information.
 * @return  command->args, the argument that goes with the cmd.
 */
char* command_get_args(Command* command);

/**
 * @brief  It gets the status of the command of the list to indicate whether or not it will be excuted.
 * @author Estefanía Fenoy Montes
 * @param command the command structure with its information.
 * @return  command->status, the status of the command if it is ERROR the cmd won't be executed otherwise it is OK it will be executed.
 */
Status command_get_cmd_status(Command *command);
/**
 * @brief  It destroys the structure of command that contains all the information related to the command executed.
 * @author Estefanía Fenoy Montes
 * @param command the command structure with its information.
 * @return  OK if everything worked, ERROR if something went wrong.
 */
Status command_destroy(Command *command);


/**
 * @brief  It sets the status of the command if it is OK the cmd will be executed otherwise if it ERROR it won't be exucuted.
 * @author Estefanía Fenoy Montes
 * @param command the command structure with its information.
 * @return  OK if everything worked, ERROR if something went wrong.
 */
Status command_set_cmd_status(Command *command, Status status);
#endif
