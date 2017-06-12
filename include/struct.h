/*
** struct.h for whaou in /home/benoit.pingris/delivery/Jeux
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Fri Jun  9 21:19:42 2017 benoit pingris
** Last update Sat Jun 10 23:19:11 2017 benoit pingris
*/

#ifndef STRUCT_H_
# define STRUCT_H_

# include "csfml.h"

typedef struct	s_opt
{
  sfVector2f	pos;
  int		size;
  int		angle;
}		t_opt;

typedef struct	s_vec
{
  sfVector2i	pos;
  sfVector2i    size;
  sfVector2i	dir;
}		t_vec;

typedef struct	s_info
{
  sfRenderWindow	*win;
  sfUint8		*pixels;
  char			**map;
  int			rows;
  int			cols;
}		t_info;

#endif /* !STRUCT_H_ */
