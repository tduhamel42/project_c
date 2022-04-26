/*
** my_strdup.c for my_strdup in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Mon Mar 21 13:18:09 2016 tanguy duhamel
** Last update Mon Mar 21 13:19:40 2016 tanguy duhamel
*/

#include <stdlib.h>
#include "my_string.h"

char		*my_strdup(char *str)
{
  char		*new_str;
  int		i;

  if ((new_str = malloc(sizeof(char) * my_strlen(str) + 1))== NULL)
    return (NULL);
  i = 0;
  while (str[i] != 0)
    {
      new_str[i] = str[i];
      i++;
    }
  new_str[i] = 0;
  return (new_str);
}
