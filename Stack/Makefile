FLAGS = -Wall -Werror -Wextra

all : stack

stack : main.cpp Stack.cpp Stack.h Verification.cpp Verification.h
	g++ $(FLAGS) main.cpp Stack.cpp Verification.cpp

clean : 
	rm a.out