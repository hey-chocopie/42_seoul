CXX				= clang++
RM				= rm -f
CXXFLAGS		= -fsanitize=address
#-Wall -Wextra -Werror -std=c++98 -fsanitize=address
NAME			= test

SRCS			= main.cpp
OBJS_DIR		= objs

OBJS			= $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

$(OBJS_DIR)/%.o:%.cpp
				@mkdir -p $(OBJS_DIR)
				$(CXX) $(CXXFLAGS) -c $< -o $(<:%.cpp=$(OBJS_DIR)/%.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

test-vector:
	$(CXX) $(CXXFLAGS) ./tester/vector_test.cpp
test-map:
	$(CXX) $(CXXFLAGS) ./tester/map_test.cpp
test-stack:
	$(CXX) $(CXXFLAGS) ./tester/stack_test.cpp
clean:
				$(RM) $(OBJS)
				rm -rf $(OBJS_DIR)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
