/**
 * @brief It implements the command interpreter
 *
 * @file command.c
 * @author Estefanía Fenoy Montes, Carmen Gómez Escobar
 * @version 3.5
 * @date 26-01-2024
 * @copyright GNU Public License
 */

#include "command.h"

#include <stdio.h>
#include <string.h>
#include <strings.h>

#define CMD_LENGHT 30

char *cmd_to_str[N_CMD][N_CMDT] = {{"", "No command"}, {"", "Unknown"}, {"e", "Exit"}, {"n", "Next"}, {"b", "Back"}};

/**
 * @brief  It reads a command recived from the user input and gives the asociated value defined in the Command struct.
 * @author Estefania Fenoy Montes, Carmen Gómez Escobar
 *
 * @return  cmd, a Command variable whcich value is the asociated command to the word recived.
 */
Command command_get_user_input()
{
  Command cmd = NO_CMD;
  char input[CMD_LENGHT] = "", *token = NULL;
  int i = UNKNOWN - NO_CMD + 1;

  if (fgets(input, CMD_LENGHT, stdin))
  {
    token = strtok(input, " \n");
    cmd = UNKNOWN;
    while (token && cmd == UNKNOWN && i < N_CMD)
    {
      if (!strcasecmp(token, cmd_to_str[i][CMDS]) || !strcasecmp(token, cmd_to_str[i][CMDL]))
      {
        cmd = i + NO_CMD;
      }
      else
      {
        i++;
      }
    }
  }

  return cmd;
}
