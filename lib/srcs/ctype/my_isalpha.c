/*
** my_isalpha.c for my_isalpha in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Mon Mar 21 22:03:48 2016 tanguy duhamel
** Last update Mon Mar 21 22:04:38 2016 tanguy duhamel
*/

#include "my_ctype.h"

int		my_isalpha(int c)
{
  return ((my_islower(c) || my_isupper(c)) ? 1 : 0);
}
