/*
** my_strcpy.c for my_strcpy.c in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Mon Mar 21 13:15:12 2016 tanguy duhamel
** Last update Mon Mar 21 21:24:33 2016 tanguy duhamel
*/

#include "my_string.h"

char		*my_strcpy(char *dest, char *src)
{
  return (my_memcpy(dest, src, my_strlen(src) + 1));
}
