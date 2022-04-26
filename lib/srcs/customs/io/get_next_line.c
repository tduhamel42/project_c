/*
** get_next_line.c<customs> for get_next_line in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Tue Mar 22 22:13:40 2016 tanguy duhamel
** Last update Tue Mar 22 22:24:28 2016 tanguy duhamel
*/

#include <unistd.h>
#include <stdlib.h>
#include "customs.h"

int			add_char(t_lchar **list, char c)
{
  t_lchar		*tmp;
  t_lchar		*new_char;

  if ((new_char = malloc(sizeof(t_lchar))) == NULL)
    return (-1);
  new_char->c = c;
  new_char->next = NULL;
  if ((*list) == NULL)
    {
      (*list) = new_char;
      return (0);
    }
  tmp = (*list);
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new_char;
  return (0);
}

int			my_get_str_size(t_lchar *list)
{
  int			size;
  t_lchar		*tmp;

  size = 0;
  tmp = list;
  while (tmp != NULL)
    {
      if (tmp->c == 0 || tmp->c == '\n')
	return (size);
      size++;
      tmp = tmp->next;
    }
  return (size);
}

int			my_get_is_end_line(t_lchar *list)
{
  t_lchar		*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      if (tmp->c == 0 || tmp->c == '\n')
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

char			*my_list_to_str(t_lchar **list)
{
  int			i;
  t_lchar		*tmp;
  char			*str;

  i = 0;
  if ((*list) == NULL)
    return (NULL);
  if ((str = malloc(sizeof(char) * (my_get_str_size((*list)) + 1))) == NULL)
    return (NULL);
  while ((*list)->next != NULL && (*list)->c != 0 && (*list)->c != '\n')
    {
      tmp = (*list);
      str[i++] = (*list)->c;
      (*list) = (*list)->next;
      free(tmp);
    }
  str[i] = 0;
  tmp = (*list);
  (*list) = (*list)->next;
  free(tmp);
  return (str);
}

char			*get_next_line(const int fd)
{
  static t_lchar	*list;
  char			buffer[READ_SIZE];
  int			i;
  int			n;

  i = 0;
  if (my_get_is_end_line(list))
    return (my_list_to_str(&list));
  while (i < READ_SIZE)
    buffer[i++] = 0;
  if ((n = read(fd, buffer, READ_SIZE)) < 0)
    return (NULL);
  if (n == 0)
    return (my_list_to_str(&list));
  i = 0;
  while (i < n)
    if ((add_char(&list, buffer[i++])) == -1)
      return (NULL);
  if (my_get_is_end_line(list))
    return (my_list_to_str(&list));
  return (get_next_line(fd));
}
