/*
** my_strstr.c for my_strstr in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Sun Mar 27 21:47:03 2016 tanguy duhamel
** Last update Sun Apr 10 14:42:09 2016 tanguy duhamel
*/

#include <stdlib.h>
#include "my_string.h"

char		*my_strstr(char *str, char *to_find)
{
  int		i;

  i = 0;
  if (str[0] != 0)
    {
      while (to_find[i] != 0)
	{
	  if (to_find[i] != str[i])
	    return (my_strstr(str + 1, to_find));
	  i++;
	}
      return (str);
    }
  return (NULL);
}
