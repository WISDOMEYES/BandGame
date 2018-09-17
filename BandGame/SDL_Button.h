#pragma once
#include"stdafx.h"

class CSystem;

typedef struct S_BUTTON
{
	enum eButtonState { BUTTONDOWN, BUTTONUP };

	SDL_Texture* imgUp;
	SDL_Texture* imgOv;
	SDL_Texture* imgDown;
	SDL_Texture* imgCurrent;

	SDL_Rect rtClip;

	int nX, nY;
	int imgW, imgH;

	//false -basic, true -switch
	bool type;

	bool typeSwitch = false;

	bool bIsVisible = true;
	bool overClick = false;

	int(*func)();
	int(*sp)();

}BUTTON;

BUTTON* InitButton(SDL_Renderer* screen, const char* szUp, const char* szDown, const char* szOver, int x, int y, bool type,int(*f)());//�̴�
BUTTON* InitSButton(SDL_Renderer* screen, const char* szUp,int x, int y, int(*f)(),int(*s)());//�̴�
void Release(BUTTON* pBtn);//�޸� ����
void Draw(SDL_Renderer* screen, BUTTON* pBtn);//��� ��ư�� �׸� ���̳�

void setBPos(BUTTON* pbtn);

BUTTON::eButtonState GetState(BUTTON* pBtn);//��ư�� ���¸� �˾ƿ���
void OverClick(CSystem* _cSystem,BUTTON* pBtn, int px, int py);
void ClickDown(BUTTON* pBtn);
void ClickUp(CSystem* _cSystem, BUTTON* pBtn);

bool IsOver(BUTTON* pBtn, int px, int py);//���콺�� ���� �ֳ�
bool IsOver(SDL_Rect* rc, int px, int py);//���콺�� ���� �ֳ�
void Toggle(BUTTON* pBtn);//���� �ݴ�� �ٲٱ�
void ResetOnUp(BUTTON* pBtn);//��� ������ ����
void SetCoord(BUTTON* btn, int x, int y);
void SetVisible(BUTTON* btn, bool visible);
bool IsVisible(BUTTON* btn);

void MouseDown(BUTTON* pBtn, int px, int py);
void MouseUp(CSystem* _cSystem,BUTTON* pBtn, int px, int py);

void Reset(BUTTON* pBtn);