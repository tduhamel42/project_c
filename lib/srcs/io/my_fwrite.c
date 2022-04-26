/*
** my_fwrite.c for my_fwrite in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Tue Mar 22 22:29:36 2016 tanguy duhamel
** Last update Tue Mar 22 22:34:31 2016 tanguy duhamel
*/

#include <unistd.h>
#include "my_stdio.h"

int		my_fwrite(const void *ptr, int size, int nb, t_myfile *file)
{
  int		n;

  size = size * nb;
  if ((n = write(file->fd, ptr, size)) < 1)
    return (0);
  if (n > 1)
    n = n / size;
  return (n);
}
