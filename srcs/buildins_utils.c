/*
** buildins_utils.c for minishell in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Fri Apr  1 10:26:36 2016 tanguy duhamel
** Last update Sun Apr 10 11:08:55 2016 tanguy duhamel
*/

#include "my_string.h"
#include "minishell.h"

int		is_buildins(char *bin)
{
  if (my_strcmp("cd", bin))
    return (CD);
  if (my_strcmp("exit", bin))
    return (EXIT);
  if (my_strcmp("setenv", bin))
    return (SETENV);
  if (my_strcmp("unsetenv", bin))
    return (UNSETENV);
  if (my_strcmp("pwd", bin))
    return (PWD);
  return (0);
}

int		exec_buildins(t_shell *shell, t_cmd *cmd, int nb_buildins)
{
  if (nb_buildins == CD)
    my_cd(shell);
  else if (nb_buildins == EXIT)
    my_exit(shell);
  else if (nb_buildins == ENV)
    display_env(&shell->env);
  else if (nb_buildins == SETENV)
    my_cmdsetenv(shell, cmd);
  else if (nb_buildins == UNSETENV)
    my_unsetenv(&shell->env, cmd);
  else if (nb_buildins == PWD)
    return (my_pwd(&shell->env));
  return (0);
}
