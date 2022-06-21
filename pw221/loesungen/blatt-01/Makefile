all: clean compile test checkstyle

compile:
	g++ -o CollatzMain CollatzMain.cpp
	g++ -o CollatzTest CollatzTest.cpp -lgtest -lpthread

test:
	./CollatzTest

checkstyle:
	python3 ../cpplint.py *.cpp

clean:
	rm -f CollatzMain
	rm -f CollatzTest
