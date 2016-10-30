# Compile algorithm test cases

CXX = g++
CXX_FLAGS = -c -Wall -Wextra -g
I_FLAGS = 
LD_FLAGS =
LD_LIBS = 
SOURCES = $(wildcard *.cpp)
OBJECTS = $(patsubst %.cpp,%.o,$(SOURCES))
EXECUTABLE = algorithm_tests

all: clean $(SOURCES) $(EXECUTABLE)
	#

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@ $(LD_LIBS)

%.o: %.cpp
	$(CXX) $(I_FLAGS) $(CXX_FLAGS) -c $*.cpp

clean:
	rm -f *.o
	rm -f $(EXECUTABLE)
	find -name "*~" -exec rm -vf {} \;
