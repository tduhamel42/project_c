/*
** my_itoa.c for my_itoa in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Wed Mar 23 22:46:31 2016 tanguy duhamel
** Last update Fri Apr  8 21:16:24 2016 tanguy duhamel
*/

#include <stdlib.h>
#include "customs.h"
#include "my_stdlib.h"
#include "my_string.h"

int		get_number_digits(int nb)
{
  int		i;
  int		nbr;

  i = 10;
  nbr = 0;
  while (nb / i)
    {
      nbr++;
      i *= 10;
    }
  return (nbr + 1);
}

char		get_char(int nb)
{
  int		i;
  int		j;
  char		digits[16];

  i = 48;
  j = 0;
  while (j < 15)
    {
      if (i == ':')
	i += 7;
      digits[j++] = i;
      i++;
    }
  return (digits[nb]);

}

char		*my_itoa(int nb, int base)
{
  char		*nbr;
  int		nbr_digits;
  int		i;

  nbr_digits = get_number_digits(nb);
  if ((nbr = malloc(sizeof(int) * nbr_digits + 1)) == NULL)
      return (NULL);
  i = 0;
  if (nb == 0)
    {
      nbr[0] = '0';
      nbr[1] = 0;
      return (nbr);
    }
  while (nb > 0)
    {
      if (i >= nbr_digits)
	return (NULL);
      nbr[i] = get_char(nb % base);
      nb = nb / base;
      i++;
    }
  nbr[i] = 0;
  nbr = my_strrev(nbr);
  return (nbr);
}
