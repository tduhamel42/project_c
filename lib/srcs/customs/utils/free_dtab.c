/*
** free_dtab.c for free_dtab in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Sat Mar 26 15:06:01 2016 tanguy duhamel
** Last update Sat Mar 26 15:07:08 2016 tanguy duhamel
*/

#include <stdlib.h>

int		free_dtab(void **tab, int len)
{
  int		i;

  i = 0;
  while (i < len)
    free(tab[i++]);
  free(tab);
  return (0);
}
