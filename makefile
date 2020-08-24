OBJS := main.o Maze2dGenerator.o  Solution.o Maze2dSearchable.o MyMaze2dGenerator.o MazeCompression.o CLI.o MyModel.o Demo.o Observer.o Observable.o
CXXFLAGS += -g -std=c++17
CXX = clang++
all: $(OBJS)
	$(CXX) $(OBJS) -o project

clean:
	rm -f $(OBJS)
	rm -f project