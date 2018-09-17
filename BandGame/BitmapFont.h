#pragma once

typedef struct tagBitmapFont
{
	SDL_Surface* surface;
	SDL_Rect chars[26];
} BMPFONT;

BMPFONT* _CreateFont(char* filename, int w, int h);
void _DeleteFont(BMPFONT* bmpfont);
void _DrawChar(SDL_Surface* screen, BMPFONT* bmpfont, int x, int y, char ch);
void _DrawChars(SDL_Surface* screen, BMPFONT* bmpfont, int x, int y, char* str);