/*
** my_vdprintf.c for my_vdprintf in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Thu Mar 24 13:26:38 2016 tanguy duhamel
** Last update Thu Mar 31 15:32:19 2016 tanguy duhamel
*/

#include <stdlib.h>
#include "my_stdio.h"
#include "functions.h"

int		aff_multiplemod(char *str, int fd, int *i)
{
  if (str[*i] == '%' && str[*i + 1] == '%')
    {
      my_fdputchar(fd, &str[*i + 1]);
      *i = *i + 1;
    }
  else if (str[*i] == '%' && str[*i + 1] == ' ')
    {
      my_fdputchar(fd, &str[*i]);
      *i = *i + 2;
    }
  return (0);
}

int		simple_format(va_list list, int fd, char c)
{
  int		j;

  j = 0;
  while (functions[j].character != c)
    j = j + 1;
  functions[j].func(fd, va_arg(list, void *));
  return (0);
}

int		complex_format(va_list list, int fd, char *str, int i)
{
  int		sizes[3];
  void		*to_aff;
  int		iter[2];

  sizes[0] = get_nbrchar(str, i + 1);
  sizes[1] = get_nbrspaces(str, i + 1);
  iter[0] = i + sizes[0];
  to_aff = va_arg(list, void *);
  sizes[2] = get_toafflen(fd, str[iter[0] + 1], to_aff);
  iter[1] = fd;
  aff_complex(sizes, iter, to_aff, str);
  return (0);
}

int		do_printf(char *str, va_list list, int fd)
{
  int		i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] == '%' && str[i + 1] != '%' && str[i + 1] != ' '
	  && str[i + 1] != 0 && str[i + 1] != '\n')
	{
	  if (is_intab(str[i + 1]) == 1 && str[i + 1] != 48)
	    simple_format(list, fd, str[i + 1]);
	  else
	    {
	      complex_format(list, fd, str, i);
	      i = i + get_nbrchar(str, i + 1);
	    }
	  i = i + 1;
	}
      else if ((str[i] == '%' && str[i + 1] == '%')
			   || (str[i] == '%' && str[i + 1] == ' '))
	aff_multiplemod(str, fd, &i);
      else
	my_fdputchar(fd, &str[i]);
      i = i + 1;
    }
  return (0);
}

int		my_vdprintf(int fd, char *format, va_list list)
{
  if (format == NULL)
    return (0);
  if (fd < 1)
    return (0);
  do_printf(format, list, fd);
  return (0);
}
