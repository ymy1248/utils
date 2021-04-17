CFLAGS = -std=c++14 -g -Wall

reg: list_basic_reg.exe
	./list_basic_reg.exe

list.o: ../ds/list.hpp ../ds/list.cpp
	g++ $(CFLAGS) -o $@ -c ../ds/list.hpp

vector.o: ../ds/vector.hpp ../ds/vector.cpp
	g++ $(CFLAGS) -o $@ -c ../ds/vector.hpp

catch.o: ../reg/catch.hpp
	g++ $(CFLAGS) -c ../reg/catch.hpp -o $@ 

list_basic.o: ../reg/ds/list_basic.cpp ../ds/list.hpp ../ds/list.cpp
	g++ $(CFLAGS) -c ../reg/ds/list_basic.cpp -o $@ 

list_basic_reg.exe: catch.o list_basic.o list.o
	g++ $(CFLAGS) catch.o list_basic.o -o $@ 

clean:
	rm -f *.o *.exe
