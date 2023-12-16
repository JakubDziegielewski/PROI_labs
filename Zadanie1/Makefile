CC = 		g++
CCFLAGS = 	-g -Wall -Werror
LINK = 		g++
LINKFLAGS = -g -Wall -Werror

all: geometric_sequence.o main.o output_file.o

geometric_sequence.o : geometric_sequence.cpp
		$(CC) $(CCFLAGS) -c -o geometric_sequence.o geometric_sequence.cpp
main.o : main.cpp
		$(CC) $(CCFLAGS) -c -o main.o main.cpp
output_file.o : geometric_sequence.o main.o
		$(CC) $(LINKFLAGS) -o output_file.o geometric_sequence.o main.o -lm
