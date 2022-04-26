/*
** my_convert_base.c for my_convert_base in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Thu Mar 31 10:17:04 2016 tanguy duhamel
** Last update Thu Mar 31 15:08:42 2016 tanguy duhamel
*/

#include "customs.h"

int		my_fdputbinary(int fd, void *n)
{
  unsigned int	nb;

  nb = *(unsigned int *)n;
  if ((nb / 2) != 0)
    {
      nb = nb / 2;
      my_fdputbinary(fd, &nb);
    }
  nb = nb * 2;
  nb = (nb % 2) + 48;
  my_fdputchar(fd, &nb);
  return (0);
}

int		my_fdputoctal(int fd, void *n)
{
  unsigned int	nb;

  nb = *(unsigned int *)n;
  if ((nb / 8) != 0)
    {
      nb = nb / 8;
      my_fdputoctal(fd, &nb);
    }
  nb = nb * 8;
  nb = (nb % 8) + 48;
  my_fdputchar(fd, &nb);
  return (0);
}

int		my_fdputhexa_l(int fd, void *n)
{
  unsigned long	nb;

  nb = *(unsigned long *)n;
  if ((nb / 16) != 0)
    {
      nb = nb / 16;
      my_fdputhexa_l(fd, &nb);
    }
  nb = nb * 16;
  if ((nb % 16) > 9)
    {
      nb = ((nb % 16) - 9) + 96;
      my_fdputchar(fd, &nb);
    }
  else
    {
      nb = (nb % 16) + 48;
      my_fdputchar(fd, &nb);
    }
  return (0);
}

int		my_fdputhexa_u(int fd, void *n)
{
  unsigned int	nb;

  nb = *(unsigned int *)n;
  if ((nb / 16) != 0)
    {
      nb = nb / 16;
      my_fdputhexa_u(fd, &nb);
    }
  nb = nb * 16;
  if ((nb % 16) > 9)
    {
      nb = ((nb % 16) - 9) + 64;
      my_fdputchar(fd, &nb);
    }
  else
    {
      nb = (nb % 16) + 48;
      my_fdputchar(fd, &nb);
    }
  return (0);
}
