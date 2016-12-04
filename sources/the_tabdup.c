/*
** the_tabdup.c for PSU_2015_42sh in sources/tools
**
** Made by Benoit Hamon
** Login   <hamon_e@epitech.net>
**
** Started on  Mon May 30 01:48:11 2016 Benoit Hamon
** Last update Sun Jun 05 21:27:22 2016 Nicolas Goudal
*/

#include <stdlib.h>
#include <string.h>

int		the_tablen(char const **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    ++i;
  return (i);
}

char		**the_tabdup(char const **tab)
{
  int		i;
  char		**res;

  if (!tab || !(res = malloc(sizeof(char *) * (the_tablen(tab) + 1))))
    return (NULL);
  i = 0;
  while (tab[i])
  {
    if (!(res[i] = strdup(tab[i])))
      return (NULL);
    ++i;
  }
  res[i] = NULL;
  return (res);
}
