CFLAGS = -std=c++14 -g -Wall

catch.o: catch.hpp
	g++ $(CFLAGS) -c catch.hpp -o $@ 

list_basic.o: ./ds/list_basic.cpp
	g++ $(CFLAGS) -c ./ds/list_basic.cpp -o $@ 

list_basic.exe: catch.o list_basic.o ../ds/list.o
	g++ $(CFLAGS) catch.o list_basic.o ../ds/list.o -o $@ 

clean:
	rm *.o *.exe
