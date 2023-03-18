all : CPU

CPU_CHECK : main.cpp asm.cpp ../Onegin/evgeniy_onegin.cpp ../Stack/Stack.cpp ../Stack/Verification.cpp cpu.cpp
	g++ main.cpp asm.cpp ../Onegin/evgeniy_onegin.cpp ../Stack/Stack.cpp ../Stack/Verification.cpp cpu.cpp -E cpu.cpp > qwe.c

CPU : main.cpp asm.cpp ../Onegin/evgeniy_onegin.cpp ../Stack/Stack.cpp ../Stack/Verification.cpp cpu.cpp
	g++ main.cpp asm.cpp ../Onegin/evgeniy_onegin.cpp ../Stack/Stack.cpp ../Stack/Verification.cpp cpu.cpp
	
rebuild : clean all

clean :
	rm a.out
