/*
** setup.c for whaou in /home/benoit.pingris/delivery/csfml_test
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Sun Jun 11 17:53:25 2017 benoit pingris
** Last update Sun Jun 11 17:59:20 2017 benoit pingris
*/

#include "csfml.h"
#include "macro.h"

void	setup_vectors(t_vec *vec, t_info *info)
{
  vec->size.x = WIDTH / info->cols - MOVE;
  vec->size.y = HEIGHT / info->rows - MOVE;
  vec->pos.x = 0;
  vec->pos.y = 0;
}

void	setup_opt(t_opt *opt, int x, int y, int size, int angle)
{
  opt->pos.x = x;
  opt->pos.y = y;
  opt->size = size;
  opt->angle = angle;
}
