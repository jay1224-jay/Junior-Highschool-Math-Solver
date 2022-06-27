/*
 *
 * TO-DO: 
 * 1. finish string split and gcd gui (including math part)
 * 
 */


#include <iostream>
#include <string>
#include <vector>


#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Box.H>

#include "variable.h"




void gcd_calc(Fl_Widget*, void*) {

    std::vector<int> numbers;

    std::string str(gcd_number_input->value());

    std::string token, delimiter = " ";

    size_t pos = 0;

    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        numbers.push_back(stoi(token));
        str.erase(0, pos + delimiter.length());
    }
    numbers.push_back(stoi(str));

    std::cout << std::endl;

    int sum = 0;

    for ( int i : numbers)
        sum += i;
    
    std::cout << sum << std::endl;

    //std::string numbers = gcd_number_input->value();

    //gcd_output_text->label(str);
}


void make_ui(void);



int main( int argc, char** argv) {

    make_ui();
    
    w->show(argc, argv);
    return Fl::run();

}
