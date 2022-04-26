/*
** my_strcat.c for my_strcat in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Mon Mar 21 13:06:11 2016 tanguy duhamel
** Last update Mon Mar 21 21:15:21 2016 tanguy duhamel
*/

#include "my_string.h"

char		*my_strcat(char *str1, char *str2)
{
  return (my_strcpy(str1 + my_strlen(str1), str2));
}
