/*
** my_strncasecmp.c for my_strncasecmp.c in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Mon Mar 21 15:46:32 2016 tanguy duhamel
** Last update Mon Mar 21 15:55:02 2016 tanguy duhamel
*/

#include "my_string.h"

int		my_strncasecmp(char *str1, char *str2, int n)
{
  int		i;

  i = 0;
  if (n > my_strlen(str1) - 1 || n > my_strlen(str2) -1)
    return (0);
  while (i < n)
    {
      if (str1[i] >= 'A' || str1[i] <= 'Z')
	str1[i] = str1[i] + 32;
      if (str2[i] >= 'A' || str2[i] <= 'Z')
	str2[i] = str2[i] + 32;
      if (str1[i] != str2[i])
	return (0);
      i++;
    }
  return (1);
}
