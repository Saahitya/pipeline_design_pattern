CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++14 -lpthread

pipeline: main.o multiply.o add.o pipeline.o stage.o
	$(CXX) -o pipeline main.o pipeline.o multiply.o add.o stage.o $(CXXFLAGS)

multiply.o: multiply.cpp
	$(CXX) -c multiply.cpp $(CXXFLAGS)

pipeline.o: pipeline.cpp
	$(CXX) -c pipeline.cpp $(CXXFLAGS)

add.o: add.cpp
	$(CXX) -c add.cpp $(CXXFLAGS)

main.o: main.cpp
	$(CXX) -c main.cpp $(CXXFLAGS)

stage.o: stage.cpp
	$(CXX) -c stage.cpp $(CXXFLAGS)

run: pipeline
	./pipeline

stats: 
	cloc --exclude-lang=XML --git .

oldschool:
	clang++-8 -pthread -o OldSchool/main OldSchool/basic_pipeline.cpp OldSchool/main.cpp OldSchool/stage.cpp
