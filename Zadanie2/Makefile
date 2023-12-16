CC = 		g++
CCFLAGS = 	-g -Wall -Werror
LINK = 		g++
LINKFLAGS = -g -Wall -Werror

all: complex_number.o test.o main.o output_file.o

complex_number.o : complex_number.cpp
		$(CC) $(CCFLAGS) -c -o complex_number.o complex_number.cpp
test.o : complex_number.test.cpp
		$(CC) $(CCFLAGS) -o test.o complex_number.test.cpp complex_number.o
main.o : main.cpp
		$(CC) $(CCFLAGS) -c -o main.o main.cpp
output_file.o : complex_number.o main.o
		$(CC) $(LINKFLAGS) -o output_file.o complex_number.o main.o -lm
