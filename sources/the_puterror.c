/*
** the_puterror.c for PSU_2015_42sh in sources/tools
**
** Made by Benoit Hamon
** Login   <hamon_e@epitech.net>
**
** Started on  Mon May 30 01:48:05 2016 Benoit Hamon
** Last update Sun Jun 05 21:27:15 2016 Nicolas Goudal
*/

#include <stdio.h>

void			*the_puterror(char const *str,
				      char const *detail)
{
  dprintf(2, str, detail);
  return (NULL);
}

int			the_putserror(char const *str,
				      char const *detail)
{
  dprintf(2, str, detail);
  return (-1);
}
