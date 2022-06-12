CC=g++
flags=-std=c++11 -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self
exe=graphs
lib=libgrafo.dll

$(exe): main.o $(lib)
	$(CC) $(flags) main.o -o $(exe) -L. -lgrafo -Wl,-rpath=.

$(lib): graph.o adj_list.o node.o
	$(CC) $(flags) -shared graph.o adj_list.o node.o -o $(lib)

main.o: main.cpp
	$(CC) $(flags) -fPIC -c main.cpp -o main.o

graph.o: graph.cpp graph.h
	$(CC) $(flags) -fPIC -c graph.cpp -o graph.o

adj_list.o: adj_list.cpp adj_list.h
	$(CC) $(flags) -fPIC -c adj_list.cpp -o adj_list.o

node.o: node.cpp node.h
	$(CC) $(flags) -c node.cpp -o node.o


run: $(exe)
	.\$(exe)
# ./ for mac
# .\ for windows
again: clean $(exe)

clean:
	del $(exe).exe *.o *.dll 
#rm for mac
#del for windows