/*
 *
 * TO-DO: 
 * 1. finish string split and gcd gui (including math part)
 * 
 */


#include <iostream>
#include <string>
#include <vector>
#include <cstdio>


#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>

#include "variable.h"


int GCD(std::vector<int> nums, int length=2);


void gcd_calc(Fl_Widget*, void*) {



    std::vector<int> numbers;

    std::string str(gcd_number_input->value());

    std::string token, delimiter = " ";

    size_t pos = 0;

    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        try {
            numbers.push_back(stoi(token));
        } 
        catch ( const std::exception& e ) {
            std::cout << "an error\n";
            std::cout << e.what() << std::endl;

            char msg[100];

            char* token_charp = const_cast<char*>(token.c_str());


            sprintf(msg, "invaild input: \"%s\"\nmake sure you type numbers with only one space \" \"", token_charp);

            fl_message(msg);
        }

        str.erase(0, pos + delimiter.length());
    }
    try {
        numbers.push_back(stoi(str));
    } 
    catch ( const std::exception& e ) {
        std::cout << "an error\n";
        std::cout << e.what() << std::endl;

        char msg[100];

        char* str_charp = const_cast<char*>(str.c_str());


        sprintf(msg, "invaild input: \"%s\"\nmake sure you type numbers with only one space \" \"", str_charp);

        fl_message(msg);
    }


    int gcd = GCD(numbers, numbers.size());


    char buf[20];

    sprintf(buf, "gcd: %d", gcd);


    /*
    std::string gcd_str = std::to_string(gcd);

    int len = gcd_str.size();

    char* label = new char[ len + 1];

    std::copy(gcd_str.begin(), gcd_str.end(), label);

    label[len] = '\0';
    */

    gcd_output_text->label(buf);

    //delete[] label;

    //std::string numbers = gcd_number_input->value();

    //gcd_output_text->label(str);
}

void gcd_clean(Fl_Widget*, void*) {

    gcd_number_input->value(0);
    gcd_output_text->label("gcd: ");

}
    


void make_ui(void);



int main( int argc, char** argv) {

    make_ui();
    
    w->show(argc, argv);
    return Fl::run();

}
