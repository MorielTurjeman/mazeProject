OBJS := main.o, maze2d.o, maze2dGenerator.o, simpleMaze2dGeneratir.o

CXXFLAGS += -g

all: $(OBJS)
	$(CXX) $(OBJS) -o project

clean:
	rm -f $(OBJS)
	rm -f project