CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++14 -lpthread

pipeline: main.o multiply.o add.o pipeline.o base_functor.o
	$(CXX) -o pipeline main.o pipeline.o multiply.o add.o base_functor.o $(CXXFLAGS)

multiply.o: multiply.cpp
	$(CXX) -c multiply.cpp $(CXXFLAGS)

pipeline.o: pipeline.cpp
	$(CXX) -c pipeline.cpp $(CXXFLAGS)

add.o: add.cpp
	$(CXX) -c add.cpp $(CXXFLAGS)

main.o: main.cpp
	$(CXX) -c main.cpp $(CXXFLAGS)

base_functor.o: base_functor.cpp
	$(CXX) -c base_functor.cpp $(CXXFLAGS)

run: pipeline
	./pipeline
