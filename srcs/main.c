/*
** main.c<mystdlib> for my_stdtest in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Mon Mar 21 15:10:28 2016 tanguy duhamel
** Last update Sun Apr 10 18:11:11 2016 tanguy duhamel
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include "my_stdio.h"
#include "my_string.h"
#include "my_stdlib.h"
#include "minishell.h"

static void	catch_signal(int sig)
{
  if (sig == SIGINT)
    my_printf(GREEN "\n%s" DEFAULT, PS1);
}

int		handle_command(t_shell *shell)
{
  my_printf(GREEN "%s" DEFAULT, shell->ps1);
  while ((shell->line = get_next_line(0)))
    {
      if ((parse_command(&shell->cmd, shell->line)) == ERROR)
	return (ERROR);
      if ((lex_command(shell)) == ERROR)
	return (ERROR);
      if ((exec_command(shell)) == ERROR)
      	return (ERROR);
      free_command(&shell->cmd);
      free(shell->line);
      my_printf(GREEN "%s" DEFAULT, shell->ps1);
    }
  return (0);
}

int		my_shell(int bonus, char **env)
{
  t_shell	*shell;

  if ((signal(SIGINT, catch_signal)) == SIG_ERR)
    return (ERROR);
  if ((shell = init_shell(bonus, env)) == NULL)
    return (ERROR);
  handle_command(shell);
  my_exit(shell);
  return (0);
}

int		main(int argc, char **argv, char **env)
{
  int		bonus;

  bonus = 0;
  if (argc == 2)
    bonus = my_strcmp(argv[1], "--bonus");
  return (my_shell(bonus, env));
}
