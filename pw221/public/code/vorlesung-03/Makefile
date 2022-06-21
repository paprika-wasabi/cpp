.SUFFIXES:
.PHONY: compile checkstyle clean

compile: NcursesDemoMain

checkstyle:
	python3 ../cpplint.py --repository=. *.cpp *.h

NcursesDemoMain.o: NcursesDemoMain.cpp
	g++ -c NcursesDemoMain.cpp

NcursesDemo.o: NcursesDemo.cpp
	g++ -c NcursesDemo.cpp

NcursesDemoMain: NcursesDemo.o NcursesDemoMain.o
	$(CXX) -o $@ $^ -lncurses

clean:
	rm -f *.o
	rm -f *Main
