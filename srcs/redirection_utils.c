/*
** redirection_utils.c for redirection in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Wed Apr  6 20:02:53 2016 tanguy duhamel
** Last update Sun Apr 10 17:21:15 2016 tanguy duhamel
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "my_string.h"
#include "minishell.h"

int		exec_command_for_redir(t_shell *shell, t_llist **list)
{
  t_llist	*tmp;
  t_cmd		*cmd;

  get_first_elem(list);
  tmp = (*list);
  while (tmp != NULL)
    {
      cmd = tmp->data;
      if (cmd->type == SEMICOLON)
	simple_command(shell, cmd);
      if (cmd->type == PIPE)
	piped_command(shell, cmd);
      if (cmd->type == REDIRECTION)
	redirection_command(shell, cmd);
      tmp = tmp->next;
    }
  return (0);
}

static int	do_right_redirection(int fd, t_shell *shell, t_cmd *cmd)
{
  int		pid;

  if ((pid = fork()) == ERROR)
    return (ERROR);
  if (!pid)
    {
      if ((dup2(fd, 1)) == ERROR)
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

static int	handle_sright_redirection(t_shell *shell, t_cmd *cmd)
{
  int		i;
  char		**args;
  int		fd;

  if ((args = my_split(cmd->args[0], '>')) == NULL)
    return (ERROR);
  if ((parse_command(&cmd->cmd, args[0])) == ERROR)
    return (ERROR);
  i = 1;
  while (args[i] != NULL)
    {
      if (my_strlen(args[i]) > 0)
	{
	  if ((fd = open_sright_redirection(args[i])) == ERROR)
	    return (ERROR);
	  if ((do_right_redirection(fd, shell, cmd)) == ERROR)
	    return (ERROR);
	}
      i++;
    }
  return (0);
}

static int	handle_dright_redirection(t_shell *shell, t_cmd *cmd)
{
  int		i;
  char		**args;
  int		fd;

  if ((args = my_split(cmd->args[0], '>')) == NULL)
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
	  if ((fd = open_dright_redirection(args[i])) == ERROR)
	    return (ERROR);
	  if ((do_right_redirection(fd, shell, cmd)) == ERROR)
	    return (ERROR);
	}
      i++;
    }
  return (0);
}

int		redirection_command(t_shell *shell, t_cmd *cmd)
{
  if ((my_strstr(cmd->args[0], ">>")))
    return (handle_dright_redirection(shell, cmd));
  else if ((my_strstr(cmd->args[0], ">")))
    return (handle_sright_redirection(shell, cmd));
  else if ((my_strstr(cmd->args[0], "<")))
    return (handle_sleft_redirection(shell, cmd));
  else if ((my_strstr(cmd->args[0], "<<")))
    return (handle_dleft_redirection(shell, cmd));
  return (0);
}
