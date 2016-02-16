CXX=g++

CXXFLAGS= -std=c++11 -Wall -g -Werror -Wextra

BINARIES=prog2

all: ${BINARIES}

prog2: Main.o minHeap.o countFreq.o Node.o makeMaps.o
	${CXX} $^ -o $@

run: prog2
	-./prog2

clean:
	/bin/rm -f ${BINARIES} *.o

