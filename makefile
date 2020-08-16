OBJS := main.o Maze2dGenerator.o  Solution.o Maze2dSearchable.o
CXXFLAGS += -g -std=c++17
CXX = clang++
all: $(OBJS)
	$(CXX) $(OBJS) -o project

clean:
	rm -f $(OBJS)
	rm -f project