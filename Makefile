bin/Hello: src/Hello.cpp
	g++ -o bin/Hello -Wall -g src/Hello.cpp

bin/Counter: src/Counter.h src/DoubleCounter.h src/Counter.cpp src/DoubleCounter.cpp src/Count.cpp
	g++ -o bin/Counter -Wall -g src/Counter.h src/DoubleCounter.h src/Counter.cpp src/DoubleCounter.cpp src/Count.cpp
