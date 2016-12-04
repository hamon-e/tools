/*
** the_itoa.c for the_lib in sources
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Fri Mar 11 07:22:49 2016 Nicolas Goudal
** Last update Sun Dec 04 12:48:51 2016 Benoit Hamon
*/

#include <stdlib.h>
#include "tools.h"

static int	count(int nbr)
{
  int		i;

  i = 0;
  if (nbr == 0)
    return (1);
  if (nbr < 0)
  {
    ++i;
    nbr = -nbr;
  }
  while (nbr)
  {
    ++i;
    nbr /= 10;
  }
  return (i);
}

char		*the_itoa(int nbr)
{
  char		*res;
  int		i;

  i = count(nbr);
  if (!(res = malloc(sizeof(char) * (i + 1))))
    return (the_puterror(ERR_MSG_MALLOC, NULL));
  *res = '0';
  res[i] = '\0';
  if (nbr < 0)
  {
    *res = '-';
    nbr = -nbr;
  }
  while (nbr)
  {
    res[i - 1] = nbr % 10 + '0';
    nbr /= 10;
    --i;
  }
  return (res);
}
