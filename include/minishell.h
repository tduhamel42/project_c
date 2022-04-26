/*
** minishell.h for minishell2 in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Wed Mar 16 13:30:09 2016 tanguy duhamel
** Last update Sun Apr 10 14:57:58 2016 tanguy duhamel
*/

#ifndef MINISHELL_H_
# define MINISHELL_H_

#include "customs.h"

/*
** Utils
*/

# define ERROR		(-1)
# define PS1		"$> "
# define PIPE		1
# define SEMICOLON      2
# define REDIRECTION	3
# define REDI_RIGHT	4
# define REDI_LEFT	5
# define DREDI_RIGHT	6
# define DREDI_LEFT	7

/*
** Colors
*/

# define DEFAULT	"\e[0m"
# define RED		"\e[31m"
# define BLACK		"\e[30m"
# define GREEN		"\e[32m"
# define YELLOW		"\e[33m"
# define BLUE		"\e[34m"
# define MAGENTA	"\e[35m"
# define CYAN		"\e[36m"
# define WHITE		"\e[97m"

/*
** Buildins
*/

# define CD		1
# define PWD		2
# define SETENV		3
# define UNSETENV	4
# define EXIT		5
# define ENV		6

typedef struct		s_history
{
  char			**args;
  int			len;
}			t_history;

typedef struct		s_cmd
{
  char			**args;
  int			len;
  int			type;
  t_llist		*cmd;
}			t_cmd;

typedef struct		s_shell
{
  char			*ps1;
  char			*line;
  t_llist		*env;
  t_llist		*alias;
  t_llist		*variables;
  t_llist		*cmd;
}			t_shell;

typedef struct		s_tabbuilins
{
  int			buildins;
  int			(*func)(t_shell *);
}			t_tabbuildins;

/*
** Utils
*/

t_shell			*init_shell(int bonus, char **env);
int			free_shell(t_shell *shell);
int			get_tab_len(char **tab);
char			*my_epur_str(char *str);
int			my_strcontains(char *str, char c);
int			open_sright_redirection(char *filename);
int			open_dright_redirection(char *filename);
int			open_sleft_redirection(char *filename);
int			open_dleft_redirection(char *filename);
int			exec_command_for_redir(t_shell *shell, t_llist **list);

/*
** Env utils
*/

int			put_env_in_list(t_llist **env, char **str_env);
int			add_env_var(t_llist **env, t_variable *var);
char			**env_to_tab(t_llist **env);
int			get_nbr_env(t_llist **env);
char			*my_getenv(t_llist **env, char *name);
int			my_setenv(t_llist **env, char *name, char *value);

/*
** Buildins
*/

int			my_cd(t_shell *shell);
int			my_pwd(t_llist **env);
void			my_exit(t_shell *shell);
int			display_env(t_llist **env);
int			is_buildins(char *bin);
int			exec_buildins(t_shell *shell, t_cmd *cmd,
				      int nb_buildins);
int			my_unsetenv(t_llist **list, t_cmd *cmd);
int			my_cmdsetenv(t_shell *shell, t_cmd *cmd);

/*
** Command utils
*/

int			parse_command(t_llist **cmd, char *buffer);
t_cmd			*create_command(char *cmd, int type);
int			lex_command(t_shell *shell);
int			exec_command(t_shell *shell);
int			simple_command(t_shell *shell, t_cmd *cmd);
int			free_command(t_llist **cmd);
char			*get_binary_path(t_shell shell, t_cmd cmd);
int			create_piped_command(t_cmd *cmd);
int			display_error(int status);
int			handle_sleft_redirection(t_shell *shell, t_cmd *cmd);
int			handle_dleft_redirection(t_shell *shell, t_cmd *cmd);
int			redirection_command(t_shell *shell, t_cmd *cmd);

/*
** Exec utils
*/

int			my_simple_exec(char *path, char **args, char **env);
int			piped_command(t_shell *shell, t_cmd *cmd);
int			my_redi_right_exec();
int			my_redi_left_exec();

#endif /* !MINISHELL_H_ */
