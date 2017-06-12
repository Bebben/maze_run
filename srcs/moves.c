/*
** moves.c for whaou in /home/benoit.pingris/delivery/Jeux
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Sat Jun 10 14:59:20 2017 benoit pingris
** Last update Sat Jun 10 23:23:53 2017 benoit pingris
*/

#include "macro.h"
#include "csfml.h"

int	collisions(t_info *info, int y_1, int x_1)
{
  int	pos;

  pos = (WIDTH * y_1 + x_1) * 4;
  if (pos >= 0 && pos <= WIDTH * HEIGHT * 4)
    if (info->pixels[pos] != 0 ||
	info->pixels[pos + 1] != 0 ||
	info->pixels[pos + 2] != 0 ||
	info->pixels[pos + 3] != 0)
      return (ERROR);
  return (SUCCESS);
}

void	check_event(t_vec *vec, t_info *info)
{
  if (sfKeyboard_isKeyPressed(sfKeyDown) &&
      vec->pos.y + vec->size.y + MOVE <= HEIGHT &&
      !(collisions(info, vec->pos.y + MOVE + vec->size.y, vec->pos.x)) &&
      !(collisions(info, vec->pos.y + MOVE + vec->size.y, vec->pos.x + vec->size.x)))
    vec->pos.y += MOVE;
  if (sfKeyboard_isKeyPressed(sfKeyUp) &&
      vec->pos.y - MOVE >= 0 &&
      !(collisions(info, vec->pos.y - MOVE, vec->pos.x)) &&
      !(collisions(info, vec->pos.y - MOVE, vec->pos.x + vec->size.x)))
    vec->pos.y -= MOVE;
  if (sfKeyboard_isKeyPressed(sfKeyLeft) &&
      vec->pos.x - MOVE >= 0 &&
      !(collisions(info, vec->pos.y, vec->pos.x - MOVE)) &&
      !(collisions(info, vec->pos.y + vec->size.y, vec->pos.x - MOVE)))
    vec->pos.x -= MOVE;
  if (sfKeyboard_isKeyPressed(sfKeyRight) &&
      vec->pos.x + vec->size.x + MOVE <= WIDTH &&
      !(collisions(info, vec->pos.y, vec->pos.x + MOVE + vec->size.x)) &&
      !(collisions(info, vec->pos.y + vec->size.y, vec->pos.x + vec->size.x+ MOVE)))
    vec->pos.x += MOVE;
  if (sfKeyboard_isKeyPressed(sfKeyQ))
    sfRenderWindow_close(info->win);
}
