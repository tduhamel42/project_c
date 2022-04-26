/*
** command_parser.c for minishell in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Thu Mar 31 21:15:14 2016 tanguy duhamel
** Last update Sun Apr 10 17:19:59 2016 tanguy duhamel
*/

#include <stdlib.h>
#include "my_string.h"
#include "minishell.h"

static int	parse_semicolon_command(t_llist **cmd, char *line)
{
  t_cmd		*tmp;
  char		*command;
  char		**args;
  int		i;

  if ((args = my_split(line, ';')) == NULL)
    return (ERROR);
  i = 0;
  while (args[i] != NULL)
    {
      if ((command = my_epur_str(args[i])) == NULL)
	return (ERROR);
      if ((!my_strcontains(args[i], '|')) && !my_strcontains(args[i], '<')
	  && !my_strcontains(args[i], '>'))
	{
	  if ((tmp = create_command(command, SEMICOLON)) == NULL)
	    return (ERROR);
	}
      else
	if ((tmp = create_command(command, PIPE)) == NULL)
	  return (ERROR);
      if ((add_elem(cmd, tmp)) == ERROR)
	return (ERROR);
      i++;
    }
  free_dtab((void **)args, get_tab_len(args));
  return (0);
}

static int	parse_redirection_command(t_llist **cmds)
{
  t_llist	*tmp;
  t_cmd		*cmd;
  int		i;
  int		is_redi;

  get_first_elem(cmds);
  tmp = (*cmds);
  is_redi = 0;
  while (tmp != NULL)
    {
      cmd = tmp->data;
      i = 0;
      while (cmd->args[i] != NULL)
	{
	  if (my_strcontains(cmd->args[i], '>')
	      || my_strcontains(cmd->args[i], '<'))
	    {
	      cmd->type = REDIRECTION;
	      is_redi++;
	    }
	  i++;
	}
      tmp = tmp->next;
    }
  return (is_redi);
}

static int	parse_piped_command(t_llist **cmds)
{
  t_llist	*tmp;
  t_cmd		*cmd;

  get_first_elem(cmds);
  tmp = (*cmds);
  while (tmp != NULL)
    {
      cmd = tmp->data;
      if (my_strcontains(cmd->args[0], '|'))
	{
	  cmd->type = PIPE;
	  if ((create_piped_command(cmd)) == ERROR)
	    return (ERROR);
	}
      tmp = tmp->next;
    }
  return (0);
}

int		parse_command(t_llist **cmd, char *line)
{
  int		is_redi;

  if ((parse_semicolon_command(cmd, line)) == ERROR)
    return (ERROR);
  if ((is_redi = parse_redirection_command(cmd)) == ERROR)
    return (ERROR);
  if ((parse_piped_command(cmd)) == ERROR && !is_redi)
    return (ERROR);
  return (0);
}
