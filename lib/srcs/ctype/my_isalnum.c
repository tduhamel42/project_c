/*
** my_isalnum.c for my_isalnum in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Mon Mar 21 22:08:52 2016 tanguy duhamel
** Last update Mon Mar 21 22:09:45 2016 tanguy duhamel
*/

#include "my_ctype.h"

int		my_isalnum(int c)
{
  return ((my_isalpha(c) || my_isdigit(c)) ? 1 : 0);
}
