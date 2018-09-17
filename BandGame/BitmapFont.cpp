#include"stdafx.h"

BMPFONT* _CreateFont(char* filename, int w, int h)
{
	BMPFONT* Temp = (BMPFONT*)malloc(sizeof(BMPFONT));
	Temp->surface = SDL_LoadBMP(filename);
	for (int i = 0; i < 26; i++)
	{
		Temp->chars[i].x = i*w;
		Temp->chars[i].y = 0;
		Temp->chars[i].w = w;
		Temp->chars[i].h = h;
	}


	return Temp;
}
void _DeleteFont(BMPFONT* bmpfont)
{
	if (bmpfont == NULL)return;
	SDL_FreeSurface(bmpfont->surface);
	free(bmpfont);
}
void _DrawChar(SDL_Surface* screen, BMPFONT* bmpfont, int x, int y, char ch)
{
	if ((ch <= 'A'&& ch >= 'Z') || (ch <= 'a'&& ch >= 'z'))return;
	int c = SDL_toupper((int)ch);
	int n = c - 'A';
	SDL_Rect rtXY = { x,y,bmpfont->chars[n].w,bmpfont->chars[n].h };
	SDL_BlitSurface(bmpfont->surface, &bmpfont->chars[n], screen, &rtXY);
}

void _DrawChars(SDL_Surface* screen, BMPFONT* bmpfont, int x, int y, char* str)
{
	char ch;
	int d = 0;
	for (int n = 0; n < strlen(str); n++)
	{
		ch = str[n];
		d += bmpfont->chars[n].w;
		_DrawChar(screen, bmpfont, d, y, ch);
	}
}