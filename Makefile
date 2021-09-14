LEDALIB='/usr/local/LEDA'
LEDAINCL='/usr/local/LEDA/incl'

compile:
	g++ main.cpp generator.cpp generator.h -o run -std=c++0x -O3 -I$(LEDAINCL) -L$(LEDALIB) -lleda
	./run

clean:
	rm -f run


