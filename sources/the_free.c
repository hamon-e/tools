/*
** the_free.c for PSU_2015_42sh in sources/tools/free
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Sun Jun 05 21:34:10 2016 Nicolas Goudal
** Last update Sun Dec 04 12:49:14 2016 Benoit Hamon
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include "tools.h"
#include "free.h"

void		*the_free(int nbr, ...)
{
  va_list	ap;
  t_free	type;
  int		i;

  va_start(ap, nbr);
  while (nbr)
  {
    type = va_arg(ap, t_free);
    i = 0;
    while (g_dico_free[i].f && g_dico_free[i].type != type)
      ++i;
    if (g_dico_free[i].f)
      g_dico_free[i].f(va_arg(ap, void *));
    --nbr;
  }
  va_end(ap);
  return (NULL);
}
