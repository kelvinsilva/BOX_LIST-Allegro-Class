#include "CUSTOM_FUNCTIONS_HEADER.h"
#include "BOX_LIST_CLASS.hpp"

#define WHITE makecol(255, 255, 255)

using std::string;



int main(){

    //Init allegro
    allegro_init();
    install_keyboard();
    if(install_sound(DIGI_AUTODETECT, MIDI_NONE, "") != 0){
        allegro_message("error initializing the sound system");
    }


    set_color_depth(16);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 400, 300, 0, 0);

    //Load My font to use....
    FONT *BOX_FONT = load_font("BITMAPS\\BOX_FONT.pcx", NULL, NULL);

    //Create the box_list item
    //Step 0...
    BOX_LIST<string, string> box(0, 0, 150, 200, 4, WHITE, screen, BOX_FONT, 40);

    //Load some values into display
    vector<string> Number_Letter_display;
    Number_Letter_display.push_back("Zero");
    Number_Letter_display.push_back("One");
    Number_Letter_display.push_back("Two");
    Number_Letter_display.push_back("Three");
    Number_Letter_display.push_back("Four");

    vector<string> Number_Symbol_Value;
    Number_Symbol_Value.push_back("Symbol: 0");
    Number_Symbol_Value.push_back("Symbol: 1");
    Number_Symbol_Value.push_back("Symbol: 2");
    Number_Symbol_Value.push_back("Symbol: 3");
    Number_Symbol_Value.push_back("Symbol: 4");


    //Step 1..
    box.load_display_array(Number_Letter_display);
    //Step 2..
    box.load_value_array(Number_Symbol_Value);


bool loop_switch = true;
while(loop_switch){

    if(key[KEY_ESC]){
        loop_switch = false;
    }

    clear(screen);

    //Step 3...
    box.display();

    //Step 4...
    if(key[KEY_DOWN])
        box.select_down();

    if(key[KEY_UP])
        box.select_up();

    textprintf_ex(screen, font, 15, 200, WHITE, 0, "box.return_index_content: %i", box.return_index_content());
    textprintf_ex(screen, font, 15, 220, WHITE, 0, "box.return_display_content: %s", box.return_display_content().c_str());
    textprintf_ex(screen, font, 15, 240, WHITE, 0, "box.return_value_content: %s", box.return_value_content().c_str());

    vsync();
    rest(45); //Make some rest
}
    return 0;
}
END_OF_MAIN()
