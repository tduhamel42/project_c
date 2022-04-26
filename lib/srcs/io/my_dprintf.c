/*
** my_dprintf.c for my_dprintf in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Thu Mar 24 13:29:35 2016 tanguy duhamel
** Last update Thu Mar 31 15:21:10 2016 tanguy duhamel
*/

#include "my_stdio.h"

int		my_dprintf(int fd, char *format, ...)
{
  int		ret;
  va_list	list;

  va_start(list, format);
  ret = my_vdprintf(fd, format, list);
  va_end(list);
  return (ret);
}
