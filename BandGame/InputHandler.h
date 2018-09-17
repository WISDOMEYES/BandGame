#pragma once

enum M_Btn { LEFT, RIGHT, MIDDLE };//마우스 입력 이넘(밖으로 빼도 됨)
typedef struct _MOUSESTATE
{
	int x, y;						  //마우스 위치
	BYTE btn[4];					  //마우스 버튼 매열(오른,왼,휠)
	UINT32 type;					  //마우스의 상태 받아오기

}MOUSESTATE;


class IInputHandler
{
public:
	IInputHandler()
	{
	}

	virtual ~IInputHandler()
	{
	}

public:
	virtual void KeyboardHandler(void) = 0;
	virtual void MouseHandler(MOUSESTATE mouseState) = 0;
};


