##
## Makefile for PSU_2015_42sh in .
## 
## Made by Benoit Hamon
## Login   <hamon_e@epitech.net>
## 
## Started on  Mon May 30 01:47:11 2016 Benoit Hamon
## Last update Sun Dec 04 13:42:07 2016 Benoit Hamon
##

CC		=	gcc

SRCS_DIR	=	sources/
OBJS_DIR	=	objects/

HDRS_DIRS	=	headers/
HDRS_DIRS	+=	headers_public/
HDRS_DIRS	+=	$(foreach var, $(DEPEDENCIES), ../$(var)/headers_public/)

CFLAGS_DB	+=	-g3

RM		=	rm -rf
MAKE		=	make --no-print-directory
AR		=	ar rc
RANLIB		=	ranlib

RED		=	\033[0;31m
GREEN		=	\033[0;32m
BLUE		=	\033[1;34m
PURPLE		=	\033[0;35m
CYAN		=	\033[0;36m
RESET		=	\033[0m

NAME_TMP	=	$(shell echo `$(call function, name:, 0)` | tr a-z A-Z)
NAME		=	$(shell $(call function, name:, 0)).a
SRCS_NAMES	=	$(shell $(call function, \[*\], 1))
CFLAGS		=	$(addprefix -, $(shell $(call function, cflags:, 0)))
DEPEDENCIES	=	$(shell $(call function, depedencies:, 0))
LIB		=	$(addprefix -l, $(shell $(call function, lib:, 0)))
BONUS_FILES	+=	$(addprefix $(SRCS_DIR), $(shell $(call function, bonus:, 0)))

OBJS		=	$(addprefix $(OBJS_DIR), $(SRCS_NAMES:.c=.o))
OBJS_DEP	=	$(addprefix $(OBJS_DIR), $(SRCS_NAMES:.c=.d))
OBJS_DB		=	$(addprefix $(OBJS_DIR), $(SRCS_NAMES:.c=.o.db))
HDRS		=	$(addprefix -I, $(HDRS_DIRS))
NAME_DB		=	$(subst .a,_db.a,$(NAME))

the_clean = $(foreach var, $1, if [ -f $(var) ] ; then              \
	          printf " $(RED)DELETE$(RESET) $(notdir $(var))\n" \
	          && $(RM) $(var) ;                                 \
	        fi ; if [ -d $(var) ] ; then                        \
	          printf " $(RED)DELETE$(RESET) $(var)\n"           \
	          && $(RM) $(var) ;                                 \
	        fi ; )

function = echo $$(while read line ; do                                  \
	     if [[ $$line =~ $1 ]] ; then                                \
	       folder=$$(echo $$line | sed 's/\]$$//' | sed 's/^\[//') ; \
	       while read line && [[ ! -z "$$line" ]]; do                \
	         if [ $2 = 1 ] ; then                                    \
	           echo "$$folder/$$line " ;                             \
	         else                                                    \
	           echo "$$line " ;                                      \
	         fi ;                                                    \
	       done ;                                                    \
	     fi ;                                                        \
	   done < config)

.PHONY : all debug project clean fclean re

all : project

project :
	@printf "$(BLUE)----- $(NAME_TMP) COMPILATION -----$(RESET)\n"
	@mkdir -p $(OBJS_DIR)
	@if ! $(MAKE) -q $(NAME) ; then                                                   \
	    $(MAKE) $(NAME)                                                               \
	    && printf "$(BLUE)-----       SUCCESS       -----$(RESET)\n\n" ;              \
	  else                                                                            \
	    printf " Nothing to $(GREEN)Compile$(RESET) for $(CYAN)$(NAME)$(RESET)\n\n" ; \
	  fi ;

debug :
	@printf "$(BLUE)--- $(NAME_TMP)_DB COMPILATION ---$(RESET)\n"
	@mkdir -p $(OBJS_DIR)
	@if ! $(MAKE) -q $(NAME_DB) ; then                                                   \
	    $(MAKE) $(NAME_DB)                                                               \
	    && printf "$(BLUE)-----       SUCCESS       -----$(RESET)\n\n" ;                 \
	  else                                                                               \
	    printf " Nothing to $(GREEN)Compile$(RESET) for $(CYAN)$(NAME_DB)$(RESET)\n\n" ; \
	  fi ;

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@printf " $(PURPLE)COMPILE$(RESET) $(notdir $<)\n"
	@-mkdir -p $(dir $@) 2>/dev/null
	@$(CC) -c $< -o $@ $(CFLAGS) $(HDRS)

$(OBJS_DIR)%.d : $(SRCS_DIR)%.c
	@printf " $(PURPLE)REQUIRE$(RESET) $(notdir $@)\n"
	@-mkdir -p $(dir $@) 2>/dev/null
	@echo -n $(dir $@) > $@
	@$(CC) -MM $< $(HDRS) >> $@

$(OBJS_DIR)%.o.db : $(SRCS_DIR)%.c
	@printf " $(PURPLE)COMPILE$(RESET) $(notdir $<)\n"
	@-mkdir -p $(dir $@) 2>/dev/null
	@$(CC) -c $< -o $@ $(CFLAGS) $(CFLAGS_DB) $(HDRS)

$(NAME) : $(OBJS_DEP) $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@$(RANLIB) $(NAME)
	@printf " $(GREEN)CREATE$(RESET) $(CYAN)$(NAME)$(RESET)\n"

$(NAME_DB) : $(OBJS_DEP) $(OBJS_DB)
	@$(AR) $(NAME_DB) $(OBJS_DB)
	@$(RANLIB) $(NAME_DB)
	@printf " $(GREEN)CREATE$(RESET) $(CYAN)$(NAME_DB)$(RESET)\n"

clean :
	@printf "$(BLUE)-----   $(NAME_TMP) DELETION  -----$(RESET)\n"
	@if [ ! -d $(OBJS_DIR) ] ; then                     \
	    printf " Nothing to $(RED)Delete$(RESET)\n\n" ; \
	  else                                              \
	    $(call the_clean, $(OBJS))                      \
	    $(call the_clean, $(OBJS_DB))                   \
	    $(call the_clean, $(OBJS_DEP))                  \
	    $(call the_clean, $(OBJS_DIR))                  \
	  fi ;

fclean :
	@printf "$(BLUE)-----   $(NAME_TMP) DELETION  -----$(RESET)\n"
	@if [[ ! -d $(OBJS_DIR) && ! -f $(NAME) && ! -f $(NAME_DB) ]] ; then \
	    printf " Nothing to $(RED)Delete$(RESET)\n\n" ;                  \
	  else                                                               \
	    $(call the_clean, $(OBJS))                                       \
	    $(call the_clean, $(OBJS_DB))                                    \
	    $(call the_clean, $(OBJS_DEP))                                   \
	    $(call the_clean, $(NAME_DB))                                    \
	    $(call the_clean, $(NAME))                                       \
	    $(call the_clean, $(OBJS_DIR))                                   \
	  fi ;

re : fclean all

ifeq ($(MAKECMDGOALS), $(NAME))
-include $(OBJS_DEP)
endif
