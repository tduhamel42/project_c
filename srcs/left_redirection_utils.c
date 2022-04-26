/*
** left_redirection_utils.c for minishell in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Sun Apr 10 14:48:42 2016 tanguy duhamel
** Last update Sun Apr 10 17:20:25 2016 tanguy duhamel
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "my_string.h"
#include "minishell.h"

static int	do_left_redirection(int fd, t_shell *shell, t_cmd *cmd)
{
  int		pid;

  if ((pid = fork()) == ERROR)
    return (ERROR);
  if (!pid)
    {
      if ((dup2(fd, 0)) == ERROR)
	return (ERROR);
      exec_command_for_redir(shell, &cmd->cmd);
      exit(EXIT_SUCCESS);
    }
  else
    {
      close(fd);
      wait(NULL);
    }
  return (0);
}

int		handle_dleft_redirection(t_shell *shell, t_cmd *cmd)
{
  int		i;
  char		**args;
  int		fd;

  if ((args = my_split(cmd->args[0], '<')) == NULL)
    return (ERROR);
  if ((parse_command(&cmd->cmd, args[0])) == ERROR)
    return (ERROR);
  i = 1;
  while (args[i] != NULL)
    {
      args[i] = args[i]++;
      i++;
    }
  i = 1;
  while (args[i] != NULL)
    {
      if (my_strlen(args[i]) > 0)
	{
	  if ((fd = open_dleft_redirection(args[i])) == ERROR)
	    return (ERROR);
	  if ((do_left_redirection(fd, shell, cmd)) == ERROR)
	    return (ERROR);
	}
      i++;
    }
  return (0);
}

int		handle_sleft_redirection(t_shell *shell, t_cmd *cmd)
{
  int		i;
  char		**args;
  int		fd;

  if ((args = my_split(cmd->args[0], '<')) == NULL)
    return (ERROR);
  if ((parse_command(&cmd->cmd, args[0])) == ERROR)
    return (ERROR);
  i = 1;
  while (args[i] != NULL)
    {
      if ((fd = open_sleft_redirection(args[i])) == ERROR)
	return (ERROR);
      if ((do_left_redirection(fd, shell, cmd)) == ERROR)
	return (ERROR);
      i++;
    }
  return (0);
}
