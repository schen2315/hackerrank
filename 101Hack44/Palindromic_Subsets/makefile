
FLAGS = -g -Wall -std=c++11

1:	driver
	./driver < testfile1.txt
2:	driver 
	./driver < testfile2.txt
driver:	solution.o
	g++ $(FLAGS) solution.o -o driver
solution.o:	solution.cpp
	g++ $(FLAGS) -c solution.cpp -o solution.o

clean:
	rm -f *.o driver
	rm -rf ./driver.dSYM