bin/hello: src/trash/hello.cpp
	g++ -o $@ -Wall -g $^

bin/counter: src/trash/counter.h src/trash/double_counter.h src/trash/counter.cpp src/trash/double_counter.cpp src/trash/count.cpp
	g++ -o $@ -Wall -g $^

bin/fill: src/trash/tmpl.h src/trash/fill.cpp
	g++ -o $@ -Wall -g $^

bin/try_catch: src/trash/try_catch.cpp
	g++ -o $@ -Wall -g $^

bin/01_01_05: src/01_01_05_main.cpp
	g++ -o $@ -Wall -g $^

bin/01_03_05: $(wildcard src/01_03_05/*.h src/01_03_05/*.cpp)
	g++ -o $@ -Wall -g $^
