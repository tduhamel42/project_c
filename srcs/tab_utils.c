/*
** tab_utils.c for minishell in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Fri Apr  1 11:12:38 2016 tanguy duhamel
** Last update Fri Apr  1 11:14:25 2016 tanguy duhamel
*/

#include <stdlib.h>
#include "minishell.h"

int		get_tab_len(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}
