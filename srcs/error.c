/*
** error.c for whaou in /home/benoit.pingris/delivery/Jeux
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Fri Jun  9 22:49:26 2017 benoit pingris
** Last update Sat Jun 10 10:40:10 2017 benoit pingris
*/

#include <string.h>
#include "useful.h"
#include "macro.h"

int		check_rows(char **map)
{
  int		i;
  size_t	nb;

  i = 0;
  nb = strlen(map[0]);
  while (map[i])
    {
      if (strlen(map[i]) != nb)
	return (disp_err(WEIRD_SHAPE));
      ++i;
    }
  return (SUCCESS);
}

int		is_char_ok(char **map)
{
  int		i;
  int		j;

  i = 0;
  while (map[i])
    {
      j = 0;
      while (map[i][j])
	{
	  if (map[i][j] != '0' && map[i][j] != '1')
	    return (disp_err(BAD_FILE));
	  ++j;
	}
      ++i;
    }
  return (SUCCESS);
}

int		check_err(char **map)
{
  if (check_rows(map) == ERROR ||
      is_char_ok(map) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
