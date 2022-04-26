/*
** open_redirection_utils.c for minishell in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Sun Apr 10 11:30:04 2016 tanguy duhamel
** Last update Sun Apr 10 15:03:01 2016 tanguy duhamel
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "my_stdio.h"
#include "minishell.h"

int		open_sright_redirection(char *filename)
{
  int		fd;

  filename = my_epur_str(filename);
  if ((fd = open(filename, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR
		 | S_IRGRP | S_IROTH)) == ERROR)
    return (ERROR);
  return (fd);
}

int		open_dright_redirection(char *filename)
{
  int		fd;

  filename = my_epur_str(filename);
  if ((fd = open(filename, O_CREAT | O_APPEND | O_RDWR, S_IRUSR | S_IWUSR
		 | S_IRGRP | S_IROTH)) == ERROR)
    return (ERROR);
  return (fd);
}

int		open_sleft_redirection(char *filename)
{
  int		fd;

  filename = my_epur_str(filename);
  if ((fd = open(filename, O_RDONLY, S_IRUSR | S_IWUSR
		 | S_IRGRP | S_IROTH)) == ERROR)
    {
      my_dprintf(1, RED "%s: Aucun fichier ou dossier de ce type.\n" DEFAULT,
		 filename);
      return (ERROR);
    }
  return (fd);
}

int		open_dleft_redirection(char *filename)
{
  int		fd;

  filename = my_epur_str(filename);
  if ((fd = open(filename, O_RDONLY, S_IRUSR | S_IWUSR
		 | S_IRGRP | S_IROTH)) == ERROR)
    return (ERROR);
  return (fd);
}
