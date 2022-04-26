/*
** variable_utils.c for variable_utils in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Sat Mar 26 15:09:36 2016 tanguy duhamel
** Last update Tue Apr 12 21:31:49 2016 tanguy duhamel
*/

#include <stdlib.h>
#include "my_string.h"
#include "customs.h"

static int	get_var_name_len(char *str, char sep)
{
  int		i;

  i = 0;
  while (str[i] != sep)
    i++;
  return (i);
}

char		*get_variable_name(char *str, char sep)
{
  int		len;
  int		i;
  char		*name;

  len = get_var_name_len(str, sep);
  if ((name = malloc(sizeof(char) * len + 1)) == NULL)
    return (NULL);
  i = 0;
  while (str[i] != sep)
    {
      name[i] = str[i];
      i++;
    }
  name[i] = 0;
  return (name);
}

char		*get_variable_value(char *str, char sep)
{
  int		i;
  int		j;
  char		*value;
  int		len;

  len = get_var_name_len(str, sep);
  i = len + 1;
  j = 0;
  if ((value = malloc(sizeof(char) * my_strlen(str) - len)) == NULL)
    return (NULL);
  while (str[i] != 0)
    value[j++] = str[i++];
  value[j] = 0;
  return (value);
}

t_variable	*get_variable(char *str, char sep)
{
  t_variable	*var;

  if (str == NULL)
    return (NULL);
  if ((var = malloc(sizeof(t_variable))) == NULL)
    return (NULL);
  if ((var->name = get_variable_name(str, sep)) == NULL)
    return (NULL);
  if ((var->value = get_variable_value(str, sep)) == NULL)
    return (NULL);
  return (var);
}

int		free_variable(t_variable *var)
{
  if (var->name)
    free(var->name);
  if (var->value && my_strlen(var->value) > 0)
    free(var->value);
  free(var);
  return (0);
}
