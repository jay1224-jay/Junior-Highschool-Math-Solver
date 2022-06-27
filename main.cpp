/*
 *
 * TO-DO: 
 * 1. finish string split and gcd gui (including math part)
 * 
 */


#include <iostream>
#include <string>


#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>

#include "variable.h"




void gcd_calc(Fl_Widget*, void*) {
    std::string numbers = gcd_number_input->value();

    std::cout << numbers << std::endl;
}


void make_ui(void);



int main( int argc, char** argv) {

    make_ui();
    
    w->show(argc, argv);
    return Fl::run();

}
