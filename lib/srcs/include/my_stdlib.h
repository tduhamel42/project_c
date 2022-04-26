/*
** my_stdlib.h for my_stdlib in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Mon Mar 21 20:43:33 2016 tanguy duhamel
** Last update Sat Mar 26 14:50:48 2016 tanguy duhamel
*/

#ifndef MY_STDLIB_H_
# define MY_STDLIB_H_

/*
** Realloc, calloc
*/

void		*my_realloc(void *ptr, int size); /* DONE */
void		*my_calloc(int nb, int size); /* DONE */

/*
** String conversion
*/

long int	my_strtol(char *str, char **endptr, int base); /* DONE */
int		my_atoi(char *str); /* DONE */
char		*my_itoa(int nb, int base); /* DONE */

/*
** Environnement utils
*/

char		*my_getenv(char *name); /* TODO */

#endif /* !MY_STDLIB_H_ */
