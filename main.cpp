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
#include <cmath>


#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Int_Input.H>

#include "variable.h"

#define PI 3.14159265359


int GCD(std::vector<int> nums, int length=2);


void gcd_calc(Fl_Widget*, void*) {



    std::vector<int> numbers;

    std::string str(gcd_number_input->value());

    if ( str.size() != 0 ) {

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

                if (token != "") {



                    char msg[100];

                    char* token_charp = const_cast<char*>(token.c_str());


                    sprintf(msg,"invaild input: \"%s\"", token_charp);



                    fl_message(msg, 0);
                    //fl_message(token);
                }
            }

            str.erase(0, pos + delimiter.length());
        }
        try {
            numbers.push_back(stoi(str));
        }
        catch ( const std::exception& e ) {
            std::cout << "an error\n";
            std::cout << e.what() << std::endl;



            if (token != "") {



                char msg[100];


                char* str_charp = const_cast<char*>(str.c_str());


                sprintf(msg, "invaild input: \"%s\"", str_charp);

                fl_message(msg, 0);


            }
        }
        if ( numbers.size() > 1 ) {

            int gcd = GCD(numbers, numbers.size());


            char buf[20];

            sprintf(buf, "gcd: %d", gcd);
            gcd_output_text->label(buf);
        } else
            fl_message("too few number", 0);


        /*
        std::string gcd_str = std::to_string(gcd);

        int len = gcd_str.size();

        char* label = new char[ len + 1];

        std::copy(gcd_str.begin(), gcd_str.end(), label);

        label[len] = '\0';
        */


        //delete[] label;

        //std::string numbers = gcd_number_input->value();

        //gcd_output_text->label(str);
    }


}

void gcd_clean(Fl_Widget*, void*) {

    gcd_number_input->value(0);
    gcd_output_text->label("gcd: ");

}


void lcm_calc(Fl_Widget* , void*) {

    std::vector<int> numbers;

    std::string str(lcm_number_input->value());

    if ( str.size() != 0 ) {

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



                if (token != "") {

                    char msg[100];

                    char* token_charp = const_cast<char*>(token.c_str());

                    sprintf(msg, "invaild input: \"%s\"", token_charp);

                    fl_message(msg, 0);
                }
            }

            str.erase(0, pos + delimiter.length());
        }
        try {
            numbers.push_back(stoi(str));
        }
        catch ( const std::exception& e ) {
            std::cout << "an error\n";
            std::cout << e.what() << std::endl;

            if (str != "") {

                char msg[100];

                char* str_charp = const_cast<char*>(str.c_str());


                sprintf(msg, "invaild input: \"%s\"", str_charp);

                fl_message(msg, 0);
            }

        }


        if ( numbers.size() > 1 ) {

            int gcd = GCD(numbers, numbers.size()),
                lcm,
                product=1;

            // note: lcm = (a x b x c) / gcd(a, b, c);
            //

            for ( int n : numbers )
                product *= n;

            lcm = product / gcd;


            char buf[20];

            sprintf(buf, "lcm: %d", lcm);

            std::cout << buf << std::endl;


            /*
            std::string gcd_str = std::to_string(gcd);

            int len = gcd_str.size();

            char* label = new char[ len + 1];

            std::copy(gcd_str.begin(), gcd_str.end(), label);

            label[len] = '\0';
            */

            lcm_output_text->label(buf);

            //delete[] label;

            //std::string numbers = gcd_number_input->value();

            //gcd_output_text->label(str);
        } else
            fl_message("too few number", 0);
    }
}

void lcm_clean(Fl_Widget* , void*) {
    lcm_number_input->value(0);
    lcm_output_text->label("lcm: ");
}




void sincos_calc(Fl_Widget*, void*) {

    long double sin_val, cos_val, tan_val;

    sin_val = sin( atoi( sin_degree->value() ) * PI / 180);
    cos_val = cos( atoi( cos_degree->value() ) * PI / 180);
    tan_val = tan( atoi( tan_degree->value() ) * PI / 180);


    char sin_s[20], cos_s[20], tan_s[20];

    snprintf(sin_s, 20, "%LF", sin_val);
    snprintf(cos_s, 20, "%LF", cos_val);
    snprintf(tan_s, 20, "%LF", tan_val);



    sin_output->value(sin_s);
    cos_output->value(cos_s);
    tan_output->value(tan_s);


}

void sincos_clean(Fl_Widget*, void*) {


    
    sin_degree->value(0);
    cos_degree->value(0);
    tan_degree->value(0);


}



void make_ui(void);



int main( int argc, char** argv) {

    make_ui();

    w->show(argc, argv);
    return Fl::run();

}
