CC=g++
flags=-std=c++11 -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self
exe=graphs

$(exe): main.o graph.o adj_list.o node.o
	$(CC) $(flags) main.o graph.o adj_list.o node.o -o $(exe)

main.o: main.cpp
	$(CC) $(flags) -c main.cpp -o main.o

graph.o: graph.cpp graph.h
	$(CC) $(flags) -c graph.cpp -o graph.o

adj_list.o: adj_list.cpp adj_list.h
	$(CC) $(flags) -c adj_list.cpp -o adj_list.o

node.o: node.cpp node.h
	$(CC) $(flags) -c node.cpp -o node.o


run: $(exe)
	.\$(exe)
# ./ for mac
# .\ for windows
again: clean $(exe)

clean:
	del $(exe) *.o 
#rm for mac
#del for windows