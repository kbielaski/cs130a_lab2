CXX=g++

CXXFLAGS= -std=c++11 -Wall -g -Werror -Wextra

BINARIES=prog2

all: ${BINARIES}

prog2: Main.cpp minHeap.cpp countFreq.cpp Node.cpp makeMaps.cpp
	${CXX} $^ -o $@

run: prog2
	-./prog2

clean:
	/bin/rm -f ${BINARIES} *.o

 