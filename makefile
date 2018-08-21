CC=gcc

all:sensor-demo

sensor-demo: build/main.o build/sensor.o build/imu.o build/accelerometer.o build/json_wrapper.o build/gyroscope.o build/magnetometer.o build/light.o build/sound.o build/env.o
	g++ $^ -o $@
build/sensor.o: src/sensor.cpp include/sensor.h
	$(CC) -c src/sensor.cpp -o build/sensor.o -I.

build/env.o: src/env.cpp include/env.h
	$(CC) -c src/env.cpp -o build/env.o -I.

build/light.o: src/light.cpp include/light.h
	$(CC) -c src/light.cpp -o build/light.o -I.

build/sound.o: src/sound.cpp include/sound.h
	$(CC) -c src/sound.cpp -o build/sound.o -I.

build/accelerometer.o: src/accelerometer.cpp include/accelerometer.h
	$(CC) -c src/accelerometer.cpp -o build/accelerometer.o -I.

build/gyroscope.o: src/gyroscope.cpp include/gyroscope.h
	$(CC) -c src/gyroscope.cpp -o build/gyroscope.o -I.

build/magnetometer.o: src/magnetometer.cpp include/magnetometer.h
	$(CC) -c src/magnetometer.cpp -o build/magnetometer.o -I.

build/imu.o: src/imu.cpp include/imu.h
	$(CC) -c src/imu.cpp -o build/imu.o -I.

build/json_wrapper.o: src/json_wrapper.cpp include/json_wrapper.h
	$(CC) -c src/json_wrapper.cpp -o build/json_wrapper.o -I.

build/main.o: src/main.cpp include/json.hpp
	$(CC) -c src/main.cpp -o build/main.o -I.
clean:
	rm -rf build/*.o sensor-demo
