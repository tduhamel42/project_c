/*
** my_pow.c for my_pow in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Thu Mar 24 09:35:25 2016 tanguy duhamel
** Last update Thu Mar 24 13:55:17 2016 tanguy duhamel
*/

double		my_pow(double x, double y)
{
  if (y < 0)
    return (0);
  return (x * my_pow(x, y - 1));
}
