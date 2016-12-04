/*
** the_atoi.c for PSU_2015_42sh in sources/tools
**
** Made by Benoit Hamon
** Login   <hamon_e@epitech.net>
**
** Started on  Mon May 30 01:47:51 2016 Benoit Hamon
** Last update Thu Dec 01 22:10:46 2016 Benoit Hamon
*/

#include <string.h>

int		the_atoi(char const *format)
{
  int		neg;
  int		res;

  if (!format)
    return (0);
  res = 0;
  neg = *format == '-' ? -1 : 1;
  if (neg == -1)
    ++format;
  while (*format >= '0' && *format <= '9')
  {
    res = res * 10 + (*format - '0') * neg;
    ++format;
  }
  return (res);
}
