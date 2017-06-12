/*
** disp_err.c for wahou in /home/benoit.pingris/delivery/Jeux
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Fri Jun  9 21:48:09 2017 benoit pingris
** Last update Fri Jun  9 21:50:04 2017 benoit pingris
*/

#include <stdio.h>
#include "macro.h"

int	disp_err(char *s)
{
  dprintf(2, "%s\n", s);
  return (ERROR);
}
