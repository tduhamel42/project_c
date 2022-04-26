/*
** linked_list.c for linked_list in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Tue Mar 22 22:44:58 2016 tanguy duhamel
** Last update Thu Mar 31 21:07:34 2016 tanguy duhamel
*/

#include <stdlib.h>
#include "customs.h"

int		get_first_elem(t_llist **list)
{
  if ((*list) != NULL)
    {
      while ((*list)->prev != NULL)
	(*list) = (*list)->prev;
    }
  return (0);
}

int		get_last_elem(t_llist **list)
{
  if ((*list) != NULL)
    {
      while ((*list)->next != NULL)
	(*list) = (*list)->next;
    }
  return (0);
}

int		add_elem(t_llist **list, void *data)
{
  t_llist	*new_elem;

  if ((new_elem = malloc(sizeof(t_llist))) == NULL)
    return (-1);
  new_elem->data = data;
  new_elem->next = NULL;
  if ((*list) != NULL)
    (*list)->next = new_elem;
  new_elem->prev = (*list);
  (*list) = new_elem;
  return (0);
}

int		delete_elem(t_llist *elem, int (*func)(void *))
{
  func(elem->data);
  free(elem);
  return (0);
}
