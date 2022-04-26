/*
** my_isblank.c for my_isblank in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Mon Mar 21 22:10:38 2016 tanguy duhamel
** Last update Mon Mar 21 22:11:14 2016 tanguy duhamel
*/

int		my_isblank(int c)
{
  return ((c == ' ' || c == '\t') ? 1 : 0);
}
