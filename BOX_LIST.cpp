//Kelvin Silva
//Makes a box with a list and a rectangle to select
//Current bugs: sometimes when you go down, its infinite

#include <allegro.h>
#include <winalleg.h>
#include <vector>
#include <string>
#include "CUSTOM_FUNCTIONS_HEADER.h"

using std::string;
using std::vector;

template<class Type1, class Type2>
class BOX_LIST{

private:

    int xpos, ypos; //Note that this deontes top right corner....
    int sizex2, sizey2;
    int thickness_box;
    int items_per_box;

    int color;

    int shift_start = 0;

    int cursorposct;

    int cursorx1, cursory1, cursorx2, cursory2;

    BITMAP *draw_surface;
    FONT *font_box;

    int font_sz;

    vector<Type1> box_contents_display;
    vector<Type2> box_contents_value;

    void scroll_up();
    void scroll_down();


public:
           //sizex1, sizey1, sizex2, sizey2, thickness, itemsperbox, contents of box.
    BOX_LIST(int, int, int, int, int, int, BITMAP*, FONT*, int);
    ~BOX_LIST();



    void select_up();
    void select_down();
    void display();
    void display_cursor();
    void load_display_array(vector<Type1>);
    void load_value_array(vector<Type2>);


    int return_index_content();
    Type1 return_display_content();
    Type2 return_value_content();


};


template<class Type1, class Type2>
BOX_LIST<Type1, Type2>::BOX_LIST(int x, int y, int l, int w, int thick, int col, BITMAP* bitmp, FONT *fon, int fonsz){

        xpos = x;
        ypos = y;
        sizex2 = (x+w);
        sizey2 = (y+l);

        thickness_box = thick;



        color = col;

        draw_surface = bitmp;
        font_box = fon;
        font_sz = fonsz;

        items_per_box = (l/fonsz);

        cursorx1 = xpos+2;
        cursory1 = ypos+2;
        cursorx2 = sizex2-2;
        cursory2 = font_sz;

}

template<class Type1, class Type2>
BOX_LIST<Type1, Type2>::~BOX_LIST(){



}

template<class Type1, class Type2>
void BOX_LIST<Type1, Type2>::display(){

    for(int i = 0; i < thickness_box; i++){
        rect(draw_surface, xpos+i, ypos+i, sizex2+i, sizey2+i, color);
    }

    int x = 0;
    for(int i = shift_start; i < box_contents_display.size() && i < items_per_box+shift_start; i++, x++){

       textprintf_ex(draw_surface, font_box, xpos+thickness_box+5, ypos+thickness_box+(x*font_sz) , color, -1, box_contents_display[i].c_str());

    }

    display_cursor();

}

template<class Type1, class Type2>
void BOX_LIST<Type1, Type2>::display_cursor(){

    cursory1 = if_neg_ret_zero((ypos+(cursorposct*font_sz)));
    cursory2 = if_neg_ret_zero((font_sz+(cursorposct*font_sz)));

    rect(draw_surface, cursorx1+thickness_box+2, cursory1,  cursorx2-2, cursory2, color);
}

template<class Type1, class Type2>
void BOX_LIST<Type1, Type2>::scroll_up(){

    shift_start--;

    shift_start = if_neg_ret_zero(shift_start);
}

template<class Type1, class Type2>
void BOX_LIST<Type1, Type2>::scroll_down(){

    shift_start++;

    if(shift_start > box_contents_display.size() - items_per_box){
        shift_start = box_contents_display.size() - shift_start;
    }
}

template<class Type1, class Type2>
void BOX_LIST<Type1, Type2>::select_up(){


    cursorposct--;

    if(cursorposct < 0){
        cursorposct = 0;
        scroll_up();
    }
}

template<class Type1, class Type2>
void BOX_LIST<Type1, Type2>::select_down(){

    cursorposct++;

    if(cursorposct >= items_per_box){
        cursorposct = items_per_box;
        scroll_down();
    }

    //cursorposct = if_neg_ret_zero(cursorposct);

}

template<class Type1, class Type2>
void BOX_LIST<Type1, Type2>::load_display_array(vector<Type1> disp){
    box_contents_display = disp;
}

template<class Type1, class Type2>
void BOX_LIST<Type1, Type2>::load_value_array(vector<Type2> val){
    box_contents_value = val;
}

template<class Type1, class Type2>
int BOX_LIST<Type1, Type2>::return_index_content(){
    return cursorposct+shift_start;
}

template<class Type1, class Type2>
Type1 BOX_LIST<Type1, Type2>::return_display_content(){
    return box_contents_display[return_index_content()];
}

template<class Type1, class Type2>
Type2 BOX_LIST<Type1, Type2>::return_value_content(){
    return box_contents_value[return_index_content()];
}
