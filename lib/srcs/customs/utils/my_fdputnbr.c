/*
** my_fdputnbr.c for my_fdputnbr in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Thu Mar 31 09:48:22 2016 tanguy duhamel
** Last update Thu Mar 31 15:31:54 2016 tanguy duhamel
*/

#include <unistd.h>
#include "functions.h"

int		my_fdputnbr(int fd, void *n)
{
  int		nb;

  nb = *(int *)(n);
  if (nb < 0)
    {
      my_fdputchar(fd, "-");
      nb = -nb;
    }
  if (nb / 10 != 0)
    {
      nb = nb / 10;
      my_fdputnbr(fd, &nb);
    }
  nb = (nb * 10) % 10 + '0';
  my_fdputchar(fd, &nb);
  return (0);
}

int		my_fdputuint(int fd, void *n)
{
  unsigned int	nb;

  nb = *(unsigned int *)n;
  if (nb / 10 != 0)
    {
      nb = nb / 10;
      my_fdputnbr(fd, &nb);
    }
  nb = (nb * 10) % 10 + '0';
  my_fdputchar(fd, &nb);
  return (0);
}

int		my_fdputlong(int fd, void *n)
{
  long		nb;

  nb = *(long *)n;
  if (nb < 0)
    {
      my_fdputchar(fd, "-");
      nb = -nb;
    }
  if (nb / 10 != 0)
    {
      nb = nb / 10;
      my_fdputlong(fd, &nb);
    }
  nb = (nb * 10) % 10 + '0';
  my_fdputchar(fd, &nb);
  return (0);
}

int		my_fdputshort(int fd, void *n)
{
  short		nb;

  nb = *(short *)n;
  if (nb < 0)
    {
      my_fdputchar(fd, "-");
      nb = -nb;
    }
  if (nb / 10 != 0)
    {
      nb = nb / 10;
      my_fdputshort(fd, &nb);
    }
  nb = (nb * 10) % 10 + '0';
  my_fdputchar(fd, &nb);
  return (0);
}

int		my_fdputaddress(int fd, void *n)
{
  unsigned long	add;

  add = *(unsigned long *)n;
  my_fdputstr(fd, "0x");
  my_fdputhexa_l(fd, &add);
  return (0);
}
