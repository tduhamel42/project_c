/*
** printf_advanced_utils.c for printf_advanced_utils in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Thu Mar 31 10:45:27 2016 tanguy duhamel
** Last update Thu Mar 31 15:17:19 2016 tanguy duhamel
*/

#include "my_string.h"
#include "customs.h"

static const t_tabfunc formatslen[8] = {
  { 's', &my_pstrlen },
  { 'i', &my_nbrlen },
  { 'd', &my_nbrlen },
  { 'u', &my_nbrlen },
  { 'f', &my_floatlen },
  { 'x', &my_hexalen },
  { 'X', &my_hexalen },
  { 'p', &my_addlen }
};

int	my_putcmp(int *n, int cmp)
{
  *n = cmp;
  return (cmp);
}

int	get_nbrchar(const char *str, int i)
{
  int	size;

  size = 0;
  while (str[i] >= '0' && str[i] <= '9')
    {
      size = size + 1;
      i = i + 1;
    }
  return (size);
}

int	get_nbrspaces(const char *str, int i)
{
  int	nb;

  nb = 0;
  if (str[i] == 0)
    return (0);
  while (str[i] <= '9' && str[i] >= '0')
    nb = (nb + (str[i++] - 48)) * 10;
  return (nb / 10);
}

int	get_toafflen(int fd, char character, void *to_aff)
{
  int	j;
  int	size;

  j = 0;
  size = 0;
  while (formatslen[j].character != character)
    j = j + 1;
  size = formatslen[j].func(fd, &to_aff);
  return (size);
}
