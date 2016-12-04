/*
** free_str.c for PSU_2015_42sh in sources/tools/free
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Sun Jun 05 21:33:57 2016 Nicolas Goudal
** Last update Sun Jun 05 21:33:58 2016 Nicolas Goudal
*/

#include <stdlib.h>

void		*free_str(char *str)
{
  free(str);
  return (NULL);
}
