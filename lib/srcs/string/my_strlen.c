/*
** basic_str_utils.c for mystdlib in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Mon Mar 21 10:46:57 2016 tanguy duhamel
** Last update Mon Mar 21 13:19:12 2016 tanguy duhamel
*/

#include <stdlib.h>

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  if (str != NULL)
    {
      while (str[i] != 0)
	i++;
    }
  return (i);
}

