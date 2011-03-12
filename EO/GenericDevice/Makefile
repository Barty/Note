all: main

main: main.o genericDevice.o genericAttribute.o tempDevice.o
	g++ main.o genericDevice.o genericAttribute.o tempDevice.o -o test-deviceCache

main.o: main.cpp
	g++ -c main.cpp

genericDevice.o: genericDevice.cpp genericDevice.h
	g++ -c genericDevice.cpp
	
genericAttribute.o: genericAttribute.cpp genericAttribute.h
	g++ -c genericAttribute.cpp

tempDevice.o: tempDevice.cpp tempDevice.h
	g++ -c tempDevice.cpp
	
clean:
	rm -rf *.o test-deviceCache
