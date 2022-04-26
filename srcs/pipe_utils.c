/*
** pipe_utils.c for minishell in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Sun Apr  3 18:23:32 2016 tanguy duhamel
** Last update Sun Apr 10 10:40:13 2016 tanguy duhamel
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "my_stdio.h"
#include "minishell.h"

int		create_piped_command(t_cmd *cmd)
{
  int		i;
  t_cmd		*tmp_cmd;
  char		**args;
  char		*command;

  if ((args = my_split(cmd->args[0], '|')) == NULL)
    return (ERROR);
  i = 0;
  while (args[i] != NULL)
    {
      if ((command = my_epur_str(args[i])) == NULL)
	return (ERROR);
      if ((tmp_cmd = create_command(command, SEMICOLON)) == NULL)
	return (ERROR);
      if ((add_elem(&cmd->cmd, tmp_cmd)) == ERROR)
	return (ERROR);
      i++;
    }
  return (0);
}

static char	*get_path(t_shell shell, t_cmd *tmp)
{
  char		*path;

  path = get_binary_path(shell, *tmp);
  path = my_str_realcat(path, "/");
  path = my_str_realcat(path, tmp->args[0]);
  return (path);
}

static int	exec_father(int *fd, t_shell *shell, t_llist *cmd, char **env)
{
  char		*path;
  t_cmd		*tmp;

  if (cmd->prev != NULL)
    {
      close(fd[1]);
      if ((dup2(fd[0], 0)) == ERROR)
	return (ERROR);
    }
  tmp = cmd->data;
  path = get_path(*shell, tmp);
  my_simple_exec(path, tmp->args, env);
  exit(EXIT_SUCCESS);
}

static int	do_pipe_command(t_shell *shell, t_llist *cmd,
				char **env)
{
  int		fildes[2];
  pid_t		pid;

  if (cmd != NULL)
    {
      if (cmd->prev != NULL)
	{
	  pipe(fildes);
	  if ((pid = fork()) == ERROR)
	    return (ERROR);
	}
      if (!pid)
	{
	  close(fildes[0]);
	  if ((dup2(fildes[1], 1)) == ERROR)
	    return (ERROR);
	  do_pipe_command(shell, cmd->prev, env);
	}
      else
	exec_father(fildes, shell, cmd, env);
    }
  return (0);
}

int		piped_command(t_shell *shell, t_cmd *cmd)
{
  char		**env;
  pid_t		pid;

  get_last_elem(&cmd->cmd);
  if ((env = env_to_tab(&shell->env)) == NULL)
    return (ERROR);
  if ((pid = fork()) == ERROR)
    return (ERROR);
  if (!pid)
    do_pipe_command(shell, cmd->cmd, env);
  else
    wait(NULL);
  free_dtab((void **)env, get_tab_len(env));
  return (0);
}
