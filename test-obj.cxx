// generated by Fast Light User Interface Designer (fluid) version 1.0308

#include "test-obj.h"

Fl_Menu_Item menu_[] = {
 {"item", 10,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0}
};

int main(int argc, char** argv) {
  Fl_Double_Window* w;
  { Fl_Double_Window* o = new Fl_Double_Window(100, 100);
    w = o; if (w) {/* empty */}
    { Fl_Menu_Bar* o = new Fl_Menu_Bar(0, 0, 100, 20);
      o->menu(menu_);
    } // Fl_Menu_Bar* o
    { Fl_Menu_Button* o = new Fl_Menu_Button(0, 0, 75, 20, "menu");
    } // Fl_Menu_Button* o
    o->end();
  } // Fl_Double_Window* o
    w->show(argc, argv);
    return Fl::run();
}