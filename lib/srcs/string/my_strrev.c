/*
** my_strrev.c for my_strrev in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Sat Mar 26 11:33:23 2016 tanguy duhamel
** Last update Sat Mar 26 15:11:35 2016 tanguy duhamel
*/

#include <stdlib.h>
#include "my_string.h"

char		*my_strrev(char *str)
{
  int		i;
  int		j;
  char		tmp;

  i = 0;
  j = my_strlen(str) - 1;
  while (i < j)
    {
      tmp = str[i];
      str[i] = str[j];
      str[j] = tmp;
      i++;
      j--;
    }
  return (str);
}
