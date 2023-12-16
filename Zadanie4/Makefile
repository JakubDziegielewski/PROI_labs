CC = 		g++
CCFLAGS = 	-g -Wall -Werror
LINK = 		g++
LINKFLAGS = -g -Wall -Werror

all: zero_length_exception.o circle.o solid_of_revolution.o cone.o cylinder.o main.o test.cylinder.o test.cone.o 

zero_length_exception.o : zero_length_exception.cpp
		$(CC) $(CCFLAGS) -c -o zero_length_exception.o zero_length_exception.cpp
circle.o : circle.cpp
		$(CC) $(CCFLAGS) -c -o circle.o circle.cpp
solid_of_revolution.o : solid_of_revolution.cpp
		$(CC) $(CCFLAGS) -c -o solid_of_revolution.o solid_of_revolution.cpp
cone.o : cone.cpp
		$(CC) $(CCFLAGS) -c -o cone.o cone.cpp
cylinder.o : cylinder.cpp
		$(CC) $(CCFLAGS) -c -o cylinder.o cylinder.cpp
main.o : main.cpp
		$(CC) $(CCFLAGS) -o main.o main.cpp zero_length_exception.o circle.o solid_of_revolution.o cone.o cylinder.o
test.cylinder.o : cylinder.test.cpp
		$(CC) $(CCFLAGS) -o cylinder.test.o cylinder.test.cpp zero_length_exception.o circle.o solid_of_revolution.o cone.o cylinder.o
test.cone.o : cone.test.cpp
		$(CC) $(CCFLAGS) -o cone.test.o cone.test.cpp zero_length_exception.o circle.o solid_of_revolution.o cone.o cylinder.o
