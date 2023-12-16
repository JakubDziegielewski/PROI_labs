CC = 		g++
CCFLAGS = 	-g -Wall -Werror
LINK = 		g++
LINKFLAGS = -g -Wall -Werror

all: date.o date_validator.o main.o output_file.o

date.o : date.cpp
		$(CC) $(CCFLAGS) -c -o date.o date.cpp
date_validator.o : date_validator.cpp
		$(CC) $(CCFLAGS) -c -o date_validator.o date_validator.cpp
main.o : main.cpp
		$(CC) $(CCFLAGS) -c -o main.o main.cpp
output_file.o : date.o date_validator.o main.o
		$(CC) $(LINKFLAGS) -o output_file.o date.o date_validator.o main.o -lm