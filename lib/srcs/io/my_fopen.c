/*
** my_fopen.c for my_fopen in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Tue Mar 22 21:44:59 2016 tanguy duhamel
** Last update Tue Mar 22 22:04:58 2016 tanguy duhamel
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "my_stdio.h"

int		get_mode(const char *mode)
{
  int		i;
  int		imode;

  i = 0;
  imode = O_RDONLY;
  while (mode[i] != 0)
    {
      if (mode[i] == 'r')
	{
	  imode = O_RDONLY;
	  if (mode[i + 1] == '+')
	    imode = O_RDWR;
	}
      else if (mode[i] == 'w')
	{
	  imode = (O_WRONLY | O_CREAT | O_TRUNC);
	  if (mode[i + 1] == '+')
	    imode = (O_RDWR | O_CREAT | O_TRUNC);
	}
      i++;
    }
  return (imode);
}

t_myfile	*my_fopen(const char *path, const char *mode)
{
  t_myfile	*file;

  if ((file = malloc(sizeof(t_myfile))) == NULL)
    return (NULL);
  file->mode = get_mode(mode);
  if ((file->fd = open(path, file->mode, S_IRUSR | S_IWUSR
		       | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)) == -1)
    return (NULL);
  return (file);
}

int		my_fclose(t_myfile *file)
{
  if (file->fd)
    close(file->fd);
  free(file);
  return (0);
}
