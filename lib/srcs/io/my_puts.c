/*
** my_puts.c for my_puts in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Mon Mar 21 14:58:12 2016 tanguy duhamel
** Last update Mon Mar 21 15:05:38 2016 tanguy duhamel
*/

#include <unistd.h>
#include "my_string.h"

int		my_puts(char *str)
{
  if ((write(1, str, my_strlen(str))) == -1)
    return (-1);
  if ((write(1, "\n", 1)) == -1)
    return (-1);
  return (0);
}
