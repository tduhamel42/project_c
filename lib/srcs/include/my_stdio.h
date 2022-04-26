/*
** my_stdio.h for my_stdio.h in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Mon Mar 21 11:04:06 2016 tanguy duhamel
** Last update Thu Mar 31 15:20:31 2016 tanguy duhamel
*/

#ifndef MY_STDIO_H_
# define MY_STDIO_H_

#include <stdarg.h>

typedef struct	s_myfile
{
  int		fd;
  int		mode;
}		t_myfile;

/*
** Basic output
*/

int		my_putchar(char c); /* DONE */
int		my_puts(char *str); /* DONE */

/*
** Printf family
*/

int		my_printf(char *format, ...); /* DONE */
int		my_fprintf(t_myfile *file, char *format, ...); /* DONE */
int		my_dprintf(int fd, char *format, ...); /* DONE */
int		my_sprintf(char *str, char *format, ...); /* TODO */
int		my_vprintf(char *format, va_list ap); /* DONE */
int		my_vfprintf(t_myfile *file, char *format, va_list ap); /* DONE */
int		my_vdprintf(int fd, char *format, va_list ap); /* TODO */
int		my_vsprintf(char *str, char *format, va_list ap); /* TODO */

/*
** Scanf family
*/

int		my_scanf(const char *format, ...); /* DONE */
int		my_vscanf(const char *format, va_list ap); /* TODO */

/*
** Basic file operation
*/

t_myfile	*my_fopen(const char *path, const char *mode); /* DONE */
int		my_fwrite(const void *ptr, int size, int nb, t_myfile *file); /* DONE */
int		my_fread(void *ptr, int size, int nb, t_myfile *file); /* DONE */
int		my_fclose(t_myfile *file); /* DONE */

/*
** File reading operation
*/

char		*my_fgets(char *s, int size, t_myfile *file); /* TODO */

#endif /* !MY_STDIO_H_ */
