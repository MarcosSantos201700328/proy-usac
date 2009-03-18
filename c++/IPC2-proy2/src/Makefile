mothell : mothell.cpp
	g++ -ggdb -Wall -o main mothell.cpp
mothelllinuxrelease : mothell.cpp
	g++ $(CFLAGS) -Wall -O2 -o mothell mothell.cpp
mothellwin32release: mothell.cpp
	g++ $(CFLAGS) -Wall -O2 -o mothell.exe mothell.cpp
clean:
	rm -f *.o mothell

