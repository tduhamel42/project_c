/*
** env_utils.c for minishell in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Tue Mar 29 10:58:40 2016 tanguy duhamel
** Last update Fri Apr  8 22:10:58 2016 tanguy duhamel
*/

#include <stdlib.h>
#include "my_stdio.h"
#include "customs.h"
#include "my_string.h"
#include "minishell.h"

int		get_nbr_env(t_llist **lenv)
{
  int		i;
  t_llist	*tmp;

  i = 0;
  get_first_elem(lenv);
  tmp = (*lenv);
  while (tmp != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}

char		**env_to_tab(t_llist **lenv)
{
  char		**tab;
  t_variable	*var;
  t_llist	*tmp;
  int		i;

  if ((*lenv) == NULL)
    return (NULL);
  get_first_elem(lenv);
  tmp = (*lenv);
  if ((tab = malloc(sizeof(char *) * (get_nbr_env(lenv) + 1))) == NULL)
    return (NULL);
  i = 0;
  while (tmp != NULL)
    {
      var = tmp->data;
      if (var->name != NULL && var->value != NULL)
	{
	  tab[i] = my_str_realcat(var->name, "=");
	  tab[i] = my_str_realcat(tab[i], var->value);
	  i++;
	}
      tmp = tmp->next;
    }
  tab[i] = (char *)0;
  return (tab);
}

char		*my_getenv(t_llist **lenv, char *name)
{
  t_llist	*tmp;
  t_variable	*var;

  get_first_elem(lenv);
  tmp = (*lenv);
  while (tmp != NULL)
    {
      var = tmp->data;
      if (my_strcmp(var->name, name))
	return (var->value);
      tmp = tmp->next;
    }
  return (NULL);
}

int		my_setenv(t_llist **lenv, char *name, char *value)
{
  t_llist	*tmp;
  t_variable	*var;

  get_first_elem(lenv);
  tmp = (*lenv);
  while (tmp != NULL)
    {
      var = tmp->data;
      if (my_strcmp(var->name, name))
	{
	  var->value = value;
	  return (0);
	}
      tmp = tmp->next;
    }
  return (0);
}

int		put_env_in_list(t_llist **env, char **str_env)
{
  int		i;
  t_variable	*tmp;

  i = 0;
  while (str_env[i] != NULL)
    {
      if ((tmp = get_variable(str_env[i], '=')) == NULL)
	return (ERROR);
      if ((add_elem(env, tmp)) == ERROR)
	return (ERROR);
      i++;
    }
  return (0);
}
