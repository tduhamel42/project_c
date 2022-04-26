/*
** command_lexer.c for minishell in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Thu Mar 31 21:32:01 2016 tanguy duhamel
** Last update Sun Apr 10 17:23:45 2016 tanguy duhamel
*/

#include <stdlib.h>
#include "minishell.h"

static char	*check_for_var(t_llist **list, char *str)
{
  char		*value;

  if (my_strcontains(str, '$'))
    if ((value = my_getenv(list, str + 1)) != NULL)
      return (my_str_realcat(value, ""));
  return (NULL);
}

static char	*check_for_tilde(t_llist **list, char *str)
{
  char		*value;

  if (my_strcontains(str, '~'))
    if ((value = my_getenv(list, "HOME")) != NULL)
      return (my_str_realcat(value, str + 1));
  return (NULL);
}

static int	check_tab(t_llist **list, char **args)
{
  int		i;
  char		*value;

  i = 0;
  while (args[i] != 0)
    {
      if ((value = check_for_var(list, args[i])) != NULL)
	args[i] = value;
      if ((value = check_for_tilde(list, args[i])) != NULL)
	args[i] = value;
      i++;
    }
  return (0);
}

int		lex_command(t_shell *shell)
{
  t_llist	*tmp;
  t_llist	*ttmp;
  t_cmd		*cmd;
  t_cmd		*tmp_cmd;

  get_first_elem(&shell->cmd);
  tmp = shell->cmd;
  while (tmp != NULL)
    {
      cmd = tmp->data;
      if (cmd->cmd != NULL)
	{
	  get_first_elem(&cmd->cmd);
	  ttmp = cmd->cmd;
	  while (ttmp != NULL)
	    {
	      tmp_cmd = ttmp->data;
	      check_tab(&shell->env, tmp_cmd->args);
	      ttmp = ttmp->next;
	    }
	}
      check_tab(&shell->env, cmd->args);
      tmp = tmp->next;
    }
  return (0);
}
