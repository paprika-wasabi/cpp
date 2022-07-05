.SUFFIXES:
.PRECIOUS: %.o
.PHONY: all compile checkstyle test clean

CXX = g++ -Wall -Wextra -O3
TEST_BINARY = StringTest
MAIN_BINARY = StringBenchmarkMain
OBJECTS = String.o
LIBS =
TESTLIBS = -lgtest -lgtest_main -lpthread

all: compile checkstyle test

compile: $(MAIN_BINARY) $(TEST_BINARY)

checkstyle:
	python3 ../cpplint.py --repository=. *.cpp

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
