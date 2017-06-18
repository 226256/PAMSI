CXX=g++
CXXFLAGS=-std=c++14 -Wall -pedantic  -O2
BIN=lab4.exe

SRC=$(wildcard src/*.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: $(OBJ)
	$(CXX) -o $(BIN) $^
	rm -f */*.o 
 
%.o: %.c
	$(CXX) $@ -c $<
        
clean:
	rm -f $(BIN) 

