/*
** main.c for wahou in /home/benoit.pingris/delivery/Jeux
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Thu Jun  8 19:36:11 2017 benoit pingris
** Last update Mon Jun 12 23:25:37 2017 benoit pingris
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "useful.h"
#include "macro.h"
#include "get_next_line.h"
#include "csfml.h"

sfRenderWindow		*create_window(char* name, int width, int height)
{
  sfRenderWindow	*window;
  sfVideoMode		mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  if (!(window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL)))
    return (NULL);
  return (window);
}

sfUint8			*create_pixel_buffer(int width, int height)
{
  sfUint8		*pixels;
  int			i;

  if (!(pixels = malloc(width * height * 4 * sizeof(*pixels))))
    return (NULL);
  i = 0;
  while (i < width * height * 4)
    {
      pixels[i] = 0;
      i = i + 1;
    }
  return pixels;
}

int	get_size(char *file)
{
  char	*s;
  int	fd;
  int	i;

  i = 0;
  if ((fd = open(file, O_RDONLY)) == -1)
    return (-1);
  while ((s = get_next_line(fd)))
    {
      ++i;
      free(s);
    }
  close(fd);
  return (i);
}

char	**get_map(char *file)
{
  int	fd;
  int	len;
  int	i;
  char	**tab;
  char	*s;

  i = 0;
  if ((len = get_size(file)) == -1 ||
      (fd = open(file, O_RDONLY)) == -1 ||
      !(tab = malloc(sizeof(char *) * (len + 1))))
    return (NULL);
  while ((s = get_next_line(fd)))
    {
      if ((tab[i++] = strdup(s)) == NULL)
	return (NULL);
      free(s);
    }
  tab[i] = NULL;
  close(fd);
  showtab(tab);
  return (tab);
}

void	print_menu(t_opt opt, t_info *info)
{
  setup_opt(&opt, WIDTH / 3, 50, 50, 0);
  sfRenderWindow_clear(info->win, sfBlack);
  draw_text(info->win, WELCOME, &opt);
  setup_opt(&opt, WIDTH / 3, 200, 50, 0);
  draw_text(info->win, M_1, &opt);
  setup_opt(&opt, WIDTH / 3, 270, 50, 0);
  draw_text(info->win, M_2, &opt);
  sfRenderWindow_display(info->win);
}

/* void		menu(t_info *info) */
/* { */
/*   sfVector2i	mouse; */
/*   sfEvent	event; */
/*   t_opt		opt; */
/*   int		level; */

/*   level = 0; */
/*   while (level == 0) */
/*     { */
/*       print_menu(opt, info); */
/*       mouse = sfMouse_getPositionRenderWindow(info->win); */
/*       if (mouse.x >= WIDTH / 3 && mouse.x <= WIDTH && */
/* 	  mouse.y >= 200 && mouse.y <= 500) */
/* 	level = 1; */
/*     } */
/* } */

int	main(int ac, char **av)
{
  struct stat		st;
  t_info		info;
  int			ret;

  if (ac == 1)
    return (disp_err(MISSING_FILE));
  ret = SUCCESS;
  if (stat(av[1], &st) == -1 ||
      st.st_size == 0 ||
      !(info.map = get_map(av[1])) ||
      (check_err(info.map) == ERROR) ||
      !(info.win = create_window("Whaou", WIDTH, HEIGHT)) ||
      !(info.pixels = create_pixel_buffer(WIDTH, HEIGHT)) ||
      (info.rows = get_size(av[1])) == -1)
    return (ERROR);
  info.cols = strlen(info.map[0]);
  sfRenderWindow_setVerticalSyncEnabled(info.win, sfTrue);
  //  menu(&info);
  ret = game(&info);
  return (ret);
}
