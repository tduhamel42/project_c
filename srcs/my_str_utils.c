/*
** my_str_utils.c for minishell in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Sat Apr  2 12:37:53 2016 tanguy duhamel
** Last update Sun Apr  3 18:11:59 2016 tanguy duhamel
*/

#include <stdlib.h>
#include "my_string.h"

char		*my_epur_str(char *str)
{
  int		i;
  int		j;
  char		*epur_str;

  i = 0;
  j = 0;
  if ((epur_str = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return (NULL);
  while (str[i] != 0)
    {
      while (str[i] == ' ' || str[i] == '\t')
	i++;
      while (str[i] != 0 && str[i] != ' ' && str[i] != '\t')
	epur_str[j++] = str[i++];
      if (str[i] != 0)
	{
	  epur_str[j++] = ' ';
	  i++;
	}
    }
  epur_str[j] = 0;
  return (epur_str);
}

int		my_strcontains(char *str, char c)
{
  int		i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] == c)
	return (1);
      i++;
    }
  return (0);
}
