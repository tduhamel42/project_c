/*
** my_printf.c for my_printf in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Tue Mar 22 23:14:47 2016 tanguy duhamel
** Last update Thu Mar 31 15:20:54 2016 tanguy duhamel
*/

#include "my_stdio.h"

int		my_printf(char *format, ...)
{
  va_list	list;
  int		ret;

  va_start(list, format);
  ret = my_vprintf(format, list);
  va_end(list);
  return (ret);
}
