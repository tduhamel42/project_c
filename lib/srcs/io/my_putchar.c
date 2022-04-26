/*
** basic_output.c for my_stdio.h in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Mon Mar 21 11:07:27 2016 tanguy duhamel
** Last update Mon Mar 21 15:02:46 2016 tanguy duhamel
*/

#include <unistd.h>

int		my_putchar(char c)
{
  return (write(1, &c, 1));
}
