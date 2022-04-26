/*
** my_pwd.c for minishell in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Sat Apr  2 11:20:58 2016 tanguy duhamel
** Last update Sat Apr  2 11:25:26 2016 tanguy duhamel
*/

#include <stdlib.h>
#include "my_stdio.h"
#include "minishell.h"

int		my_pwd(t_llist **env)
{
  char		*pwd;

  if ((pwd = my_getenv(env, "PWD")) == NULL)
    return (ERROR);
  my_printf("%s\n", pwd);
  return (0);
}
