OBJS := main.o Maze2dGenerator.o  Solution.o Maze2dSearchable.o MyMaze2dGenerator.o MazeCompression.o CLI.o Model.o Demo.o Observer.o Observable.o View.o MyView.o MyController.o MyModel.o
CXXFLAGS += -g -std=c++17
CXX = clang++
all: $(OBJS)
	$(CXX) $(OBJS) -o project

clean:
	rm -f $(OBJS)
	rm -f project