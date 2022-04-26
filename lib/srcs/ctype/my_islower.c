/*
** my_islower.c for my_islower in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Mon Mar 21 21:57:53 2016 tanguy duhamel
** Last update Mon Mar 21 22:00:45 2016 tanguy duhamel
*/

int		my_islower(int c)
{
  return ((c >= 'a' && c <= 'z') ? 1 : 0);
}
