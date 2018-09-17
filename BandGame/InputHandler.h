#pragma once

enum M_Btn { LEFT, RIGHT, MIDDLE };//���콺 �Է� �̳�(������ ���� ��)
typedef struct _MOUSESTATE
{
	int x, y;						  //���콺 ��ġ
	BYTE btn[4];					  //���콺 ��ư �ſ�(����,��,��)
	UINT32 type;					  //���콺�� ���� �޾ƿ���

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


