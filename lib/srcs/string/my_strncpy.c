/*
** my_strncpy.c for my_strncpy in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Mon Mar 21 14:52:00 2016 tanguy duhamel
** Last update Fri Apr  8 21:15:06 2016 tanguy duhamel
*/

#include "my_string.h"

char		*my_strncpy(char *dest, char *src, int n)
{
  int		i;

  while (src[i] != 0)
    {
      dest[i] = src[i];
      i++;
    }
  while (i < n)
    dest[i] = 0;
  return (dest);
}
