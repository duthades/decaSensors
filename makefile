CC=gcc
CFLAGS=-I. -ftest-coverage -fprofile-arcs
all:sensor-demo

sensor-demo: build/functions.o build/main.o build/sensor.o build/imu.o build/accelerometer.o build/json_wrapper.o build/gyroscope.o build/magnetometer.o build/light.o build/sound.o build/env.o
	g++ $^ -o $@ -ftest-coverage -fprofile-arcs
build/sensor.o: src/sensor.cpp include/sensor.h
	$(CC) -c src/sensor.cpp -o build/sensor.o $(CFLAGS)

build/functions.o: src/functions.cpp include/functions.h
	$(CC) -c src/functions.cpp -o build/functions.o $(CFLAGS)

build/env.o: src/env.cpp include/env.h
	$(CC) -c src/env.cpp -o build/env.o $(CFLAGS)

build/light.o: src/light.cpp include/light.h
	$(CC) -c src/light.cpp -o build/light.o $(CFLAGS)

build/sound.o: src/sound.cpp include/sound.h
	$(CC) -c src/sound.cpp -o build/sound.o $(CFLAGS)

build/accelerometer.o: src/accelerometer.cpp include/accelerometer.h
	$(CC) -c src/accelerometer.cpp -o build/accelerometer.o $(CFLAGS)

build/gyroscope.o: src/gyroscope.cpp include/gyroscope.h
	$(CC) -c src/gyroscope.cpp -o build/gyroscope.o $(CFLAGS)

build/magnetometer.o: src/magnetometer.cpp include/magnetometer.h
	$(CC) -c src/magnetometer.cpp -o build/magnetometer.o $(CFLAGS)

build/imu.o: src/imu.cpp include/imu.h
	$(CC) -c src/imu.cpp -o build/imu.o $(CFLAGS)

build/json_wrapper.o: src/json_wrapper.cpp include/json_wrapper.h
	$(CC) -c src/json_wrapper.cpp -o build/json_wrapper.o $(CFLAGS)

build/main.o: src/main.cpp 
	$(CC) -c src/main.cpp -o build/main.o $(CFLAGS)
clean:
	rm -rf build/*.o sensor-demo
