/*
** csfml.h for whaou in /home/benoit.pingris/delivery/Jeux
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Thu Jun  8 19:35:39 2017 benoit pingris
** Last update Sun Jun 11 17:58:35 2017 benoit pingris
*/

#ifndef CSFML_H_
# define CSFML_H_

# include <SFML/Graphics.h>
# include <SFML/Audio.h>
# include <SFML/Network.h>
# include <SFML/System.h>
# include <SFML/Window.h>
# include "struct.h"

int	game(t_info *);

void	draw_pixel(sfUint8 *, int, int, int);
void	draw_line(sfUint8 *, int, int, int, int, int);
void	draw_shape(sfUint8 *, int, int, int, int, int);
void	draw_text(sfRenderWindow *, char *, t_opt *);

void	check_event(t_vec *, t_info *);
int	collisions(t_info *, int, int);

void	setup_opt(t_opt *, int, int, int, int);
void	setup_vectors(t_vec *, t_info *);

sfUint8	*create_pixel_buffer(int, int);

#endif /* !CSFML_H_ */
