/*
** command_exec.c for minishell in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Fri Apr  1 09:21:17 2016 tanguy duhamel
** Last update Sat Apr  9 12:10:02 2016 tanguy duhamel
*/

#include <stdlib.h>
#include "minishell.h"

int		exec_command(t_shell *shell)
{
  t_llist	*tmp;
  t_cmd		*cmd;

  get_first_elem(&shell->cmd);
  tmp = shell->cmd;
  while (tmp != NULL)
    {
      cmd = tmp->data;
      if (cmd->type == SEMICOLON)
	simple_command(shell, cmd);
      if (cmd->type == PIPE)
	piped_command(shell, cmd);
      if (cmd->type == REDIRECTION)
	redirection_command(shell, cmd);
      tmp = tmp->next;
    }
  return (0);
}
