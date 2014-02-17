#include <nds.h>
#include <stdio.h>
#include <../lib/gl2d.h>
#include <math.h>
#include <nds/ndstypes.h>
#include <nds/arm9/trig_lut.h>

#include "../h/gamestate.h"
#include "../h/gameengine.h"

#include "../h/global.h"

Menu Menu::_state;

u8 lsin1[2048];
u8 lsin2[2048];
u8 lsin3[2048];
u16 pal[256];   

const u8 K1 = 32;
const u8 K2 = 12;
const u8 K3 = 28;

// maximum values our dynamic plasmas can move
u16 KSIN1;
u16 KSIN2;
u16 KSIN3;

u8 rot;						// translucent factor
u16 counter =0;				// frame counter
u16 a = 0, b = 0, ct = 0;	// movement deltas
u16 c;	

void DrawPlasma();

void Menu::Init()
{			
    iprintf("Menu.Init\n");
			
	KSIN1 = u8(K1 *(360/57.3f));
	KSIN2 = u8(K2 *(360/57.3f));
	KSIN3 = u8(K3 *(360/57.3f));	
	
	for (int i = 0; i< ((2048) - 1); i++)
	{
        lsin1[i] = sin(i/(float)K1) * 32+32;
        lsin2[i] = sin(i/(float)K2) * 16+16;
        lsin3[i] = sin(i/(float)K3) * 20+20;
    }    
	
	for (int i=0; i<256; i++)
	{
	    u8 r = (u8)(abs(int(16 - 15 * sin(i * M_PI / 16.0f))));
		u8 g = (u8)(abs(int(16 - 15 * sin(i * M_PI / 12.0f))));
		u8 b = (u8)(abs(int(16 - 15 * sin(i * M_PI / 18.0f))));
		pal[i] = RGB15(r,g,b);
	}

	irqInit();
	irqEnable(IRQ_VBLANK);
	
	videoSetMode(MODE_FB0);
	vramSetBankA(VRAM_A_LCD);
}

void Menu::Dispose()
{
	
}

void Menu::Pause()
{
	
}

void Menu::Resume()
{

}

void Menu::HandleEvents(GameEngine* game)
{
	
}

void Menu::Update(GameEngine* game) 
{
	
}

void Menu::Render(GameEngine* game) 
{
	glBegin2D();        
	
	// backdrop
	glBoxFilled( 0, 0, 259, 191,0);
	
	DrawPlasma();
	
	// starfield 
	
	// nyancat
	
	// press start
				
	glEnd2D();
	glFlush(0);                    		
	
	swiWaitForVBlank();
}

void DrawPlasma()
{
	a= (a + 1) % (KSIN1 + 1);
	b = (b + 1) % (KSIN2 + 1);
	ct = (ct + 1) % (KSIN3 + 1);
	
	// offset 2nd plasma by a factor of 64 * 2 or (-64 to 64)
	rot = 64 * (((counter & 1) == 1) | 1);
	
	// inc frame
	counter++;
	
	//write to vram directly
	short unsigned int *vram_offset = VRAM_A;
	
	for (int ya = 0; ya<SCREEN_HEIGHT; ya++)
	{
		for (int xa = 0; xa <SCREEN_WIDTH-1; xa++)
		{
			rot = -rot;		// draw plasmas every other pixel
			// calculate colors
			c = (lsin1[xa + a + rot] + lsin2[ya + b + rot] +lsin3[1024+xa + ya - ct]);
			c = (lsin1[xa + a + rot+c] + lsin2[ya + b + rot+c] +lsin3[1024+xa + ya - ct+c]);
			// write to vram
			*vram_offset++ = pal[c];
		}
		vram_offset++;		// magic
	}	
}
