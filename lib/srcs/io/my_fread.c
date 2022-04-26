/*
** my_fread.c for my_fread in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Tue Mar 22 22:31:42 2016 tanguy duhamel
** Last update Tue Mar 22 22:37:02 2016 tanguy duhamel
*/

#include <unistd.h>
#include "my_stdio.h"

int		my_fread(void *ptr, int size, int nb, t_myfile *file)
{
  int		n;

  size = size * nb;
  if ((n = read(file->fd, ptr, size)) < 1)
    return (0);
  if (n > 1)
    n = n / size;
  return (n);
}
