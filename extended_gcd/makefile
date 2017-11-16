
FLAGS = -g -Wall -std=c++11

all:	solution.o
	g++ $(FLAGS) solution.o -o driver
solution.o:	solution.cpp
	g++ $(FLAGS) -c solution.cpp -o solution.o

clean:
	rm -f *.o driver
	rm -rf ./driver.dSYM