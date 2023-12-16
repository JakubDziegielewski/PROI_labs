CC = 		g++ -std=c++17
CCFLAGS = 	-g -Wall -Werror -c
LINK = 		g++ -std=c++17
LINKFLAGS = -g -Wall -Werror
TESTGLAGS = -g -Wall -Werror

all: company.o item.o order.o invoice.o invoice_reader.o main.o output_file.o

tests: test.item.o test.order.o test.invoice.o

company.o : src/company.cpp
		$(CC) $(CCFLAGS) -o src/company.o src/company.cpp
item.o : src/item.cpp
		$(CC) $(CCFLAGS) -o src/item.o src/item.cpp
order.o : src/order.cpp 
		$(CC) $(CCFLAGS) -o src/order.o src/order.cpp
invoice.o : src/invoice.cpp
		$(CC) $(CCFLAGS) -o src/invoice.o src/invoice.cpp
invoice_reader.o : src/invoice_reader.cpp
		$(CC) $(CCFLAGS) -o src/invoice_reader.o src/invoice_reader.cpp
main.o : main.cpp
		$(CC) $(CCFLAGS) -o main.o main.cpp
output_file.o : company.o item.o order.o invoice.o main.o
		$(LINK) $(LINKFLAGS) -o output_file.o src/company.o src/item.o src/order.o src/invoice.o src/invoice_reader.o main.o -lm

test.item.o : src/item.test.cpp
		$(CC) $(TESTGLAGS) -o test.item.o src/item.test.cpp src/item.o
test.order.o : src/order.test.cpp
		$(CC) $(TESTGLAGS) -o test.order.o src/order.test.cpp src/order.o src/item.o
test.invoice.o : src/invoice.test.cpp
		$(CC) $(TESTGLAGS) -o test.invoice.o src/invoice.test.cpp src/invoice.o src/company.o src/item.o src/order.o
