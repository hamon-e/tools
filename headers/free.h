/*
** free.h for tools in headers
**
** Made by Benoit Hamon
** Login   <hamon_e@epitech.net>
**
** Started on  Sun Dec 04 12:56:29 2016 Benoit Hamon
** Last update Sun Dec 04 12:56:40 2016 Benoit Hamon
*/

#ifndef HEADERS_FREE_H_
# define HEADERS_FREE_H_

void				*free_str();
void				*free_tab();
# if __has_include(THE_FREE_FUNC_PATH)
#  include THE_FREE_FUNC_PATH
# endif

static const t_func_free	g_dico_free[] =
{
  {FREE_STR, free_str},
  {FREE_TAB, free_tab},
# if __has_include(THE_FREE_DICO_PATH)
#  include THE_FREE_DICO_PATH
# endif
  {0, NULL}
};

#endif /* end of include guard: HEADERS_FREE_H_ */
