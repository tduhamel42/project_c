/*
** my_split.c for mu_split in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Sat Mar 26 15:00:05 2016 tanguy duhamel
** Last update Sat Apr  2 11:43:25 2016 tanguy duhamel
*/

#include <stdlib.h>
#include "my_string.h"

int		get_nbr_word(char *str, char separator)
{
  int		i;
  int		nbr;

  i = 0;
  nbr = 0;
  while (str[i] != 0)
    {
      if (str[i] == separator)
	nbr++;
      i++;
    }
  return (++nbr);
}

int		*get_word_sizes(char *str, int nbr_word, char separator)
{
  int		i;
  int		j;
  int		tmp;
  int		*sizes;

  if ((sizes = malloc(sizeof(int) * nbr_word)) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  tmp = 0;
  while (str[i] != 0)
    {
      if (str[i] != separator)
	tmp++;
      if (str[i] == separator || str[i + 1] == 0)
	{
	  sizes[j++] = tmp;
	  tmp = 0;
	}
      i++;
    }
  return (sizes);
}

char		**my_string_tab_alloc(int nbr_word, int *sizes)
{
  int		i;
  char		**tab;

  if ((tab = malloc(sizeof(char *) * (nbr_word + 1))) == NULL)
    return (NULL);
  i = 0;
  while (i < nbr_word)
    {
      if ((tab[i] = malloc(sizeof(char) * (sizes[i] + 1))) == NULL)
	return (NULL);
      i++;
    }
  tab[i] = NULL;
  return (tab);
}

char		**my_split(char *str, char separator)
{
  int		iter[3];
  int		nbr_word;
  int		*sizes;
  char		**tab;

  iter[0] = 0;
  iter[1] = 0;
  iter[2] = 0;
  nbr_word = get_nbr_word(str, separator);
  if ((sizes = get_word_sizes(str, nbr_word, separator)) == NULL)
    return (NULL);
  if ((tab = my_string_tab_alloc(nbr_word, sizes)) == NULL)
    return (NULL);
  while (str[iter[0]] != 0)
    {
      if (str[iter[0]] != separator)
	tab[iter[1]][iter[2]++] = str[iter[0]];
      if (str[iter[0]] == separator || str[iter[0] + 1] == 0)
	{
	  tab[iter[1]++][iter[2]] = 0;
	  iter[2] = 0;
	}
      iter[0]++;
    }
  tab[iter[1]] = (char *)0;
  free(sizes);
  return (tab);
}
