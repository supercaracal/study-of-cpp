bin/Hello: src/Hello.cpp
	g++ -o bin/Hello -Wall -g src/Hello.cpp

bin/Counter: src/Counter.h src/DoubleCounter.h src/Counter.cpp src/DoubleCounter.cpp src/Count.cpp
	g++ -o bin/Counter -Wall -g src/Counter.h src/DoubleCounter.h src/Counter.cpp src/DoubleCounter.cpp src/Count.cpp

bin/Fill: src/Tmpl.h src/Fill.cpp
	g++ -o bin/Fill -Wall -g src/Tmpl.h src/Fill.cpp

bin/TryCatch: src/TryCatch.cpp
	g++ -o bin/TryCatch -Wall -g src/TryCatch.cpp

bin/01_01_05: src/01_01_05_main.cpp
	g++ -o bin/01_01_05 -Wall -g src/01_01_05_main.cpp

bin/01_03_05: src/01_03_05/main.cpp src/01_03_05/headers/game.h src/01_03_05/game.cpp
	g++ -o bin/01_03_05 -Wall -g src/01_03_05/main.cpp src/01_03_05/headers/game.h src/01_03_05/game.cpp
