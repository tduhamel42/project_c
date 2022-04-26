/*
** my_vfprintf.c for my_vfprintf in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Thu Mar 24 13:34:00 2016 tanguy duhamel
** Last update Thu Mar 31 15:21:30 2016 tanguy duhamel
*/

#include "my_stdio.h"

int		my_vfprintf(t_myfile *file, char *format, va_list list)
{
  int		ret;

  ret = my_vdprintf(file->fd, format, list);
  return (ret);
}
