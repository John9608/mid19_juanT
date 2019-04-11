all: mid19 unittest

mid19: mid19.cpp
	    g++ mid19.cpp -Wall -Wextra -o mid19 -O3
unittest: mid19.cpp
	g++ mid19.cpp -Wall -Wextra -o unittest -O3 -DUNIT_TEST

clean: 
	        rm -f mid19
			rm -f unittest
			rm -f *.o

