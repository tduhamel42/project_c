/*
** env_utils_buildins.c for minishell in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Sat Apr  2 12:27:50 2016 tanguy duhamel
** Last update Sat Apr  2 12:31:01 2016 tanguy duhamel
*/

#include <stdlib.h>
#include "my_stdio.h"
#include "minishell.h"

int		display_env(t_llist **lenv)
{
  t_llist	*tmp;
  t_variable	*var;

  get_first_elem(lenv);
  tmp = (*lenv);
  while (tmp != NULL)
    {
      var = tmp->data;
      my_printf("%s=%s\n" DEFAULT, var->name, var->value);
      tmp = tmp->next;
    }
  return (0);

}
