/*
** get_next_line.c for PSU_2015_42sh in sources/tools
**
** Made by Benoit Hamon
** Login   <hamon_e@epitech.net>
**
** Started on  Mon May 30 01:47:37 2016 Benoit Hamon
** Last update Sun Dec 04 12:49:31 2016 Benoit Hamon
*/

#include <unistd.h>
#include <stdlib.h>
#include "tools.h"

static void	delete_elem(t_list *elem, t_list *start)
{
  t_list	*elem_tmp;

  elem_tmp = start;
  while (elem_tmp->next != elem)
    elem_tmp = elem_tmp->next;
  if (elem->next)
    elem_tmp->next = elem->next;
  else
    elem_tmp->next = NULL;
  free(elem);
}

static char	*my_strcat(char *s1, char *s2)
{
  char		*sfinal;
  int		idx;
  int		size1;
  int		size2;

  idx = -1;
  size1 = 0;
  size2 = 0;
  if (!s1)
    size1 = 0;
  else
    while (s1[size1])
      ++size1;
  while (s2[size2] && s2[size2] != '\n')
    ++size2;
  if (!(sfinal = malloc(sizeof(char) * (size1 + size2 + 1))))
    return (NULL);
  while (++idx < size1)
    sfinal[idx] = s1[idx];
  --idx;
  while (s2[++idx - size1] && s2[idx - size1] != '\n')
    sfinal[idx] = s2[idx - size1];
  sfinal[idx] = '\0';
  free(s1);
  return (sfinal);
}

static t_list	*check_list(t_list *list_tmp, const int fd)
{
  t_list	*new;

  while (list_tmp->next && list_tmp->next->fd != fd)
    list_tmp = list_tmp->next;
  if (!list_tmp->next)
  {
    if (!(new = malloc(sizeof(t_list))))
      return (NULL);
    list_tmp->next = new;
    new->next = NULL;
    new->fd = fd;
    new->buffer[0] = '\0';
    new->idx = 0;
  }
  if (list_tmp->next->fd == fd)
  {
    list_tmp = list_tmp->next;
    return (list_tmp);
  }
  return (new);
}

static char	*read_next_line(t_list *elem, char *line, t_list *start)
{
  int		rd;

  rd = 0;
  while ((rd = read(elem->fd, elem->buffer, READ_SIZE)) > 0)
  {
    elem->idx = 0;
    elem->buffer[rd] = '\0';
    while (elem->buffer[elem->idx] != '\n' && elem->buffer[elem->idx])
      ++elem->idx;
    if (!(line = my_strcat(line, elem->buffer)))
      return (NULL);
    if (elem->buffer[elem->idx] == '\n')
      return (line);
  }
  if (elem->idx != -1
      && !elem->buffer[elem->idx]
      && elem->buffer[elem->idx - 1] != '\n')
  {
    elem->idx = -1;
    return (line);
  }
  delete_elem(elem, start);
  free(line);
  return (NULL);
}

char		*get_next_line(const int fd)
{
  static t_list	list = {NULL, 0, "\0", 0};
  t_list	*list_tmp;
  char		*line;
  int		line_size;

  line_size = 0;
  line = NULL;
  list_tmp = &list;
  if (!(list_tmp = check_list(list_tmp, fd)))
    return (NULL);
  if (list_tmp->buffer[list_tmp->idx] == '\n')
  {
    if (!(line = my_strcat(line, &list_tmp->buffer[list_tmp->idx + 1])))
      return (NULL);
    while (line[line_size])
      ++line_size;
    list_tmp->idx += line_size + 1;
    if (list_tmp->buffer[list_tmp->idx] == '\n')
      return (line);
  }
  return (read_next_line(list_tmp, line, &list));
}
