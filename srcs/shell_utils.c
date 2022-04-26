/*
** shell_utils.c for minishell2 in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Tue Mar 29 10:51:47 2016 tanguy duhamel
** Last update Fri Apr  8 21:09:55 2016 tanguy duhamel
*/

#include <stdlib.h>
#include "minishell.h"

t_shell			*init_shell(int bonus, char **env)
{
  t_shell		*shell;

  if ((shell = malloc(sizeof(t_shell))) == NULL)
    return (NULL);
  shell->env = NULL;
  if ((put_env_in_list(&shell->env, env)) == ERROR)
    return (NULL);
  shell->alias = NULL;
  shell->variables = NULL;
  shell->cmd = NULL;
  if (bonus == 0)
    shell->ps1 = PS1;
  return (shell);
}
