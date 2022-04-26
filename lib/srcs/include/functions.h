/*
** functions.h for functions in /home/duhame_t
** 
** Made by tanguy duhamel
** Login   <duhame_t@epitech.net>
** 
** Started on  Thu Mar 31 15:30:51 2016 tanguy duhamel
** Last update Thu Mar 31 15:33:43 2016 tanguy duhamel
*/

#ifndef FUNCTIONS_H_
# define FUNCTIONS_H_

#include "customs.h"

static const t_tabfunc functions[13] = {
  { 'c', &my_fdputchar },
  { 'd', &my_fdputnbr },
  { 'i', &my_fdputnbr },
  { 'u', &my_fdputuint },
  { 'f', &my_fdputfloat },
  { 's', &my_fdputstr },
  { 'S', &my_fdputstr_wnpc },
  { 'x', &my_fdputhexa_l },
  { 'c', &my_fdputhexa_u },
  { 'p', &my_fdputaddress },
  { 'o', &my_fdputoctal },
  { 'b', &my_fdputbinary }
};

#endif /* !FUNCTIONS_H_ */
