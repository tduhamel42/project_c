/*
** my_fdputchar.c for my_fdputchar in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Thu Mar 31 09:46:04 2016 tanguy duhamel
** Last update Thu Mar 31 15:28:41 2016 tanguy duhamel
*/

#include <unistd.h>
#include "my_string.h"

int		my_fdputchar(int fd, void *c)
{
  return (write(fd, c, 1));
}

int		my_fdputstr(int fd, void *str)
{
  return (write(fd, str, my_strlen(str)));
}
