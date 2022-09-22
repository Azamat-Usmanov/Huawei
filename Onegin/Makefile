FLAGS = -Wall -Werror -Wextra

all : Onegin

Onegin : main.cpp evgeniy_onegin.cpp evgeniy_onegin.h
	g++ $(FLAGS) main.cpp evgeniy_onegin.cpp

rebuild : clean all

clean :
	rm a.out