/*
** showtab.c for whaou in /home/benoit.pingris/delivery/Jeux
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Fri Jun  9 21:52:15 2017 benoit pingris
** Last update Fri Jun  9 21:53:19 2017 benoit pingris
*/

#include <stdio.h>

void	showtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    printf("%s\n", tab[i++]);
}
