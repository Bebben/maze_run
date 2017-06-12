/*
** game.c for whaou in /home/benoit.pingris/delivery/Jeux
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Fri Jun  9 19:41:14 2017 benoit pingris
** Last update Sun Jun 11 19:26:26 2017 benoit pingris
*/

#include <unistd.h>
#include "csfml.h"
#include "macro.h"

void	reset(sfUint8 *pixels)
{
  int	i;

  i = 0;
  while (i < WIDTH * HEIGHT * 4)
    {
      pixels[i] = 0;
      ++i;
    }
}

void	print_map(t_info *info)
{
  int	i;
  int	j;
  int	x_value;
  int	y_value;

  x_value = WIDTH / info->cols;
  y_value = HEIGHT / info->rows;
  i = 0;
  while (i < info->rows)
    {
      j = 0;
      while (j < info->cols)
	{
	  if (info->map[i][j] == '1')
	    draw_shape(info->pixels, j * x_value, i * y_value, x_value, y_value, 0);
	  ++j;
	}
      ++i;
    }
}

int	end_game(t_info *info, sfSprite *sprite)
{
  t_opt	opt;

  setup_opt(&opt, WIDTH / 3, HEIGHT / 2, 30, 0);
  sfRenderWindow_clear(info->win, sfBlack);
  sfRenderWindow_drawSprite(info->win, sprite, NULL);
  draw_text(info->win, END_MSG, &opt);
  sfRenderWindow_display(info->win);
  sleep(2);
  return (SUCCESS);
}

int	game(t_info *info)
{
  sfTexture	*texture;
  sfSprite	*sprite;
  t_vec		vec;

  setup_vectors(&vec, info);
  sprite = sfSprite_create();
  texture = sfTexture_create(WIDTH, HEIGHT);
  sfSprite_setTexture(sprite, texture, sfTrue);
  while (sfRenderWindow_isOpen(info->win))
    {
      if (vec.pos.x + vec.size.y >= WIDTH - MOVE && vec.pos.y + vec.size.y>= HEIGHT - MOVE)
	return (end_game(info, sprite));
      print_map(info);
      draw_shape(info->pixels, vec.pos.x, vec.pos.y, vec.size.x, vec.size.y, 210);
      check_event(&vec, info);
      sfTexture_updateFromPixels(texture, info->pixels, WIDTH, HEIGHT, 0, 0);
      sfRenderWindow_clear(info->win, sfBlack);
      sfRenderWindow_drawSprite(info->win, sprite, NULL);
      sfRenderWindow_display(info->win);
      reset(info->pixels);
    }
  return (SUCCESS);
}
