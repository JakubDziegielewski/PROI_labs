CC = 		g++
CCFLAGS = 	-g -Wall -Werror
LINK = 		g++
LINKFLAGS = -g -Wall -Werror

all: person.o party.o test.o main.o output_file.o

person.o : person.cpp
		$(CC) $(CCFLAGS) -c -o person.o person.cpp
party.o : party.cpp
		$(CC) $(CCFLAGS) -c -o party.o party.cpp
test.o : party.test.cpp
		$(CC) $(CCFLAGS) -o party.test.o party.test.cpp party.o person.o
main.o : main.cpp
		$(CC) $(CCFLAGS) -c -o main.o main.cpp
output_file.o : party.o main.o
		$(CC) $(LINKFLAGS) -o output_file.o person.o party.o main.o -lm
