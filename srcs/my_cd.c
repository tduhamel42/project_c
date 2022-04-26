/*
** my_cd.c for minishell in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Sat Apr  2 12:02:33 2016 tanguy duhamel
** Last update Sun Apr 10 15:47:02 2016 tanguy duhamel
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_string.h"
#include "my_stdio.h"
#include "minishell.h"

static int		my_change_directory(char *path)
{
  char			*err;

  if ((chdir(path)))
    {
      err = my_str_realcat(path, ": Aucun fichier ou dossier de ce type.");
      my_dprintf(2, RED "%s\n" DEFAULT, err);
      free(err);
      return (ERROR);
    }
  return (0);
}

int		my_cd(t_shell *shell)
{
  char		*path;
  char		*pwd;
  static char	*oldpwd;
  t_cmd		*cmd;

  cmd = shell->cmd->data;
  path = cmd->args[1];
  pwd = NULL;
  if (my_strcmp(cmd->args[1], "-") && oldpwd != NULL)
    path = oldpwd;
  if ((access(path, R_OK)) == ERROR || (my_change_directory(path)) == ERROR)
    {
      my_dprintf(2, RED "%s: Permission non accordée.\n" DEFAULT, path);
      return (ERROR);
    }
  pwd = getcwd(pwd, 4096);
  oldpwd = my_getenv(&shell->env, "PWD");
  if ((my_setenv(&shell->env, "PWD", pwd)) == ERROR)
    return (ERROR);
  return (0);
}
