CC=g++
flags=-std=c++11 -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self
exe=grafo
lib=_grafo.pyd


swigroute=C:\Users\lucas\Downloads\swigwin-4.0.2\swigwin-4.0.2
pythonroute=C:\Users\lucas\Anaconda3\pkgs\python-3.7.1-h8c8aaf0_6

# if problems try removing \s or changing "\" to "/"
$(lib): grafo_wrap.cxx graph.o adj_list.o node.o
	$(CC) -fPIC -c grafo_wrap.cxx -o grafo_wrap.o -I$(pythonroute)/include
	$(CC) -shared grafo_wrap.o node.o adj_list.o graph.o -o _grafo.pyd -L$(pythonroute) -lpython37

grafo_wrap.cxx: grafo.i graph.h adj_list.h node.h
	$(swigroute)/swig -python -c++ grafo.i



$(exe): main.o graph.o adj_list.o node.o
	$(CC) $(flags) main.o graph.o adj_list.o node.o -o $(exe)
	
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
	del $(exe).exe *.o *.dll *.pyd *.cxx 
#rm for mac
#del for windows