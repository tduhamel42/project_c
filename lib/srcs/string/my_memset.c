/*
** my_memset.c for my_memset in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Mon Mar 21 21:35:13 2016 tanguy duhamel
** Last update Mon Mar 21 21:40:50 2016 tanguy duhamel
*/

void		*my_memset(void *ptr, int c, int n)
{
  char		*d;

  d = ptr;
  while (n)
    {
      *d++ = c;
      n--;
    }
  return (ptr);
}
