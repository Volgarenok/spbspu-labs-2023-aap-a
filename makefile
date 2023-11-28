CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: out/serter.tugce/P0/lab

out/serter.tugce/P0/lab: out/serter.tugce/P0/main.o out/serter.tugce/P0/credentials.o | out/serter.tugce/P0
	$(CXX) $(CXXFLAGS) $^ -o $@

out/serter.tugce/P0/main.o: serter.tugce/P0/main.cpp serter.tugce/P0/credentials.hpp | out/serter.tugce/P0
	$(CXX) $(CXXFLAGS) -c $< -o $@

out/serter.tugce/P0/credentials.o: serter.tugce/P0/credentials.cpp serter.tugce/P0/credentials.hpp | out/serter.tugce/P0
	$(CXX) $(CXXFLAGS) -c $< -o $@

out/serter.tugce/P0:
	mkdir -p $@

clean:
	rm -rf out

.PHONY: all clean

