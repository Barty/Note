all: main

main: main.o genericDevice.o genericAttribute.o lightSensorDevice.o
	g++ main.o genericDevice.o genericAttribute.o lightSensorDevice.o -o test-deviceCache

main.o: main.cpp
	g++ -c main.cpp

genericDevice.o: genericDevice.cpp genericDevice.h
	g++ -c genericDevice.cpp
	
genericAttribute.o: genericAttribute.cpp genericAttribute.h
	g++ -c genericAttribute.cpp

lightSensorDevice.o: lightSensorDevice.cpp lightSensorDevice.h
	g++ -c lightSensorDevice.cpp

2RockerDevice.o: 2RockerDevice.cpp 2RockerDevice.h
	g++ -c 2RockerDevice.cpp
	
clean:
	rm -rf *.o test-deviceCache
