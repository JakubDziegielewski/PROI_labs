CC = 		g++ -std=c++17
CCFLAGS = 	-g -Wall -Werror
LINK = 		g++ -std=c++17
LINKFLAGS = -g -Wall -Werror

all: fraction.o test.o main.o output_file.o

fraction.o : src/fraction.cpp
		$(CC) $(CCFLAGS) -c -o src/fraction.o src/fraction.cpp
test.o : src/fraction.test.cpp
		$(CC) $(CCFLAGS) -o test.o src/fraction.test.cpp src/fraction.o
main.o : main.cpp
		$(CC) $(CCFLAGS) -c -o main.o main.cpp
output_file.o : fraction.o main.o
		$(CC) $(LINKFLAGS) -o output_file.o src/fraction.o main.o -lm