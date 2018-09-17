#pragma once
#include"stdafx.h"

struct S_BUTTON;

struct RythmBtn
{
	BUTTON* _btn;
	char _checkAdr[256]{ ADR_BTN_ANIMATION };
	char _imgAdr[5][256]{ ADR_BTN_ANIMATION ,ADR_BTN_ANIMATION ,ADR_BTN_ANIMATION ,ADR_BTN_ANIMATION ,ADR_BTN_ANIMATION };
	bool isPlaying;
	
	SDL_Rect* _RectSize;
	SDL_Texture* _AniTex[5];
	SDL_Texture* _CurrentTex;
	int index;
	int checkInd;
	SDL_Surface* _AniSur;
};

class CSystem : public CBaseWindow,
			   public CTimeManager,
			   public IInputHandler
{	
private:
	enum DrawingState{ POINTS = 0, LINES, BOXES, END };
	int m_nIsDrawingState = POINTS;

private:
	CFrameSkip*		m_pGameFrame;
	CInputManager*	m_pInputManager;

	//scene
	SDL_Surface* _sceneSur;

	SDL_Texture* _sceneTex;
	SDL_Rect* _rt;
	int currentNum;

	//button

	char str[3][256];

	int SongNum;

	//startGame
	BUTTON* s_Start;
	
	BUTTON* s_Howto;

	BUTTON* s_Exit;

	BUTTON* s_Credit;
	int creditNum;
	int creditIndex;

	BUTTON* s_ExitWin;

	//mainGame
	BUTTON* m_Return;

	BUTTON* m_Rain;

	SDL_Texture* _rainTex;

	int plusDelay;
	int rainIndex;

	BUTTON* m_Play;

	SDL_Surface* _AniSur;

	SDL_Texture* _benchTex;
	SDL_Rect* Bench;

	RythmBtn* _Object[5];
	int TickStack;
	float FPS;
	bool isPause;

	Uint32 colorkey;

	SDL_Texture* _pillTex[4];
	SDL_Texture* _currentPill;
	SDL_Rect* _Pillrt;
	int pillIndex;
	int plusPill;

	BUTTON* m_Special;

	BUTTON* m_Red;
	BUTTON* m_Blue;
	bool IsPill;

	bool pillVisible;


	//Song
	BUTTON* msc1;
	BUTTON* msc2;
	BUTTON* msc3;
	BUTTON* msc4;
	BUTTON* msc5;
	int NowPlaying;
	
	//Special
	bool isReal;
	BUTTON* MissingBtn;

	RythmBtn* _Special[5];
	char _overAdr[256]{ ADR_BTN_ANIMATION };

	/*SDL_Surface* Post;
	SDL_Texture* Missing[3];
	SDL_Rect* MissRc[3];*/
	
	char _imgAdr[10][256] = { ADR_SCENE,ADR_SCENE,ADR_SCENE,ADR_SCENE,ADR_SCENE,ADR_SCENE,ADR_SCENE,ADR_SCENE,ADR_SCENE,ADR_SCENE};
	char _rainAdr[4][256] = { ADR_SCENE,ADR_SCENE,ADR_SCENE,ADR_SCENE };

public:
	CSystem(void);
	~CSystem(void);

private:
	void Pulse();

public:
	bool Initialize();

	void Terminate();

	void Run();

	void changeScene(int sceneNum);

	void choice(int num);
	void renderPill() { SDL_RenderCopy(m_pRender, _currentPill, NULL, _Pillrt); }
	void isblue();
	void isRed();
	void startPill();

	bool rainSwitch;
	void startRain();
	void startCredit();

	void playSong(int num);
	void stopSong();
	void pauseSong();
	void restartSong();
	void rainBTn(bool PorS);
	bool IsPlaySong;

	void restartGame();

	void AniSwich(int AniNum);
	void UpdateAni();
	void RenderAni(int num);
	void PillReset(int num);

	void MissingPost();

public:
	void KeyboardHandler();
	void MouseHandler(MOUSESTATE mouseState);
};

//start
int s_Start_F();
int s_Howto_F();
int s_Exit_F();
int s_Credit_F();
int s_ExitWin_F();
//main
int m_Return_F();
int m_Rain_F();
int m_Play_F();

int m_Special_F();
int m_Blue_F();
int m_Red_F();
//Song
int m_Song1_F();
int m_Song2_F();
int m_Song3_F();
int m_Song4_F();
int m_Song5_F();

//Animation
int m_Monster();
int m_Boy();
int m_Bird();
int m_Girl();
int m_Speaker();

//special
int Spmsc1();
int Spmsc2();
int Spmsc3();
int Spmsc4();
int ghost();

int choice_F();
int choiceBlue_F();
int choiceRed_F();