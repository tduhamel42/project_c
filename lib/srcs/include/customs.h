/*
** customs.h for customs.h in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Tue Mar 22 22:14:41 2016 tanguy duhamel
** Last update Thu Mar 31 15:44:05 2016 tanguy duhamel
*/

#ifndef CUSTOMS_H_
# define CUSTOMS_H_

#ifndef READ_SIZE
# define READ_SIZE (14)
#endif /* !READ_SIZE */

typedef struct	s_lchar
{
  char		c;
  void		*next;
  void		*prev;
}		t_lchar;

typedef struct	s_variable
{
  char		*name;
  char		*value;
}		t_variable;

typedef struct	s_llist
{
  void		*data;
  void		*next;
  void		*prev;
}		t_llist;

typedef struct	s_btreenode
{
  void		*data;
  void		*right;
  void		*left;
}		t_btreenode;

typedef struct	s_tabfunc
{
  char		character;
  int		(*func)(int, void *);
}		t_tabfunc;

/*
** Custom file utils
*/

char		*get_next_line(const int fd); /* DONE */

/*
** Linked list utils
*/

int		add_elem(t_llist **list, void *data); /* DONE */
int		delete_elem(t_llist **list, t_llist *elem, int (*func)(void *)); /* TODO */
int		get_first_elem(t_llist **list); /* DONE */
int		get_last_elem(t_llist **list); /* DONE */

/*
** Binary tree utils
*/

int		add_node(t_btreenode **tree, int value, void *data);
int		delete_node(t_btreenode **tree);

/*
** Variable utils
*/

t_variable	*get_variable(char *str_variable, char sep); /* TODO */
char		*get_variable_name(char *str_variable, char sep); /* TODO */
char		*get_varible_value(char *str_variable, char sep); /* TODO */
int		free_variable(t_variable *variable); /* DONE */

/*
** String utils
*/

char		*my_str_realcat(char *str1, char *str2);
char		**my_split(char *str, char separator);
char		*my_str_replace(char *str, char *to_replace, char *replace);

/*
** Free utils
*/

int		free_dtab(void **tab, int len);

/*
** Printf utils
*/

int		my_fdputchar(int fd, void *c);
int		my_fdputstr(int fd, void *str);
int		my_fdputnbr(int fd, void *nb);
int		my_fdputuint(int fd, void *nb);
int		my_fdputlong(int fd, void *nb);
int		my_fdputshort(int fd, void *nb);
int		my_fdputaddress(int fd, void *add);
int		my_fdputstr_wnpc(int fd, void *str);
int		my_fdputhexa_u(int fd, void *nb);
int		my_fdputhexa_l(int fd, void *nb);
int		my_fdputoctal(int fd, void *nb);
int		my_fdputbinary(int fd, void *nb);
int		my_fdputfloat(int fd, void *nbr);
int		is_intab(char c);
int		aff_complex(int *sizes, int *iter, void *to_aff, const char *str);
int		get_nbrchar(const char *str, int i);
int		get_nbrspaces(const char *str, int i);
int		get_nbrchar(const char *str, int i);
int		get_toafflen(int fd, char character, void *to_aff);
int		my_addlen(int a, void *n);
int		my_hexalen(int a, void *n);
int		my_floatlen(int a, void *n);
int		my_nbrlen(int a, void *n);
int		my_pstrlen(int a, void *n);

#endif /* !CUSTOMS_H_ */
