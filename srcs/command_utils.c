/*
** command__utils.c for minishell in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Fri Apr  1 09:29:16 2016 tanguy duhamel
** Last update Sun Apr  3 18:05:20 2016 tanguy duhamel
*/

#include <stdlib.h>
#include "minishell.h"

static int	get_args_len(char **args)
{
  int		i;

  i = 0;
  while (args[i])
    i++;
  return (i);
}

t_cmd		*create_command(char *command, int type)
{
  t_cmd		*cmd;

  if ((cmd = malloc(sizeof(t_cmd))) == NULL)
    return (NULL);
  if (type == SEMICOLON)
    {
      if ((cmd->args = my_split(command, ' ')) == NULL)
	return (NULL);
    }
  else
    if ((cmd->args = my_split(command, 1)) == NULL)
      return (NULL);
  cmd->type = type;
  cmd->len = get_args_len(cmd->args);
  cmd->cmd = NULL;
  return (cmd);
}
