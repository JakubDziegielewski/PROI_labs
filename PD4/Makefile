CC = 		g++ -std=c++17
CCFLAGS = 	-g -Wall -Werror
LINK = 		g++ -std=c++17
LINKFLAGS = -g -Wall -Werror
TESTGLAGS = -g -Wall -Werror

all: element.o line.o figure.o circle.o rectangle.o writing.o drawing.o invalid_color_exception.o bad_coordinates_exception.o main.o output_file.o 
testing: test.circle.o test.line.o test.rectangle.o test.writing.o test.drawing.o

element.o : src/element.cpp
		$(CC) $(CCFLAGS) -c -o src/element.o src/element.cpp
line.o : src/line.cpp
		$(CC) $(CCFLAGS) -c -o src/line.o src/line.cpp
figure.o : src/figure.cpp
		$(CC) $(CCFLAGS) -c -o src/figure.o src/figure.cpp
circle.o : src/circle.cpp
		$(CC) $(CCFLAGS) -c -o src/circle.o src/circle.cpp
rectangle.o : src/rectangle.cpp
		$(CC) $(CCFLAGS) -c -o src/rectangle.o src/rectangle.cpp
writing.o : src/writing.cpp
		$(CC) $(CCFLAGS) -c -o src/writing.o src/writing.cpp
drawing.o : src/drawing.cpp
		$(CC) $(CCFLAGS) -c -o src/drawing.o  src/drawing.cpp
invalid_color_exception.o : src/invalid_color_exception.cpp
		$(CC) $(CCFLAGS) -c -o src/invalid_color_exception.o  src/invalid_color_exception.cpp
bad_coordinates_exception.o : src/bad_coordinates_exception.cpp
		$(CC) $(CCFLAGS) -c -o src/bad_coordinates_exception.o src/bad_coordinates_exception.cpp
main.o : main.cpp
		$(CC) $(CCFLAGS) -c -o main.o main.cpp
output_file.o : element.o line.o figure.o circle.o rectangle.o writing.o drawing.o invalid_color_exception.o bad_coordinates_exception.o main.o
		$(CC) $(LINKFLAGS) -o output_file.o src/element.o src/line.o src/figure.o src/circle.o src/rectangle.o src/writing.o src/drawing.o src/invalid_color_exception.o src/bad_coordinates_exception.o main.o -lm

test.circle.o : src/circle.test.cpp
		$(CC) $(CCFLAGS) -o src/circle.test.o src/circle.test.cpp src/circle.o src/element.o src/figure.o src/invalid_color_exception.o
		
test.line.o : src/line.test.cpp
		$(CC) $(CCFLAGS) -o src/line.test.o src/line.test.cpp src/line.o src/element.o src/invalid_color_exception.o

test.rectangle.o : src/rectangle.test.cpp
		$(CC) $(CCFLAGS) -o src/rectangle.test.o src/rectangle.test.cpp src/rectangle.o src/element.o src/figure.o src/invalid_color_exception.o

test.writing.o : src/writing.test.cpp
		$(CC) $(CCFLAGS) -o src/writing.test.o src/writing.test.cpp src/writing.o src/element.o src/figure.o src/invalid_color_exception.o

test.drawing.o : src/drawing.test.cpp
		$(CC) $(CCFLAGS) -o src/drawing.test.o src/drawing.test.cpp src/drawing.o src/element.o src/figure.o src/circle.o src/rectangle.o src/line.o src/writing.o src/invalid_color_exception.o src/bad_coordinates_exception.o