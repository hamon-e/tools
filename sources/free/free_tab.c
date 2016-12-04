/*
** free_tab.c for PSU_2015_42sh in sources/tools/free
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Sun Jun 05 21:34:00 2016 Nicolas Goudal
** Last update Sun Jun 05 21:34:00 2016 Nicolas Goudal
*/

#include <stdlib.h>

void		*free_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab && tab[i])
  {
    free(tab[i]);
    ++i;
  }
  free(tab);
  return (NULL);
}
