/*
** my_strtol.c for my_strtol in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Wed Mar 23 14:46:14 2016 tanguy duhamel
** Last update Sun Apr 10 17:25:13 2016 tanguy duhamel
*/

#include <stdlib.h>
#include "my_string.h"
#include "my_ctype.h"
#include "my_stdlib.h"

int			get_ascii_value(char c)
{
  if (c >= '0' && c <= '9')
    return (c - 48);
  if (c >= 'a' && c <= 'f')
    return (c - 'a' + 10);
  if (c >= 'A' && c <= 'F')
    return (c - 'A' + 10);
  return (0);
}

int			get_sign(char *str, int *i)
{
  int			sign;

  sign = 1;
  while (str[*i] == '+' || str[*i] == '-')
    {
      if (str[*i] == '-')
	sign *= -1;
      *i++;
    }
  *i = *i + *i - *i;
  return (sign);
}

int			get_base(char *str, int base, int *i)
{
  if (base == 0)
    {
      if (str[*i] == '0' && str[*i] == 'x')
	{
	  *i += 2;
	  return (16);
	}
      else
	return (10);
    }
  return (base);
}

long int		my_strtol(char *str, char **endptr, int base)
{
  long int		ret;
  long int		tmp;
  int			sign;
  int			i;

  ret = 0;
  i = 0;
  if (base < 0 ||  base == 1 || base > 36 || str == NULL)
    return (-1);
  sign = get_sign(str, &i);
  base = get_base(str, base, &i);
  while (str[i] != 0)
    {
      tmp = get_ascii_value(str[i++]);
      if (tmp == -1 || tmp >= base)
	i = my_strlen(str);
      else
	{
	  ret = ret * base;
	  ret = ret + tmp;
	}
    }
  endptr++;
  return (ret * sign);
}
