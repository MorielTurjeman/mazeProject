OBJS := main.o

CXXFLAGS += -g

all: $(OBJS)
	$(CXX) $(OBJS) -o project

clean:
	rm -f $(OBJS)
	rm -f project