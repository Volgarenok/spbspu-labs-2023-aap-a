CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: out/serter.tugce/P0/lab

out/serter.tugce/P0/lab: out/serter.tugce/P0/main.o out/serter.tugce/P0/credentials.o
	$(CXX) $(CXXFLAGS) $^ -o $@

out/serter.tugce/P0/main.o: serter.tugce/P0/main.cpp serter.tugce/P0/credentials.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

out/serter.tugce/P0/credentials.o: serter.tugce/P0/credentials.cpp serter.tugce/P0/credentials.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf out

.PHONY: all clean

