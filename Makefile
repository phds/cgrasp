
linesearch:	linesearch.cpp
	g++ linesearch.cpp -o linesearch -I/usr/include/python2.7/  -lpython2.7 -lmpfr -lgmp -lm

clean:
	rm linesearch
