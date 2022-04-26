/*
** my_stdio.h for my_stdio.h in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Mon Mar 21 11:04:06 2016 tanguy duhamel
** Last update Fri Apr  8 21:04:28 2016 tanguy duhamel
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

int		my_putchar(char c);
int		my_puts(char *str);

/*
** Printf family
*/

int		my_printf(char *format, ...);
int		my_fprintf(t_myfile *file, char *format, ...);
int		my_dprintf(int fd, char *format, ...);
int		my_sprintf(char *str, char *format, ...);
int		my_vprintf(char *format, va_list ap);
int		my_vfprintf(t_myfile *file, char *format, va_list ap);
int		my_vdprintf(int fd, char *format, va_list ap);
int		my_vsprintf(char *str, char *format, va_list ap);

/*
** Scanf family
*/

int		my_scanf(const char *format, ...);
int		my_vscanf(const char *format, va_list ap);

/*
** Basic file operation
*/

t_myfile	*my_fopen(const char *path, const char *mode);
int		my_fwrite(const void *ptr, int size,
			  int nb, t_myfile *file);
int		my_fread(void *ptr, int size, int nb, t_myfile *file);
int		my_fclose(t_myfile *file);

/*
** File reading operation
*/

char		*my_fgets(char *s, int size, t_myfile *file);

#endif /* !MY_STDIO_H_ */
