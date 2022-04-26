/*
** printf_utils.c for printf_utils.c in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Thu Mar 31 10:39:44 2016 tanguy duhamel
** Last update Thu Mar 31 15:32:55 2016 tanguy duhamel
*/

#include "functions.h"

int		aff_complex(int *sizes, int *iter, void *to_aff, const char *str)
{
  int		j;

  j = 0;
  if (sizes[1] > sizes[2] && sizes[1] > 0)
    {
      while (j < (sizes[1] - sizes[2]))
	{
	  my_fdputchar(iter[1], " ");
	  j = j + 1;
	}
      j = 0;
      while (functions[j].character != str[iter[0] + 1])
	j = j + 1;
      functions[j].func(iter[1], to_aff);
    }
  else
    {
      while (functions[j].character != str[iter[0] + 1])
	j = j + 1;
      functions[j].func(iter[1], &to_aff);
    }
  return (0);
}

int		is_intab(char c)
{
  int		i;

  i = 0;
  while (i < 13)
    if (functions[i++].character == c)
      return (1);
  return (0);
}
