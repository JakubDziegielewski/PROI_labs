CC = 		g++
CCFLAGS = 	-g -Wall -Werror
LINK = 		g++
LINKFLAGS = -g -Wall -Werror

all: unit.o area.o area_unit_converter.o main.o output_file.o

unit.o : unit.cpp
		$(CC) $(CCFLAGS) -c -o unit.o unit.cpp
area.o : area.cpp
		$(CC) $(CCFLAGS) -c -o area.o area.cpp
area_unit_converter.o : area_unit_converter.cpp
		$(CC) $(CCFLAGS) -c -o area_unit_converter.o area_unit_converter.cpp
main.o : main.cpp
		$(CC) $(CCFLAGS) -c -o main.o main.cpp
output_file.o : unit.o area.o area_unit_converter.o main.o
		$(CC) $(LINKFLAGS) -o output_file.o unit.o area.o area_unit_converter.o main.o -lm
