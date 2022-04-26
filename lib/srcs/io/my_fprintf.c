/*
** my_fprintf.c for my_fprintf in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Thu Mar 24 13:21:53 2016 tanguy duhamel
** Last update Thu Mar 31 15:21:20 2016 tanguy duhamel
*/

#include "my_stdio.h"

int		my_fprintf(t_myfile *file, char *format, ...)
{
  int		ret;
  va_list	list;

  va_start(list, format);
  ret = my_vfprintf(file, format, list);
  va_end(list);
  return (ret);
}
