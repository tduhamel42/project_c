/*
** my_isdigit.c for my_isdigit in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Mon Mar 21 22:05:18 2016 tanguy duhamel
** Last update Mon Mar 21 22:06:08 2016 tanguy duhamel
*/

int		my_isdigit(int c)
{
  return ((c >= '0' && c <= '9') ? 1 : 0);
}
