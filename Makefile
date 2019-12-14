CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++14 -lpthread


pipeline: main.o multiply.o add.o pipeline.o stage.o open_file.o save_file.o
	$(CXX) -o pipeline main.o pipeline.o multiply.o add.o stage.o open_file.o save_file.o $(CXXFLAGS)

multiply.o: multiply.cpp
	$(CXX) -c multiply.cpp $(CXXFLAGS)

pipeline.o: pipeline.cpp
	$(CXX) -c pipeline.cpp $(CXXFLAGS)

open_file.o: open_file.cpp
	$(CXX) $(CXXFLAGS) open_file.cpp -c

save_file.o: save_file.cpp
	$(CXX) $(CXXFLAGS) save_file.cpp -c

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

clean:
	rm *.o pipeline