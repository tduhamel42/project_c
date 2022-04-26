/*
** my_memcpy.c for my_memcpy in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Mon Mar 21 13:14:04 2016 tanguy duhamel
** Last update Mon Mar 21 21:23:55 2016 tanguy duhamel
*/

#include <stdlib.h>
#include "my_string.h"

void			*my_memcpy(void *dest, void *src, int len)
{
  unsigned char		*d;
  const unsigned char	*s;

  d = dest;
  s = src;
  while (len--)
    *d++ = *s++;
  return (dest);
}
