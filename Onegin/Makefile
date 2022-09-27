all : Onegin

# TODO: Use same naming style for your make tasks
Onegin : main.cpp evgeniy_onegin.cpp evgeniy_onegin.h my_sort.cpp my_sort.h
	g++ main.cpp evgeniy_onegin.cpp my_sort.cpp

rebuild : clean all

# TODO: clean should be marked as PHONY
clean :
	rm a.out
