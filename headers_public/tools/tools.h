/*
** tools.h for tools in headers_public/tools
**
** Made by Benoit Hamon
** Login   <hamon_e@epitech.net>
**
** Started on  Sun Dec 04 12:55:52 2016 Benoit Hamon
** Last update Sun Dec 04 13:12:11 2016 Benoit Hamon
*/

#ifndef HEADERS_PUBLIC_TOOLS_TOOLS_H_
# define HEADERS_PUBLIC_TOOLS_TOOLS_H_

# define BASE_2		"01"
# define BASE_8		"01234567"
# define BASE_10	"0123456789"
# define BASE_16_x	"0123456789abcdef"
# define BASE_16_X	"0123456789ABCDEF"

# define THE_FREE_ENUM_PATH	"../../headers/tools/the_free_enum.h"
# define THE_FREE_DICO_PATH	"../../headers/tools/the_free_dico.h"
# define THE_FREE_FUNC_PATH	"../../headers/tools/the_free_func.h"

typedef enum		e_free
{
  FREE_STR = 1,
  FREE_TAB,
# if __has_include(THE_FREE_ENUM_PATH)
#  include THE_FREE_ENUM_PATH
# endif
}			t_free;

typedef enum		e_status
{
  FAILURE = -1,
  SUCCESS = 0
}			t_status;

int			the_atoi(char const *format);
void			*the_perror(char const *str);
void			*the_puterror(char const *str,
				      char const *detail);
int			the_putserror(char const *str,
				      char const *detail);

char			*get_next_line(int fd);

int			the_tablen(char const **tab);
char			**the_tabdup(char const **tab);
void			the_putstr(int const fd,
				   char const *str);
int			the_strlen(char const *str);

void			the_pushback(void **list, void *elem, int n);
int			the_count(void *list, int n);
char			*the_list_to_str(void *list, int n_str, int n_next);
char			**the_list_to_tab(void *list, int n_str, int n_next);

void			*the_free(int nbr, ...);
char			*the_itoa(int nbr);
int			base_to_ascii(char const *word,
				      char const *base,
				      int *i);

#endif /* end of include guard: HEADERS_PUBLIC_TOOLS_TOOLS_H_ */
