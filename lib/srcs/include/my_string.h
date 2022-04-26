/*
** my_string.h for my_string in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Mon Mar 21 10:53:02 2016 tanguy duhamel
** Last update Sun Mar 27 21:48:13 2016 tanguy duhamel
*/

#ifndef MY_STRING_H_
# define MY_STRING_H_

/*
** Basic string utils
*/

int		my_strlen(char *str);
char		*my_strdup(char *str);
char		*my_strcat(char *str1, char *str2);
char		*my_strcpy(char *str1, char *str2);
char		*my_strncpy(char *dest, char *src, int size);
char		*my_strrev(char *str);
char		*my_strtok(char *str, const char *delimiter);

/*
** String comparison
*/

int		my_strcasecmp(char *str1, char *str2);
int		my_strncasecmp(char *str1, char *str2, int n);
char		*my_strchr(char *str, int c);
char		*my_strrchr(char *str, int c);
int		my_strcmp(char *s1, char *s2);
char		*my_strstr(char *str, char *to_find);

/*
** Memory
*/

void		*my_memcpy(void *dest, void *src, int size);
void		*my_memset(void *ptr, int c, int n);

#endif /* !MY_STRING_H_ */
