/*
** my_unsetenv.c for minishell in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Fri Apr  8 21:46:32 2016 tanguy duhamel
** Last update Tue Apr 12 19:30:11 2016 tanguy duhamel
*/

#include <stdlib.h>
#include "customs.h"
#include "my_string.h"
#include "my_stdio.h"
#include "minishell.h"

static int		check_last_elem(t_llist **list, char *name)
{
  t_variable		*var;

  var = (*list)->data;
  if (my_strcmp(var->name, name))
    {
      if ((*list)->prev)
	((t_llist *)(*list)->prev)->next = NULL;
      else
	(*list) = NULL;
      return (1);
    }
  return (0);
}

static int		check_first_elem(t_llist **list, char *name)
{
  t_variable		*var;

  var = (*list)->data;
  if (my_strcmp(var->name, name))
    {
      if ((*list)->next)
	{
	  if ((*list)->prev == NULL)
	    ((t_llist *)(*list)->next)->prev = NULL;
	  (*list) = (*list)->next;
	}
      else
	(*list) = NULL;
      return (1);
    }
  return (0);
}

static int		do_unset(t_llist **list)
{
  if ((*list)->prev && (*list)->next)
    {
      ((t_llist *)(*list)->prev)->next = (*list)->next;
      (*list) = (*list)->next;
    }
  else if ((*list)->prev)
    {
      ((t_llist *)(*list)->prev)->next = NULL;
      (*list) = (*list)->prev;
    }
  return (0);
}

int			my_unsetenv(t_llist **list, t_cmd *cmd)
{
  t_variable		*tmp;

  get_first_elem(list);
  if (check_first_elem(list, cmd->args[1]))
    return (0);
  while ((*list)->next != NULL)
    {
      tmp = (*list)->data;
      if (my_strcmp(tmp->name, cmd->args[1]))
	return (do_unset(list));
      (*list) = (*list)->next;
    }
  if (check_last_elem(list, cmd->args[1]))
    return (0);
  my_dprintf(2, RED "%s\n" DEFAULT, "Cannot find variable !!");
  return (0);
}
