#ifndef CUSTOM_FUNCTIONS_HEADER_H_
#define CUSTOM_FUNCTIONS_HEADER_H_

#include <allegro.h>
#include <winalleg.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <shlwapi.h>
#include <vector>

#define WHITE makecol(255,255,255)

using std::vector;
using std::string;
using std::cout;

void drawframe(BITMAP *, BITMAP *, int, int, int, int, int, int, int, int, bool);

int if_neg_ret_zero(int);

string dir_of_game();
vector<std::string> Return_List_OG_LEVELS();

#endif // CUSTOM_FUNCTIONS_HEADER_H_
