#ifndef GLOBAL__H
#define GLOBAL__H

#include <nds.h>
#include <stdio.h>
#include <../lib/gl2d.h>

#include "../h/bitmapfont.h"
#include "font.h"
#include "font_8x8.h"
#include "../h/font_8x8_uv.h"

#define TIMER_SPEED (BUS_CLOCK/1024)

#define RGB15_R(u) ( ( (u) >> 0  ) & 0x001F )
#define RGB15_G(u) ( ( (u) >> 5  ) & 0x001F )
#define RGB15_B(u) ( ( (u) >> 10 ) & 0x001F )

#define SWAP(a, b) (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))

#define MAX(a,b) ((a)<(b)) ? (b) : (a)
#define MIN(a,b) ((a)<(b)) ? (a) : (b)

extern ConsoleFont font_console;
extern BitmapFont font_small;

extern PrintConsole topScreen;
extern PrintConsole bottomScreen;
extern glImage FontImages[FONT_8X8_NUM_IMAGES];
 
#endif