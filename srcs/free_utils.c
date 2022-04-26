/*
** free_utils.c for minishell in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Thu Mar 31 20:50:21 2016 tanguy duhamel
** Last update Sat Apr  2 11:52:31 2016 tanguy duhamel
*/

#include <stdlib.h>
#include "customs.h"
#include "minishell.h"

static int	free_cmd(t_cmd *cmd)
{
  free_dtab((void **)cmd->args, cmd->len);
  free(cmd);
  return (0);
}

int		free_command(t_llist **cmd)
{
  t_llist	*tmp;

  get_first_elem(cmd);
  while ((*cmd) != NULL)
    {
      tmp = (*cmd);
      (*cmd) = (*cmd)->next;
      delete_elem(tmp, &free_cmd);
    }
  return (0);
}

static int	free_env(t_llist **env)
{
  t_llist	*tmp;

  get_first_elem(env);
  while ((*env) != NULL)
    {
      tmp = (*env);
      (*env) = (*env)->next;
      delete_elem(tmp, &free_variable);
    }
  return (0);
}

int		free_shell(t_shell *shell)
{
  free_env(&shell->env);
  free(shell->line);
  free(shell);
  return (0);
}
