/*
** my_strrchr.c for my_strrchr in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Mon Mar 21 22:20:11 2016 tanguy duhamel
** Last update Mon Mar 21 22:24:51 2016 tanguy duhamel
*/

#include <stdlib.h>

char		*my_strrchr(char *str, int c)
{
  char		*tmp;

  tmp = NULL;
  while (str++)
    {
      if (*str == c)
	tmp = str;
      if (!*str)
	return (tmp);
    }
  return tmp;
}
