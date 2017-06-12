/*
** draw.c for wahou in /home/benoit.pingris/delivery/Jeux
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Fri Jun  9 19:26:17 2017 benoit pingris
** Last update Sat Jun 10 23:23:21 2017 benoit pingris
*/

#include <stdlib.h>
#include "macro.h"
#include "csfml.h"

void			swap(int *x1, int *x2)
{
  int			tmp;

  tmp = *x2;
  *x2 = *x1;
  *x1 = tmp;
}

void			draw_pixel(sfUint8 *pixels, int x, int y, int color)
{
  pixels[(WIDTH * y + x) * 4] = sfRed.r;
  pixels[(WIDTH * y + x) * 4 + 1] = sfRed.g + color * 2;
  pixels[(WIDTH * y + x) * 4 + 2] = sfRed.b + color;
  pixels[(WIDTH * y + x) * 4 + 3] = sfRed.a;
}

void			draw_line(sfUint8 *pixels, int x1, int y1,
				  int x2, int y2, int color)
{
  int			dx;
  int			dy;
  int			x;
  int			y;

  if (x1 >= x2)
    {
      swap(&x1, &x2);
      swap(&y1, &y2);
    }
  x = x1;
  dx = x2 - x1;
  dy = y2 - y1;  
  while (x < x2)
    {
      y = y1 + dy * (x - x1) / dx;
      draw_pixel(pixels, x, y, color);
      ++x;
    }
}

void			draw_shape(sfUint8 *pixels, int x, int y, int width, int height, int color)
{
  int			i;

  i = 0;
  while (i < height)
    {
      draw_line(pixels, x, y + i, x + width, y + i, color);
      ++i;
    }
}

void			draw_text(sfRenderWindow *win, char *s, t_opt *opt)
{
  sfText		*text;
  sfFont		*font;

  text = sfText_create();
  font = sfFont_createFromFile("open.ttf");
  sfText_setString(text, s);
  sfText_setFont(text, font);
  sfText_setCharacterSize(text, opt->size);
  sfText_setColor(text, sfWhite);
  sfText_rotate(text, opt->angle);
  sfText_setPosition(text, opt->pos);
  sfRenderWindow_drawText(win, text, NULL);
  sfText_destroy(text);
  sfFont_destroy(font);  
}
