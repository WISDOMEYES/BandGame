#include"stdafx.h"
#include "SDL_Button.h"

BUTTON* InitButton(SDL_Renderer* screen,const char* szUp, const char* szDown, const char* szOver, int x, int y, bool type,int(*f)())
{
	BUTTON* Temp;

	Temp = (BUTTON*)malloc(sizeof(BUTTON));
	SDL_Surface* imgTemp;

	imgTemp = SDL_LoadBMP(szUp);
	Uint32 colorkey = SDL_MapRGB(imgTemp->format, 255, 0, 225);
	SDL_SetColorKey(imgTemp, SDL_TRUE, colorkey);
	Temp->imgUp = SDL_CreateTextureFromSurface(screen, imgTemp);

	imgTemp = SDL_LoadBMP(szDown);
	colorkey = SDL_MapRGB(imgTemp->format, 255, 0, 225);
	SDL_SetColorKey(imgTemp, SDL_TRUE, colorkey);
	Temp->imgDown = SDL_CreateTextureFromSurface(screen, imgTemp);

	imgTemp = SDL_LoadBMP(szOver);
	colorkey = SDL_MapRGB(imgTemp->format, 255, 0, 225);
	SDL_SetColorKey(imgTemp, SDL_TRUE, colorkey);
	Temp->imgOv = SDL_CreateTextureFromSurface(screen, imgTemp);

	Temp->imgCurrent = Temp->imgUp;

	Temp->imgW = imgTemp->w;
	Temp->imgH = imgTemp->h;

	Temp->rtClip.x = x -imgTemp->w/2;
	Temp->rtClip.y = y - imgTemp->h / 2;

	setBPos(Temp);

	Temp->rtClip.w = imgTemp->w;
	Temp->rtClip.h = imgTemp->h;


	SetCoord(Temp, x - imgTemp->w / 2, y - imgTemp->h / 2);

	SetVisible(Temp, true);

	Temp->type = type;

	Temp->func = f;
	Temp->overClick = false;

	SDL_FreeSurface(imgTemp);

	return Temp;
}

BUTTON * InitSButton(SDL_Renderer * screen, const char * szUp,int x, int y, int(*f)(),int(*s)())
{
	BUTTON* Temp;

	Temp = (BUTTON*)malloc(sizeof(BUTTON));
	SDL_Surface* imgTemp;

	imgTemp = SDL_LoadBMP(szUp);
	Uint32 colorkey = SDL_MapRGB(imgTemp->format, 255, 0, 255);
	SDL_SetColorKey(imgTemp, SDL_TRUE, colorkey);
	Temp->imgDown = SDL_CreateTextureFromSurface(screen, imgTemp);
	Temp->imgOv = SDL_CreateTextureFromSurface(screen, imgTemp);
	Temp->imgUp = SDL_CreateTextureFromSurface(screen, imgTemp);

	Temp->imgCurrent = Temp->imgUp;

	Temp->imgW = imgTemp->w;
	Temp->imgH = imgTemp->h;

	Temp->rtClip.x = x - imgTemp->w / 2;
	Temp->rtClip.y = y - imgTemp->h / 2;

	setBPos(Temp);

	Temp->rtClip.w = imgTemp->w;
	Temp->rtClip.h = imgTemp->h;

	SetCoord(Temp, x - imgTemp->w / 2, y - imgTemp->h / 2);

	SetVisible(Temp, true);

	Temp->func = f;
	Temp->sp = s;
	Temp->type = false;
	Temp->overClick = true;

	SDL_FreeSurface(imgTemp);

	return Temp;
}

void Release(BUTTON* pBtn)
{
	if (pBtn == NULL) return;
	
	if (pBtn->imgUp != 0)	SDL_DestroyTexture(pBtn->imgUp);
	if (pBtn->imgDown != 0)	SDL_DestroyTexture(pBtn->imgDown);

	delete pBtn;
}

void Draw(SDL_Renderer* screen, BUTTON* pBtn)
{
	if (!pBtn->bIsVisible) return;
	SDL_RenderCopy(screen, pBtn->imgCurrent,NULL,&pBtn->rtClip);
}

void setBPos(BUTTON * pbtn)
{
	pbtn->nX -= pbtn->imgW/2;
	pbtn->nY -= pbtn->imgH/2;
}

BUTTON::eButtonState GetState(BUTTON* pBtn)
{
	if (pBtn->imgCurrent == pBtn->imgDown)

		return BUTTON::eButtonState::BUTTONDOWN;
	else 
		return BUTTON::eButtonState::BUTTONUP;
}

void OverClick(CSystem* _cSystem,BUTTON * pBtn,int px, int py)
{
	if (IsOver(pBtn, px, py))
	{
		pBtn->imgCurrent = pBtn->imgOv;
		if (pBtn->overClick)
		{
			_cSystem->choice(pBtn->sp());
		}
	}
	else
	{
		if (pBtn->type&&!pBtn->typeSwitch)
		{
			pBtn->imgCurrent = pBtn->imgDown;
		}
		else ResetOnUp(pBtn);
	}
}

void ClickDown(BUTTON* pBtn)
{
	pBtn->imgCurrent = pBtn->imgDown;
}

void ClickUp(CSystem* _cSystem, BUTTON* pBtn)
{
	sndPlaySound(L"sound/btn.wav", SND_ASYNC);
	if (!pBtn->type)
	{
	pBtn->imgCurrent = pBtn->imgUp;
	}
	else
	{
		if (pBtn->typeSwitch)
		{
			pBtn->imgCurrent = pBtn->imgDown;
			pBtn->typeSwitch = false;
		}
		else
		{
			pBtn->imgCurrent = pBtn->imgUp;
			pBtn->typeSwitch = true;
		}
	}
	if (pBtn->func != 0)
	{
		pBtn->func();
		switch (pBtn->func())
		{
		case S_START:
			_cSystem->changeScene(1);
			_cSystem->stopSong();
			break;
		case S_HOWTO:
			_cSystem->changeScene(2);
			break;
		case S_CREDIT:
			_cSystem->changeScene(3);
			break;
		case S_EXIT:
			_cSystem->Terminate();
			break;
		case S_EXITWIN:
			_cSystem->changeScene(0);
			break;
		case M_RETURN:
			_cSystem->changeScene(0);
			_cSystem->stopSong();
			_cSystem->playSong(0);
			_cSystem->rainSwitch = false;
			_cSystem->restartGame();
			break;
		case M_RAIN:
			if (!pBtn->typeSwitch) { _cSystem->rainSwitch = true; _cSystem->rainBTn(1); }
			else { _cSystem->rainSwitch = false; _cSystem->rainBTn(0); }
			break;
		case M_SPECIAL:
			_cSystem->choice(3);
			break;
		case M_BLUE:
			_cSystem->isblue();
			break;
		case M_RED:
			_cSystem->isRed();
			break;
		case M_PLAY:
			if (!pBtn->typeSwitch) _cSystem->pauseSong();
			else _cSystem->restartSong();
			break;
		case M_MSC1:
			if (!pBtn->typeSwitch)
			{ 
				_cSystem->stopSong();
				_cSystem->playSong(1);
				pBtn->imgCurrent = pBtn->imgDown;
				pBtn->typeSwitch = false;
			}
			else  _cSystem->stopSong();			
			break;
		case M_MSC2:
			if (!pBtn->typeSwitch)
			{
				_cSystem->stopSong();
				_cSystem->playSong(2);
				pBtn->imgCurrent = pBtn->imgDown;
				pBtn->typeSwitch = false;
			}
			else  _cSystem->stopSong();
			break;
		case M_MSC3:
			if (!pBtn->typeSwitch)
			{
				_cSystem->stopSong();
				_cSystem->playSong(3);
				pBtn->imgCurrent = pBtn->imgDown;
				pBtn->typeSwitch = false;
			}
			else  _cSystem->stopSong();
			break;
		case M_MSC4:
			if (!pBtn->typeSwitch)
			{
				_cSystem->stopSong();
				_cSystem->playSong(4);
				pBtn->imgCurrent = pBtn->imgDown;
				pBtn->typeSwitch = false;
			}
			else  _cSystem->stopSong();
			break;
		case M_MSC5:
			if (!pBtn->typeSwitch)
			{
				_cSystem->stopSong();
				_cSystem->playSong(5);
				pBtn->imgCurrent = pBtn->imgDown;
				pBtn->typeSwitch = false;
			}
			else  _cSystem->stopSong();
			break;
		case M_MONSTER:
			_cSystem->AniSwich(0);
			break;
		case M_BOY:
			_cSystem->AniSwich(1);
			break;
		case M_BIRD:
			_cSystem->AniSwich(2);
			break;
		case M_GIRL:
			_cSystem->AniSwich(3);
			break; 
		case M_SPEAKER:
			_cSystem->AniSwich(4);
			break;
		case SP_1:
			if (!pBtn->typeSwitch)
			{
				_cSystem->stopSong();
				_cSystem->playSong(6);
				pBtn->imgCurrent = pBtn->imgDown;
				pBtn->typeSwitch = false;
			}
			else  _cSystem->stopSong();
			_cSystem->AniSwich(0);
			break;
		case SP_2:
			if (!pBtn->typeSwitch)
			{
				_cSystem->stopSong();
				_cSystem->playSong(7);
				pBtn->imgCurrent = pBtn->imgDown;
				pBtn->typeSwitch = false;
			}
			else  _cSystem->stopSong();
			_cSystem->AniSwich(1);

			break;
		case SP_3:
			if (!pBtn->typeSwitch)
			{
				_cSystem->stopSong();
				_cSystem->playSong(8);
				pBtn->imgCurrent = pBtn->imgDown;
				pBtn->typeSwitch = false;
			}
			else  _cSystem->stopSong();
			_cSystem->AniSwich(2);

			break;
		case SP_4:
			if (!pBtn->typeSwitch)
			{
				_cSystem->stopSong();
				_cSystem->playSong(9);
				pBtn->imgCurrent = pBtn->imgDown;
				pBtn->typeSwitch = false;
			}
			else  _cSystem->stopSong();
			_cSystem->AniSwich(3);

			break;
		case SP_G:
			_cSystem->AniSwich(4);
			break;

		}
	}
}

void Reset(BUTTON * pBtn)
{
	pBtn->imgCurrent = pBtn->imgUp;
	pBtn->typeSwitch = true;
}

bool IsOver(BUTTON* pBtn, int px, int py)
{
	if ((px >= pBtn->nX) && (px < (pBtn->nX + pBtn->rtClip.w)))
	{
		if ((py >= pBtn->nY) && (py < (pBtn->nY + pBtn->rtClip.h)))
		{
			return true;
		}
	}
	return false;
}

bool IsOver(SDL_Rect * rc, int px, int py)
{
	if ((px >= rc->x) && (px < (rc->x + rc->w)))
	{
		if ((py >= rc->y) && (py < (rc->y + rc->h)))
		{
			return true;
		}
	}
	return false;
}

void Toggle(BUTTON* pBtn)
{
	if (pBtn->imgCurrent == pBtn->imgUp)
		pBtn->imgCurrent = pBtn->imgDown;
	else
		pBtn->imgCurrent = pBtn->imgUp;	
}

void ResetOnUp(BUTTON* pBtn)
{
	pBtn->imgCurrent = pBtn->imgUp;
}

void SetCoord(BUTTON* pBtn, int x, int y)
{
	pBtn->nX = x;
	pBtn->nY = y;
}

void SetVisible(BUTTON* pBtn, bool visible)
{
	pBtn->bIsVisible = visible;
}

bool IsVisible(BUTTON* pBtn)
{
	return pBtn->bIsVisible;
}

void MouseDown(BUTTON* pBtn, int px, int py)
{
	if (IsOver(pBtn, px, py) && IsVisible(pBtn))
	{
		ClickDown(pBtn);
	}
}

void MouseUp(CSystem* _cSystem,BUTTON* pBtn, int px, int py)
{
	if (!pBtn->type)
	{
	ResetOnUp(pBtn);
	}
	if (IsOver(pBtn, px, py) && IsVisible(pBtn))
	{
		ClickUp(_cSystem, pBtn);
	}
}