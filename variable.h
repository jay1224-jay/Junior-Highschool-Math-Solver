//#ifndef VAR_H
//#define VAR_H

extern Fl_Window* w;
extern Fl_Input* gcd_number_input;
extern Fl_Box* gcd_output_text;


extern void gcd_calc(Fl_Widget*, void*);
extern void lcm_calc(Fl_Widget*, void*);
extern void sincos_calc(Fl_Widget*, void*);
extern void heron_calc(Fl_Widget*, void*);
extern void se_calc(Fl_Widget*, void*);

extern void gcd_clean(Fl_Widget*, void*);
extern void lcm_clean(Fl_Widget*, void*);
extern void sincos_clean(Fl_Widget*, void*);
extern void heron_clean(Fl_Widget*, void*);
extern void se_clean(Fl_Widget*, void*);

extern Fl_Input* lcm_number_input;
extern Fl_Box* lcm_output_text;

extern Fl_Float_Input* sin_degree;
extern Fl_Float_Input* cos_degree;
extern Fl_Float_Input* tan_degree;

extern Fl_Output* sin_output;
extern Fl_Output* cos_output;
extern Fl_Output* tan_output;

extern Fl_Float_Input* heron_a;
extern Fl_Float_Input* heron_b;
extern Fl_Float_Input* heron_c;

extern Fl_Output* heron_output;


extern Fl_Float_Input* se_a1;
extern Fl_Float_Input* se_a2;
extern Fl_Float_Input* se_b1;
extern Fl_Float_Input* se_b2;
extern Fl_Float_Input* se_c1;
extern Fl_Float_Input* se_c2;

extern Fl_Output* se_x_output;
extern Fl_Output* se_y_output;


//#endif
