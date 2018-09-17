#pragma once
#include <iostream>
#include <math.h>
#include <assert.h>

#define WIDTH	1280		//������ ũ�� �� �ʺ�
#define HEIGHT	720		//������ ũ�� �� ����

#define ADR_SCENE "image\\scene\\"	//�̹��� �� �⺻��ġ
#define ADR_BTN_START "image\\button\\startScene\\"	//�̹��� ��ư �⺻��ġ
#define ADR_BTN_MAIN "image\\button\\mainGame\\"
#define ADR_BTN_SPECIAL "image\\button\\specialScene\\"
#define ADR_BTN_ANIMATION "image\\button\\animation\\"
#define ADR_MSC "sound\\"

const float   PI = 3.14159f;

#define MIN8		0x00		//8Bit�� ������ //16���� 0x00 //10���� 0
#define MAX8		0xff		//8Bit�� �ְ� //16���� 0xff, 0xFF //10���� 255

#define S_START		 0
#define S_HOWTO		 1
#define S_HOWTOCLOSE 2
#define S_EXIT		 3
#define S_CREDIT	 4
#define S_EXITWIN	 5
#define M_RETURN	 6
#define M_RAIN		 7

#define M_SPECIAL	 8
#define M_BLUE		 9
#define M_RED		 10

#define M_PLAY		 11
#define M_MSC1		 12
#define M_MSC2		 13
#define M_MSC3		 14
#define M_MSC4		 15
#define M_MSC5		 16

#define M_MONSTER	 17
#define M_BOY		 18
#define M_BIRD		 19
#define M_GIRL		 20
#define M_SPEAKER	 21

#define SP_1		 22
#define SP_2		 23
#define SP_3		 24
#define SP_4		 25
#define SP_G		 26
