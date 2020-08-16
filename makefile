OBJS := main.o Maze2d.o Maze2dGenerator.o  Searcher.o Solution.o 
CXXFLAGS += -g -std=c++17
CXX = clang++
all: $(OBJS)
	$(CXX) $(OBJS) -o project

clean:
	rm -f $(OBJS)
	rm -f project