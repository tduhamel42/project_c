/*
** my_strchr.c for my_strchr in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Mon Mar 21 22:16:57 2016 tanguy duhamel
** Last update Mon Mar 21 22:24:34 2016 tanguy duhamel
*/

#include <stdlib.h>

char		*my_strchr(char *str, int c)
{
  while (str++)
    {
      if (*str == c)
	return (str);
      if (!*str)
	return (NULL);
    }
  return (NULL);
}
