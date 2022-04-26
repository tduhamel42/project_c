/*
** my_atoi.c for my_atoi in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Wed Mar 23 14:43:31 2016 tanguy duhamel
** Last update Sat Mar 26 11:01:53 2016 tanguy duhamel
*/

#include <stdlib.h>
#include "my_stdlib.h"

int		my_atoi(char *str)
{
  return (my_strtol(str, NULL, 10));
}
