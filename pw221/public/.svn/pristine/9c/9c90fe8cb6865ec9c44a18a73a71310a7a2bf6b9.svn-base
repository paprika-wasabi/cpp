all: clean compile test checkstyle

compile:
	g++ -o PrimeMain PrimeMain.cpp
	g++ -o PrimeTest PrimeTest.cpp -lgtest -lpthread

test:
	./PrimeTest

checkstyle:
	python3 ../cpplint.py *.cpp

clean:
	rm -f PrimeMain PrimeTest
