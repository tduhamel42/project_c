/*
** my_str_utils.c for mu_str_utils.c in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Thu Mar 31 11:04:40 2016 tanguy duhamel
** Last update Thu Mar 31 15:27:31 2016 tanguy duhamel
*/

#include "customs.h"

int		getzero(unsigned int nb)
{
  int		i;

  i = 0;
  while ((nb / 8) != 0)
    {
      nb = nb / 8;
      i = i + 1;
    }
  return (2 - i);
}

int		my_fdputstr_wnpc(int fd, void *st)
{
  int		i;
  int		j;
  char		*str;

  i = 0;
  j = 0;
  str = st;
  while (str[i] != 0)
    {
      if (str[i] < 32 || str[i] >= 127)
	{
	  my_fdputchar(fd, "\\");
	  while (j < getzero(str[i]))
	    {
	      my_fdputchar(fd, "0");
	      j = j + 1;
	    }
	  my_fdputoctal(fd, &str[i]);
	}
      else
	my_fdputchar(fd, &str[i]);
      j = 0;
      i = i + 1;
    }
  return (0);
}
