# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/16 18:10:04 by mpitot            #+#    #+#              #
#    Updated: 2024/06/17 15:10:51 by mpitot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.cpp		\
			Contact.cpp		\
			PhoneBook.cpp

OBJS	=	$(SRCS:%.cpp=${OBJ_D}%.o)

SRC_D	=	srcs/

OBJ_D	=	.objs/

HEAD	=	includes/

NAME	=	phonebook

CC		=	c++

FLAGS	=	-Wall -Wextra -Werror -std=c++98



RED		=	\033[1;31m
GREEN	=	\033[1;32m
YELLOW	=	\033[1;33m
BLUE	=	\033[1;34m
MAGENTA	=	\033[1;35m
CYAN	=	\033[1;36m
WHITE	=	\033[1;37m
DEFAULT	=	\033[0m
UP		=	"\033[A"
CUT		=	"\033[K"

CHANGED	=	0
NUM_SRCS := $(words $(SRCS))
COMPILED_SRCS := 0

define separator
	@echo "$(WHITE)------------------------------------------------------------$(DEFAULT)"
endef

define print_progress
	@echo "$(YELLOW)Compiling $(WHITE)[$(BLUE)$(patsubst $(SRC_D)%,%,$1)$(WHITE)]...$(DEFAULT)\r"
endef

define update_progress
	$(eval COMPILED_SRCS := $(shell echo $$(($(COMPILED_SRCS) + 1))))
	$(eval PROGRESS := $(shell echo $$((($(COMPILED_SRCS) * 100) / $(NUM_SRCS)))))
	@printf ${UP}${CUT}
	@if [ $(PROGRESS) -eq 100 ]; then \
		echo "$(WHITE)<$(GREEN)$(PROGRESS)%$(WHITE)> $(WHITE)[$(BLUE)$(patsubst $(SRC_D)%,%,$1)$(WHITE)] $(YELLOW)compiled.$(DEFAULT)\r"; \
	else \
		if [ $(PROGRESS) -lt 10 ]; then \
			echo "$(WHITE)<  $(GREEN)$(PROGRESS)%$(WHITE)> $(WHITE)[$(BLUE)$(patsubst $(SRC_D)%,%,$1)$(WHITE)] $(YELLOW)compiled.$(DEFAULT)\r"; \
		else \
			echo "$(WHITE)< $(GREEN)$(PROGRESS)%$(WHITE)> $(WHITE)[$(BLUE)$(patsubst $(SRC_D)%,%,$1)$(WHITE)] $(YELLOW)compiled.$(DEFAULT)\r"; \
		fi \
	fi
endef

define erase
	@printf ${UP}${CUT}
endef

define done_and_dusted
	@echo "$(WHITE)[$(CYAN)$1$(WHITE)] $(GREEN)compiled.$(DEFAULT)"
endef



all		:	${NAME}

${OBJS}	:	${OBJ_D}%.o: ${SRC_D}%.cpp Makefile includes/Contact.hpp includes/PhoneBook.hpp
	@$(call print_progress,$<)
	@${CC} ${FLAGS} -I${HEAD} -c $< -o $@
	@$(call update_progress,$<)

${NAME}	:	${OBJ_D} ${OBJS}
	@$(call print_progress,$(NAME))
	@${CC} ${FLAGS} -I${HEAD} ${OBJS} -o ${NAME}
	@$(eval CHANGED=1)
	@$(call erase)
	@$(call done_and_dusted,$(NAME))

${OBJ_D}:
	@mkdir -p ${OBJ_D}

clean	:
	@echo "Cleaning $(WHITE)[$(RED)$(NAME)$(WHITE)]...$(DEFAULT)"
	@rm -rf ${OBJ_D}
	@echo "$(WHITE)[$(RED)$(OBJ_D)$(WHITE)] $(RED)deleted.$(DEFAULT)"

fclean	:
	@echo "F***ing-Cleaning $(WHITE)[$(RED)$(NAME)$(WHITE)]...$(DEFAULT)"
	@rm -rf ${OBJ_D}
	@echo "$(WHITE)[$(RED)$(OBJ_D)$(WHITE)] $(RED)deleted.$(DEFAULT)"
	@rm -f ${NAME}
	@echo "$(WHITE)[$(RED)$(NAME)$(WHITE)] $(RED)deleted.$(DEFAULT)"

re		:	fclean .internal_separate1 all

.PHONY	:	all clean fclean re

.NOTPARALLEL all:
	@if [ $(CHANGED) -eq 0 ]; then \
		echo "$(YELLOW)Nothing to be done for $(WHITE)[$(CYAN)$(NAME)$(WHITE)].$(DEFAULT)"; \
	fi

.internal_announce	:
	@echo "$(YELLOW)Compiling $(WHITE)[$(CYAN)${NAME}$(WHITE)]...$(DEFAULT)"

.internal_separate1	:
	$(call separator)

.internal_separate2 :
	$(call separator)

.internal_separate3 :
	$(call separator)