/*
** my_stdlib.h for my_stdlib in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Mon Mar 21 20:43:33 2016 tanguy duhamel
** Last update Fri Apr  8 20:59:52 2016 tanguy duhamel
*/

#ifndef MY_STDLIB_H_
# define MY_STDLIB_H_

/*
** Realloc, calloc
*/

void		*my_realloc(void *ptr, int size);
void		*my_calloc(int nb, int size);

/*
** String conversion
*/

long int	my_strtol(char *str, char **endptr, int base);
int		my_atoi(char *str);
char		*my_itoa(int nb, int base);

#endif /* !MY_STDLIB_H_ */
