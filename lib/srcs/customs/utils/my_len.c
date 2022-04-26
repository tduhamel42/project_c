/*
** my_len.c for my_len in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Thu Mar 31 11:02:26 2016 tanguy duhamel
** Last update Fri Apr  8 21:11:00 2016 tanguy duhamel
*/

int		my_pstrlen(int a, void *st)
{
  int		i;
  char		*str;

  i = 0;
  a = 0;
  a++;
  str = st;
  while (str[i] != 0)
    i++;
  return (i);
}

int		my_nbrlen(int a, void *n)
{
  int		i;
  int		nb;

  i = 0;
  a = 0;
  a++;
  nb = *(int *)n;
  while ((nb / 10) != 0)
    {
      nb = nb / 10;
      i = i + 1;
    }
  return (i + 1);
}

int		my_floatlen(int a, void *n)
{
  int		i;
  int		int_part;
  double	nb;

  i = 0;
  a = 0;
  a++;
  nb = *(double *)n;
  int_part = nb;
  while ((int_part / 10) != 0)
    {
      int_part = int_part / 10;
      i = i + 1;
    }
  return (i + 8);
}

int		my_hexalen(int a, void *n)
{
  int		i;
  unsigned long	nb;

  i = 0;
  a = 0;
  a++;
  nb = *(unsigned long *)n;
  while ((nb / 16) != 0)
    {
      nb = nb / 16;
      i = i + 1;
    }
  return (i + 1);
}

int		my_addlen(int a, void *n)
{
  int		i;
  unsigned long	nb;

  i = 0;
  a = 0;
  a++;
  nb = *(unsigned long *)n;
  while ((nb / 16) != 0)
    {
      nb = nb / 16;
      i = i + 1;
    }
  return (i + 3);
}
