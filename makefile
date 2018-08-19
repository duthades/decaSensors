CC=gcc

all:sensor-demo

sensor-demo: build/main.o build/sensor.o build/imu.o build/accelerometer.o build/json_wrapper.o
	g++ $^ -o $@
build/sensor.o: src/sensor.cpp include/sensor.h
	$(CC) -c src/sensor.cpp -o build/sensor.o -I.

build/accelerometer.o: src/accelerometer.cpp include/accelerometer.h
	$(CC) -c src/accelerometer.cpp -o build/accelerometer.o -I.

build/imu.o: src/imu.cpp include/imu.h
	$(CC) -c src/imu.cpp -o build/imu.o -I.

build/json_wrapper.o: src/json_wrapper.cpp include/json_wrapper.h
	$(CC) -c src/json_wrapper.cpp -o build/json_wrapper.o -I.

build/main.o: src/main.cpp include/json.hpp
	$(CC) -c src/main.cpp -o build/main.o -I.
clean:
	rm -rf build/*.o sensor-demo
