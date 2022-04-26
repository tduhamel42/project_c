/*
** my_str_realcat.c for my_str_realcat in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Sat Mar 26 14:38:29 2016 tanguy duhamel
** Last update Sat Apr  2 11:45:19 2016 tanguy duhamel
*/

#include <stdlib.h>
#include "my_string.h"

char		*my_str_realcat(char *s1, char *s2)
{
  int		i;
  int		j;
  char		*str;

  if ((str = malloc(sizeof(char) * (my_strlen(s1)
				    + my_strlen(s2) + 1))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  if (s1 != NULL)
    while (s1[i] != 0)
      str[j++] = s1[i++];
  i = 0;
  while (s2[i] != 0)
    str[j++] = s2[i++];
  str[j] = 0;
  return (str);
}
