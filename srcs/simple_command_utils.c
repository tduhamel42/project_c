/*
** simple_command_utils.c for minishell in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Fri Apr  1 10:17:47 2016 tanguy duhamel
** Last update Fri Apr  8 21:27:23 2016 tanguy duhamel
*/

#include <stdlib.h>
#include "minishell.h"

int		simple_command(t_shell *shell, t_cmd *cmd)
{
  int		nb_buildins;
  char		*path;
  char		**env;

  if ((nb_buildins = is_buildins(cmd->args[0])))
    return (exec_buildins(shell, cmd, nb_buildins));
  if ((path = get_binary_path(*shell, *cmd)) == NULL)
    return (ERROR);
  path = my_str_realcat(path, "/");
  path = my_str_realcat(path, cmd->args[0]);
  if ((env = env_to_tab(&shell->env)) == NULL)
    return (ERROR);
  if ((my_simple_exec(path, cmd->args, env)))
    return (ERROR);
  free(path);
  free_dtab((void **)env, get_tab_len(env));
  return (0);
}
