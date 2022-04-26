/*
** my_realloc.c for my_realloc in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Mon Mar 21 20:45:38 2016 tanguy duhamel
** Last update Tue Mar 22 23:01:55 2016 tanguy duhamel
*/

#include <stdlib.h>
#include "my_string.h"

void		*my_realloc(void *ptr, int size)
{
  int		i;
  unsigned char	*new_ptr;
  unsigned char	*old_ptr;

  old_ptr = ptr;
  if (!ptr)
    return (malloc(size));
  if (!size)
    {
      free(ptr);
      return (NULL);
    }
  if ((new_ptr = malloc(size)) == NULL)
    return (NULL);
  while (i < (int)(size - sizeof(old_ptr)))
    {
      *new_ptr++ = *old_ptr++;
      i++;
    }
  free(ptr);
  return (new_ptr);
}
