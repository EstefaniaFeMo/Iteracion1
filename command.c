/**
 * @brief It implements the command interpreter
 *
 * @file command.c
 * @author Profesores PPROG, Estefanía Fenoy Montes, Carmen Gómez Escobar
 * @version 3.5
 * @date 6-02-2024
 * @copyright GNU Public License
 */

#include "command.h"

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>



#define CMD_LENGHT 30 /*!<Macro with the max length the command can be*/

/**
 * @brief Command
 *
 * This struct stores all the information of a command.
 */
struct _Command{
  CommandNum cmd; /*!<The command itself indicated in the list of CommandNum*/
  char args[CMD_LENGHT]; /*!<An argument to contain the information given apart of the command*/
  Status status; /*!<The status of the command if its call is correct, status Ok, otherwise status ERROR*/
};


char *cmd_to_str[N_CMD][N_CMDT] = {{"", "No command"}, {"", "Unknown"}, {"e", "Exit"}, {"n", "Next"}, {"b", "Back"}, {"t", "Take"}, {"d", "Drop"}, {"l", "Left"}, {"r", "Right"}, {"a", "Attack"}, {"c", "Chat"}};

/*command_create creates the structure of command initializing its members*/
Command * command_create(){
  Command *command;
  command = (Command *)malloc(sizeof(Command));
  if (command == NULL)
  {
    return NULL;
  }
  command->cmd = NO_CMD;
  command->args[0] = '\0';
  command->status=ERROR;
  return command;
}
/** command_get_user_input reads a command recived from the user input and gives the asociated values defining the Command struct */
Command *command_get_user_input()
{
  Command *command;
  char input[CMD_LENGHT] = "", *token = NULL;
  int i = UNKNOWN - NO_CMD + 1;
  command=command_create();

  if (fgets(input, CMD_LENGHT, stdin))
  {
    token = strtok(input, " \n");
    command->cmd = UNKNOWN;
    while (token && command->cmd == UNKNOWN && i < N_CMD)
    {
      if (!strcasecmp(token, cmd_to_str[i][CMDS]) || !strcasecmp(token, cmd_to_str[i][CMDL]))
      {
        command->cmd = i + NO_CMD;
      }
      else
      {
        i++;
      }
    }
    token = strtok(NULL, " \n");
    if(token)
      strcpy(command->args, token);

  }

  return command;
}

/*command_get_cmd gest the exact command which is a number in the list of commands that will be executed*/
CommandNum command_get_cmd(Command *command){
  if(command == NULL){
    return NO_CMD;
  }

  return command->cmd;
}
/*command_get_args gest the argument that goes with the command*/
char* command_get_args(Command* command){
  if(command == NULL){
    return NULL;
  }

  return command->args;
}
/*command_get_status gest the status of the command whether it will be executes it will be OK otherwise it 
will be ERROR*/
Status command_get_cmd_status(Command *command){
  if(command==NULL){
    return ERROR;
  }
  return command->status;
}
/*command_set_cmd_status sets the status of the command of the list*/
Status command_set_cmd_status(Command *command, Status status){
  if(command==NULL){
    return ERROR;
  }
  command->status=status;
  return OK;
}
/*command_destroy frees the memory of the structure command which contains all the information related to command*/
Status command_destroy(Command *command){
  if(command==NULL){
    return ERROR;
  }
  free(command);
  return OK;
}