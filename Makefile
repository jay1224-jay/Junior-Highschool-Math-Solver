
# files: main.cpp math.cpp ui.cpp

DEBUG_FLAGS = -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused
# DEBUG_FLAGS is from https://stackoverflow.com/questions/5088460/flags-to-enable-thorough-and-verbose-g-warnings;



main: ui.o math.o main.o
	g++ ui.o math.o main.o -o main `fltk-config --ldflags`

ui.o: ui.cpp variable.h
	g++ `fltk-config --cxxflags` -c ui.cpp $(DEBUG_FLAGS)

main.o: main.cpp variable.h
	g++ `fltk-config --cxxflags` -c main.cpp $(DEBUG_FLAGS)

math.o: math.cpp
	g++ -c math.cpp $(DEBUG_FLAGS)


clean:
	rm *.o
