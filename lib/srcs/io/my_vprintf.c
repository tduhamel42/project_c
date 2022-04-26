/*
** my_vprintf.c for my_vprintf in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Wed Mar 23 14:31:19 2016 tanguy duhamel
** Last update Thu Mar 31 15:21:02 2016 tanguy duhamel
*/

#include "my_stdio.h"

int		my_vprintf(char *format, va_list list)
{
  int		ret;

  ret = my_vdprintf(1, format, list);
  return (ret);
}
