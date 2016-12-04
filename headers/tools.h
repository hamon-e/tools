/*
** tools.h for tools in headers
**
** Made by Benoit Hamon
** Login   <hamon_e@epitech.net>
**
** Started on  Sun Dec 04 12:56:48 2016 Benoit Hamon
** Last update Sun Dec 04 12:57:01 2016 Benoit Hamon
*/

#ifndef HEADERS_TOOLS_H_
# define HEADERS_TOOLS_H_

# define READ_SIZE	(1400)

# include "tools/tools.h"
# include "tools/msg.h"

typedef struct		s_list
{
  struct s_list		*next;
  int			fd;
  char			buffer[READ_SIZE + 1];
  int			idx;
}			t_list;

typedef struct		s_errno_msg
{
  int			nbr;
  char const		*msg;
}			t_errno_msg;

typedef struct		s_func_free
{
  t_free		type;
  void			*(*f)();
}			t_func_free;

#endif /* end of include guard: HEADERS_TOOLS_H_ */
