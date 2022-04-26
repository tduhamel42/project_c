/*
** my_fdputfloat.c for my_fdputfloat in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Thu Mar 31 10:29:59 2016 tanguy duhamel
** Last update Thu Mar 31 15:08:09 2016 tanguy duhamel
*/

#include <stdlib.h>
#include "customs.h"

static char    *my_dec_part(int nbr)
{
  int		i;
  char		*tmp;

  if ((tmp = malloc(sizeof(char) * 7)) == NULL)
    return (NULL);
  if (tmp == NULL)
    return ("-1");
  i = 0;
  while (i < 7)
    tmp[i++] = '0';
  i = 5;
  while (i >= 0)
    {
      tmp[i--] = (nbr % 10) + '0';
      nbr = nbr / 10;
    }
  tmp[6] = '\0';
  return (tmp);
}

int		my_fdputfloat(int fd, void *n)
{
  int		int_part;
  float		dec_part;
  char		*tmp;
  double	nbr;

  nbr = *(double *)n;
  int_part = nbr;
  dec_part = nbr - int_part;
  my_fdputnbr(fd, &int_part);
  my_fdputchar(fd, ".");
  tmp = my_dec_part(dec_part * 1000000);
  if (tmp[0] == '-' && tmp[1] == '1')
    return (-1);
  my_fdputstr(fd, tmp);
  free(tmp);
  return (0);
}
