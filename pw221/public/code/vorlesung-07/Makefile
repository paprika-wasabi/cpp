.SUFFIXES:
.PRECIOUS: %.o
.PHONY: all compile checkstyle test clean

CXX = g++ -Wall -Wextra -O3
MAIN_BINARY = $(basename $(wildcard *Main.cpp))
TEST_BINARY = $(basename $(wildcard *Test.cpp))
LIBS = -lncurses
TESTLIBS = -lgtest -lgtest_main -lpthread
OBJECTS = $(addsuffix .o, $(basename $(filter-out %Main.cpp %Test.cpp, $(wildcard *.cpp))))

all: compile checkstyle test

compile: $(MAIN_BINARY) $(TEST_BINARY)

checkstyle:
	python3 ../cpplint.py --repository=. *.cpp *.h

test: $(TEST_BINARY)
	./$<

%.o: %.cpp *.h
	$(CXX) -c $<

%Main: %Main.o $(OBJECTS)
	$(CXX) -o $@ $^ $(LIBS)

%Test: %Test.o $(OBJECTS)
	$(CXX) -o $@ $^ $(LIBS) $(TESTLIBS)

clean:
	rm -f *Main
	rm -f *Test
	rm -f *.o
