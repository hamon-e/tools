/*
** str_tools.c for PSU_2015_42sh in sources/tools
**
** Made by Benoit Hamon
** Login   <hamon_e@epitech.net>
**
** Started on  Fri Jun 03 22:29:39 2016 Benoit Hamon
** Last update Sun Jun 05 21:26:43 2016 Nicolas Goudal
*/

#include <unistd.h>
#include <string.h>

int		the_putchar(int c)
{
  return (write(1, &c, 1));
}

void		the_putstr(int const fd,
			   char const *str)
{
  if (!str)
    return ;
  write(fd, str, strlen(str));
}

int		the_strcmp(char const *str1,
			   char const *str2)
{
  if (!str1 && !str2)
    return (0);
  else if (!str1 || !str2)
    return (1);
  return (strcmp(str1, str2));
}

int		the_strlen(char const *str)
{
  if (!str)
    return (0);
  return (strlen(str));
}
