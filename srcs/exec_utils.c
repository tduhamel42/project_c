/*
** exec_utils.c for minishell in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Fri Apr  1 09:49:46 2016 tanguy duhamel
** Last update Tue Apr 12 21:26:41 2016 tanguy duhamel
*/

#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "my_string.h"
#include "my_stdio.h"
#include "minishell.h"

int		display_error(int status)
{
  if (WTERMSIG(status) == SIGSEGV)
    my_dprintf(2, RED "%s\n" DEFAULT, "Segmentation fault");
  else if (WTERMSIG(status) == SIGFPE)
    my_dprintf(2, RED "%s\n", "Floating point exception");
  else if (WCOREDUMP(status))
    my_dprintf(2, RED "%s\n" DEFAULT, "(Core dumped)");
  return (0);
}

int		my_simple_exec(char *path, char **args, char **env)
{
  int			status;
  pid_t			p;
  char			*not_found;

  if ((p = fork()) == -1)
    return (ERROR);
  if (!p)
    {
      if (execve(path, args, env) == -1)
	{
	  not_found = my_str_realcat(path + 1, ": Command not found.");
	  my_dprintf(2, RED "%s\n" DEFAULT, not_found);
	  free(not_found);
	}
    }
  else
    {
      if (wait(&status) == -1)
	return (ERROR);
      display_error(status);
      return (0);
    }
  return (0);
}

static char	*get_path(char **paths, char *bin)
{
  int		i;
  DIR		*dir;
  struct dirent	*file;

  i = 0;
  while (paths[i] != NULL)
    {
      if ((dir = opendir(paths[i])) == NULL && access(paths[i], R_OK) == ERROR)
	return (NULL);
      while ((file = readdir(dir)))
	{
	  if (file != NULL)
	    {
	      if (my_strcmp(file->d_name, bin))
		{
		  closedir(dir);
		  return (paths[i]);
		}
	    }
	}
      closedir(dir);
      i++;
    }
  return (NULL);
}

static	char	*check_current_path(char *path, char *bin)
{
  DIR		*dir;
  struct dirent	*file;

  if (path == NULL || my_strlen(path) < 1)
    return (NULL);
  if ((dir = opendir(path)) == NULL && access(path, R_OK) == ERROR)
    return (NULL);
  while ((file = readdir(dir)))
    {
      if (file != NULL)
	{
	  if (my_strcmp(file->d_name, bin))
	    {
	      closedir(dir);
	      return (path);
	    }
	}
    }
  closedir(dir);
  return (NULL);
}

char		*get_binary_path(t_shell shell, t_cmd cmd)
{
  char		*path;
  char		*env;
  char		**paths;

  if (shell.env == NULL)
    return (NULL);
  if ((env = my_getenv(&shell.env, "PATH")) == NULL)
    return (NULL);
  if ((paths = my_split(env, ':')) == NULL)
    return (NULL);
  if ((path = check_current_path(
				 my_getenv(&shell.env, "PWD"), cmd.args[0] + 2)) == NULL)
    {
      if ((path = my_str_realcat(get_path(paths, cmd.args[0]), "")) == NULL)
	return (NULL);
    }
  free_dtab((void **)paths, get_tab_len(paths));
  return (path);
}
