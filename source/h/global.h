#ifndef GLOBAL__H
#define GLOBAL__H

#include <nds.h>
#include <stdio.h>
#include <../lib/gl2d.h>

#include "../h/bitmapfont.h"
#include "font.h"
#include "font_8x8.h"
#include "../h/font_8x8_uv.h"

extern ConsoleFont font_console;
extern BitmapFont font_small;

extern PrintConsole topScreen;
extern PrintConsole bottomScreen;
extern glImage FontImages[FONT_8X8_NUM_IMAGES];
 
#endif