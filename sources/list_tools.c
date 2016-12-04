/*
** list_tools.c for PSU_2015_42sh in sources/tools
**
** Made by Benoit Hamon
** Login   <hamon_e@epitech.net>
**
** Started on  Mon May 30 01:47:45 2016 Benoit Hamon
** Last update Sun Jun 05 21:26:29 2016 Nicolas Goudal
*/

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void		the_pushback(void **list, void *elem, int n)
{
  void		*tmp;

  if (*list)
  {
    tmp = *list;
    while (*(char **)((char *)tmp + n))
      tmp = *(char **)((char *)tmp + n);
    *(char **)((char *)tmp + n) = elem;
  }
  else
    *list = elem;
}

int		the_count(void *list, int n)
{
  int		res;

  res = 0;
  while (list)
  {
    list = *(char **)((char *)list + n);
    ++res;
  }
  return (res);
}

static int	the_list_to_str_count(void *list, int n_str, int n_next)
{
  int		i;

  i = 0;
  while (list)
  {
    if (*(char **)((char *)list + n_str))
      i += strlen(*(char **)((char *)list + n_str));
    list = *(char **)((char *)list + n_next);
  }
  return (i);
}

char		*the_list_to_str(void *list, int n_str, int n_next)
{
  char		*str;
  int		n;

  n = the_list_to_str_count(list, n_str, n_next);
  if (!n || !(str = malloc(sizeof(char) * (n + 1))))
    return (NULL);
  *str = '\0';
  while (list)
  {
    if (*(char **)((char *)list + n_str))
      strcat(str, *(char **)((char *)list + n_str));
    list = *(char **)((char *)list + n_next);
  }
  return (str);
}

char		**the_list_to_tab(void *list, int n_str, int n_next)
{
  char		**tab;
  int		n;
  int		i;

  n = the_list_to_str_count(list, n_str, n_next);
  if (!n || !(tab = malloc(sizeof(char *) * (n + 1))))
    return (NULL);
  i = 0;
  while (list)
  {
    if (*(char **)((char *)list + n_str))
      tab[i++] = *(char **)((char *)list + n_str);
    list = *(char **)((char *)list + n_next);
  }
  tab[i] = NULL;
  return (tab);
}
