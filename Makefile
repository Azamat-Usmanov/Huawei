FLAGS = -Wall -Werror -Wextra

solve : quadratic_equation.cpp interactive.cpp main.cpp
	g++ $(FLAGS) quadratic_equation.cpp interactive.cpp main.cpp -D solve

test : test.cpp main.cpp
	g++ $(FLAGS) test.cpp main.cpp quadratic_equation.cpp -D test

rebuid : clean all

clean :
	rm a.out
