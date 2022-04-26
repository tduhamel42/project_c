/*
** my_strcasecmp.c for my_strcasecmp in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Mon Mar 21 15:26:44 2016 tanguy duhamel
** Last update Mon Mar 21 15:58:45 2016 tanguy duhamel
*/

#include "my_string.h"

int		my_strcasecmp(char *str1, char *str2)
{
  int		i;

  i = 0;
  if (my_strlen(str1) != my_strlen(str2))
    return (0);
  while (str1[i] != 0)
    {
      if (str1[i] != str2[i])
	return (0);
      i++;
    }
  return (1);
}
