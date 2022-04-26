/*
** exit_utils.c for minishell in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Sat Apr  2 11:27:47 2016 tanguy duhamel
** Last update Sun Apr 10 15:06:31 2016 tanguy duhamel
*/

#include <stdlib.h>
#include <my_stdlib.h>
#include "minishell.h"

void		my_exit(t_shell *shell)
{
  t_cmd		*tmp;
  int		ex;

  get_last_elem(&shell->cmd);
  if (shell->cmd)
    {
      tmp = shell->cmd->data;
      if (get_tab_len(tmp->args) > 1)
	ex = my_atoi(tmp->args[1]);
      else
	ex = 0;
    }
  else
    ex = 0;
  free_command(&shell->cmd);
  free_shell(shell);
  exit(ex);
}
