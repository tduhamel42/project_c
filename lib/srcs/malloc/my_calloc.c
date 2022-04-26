/*
** my_calloc.c for my_calloc in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Mon Mar 21 21:26:19 2016 tanguy duhamel
** Last update Mon Mar 21 21:34:53 2016 tanguy duhamel
*/

#include <stdlib.h>
#include "my_string.h"

void		*my_calloc(int nb, int size)
{
  void		*ptr;

  if (!size)
    return (NULL);
  if ((ptr = malloc(size * nb)) == NULL)
    return (NULL);
  my_memset(ptr, 0, size * nb);
  return  (ptr);
}
