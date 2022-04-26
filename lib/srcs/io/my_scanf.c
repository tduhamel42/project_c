/*
** my_scanf.c for my_scanf in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Sat Mar 26 15:21:41 2016 tanguy duhamel
** Last update Sat Mar 26 15:24:14 2016 tanguy duhamel
*/

#include "my_stdio.h"

int		my_scanf(const char *format, ...)
{
  va_list	list;
  int		ret;

  va_start(list, format);
  ret = my_vscanf(format, list);
  va_end(list);
  return (ret);
}
