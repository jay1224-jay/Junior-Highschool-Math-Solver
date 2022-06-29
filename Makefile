
# files: main.cpp math.cpp ui.cpp

main: ui.o math.o main.o
	g++ ui.o math.o main.o -o main `fltk-config --use-images --ldflags`

ui.o: ui.cpp variable.h
	g++ `fltk-config --use-images --cxxflags` -c ui.cpp -Wall

main.o: main.cpp variable.h
	g++ `fltk-config --cxxflags` -c main.cpp -Wall

math.o: math.cpp
	g++ -c math.cpp -Wall


clean:
	rm *.o
