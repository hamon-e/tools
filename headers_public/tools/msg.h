/*
** msg.h for tools in headers_public/tools
**
** Made by Benoit Hamon
** Login   <hamon_e@epitech.net>
**
** Started on  Sun Dec 04 12:55:15 2016 Benoit Hamon
** Last update Sun Dec 04 12:55:46 2016 Benoit Hamon
*/

#ifndef HEADERS_PUBLIC_TOOLS_MSG_H_
# define HEADERS_PUBLIC_TOOLS_MSG_H_

# define THE_MSG_PATH		"../../../../include/tools/the_msg.h"

# define ERR_MSG_OPEN		"Could not open: %s\n"
# define ERR_MSG_READ		"Could not read: %s\n"
# define ERR_MSG_MALLOC		"Malloc Failed\n"
# define ERR_MSG_INFINITE_LOOP	"Do you have an infinite loop ?\n"
# if __has_include(THE_FREE_ENUM_PATH)
#  include THE_FREE_ENUM_PATH
# endif

#endif /* end of include guard: HEADERS_PUBLIC_TOOLS_MSG_H_ */
