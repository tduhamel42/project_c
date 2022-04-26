/*
** my_strcmp.c for my_strcmp in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Sat Mar 26 14:43:23 2016 tanguy duhamel
** Last update Sat Mar 26 14:44:16 2016 tanguy duhamel
*/

#include "my_string.h"

int		my_strcmp(char *str1, char *str2)
{
  int		i;
  int		j;
  int		len;

  i = 0;
  j = 0;
  if (my_strlen(str1) > my_strlen(str2))
    len = my_strlen(str1);
  else
    len = my_strlen(str2);
  while (i < len)
    {
      if (str2[j] != str1[i])
	return (0);
      i++;
      j++;
    }
  return (1);
}
