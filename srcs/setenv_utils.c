/*
** setenv_utils.c for minishell in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Fri Apr  8 21:25:59 2016 tanguy duhamel
** Last update Tue Apr 12 21:31:07 2016 tanguy duhamel
*/

#include <stdlib.h>
#include "my_string.h"
#include "minishell.h"

int		my_cmdsetenv(t_shell *shell, t_cmd *cmd)
{
  char		*new_env;
  t_variable	*tmp;

  if (get_tab_len(cmd->args) == 1)
    return (display_env(&shell->env));
  else if (get_tab_len(cmd->args) == 2)
    return (my_setenv(&shell->env, cmd->args[1], ""));
  else if (get_tab_len(cmd->args) == 3
	   && (new_env = my_getenv(&shell->env,cmd->args[1])) != NULL)
    return (my_setenv(&shell->env, cmd->args[1], my_strdup(cmd->args[2])));
  else if (get_tab_len(cmd->args) == 3
	   && (my_getenv(&shell->env,cmd->args[1])) == NULL)
    {
      new_env = my_str_realcat(cmd->args[1], "=");
      new_env = my_str_realcat(new_env, cmd->args[2]);
      if ((tmp = get_variable(new_env, '=')) == NULL)
	return (ERROR);
      get_last_elem(&shell->env);
      if ((add_elem(&shell->env, tmp)) == ERROR)
	return (ERROR);
    }
  return (ERROR);
}
