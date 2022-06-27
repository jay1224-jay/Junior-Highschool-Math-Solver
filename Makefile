
# files: main.cpp math.cpp ui.cpp

main: ui.o math.o main.o
	g++ ui.o math.o main.o -o main `fltk-config --ldflags`

ui.o: ui.cpp
	g++ `fltk-config --cxxflags` -c ui.cpp -Wall

main.o: main.cpp
	g++ `fltk-config --cxxflags` -c main.cpp -Wall

math.o: math.cpp
	g++ -c math.cpp -Wall


clean:
	rm *.o
