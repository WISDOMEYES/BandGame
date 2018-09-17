#include"stdafx.h"

CSystem::CSystem(void)
{

}

CSystem::~CSystem(void)
{

}

bool CSystem::Initialize()
{
	CBaseWindow::Initialize();
	CTimeManager::Initialize();

	m_pGameFrame = new CFrameSkip;
	m_pGameFrame->SetFramePerSec(60);

	m_pInputManager = new CInputManager;
	m_pInputManager->SetInputHandler(this);

	//여기에 오브젝트 초기화 코드 삽입

	//scene iIit
	_rt = new SDL_Rect;
	currentNum = 0;

	strcat(_imgAdr[0], "startScene.bmp");
	strcat(_imgAdr[1], "mainScene.bmp");
	strcat(_imgAdr[2], "howTo.bmp");
	strcat(_imgAdr[3], "credit_1.bmp");
	strcat(_imgAdr[4], "credit_2.bmp");
	strcat(_imgAdr[5], "credit_3.bmp");

	strcat(_rainAdr[0], "rain_1.bmp");
	strcat(_rainAdr[1], "rain_2.bmp");
	strcat(_rainAdr[2], "rain_3.bmp");
	strcat(_rainAdr[3], "rain_4.bmp");

	strcat(_imgAdr[6], "Sp_1.bmp");
	strcat(_imgAdr[7], "Sp_2.bmp");
	strcat(_imgAdr[8], "Sp_3.bmp");
	strcat(_imgAdr[9], "Sp_4.bmp");

	_sceneSur = SDL_LoadBMP(_rainAdr[0]);
	colorkey = SDL_MapRGB(_sceneSur->format, 255, 0, 255);
	SDL_SetColorKey(_sceneSur, SDL_TRUE, colorkey);
	_rainTex = SDL_CreateTextureFromSurface(m_pRender, _sceneSur);

	changeScene(currentNum);

	_rt->x = _rt->y = 0;
	_rt->w = WIDTH;
	_rt->h = HEIGHT;

#pragma region				objRythm

	_Object[0] = new RythmBtn;
	strcat(_Object[0]->_checkAdr, "monsterCheck.bmp");
	_Object[0]->_btn = InitButton(m_pRender, _Object[0]->_checkAdr, _Object[0]->_checkAdr, _Object[0]->_checkAdr, 260, 415, true, m_Monster);

	strcat(_Object[0]->_imgAdr[0], "monster1.bmp");
	strcat(_Object[0]->_imgAdr[1], "monster2.bmp");
	strcat(_Object[0]->_imgAdr[2], "monster3.bmp");
	strcat(_Object[0]->_imgAdr[3], "monster4.bmp");
	strcat(_Object[0]->_imgAdr[4], "monster5.bmp");

	_Object[0]->_RectSize = new SDL_Rect;
	_Object[0]->_RectSize->x = 68;
	_Object[0]->_RectSize->y = 160;
	_Object[0]->_RectSize->w = 420;
	_Object[0]->_RectSize->h = 492;


	Bench = new SDL_Rect;

	Bench->x = 406;
	Bench->y = 425;
	Bench->w = 350;
	Bench->h = 205;

	_AniSur = SDL_LoadBMP("image\\button\\mainGame\\bench.bmp");
	colorkey = SDL_MapRGB(_AniSur->format, 255, 0, 255);
	SDL_SetColorKey(_AniSur, SDL_TRUE, colorkey);
	_benchTex = SDL_CreateTextureFromSurface(m_pRender, _AniSur);


	_Object[1] = new RythmBtn;
	strcat(_Object[1]->_checkAdr, "boyCheck.bmp");
	_Object[1]->_btn = InitButton(m_pRender, _Object[1]->_checkAdr, _Object[1]->_checkAdr, _Object[1]->_checkAdr, 766, 265, true, m_Boy);

	strcat(_Object[1]->_imgAdr[0], "boy1.bmp");
	strcat(_Object[1]->_imgAdr[1], "boy2.bmp");
	strcat(_Object[1]->_imgAdr[2], "boy3.bmp");
	strcat(_Object[1]->_imgAdr[3], "boy4.bmp");
	strcat(_Object[1]->_imgAdr[4], "boy5.bmp");

	_Object[1]->_RectSize = new SDL_Rect;
	_Object[1]->_RectSize->x = 661;
	_Object[1]->_RectSize->y = 153;
	_Object[1]->_RectSize->w = 217;
	_Object[1]->_RectSize->h = 486;



	_Object[2] = new RythmBtn;
	strcat(_Object[2]->_checkAdr, "birdCheck.bmp");
	_Object[2]->_btn = InitButton(m_pRender, _Object[2]->_checkAdr, _Object[2]->_checkAdr, _Object[2]->_checkAdr, 855, 570, true, m_Bird);

	strcat(_Object[2]->_imgAdr[0], "bird1.bmp");
	strcat(_Object[2]->_imgAdr[1], "bird2.bmp");
	strcat(_Object[2]->_imgAdr[2], "bird3.bmp");
	strcat(_Object[2]->_imgAdr[3], "bird4.bmp");
	strcat(_Object[2]->_imgAdr[4], "bird5.bmp");

	_Object[2]->_RectSize = new SDL_Rect;
	_Object[2]->_RectSize->x = 710;
	_Object[2]->_RectSize->y = 419;
	_Object[2]->_RectSize->w = 274;
	_Object[2]->_RectSize->h = 289;



	_Object[3] = new RythmBtn;
	strcat(_Object[3]->_checkAdr, "girlCheck.bmp");
	_Object[3]->_btn = InitButton(m_pRender, _Object[3]->_checkAdr, _Object[3]->_checkAdr, _Object[3]->_checkAdr, 539, 454, true, m_Girl);

	strcat(_Object[3]->_imgAdr[0], "girl1.bmp");
	strcat(_Object[3]->_imgAdr[1], "girl2.bmp");
	strcat(_Object[3]->_imgAdr[2], "girl3.bmp");
	strcat(_Object[3]->_imgAdr[3], "girl4.bmp");
	strcat(_Object[3]->_imgAdr[4], "girl5.bmp");

	_Object[3]->_RectSize = new SDL_Rect;
	_Object[3]->_RectSize->x = 365;
	_Object[3]->_RectSize->y = 294;
	_Object[3]->_RectSize->w = 309;
	_Object[3]->_RectSize->h = 355;



	_Object[4] = new RythmBtn;
	strcat(_Object[4]->_checkAdr, "speakerCheck.bmp");
	_Object[4]->_btn = InitButton(m_pRender, _Object[4]->_checkAdr, _Object[4]->_checkAdr, _Object[4]->_checkAdr, 691, 513, true, m_Speaker);

	strcat(_Object[4]->_imgAdr[0], "speaker1.bmp");
	strcat(_Object[4]->_imgAdr[1], "speaker2.bmp");
	strcat(_Object[4]->_imgAdr[2], "speaker3.bmp");
	strcat(_Object[4]->_imgAdr[3], "speaker4.bmp");
	strcat(_Object[4]->_imgAdr[4], "speaker5.bmp");

	_Object[4]->_RectSize = new SDL_Rect;
	_Object[4]->_RectSize->x = 627;
	_Object[4]->_RectSize->y = 448;
	_Object[4]->_RectSize->w = 123;
	_Object[4]->_RectSize->h = 119;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			_Object[i]->_AniSur = SDL_LoadBMP(_Object[i]->_imgAdr[j]);
			colorkey = SDL_MapRGB(_Object[i]->_AniSur->format, 255, 0, 255);
			SDL_SetColorKey(_Object[i]->_AniSur, SDL_TRUE, colorkey);
			_Object[i]->_AniTex[j] = SDL_CreateTextureFromSurface(m_pRender, _Object[i]->_AniSur);
		}
		_Object[i]->_CurrentTex = _Object[i]->_AniTex[0];
		_Object[i]->isPlaying = false;
		_Object[i]->index = 0;
		_Object[i]->checkInd = 0;
	}
	TickStack = 0;
	FPS = 0.0f;
	isPause = false;

#pragma endregion

#pragma region			button_Init
#pragma region			startScene

	strcpy(str[0], ADR_BTN_START);
	strcpy(str[1], ADR_BTN_START);
	strcpy(str[2], ADR_BTN_START);
	strcat(str[0], "enter_S_to_M_U.bmp");
	strcat(str[1], "enter_S_to_M_D.bmp");
	strcat(str[2], "enter_S_to_M_O.bmp");
	s_Start = InitButton(m_pRender, str[0], str[1], str[2], WIDTH - 160, HEIGHT / 2 - 70, false, s_Start_F);

	strcpy(str[0], ADR_BTN_START);
	strcpy(str[1], ADR_BTN_START);
	strcpy(str[2], ADR_BTN_START);
	strcat(str[0], "Exit_U.bmp");
	strcat(str[1], "Exit_D.bmp");
	strcat(str[2], "Exit_O.bmp");
	s_Exit = InitButton(m_pRender, str[0], str[1], str[2], WIDTH - 160, HEIGHT / 2 + 50, false, s_Exit_F);

	strcpy(str[0], ADR_BTN_START);
	strcpy(str[1], ADR_BTN_START);
	strcpy(str[2], ADR_BTN_START);
	strcat(str[0], "Howto_U.bmp");
	strcat(str[1], "Howto_D.bmp");
	strcat(str[2], "Howto_O.bmp");
	s_Howto = InitButton(m_pRender, str[0], str[1], str[2], WIDTH - 160, HEIGHT / 2 + 170, false, s_Howto_F);

	creditNum = 3;
	creditIndex = 0;
	strcpy(str[0], ADR_BTN_START);
	strcpy(str[1], ADR_BTN_START);
	strcpy(str[2], ADR_BTN_START);
	strcat(str[0], "Credit_U.bmp");
	strcat(str[1], "Credit_D.bmp");
	strcat(str[2], "Credit_O.bmp");
	s_Credit = InitButton(m_pRender, str[0], str[1], str[2], 560, HEIGHT / 2 - 80, false, s_Credit_F);

	strcpy(str[0], ADR_BTN_START);
	strcpy(str[1], ADR_BTN_START);
	strcpy(str[2], ADR_BTN_START);
	strcat(str[0], "ExitWin_U.bmp");
	strcat(str[1], "ExitWin_D.bmp");
	strcat(str[2], "ExitWin_O.bmp");
	s_ExitWin = InitButton(m_pRender, str[0], str[1], str[2], WIDTH - 70, 70, false, s_ExitWin_F);
#pragma endregion

#pragma region			mainScene

	strcpy(str[0], ADR_BTN_MAIN);
	strcpy(str[1], ADR_BTN_MAIN);
	strcpy(str[2], ADR_BTN_MAIN);
	strcat(str[0], "returnToS_U.bmp");
	strcat(str[1], "returnToS_D.bmp");
	strcat(str[2], "returnToS_O.bmp");
	m_Return = InitButton(m_pRender, str[0], str[1], str[2], 60, 50, false, m_Return_F);

	plusDelay = 0;
	rainIndex = 0;
	rainSwitch = false;
	strcpy(str[0], ADR_BTN_MAIN);
	strcpy(str[1], ADR_BTN_MAIN);
	strcpy(str[2], ADR_BTN_MAIN);
	strcat(str[0], "rain_U.bmp");
	strcat(str[1], "rain_D.bmp");
	strcat(str[2], "rain_O.bmp");
	m_Rain = InitButton(m_pRender, str[0], str[1], str[2], 150, 50, true, m_Rain_F);

	strcpy(str[0], ADR_BTN_MAIN);
	strcpy(str[1], ADR_BTN_MAIN);
	strcpy(str[2], ADR_BTN_MAIN);
	strcat(str[0], "play_U.bmp");
	strcat(str[1], "play_D.bmp");
	strcat(str[2], "play_O.bmp");
	m_Play = InitButton(m_pRender, str[0], str[1], str[2], 240, 50, true, m_Play_F);

	strcpy(str[0], ADR_BTN_MAIN);
	strcat(str[0], "SpecialBtn.bmp");
	m_Special = InitSButton(m_pRender, str[0],641, 148, m_Special_F,choice_F);

	strcpy(str[0], ADR_BTN_MAIN);
	strcat(str[0], "SpecialPill.bmp");
	m_Blue = InitSButton(m_pRender, str[0], 731, 82, m_Blue_F,choiceBlue_F);
	m_Red = InitSButton(m_pRender, str[0],  552, 82, m_Red_F,choiceRed_F);

	_Pillrt = new SDL_Rect;
	_Pillrt->x = 4;
	_Pillrt->y = -5;
	_Pillrt->h = 720;
	_Pillrt->w = 1280;

	pillVisible = false;
	IsPill = false;
	plusPill = 0;
	pillIndex = 7;


#pragma endregion

#pragma region			SongList

	NowPlaying = 0;
	IsPlaySong = false;
	SongNum = 0;

	strcpy(str[0], ADR_BTN_MAIN);
	strcpy(str[1], ADR_BTN_MAIN);
	strcpy(str[2], ADR_BTN_MAIN);
	strcat(str[0], "Song1_U.bmp");
	strcat(str[1], "Song1_D.bmp");
	strcat(str[2], "Song1_O.bmp");
	msc1 = InitButton(m_pRender, str[0], str[1], str[2], 1109, 368, true, m_Song1_F);

	strcpy(str[0], ADR_BTN_MAIN);
	strcpy(str[1], ADR_BTN_MAIN);
	strcpy(str[2], ADR_BTN_MAIN);
	strcat(str[0], "Song2_U.bmp");
	strcat(str[1], "Song2_D.bmp");
	strcat(str[2], "Song2_O.bmp");
	msc2 = InitButton(m_pRender, str[0], str[1], str[2], 1109, 435, true, m_Song2_F);

	strcpy(str[0], ADR_BTN_MAIN);
	strcpy(str[1], ADR_BTN_MAIN);
	strcpy(str[2], ADR_BTN_MAIN);
	strcat(str[0], "Song3_U.bmp");
	strcat(str[1], "Song3_D.bmp");
	strcat(str[2], "Song3_O.bmp");
	msc3 = InitButton(m_pRender, str[0], str[1], str[2], 1109, 502, true, m_Song3_F);

	strcpy(str[0], ADR_BTN_MAIN);
	strcpy(str[1], ADR_BTN_MAIN);
	strcpy(str[2], ADR_BTN_MAIN);
	strcat(str[0], "Song4_U.bmp");
	strcat(str[1], "Song4_D.bmp");
	strcat(str[2], "Song4_O.bmp");
	msc4 = InitButton(m_pRender, str[0], str[1], str[2], 1109, 569, true, m_Song4_F);

	strcpy(str[0], ADR_BTN_MAIN);
	strcpy(str[1], ADR_BTN_MAIN);
	strcpy(str[2], ADR_BTN_MAIN);
	strcat(str[0], "Song5_U.bmp");
	strcat(str[1], "Song5_D.bmp");
	strcat(str[2], "Song5_O.bmp");
	msc5 = InitButton(m_pRender, str[0], str[1], str[2], 1109, 636, true, m_Song5_F);

	playSong(0);
#pragma endregion

#pragma region			special_scene

	_Special[0] = new RythmBtn;
	strcat(_Special[0]->_imgAdr[0], "Song1_1.bmp");
	strcat(_Special[0]->_imgAdr[1], "Song1_2.bmp");
	strcat(_Special[0]->_imgAdr[2], "Song1_3.bmp");
	strcat(_Special[0]->_imgAdr[3], "Song1_4.bmp");
	strcat(_Special[0]->_imgAdr[4], "Song1_5.bmp");

	_Special[1] = new RythmBtn;
	strcat(_Special[1]->_imgAdr[0], "Song2_1.bmp");
	strcat(_Special[1]->_imgAdr[1], "Song2_2.bmp");
	strcat(_Special[1]->_imgAdr[2], "Song2_3.bmp");
	strcat(_Special[1]->_imgAdr[3], "Song2_4.bmp");
	strcat(_Special[1]->_imgAdr[4], "Song2_5.bmp");

	_Special[2] = new RythmBtn;
	strcat(_Special[2]->_imgAdr[0], "Song3_1.bmp");
	strcat(_Special[2]->_imgAdr[1], "Song3_2.bmp");
	strcat(_Special[2]->_imgAdr[2], "Song3_3.bmp");
	strcat(_Special[2]->_imgAdr[3], "Song3_4.bmp");
	strcat(_Special[2]->_imgAdr[4], "Song3_5.bmp");

	_Special[3] = new RythmBtn;
	strcat(_Special[3]->_imgAdr[0], "Song4_1.bmp");
	strcat(_Special[3]->_imgAdr[1], "Song4_2.bmp");
	strcat(_Special[3]->_imgAdr[2], "Song4_3.bmp");
	strcat(_Special[3]->_imgAdr[3], "Song4_4.bmp");
	strcat(_Special[3]->_imgAdr[4], "Song4_5.bmp");

	_Special[4] = new RythmBtn;
	strcat(_Special[4]->_imgAdr[0], "Ghost1.bmp");
	strcat(_Special[4]->_imgAdr[1], "Ghost2.bmp");
	strcat(_Special[4]->_imgAdr[2], "Ghost3.bmp");
	strcat(_Special[4]->_imgAdr[3], "Ghost4.bmp");
	strcat(_Special[4]->_imgAdr[4], "Ghost5.bmp");

	for (int i = 0; i < 5; i++)
	{
		strcat(_Special[i]->_checkAdr, "SongCheck.bmp");
		_Special[i]->_RectSize = new SDL_Rect;
		_Special[i]->_RectSize->w = 232;
		_Special[i]->_RectSize->h = 41;
		_Special[i]->_RectSize->x = 1019;

		for (int j = 0; j < 5; j++)
		{
			_Special[i]->_AniSur = SDL_LoadBMP(_Special[i]->_imgAdr[j]);
			colorkey = SDL_MapRGB(_Special[i]->_AniSur->format, 255, 0, 255);
			SDL_SetColorKey(_Special[i]->_AniSur, SDL_TRUE, colorkey);
			_Special[i]->_AniTex[j] = SDL_CreateTextureFromSurface(m_pRender, _Special[i]->_AniSur);
		}
		_Special[i]->_CurrentTex = _Special[i]->_AniTex[0];
		_Special[i]->isPlaying = false;
		_Special[i]->index = 0;
		_Special[i]->checkInd = 0;
	}
		
	strcat(_overAdr, "Song1_O.bmp");
	_Special[0]->_btn = InitButton(m_pRender, _Special[0]->_checkAdr, _Special[0]->_checkAdr, _overAdr, 1135, 274, true, Spmsc1);
	_Special[0]->_RectSize->y = 252;

	strcpy(_overAdr, ADR_BTN_ANIMATION);
	strcat(_overAdr, "Song2_O.bmp");
	_Special[1]->_btn = InitButton(m_pRender, _Special[1]->_checkAdr,  _Special[1]->_checkAdr, _overAdr, 1135, 315, true, Spmsc2);
	_Special[1]->_RectSize->y = 293;

	strcpy(_overAdr, ADR_BTN_ANIMATION);
	strcat(_overAdr, "Song3_O.bmp");
	_Special[2]->_btn = InitButton(m_pRender, _Special[2]->_checkAdr,  _Special[2]->_checkAdr, _overAdr, 1135, 356, true, Spmsc3);
	_Special[2]->_RectSize->y = 334;
	
	strcpy(_overAdr, ADR_BTN_ANIMATION);
	strcat(_overAdr, "Song4_O.bmp");
	_Special[3]->_btn = InitButton(m_pRender, _Special[3]->_checkAdr,  _Special[3]->_checkAdr, _overAdr, 1135, 397, true, Spmsc4);
	_Special[3]->_RectSize->y = 375;

	strcpy(_Special[4]->_checkAdr, ADR_BTN_ANIMATION);
	strcat(_Special[4]->_checkAdr, "GhostCheck.bmp");
	_Special[4]->_btn = InitButton(m_pRender, _Special[4]->_checkAdr, _Special[4]->_checkAdr, _Special[4]->_checkAdr, 609, 507, true, ghost);
	_Special[4]->_RectSize->w = 188;
	_Special[4]->_RectSize->h = 326;
	_Special[4]->_RectSize->x = 509;
	_Special[4]->_RectSize->y = 385;

	_sceneSur = SDL_LoadBMP("image\\scene\\SpecialChoice.bmp");
	colorkey = SDL_MapRGB(_sceneSur->format, 255, 0, 255);
	SDL_SetColorKey(_sceneSur, SDL_TRUE, colorkey);
	_pillTex[0] = SDL_CreateTextureFromSurface(m_pRender, _sceneSur);

	_sceneSur = SDL_LoadBMP("image\\scene\\Specialblue.bmp");
	colorkey = SDL_MapRGB(_sceneSur->format, 255, 0, 255);
	SDL_SetColorKey(_sceneSur, SDL_TRUE, colorkey);
	_pillTex[1] = SDL_CreateTextureFromSurface(m_pRender, _sceneSur);

	_sceneSur = SDL_LoadBMP("image\\scene\\SpecialRed.bmp");
	colorkey = SDL_MapRGB(_sceneSur->format, 255, 0, 255);
	SDL_SetColorKey(_sceneSur, SDL_TRUE, colorkey);
	_pillTex[2] = SDL_CreateTextureFromSurface(m_pRender, _sceneSur);

	_sceneSur = SDL_LoadBMP("image\\scene\\SpecialChoice2.bmp");
	colorkey = SDL_MapRGB(_sceneSur->format, 255, 0, 255);
	SDL_SetColorKey(_sceneSur, SDL_TRUE, colorkey);
	_pillTex[3] = SDL_CreateTextureFromSurface(m_pRender, _sceneSur);

	_currentPill = _pillTex[0];
	isReal = false;

	/*Post = SDL_LoadBMP("image\\button\\animation\\Boy.bmp");
	colorkey = SDL_MapRGB(_sceneSur->format, 255, 0, 255);
	SDL_SetColorKey(_sceneSur, SDL_TRUE, colorkey);
	Missing[0] = SDL_CreateTextureFromSurface(m_pRender, Post);

	MissRc[0] = new SDL_Rect;

	MissRc[0]->h = 139;
	MissRc[0]->w = 99;
	MissRc[0]->x = 100;
	MissRc[0]->y = 200;


	Post = SDL_LoadBMP("image\\button\\animation\\girl.bmp");
	colorkey = SDL_MapRGB(_sceneSur->format, 255, 0, 255);
	SDL_SetColorKey(_sceneSur, SDL_TRUE, colorkey);
	Missing[1] = SDL_CreateTextureFromSurface(m_pRender, Post);

	MissRc[1] = new SDL_Rect;
		   
	MissRc[1]->h = 139;
	MissRc[1]->w = 99;
	MissRc[1]->x = 300;
	MissRc[1]->y = 400;


	Post = SDL_LoadBMP("image\\button\\animation\\Monster.bmp");
	colorkey = SDL_MapRGB(_sceneSur->format, 255, 0, 255);
	SDL_SetColorKey(_sceneSur, SDL_TRUE, colorkey);
	Missing[2] = SDL_CreateTextureFromSurface(m_pRender, Post);

	MissRc[2] = new SDL_Rect;
		   
	MissRc[2]->h = 139;
	MissRc[2]->w = 99;
	MissRc[2]->x = 500;
	MissRc[2]->y = 600;*/




#pragma endregion

#pragma endregion

	return true;
}

void CSystem::Pulse()
{
	CTimeManager::Pulse();
	m_pInputManager->Pulse();

	float fTimeStep = CTimeManager::GetTimeStep();

	if (m_pGameFrame->Update(fTimeStep))
	{
		SDL_SetRenderDrawColor(m_pRender, MAX8, MAX8, MAX8, MAX8);
		SDL_RenderClear(m_pRender);
		//================================
		//여기에 오브젝트 프로세스 코드 삽입
		//================================

		//scene Draw
		SDL_RenderCopy(m_pRender, _sceneTex, NULL, _rt);
		if (currentNum >= 3&&currentNum<=5)
		{
			startCredit();
		}
		if (isReal)
		{
			startPill();
		}

		//button Draw
		if (FPS != 0 && !isPause) UpdateAni();

		switch (currentNum)
		{
		case 0:
			Draw(m_pRender, s_Start);
			Draw(m_pRender, s_Howto);
			Draw(m_pRender, s_Exit);
			Draw(m_pRender, s_Credit);
			break;
		case 1:
			Draw(m_pRender, m_Return);
			Draw(m_pRender, m_Rain);
			Draw(m_pRender, m_Play);

			Draw(m_pRender, msc1);
			Draw(m_pRender, msc2);
			Draw(m_pRender, msc3);
			Draw(m_pRender, msc4);
			Draw(m_pRender, msc5);

			Draw(m_pRender, _Object[0]->_btn);
			RenderAni(0);
			Draw(m_pRender, _Object[1]->_btn);
			RenderAni(1);
			Draw(m_pRender, _Object[2]->_btn);
			SDL_RenderCopy(m_pRender, _benchTex, NULL, Bench);
			RenderAni(2);
			Draw(m_pRender, _Object[3]->_btn);
			RenderAni(3);
			Draw(m_pRender, _Object[4]->_btn);
			RenderAni(4);

			Draw(m_pRender, m_Special);
			if (IsPill)
			{
			Draw(m_pRender, m_Blue);
			Draw(m_pRender, m_Red);
			}

			if (pillVisible) renderPill();

			break;
		case 2:
		case 3:
		case 4:
		case 5:
			Draw(m_pRender, s_ExitWin);
			break;
		case 6:
		case 7:
		case 8:
		case 9:
			Draw(m_pRender, _Special[0]->_btn);
			Draw(m_pRender, _Special[1]->_btn);
			Draw(m_pRender, _Special[2]->_btn);
			Draw(m_pRender, _Special[3]->_btn);
			Draw(m_pRender, _Special[4]->_btn);
			RenderAni(0);
			RenderAni(1);
			RenderAni(2);
			RenderAni(3);
			RenderAni(4);
			break;
		}

		if (rainSwitch)
		{
			startRain();
		}

		SDL_RenderPresent(m_pRender);
	}

}

void CSystem::Terminate()
{
	//여기에 오브젝트 종료/해제 코드 삽입

	m_pInputManager->Terminate();

	CBaseWindow::Terminate();
	CTimeManager::Terminate();

	Release(s_Start);
	Release(s_Howto);
	Release(s_Exit);
	Release(s_Credit);
	Release(m_Return);
	Release(m_Rain);
	Release(m_Play);
	Release(m_Special);
	Release(m_Blue);
	Release(m_Red);
	Release(msc1);
	Release(msc2);
	Release(msc3);
	Release(msc4);
	Release(msc5);
	for (int i = 0; i < 5; i++)
	{
		Release(_Object[i]->_btn);
	}

	exit(0);
}

void CSystem::Run()
{
	while (m_bIsGameRun)
	{
		Pulse(); //Update()
	}
}

#define g_pKeyCodeScan(vk) (m_pInputManager->GetOldKeyState(vk)&&m_pInputManager->GetCurKeyState(vk))

void CSystem::KeyboardHandler()
{
	if (g_pKeyCodeScan('A'));
}

void CSystem::MouseHandler(MOUSESTATE mouseState)
{
	if (mouseState.btn[M_Btn::LEFT] == true)
	{
		if (mouseState.type == SDL_MOUSEBUTTONDOWN)
		{
			switch (currentNum)
			{
			case 0:
				MouseDown(s_Start, mouseState.x, mouseState.y);
				MouseDown(s_Howto, mouseState.x, mouseState.y);
				MouseDown(s_Exit, mouseState.x, mouseState.y);
				MouseDown(s_Credit, mouseState.x, mouseState.y);
				break;
			case 1:
				MouseDown(m_Return, mouseState.x, mouseState.y);
				MouseDown(m_Rain, mouseState.x, mouseState.y);
				MouseDown(m_Play, mouseState.x, mouseState.y);

				MouseDown(msc1, mouseState.x, mouseState.y);
				MouseDown(msc2, mouseState.x, mouseState.y);
				MouseDown(msc3, mouseState.x, mouseState.y);
				MouseDown(msc4, mouseState.x, mouseState.y);
				MouseDown(msc5, mouseState.x, mouseState.y);

				for (int i = 0; i < 5; i++)
				{
					MouseDown(_Object[i]->_btn, mouseState.x, mouseState.y);
				}

				MouseDown(m_Special, mouseState.x, mouseState.y);
				if (IsPill)
				{
					MouseDown(m_Blue, mouseState.x, mouseState.y);
					MouseDown(m_Red, mouseState.x, mouseState.y);
				}

				break;
			case 2:
			case 3:
			case 4:
			case 5:
				MouseDown(s_ExitWin, mouseState.x, mouseState.y);
				break;
			case 6:
			case 7:
			case 8:
			case 9:
				for (int i = 0; i < 5; i++)
				{
				MouseDown(_Special[i]->_btn,  mouseState.x, mouseState.y);
				}
				break;
			}
		}
		else if (mouseState.type == SDL_MOUSEBUTTONUP)
		{
			switch (currentNum)
			{
			case 0:
				MouseUp(this, s_Start, mouseState.x, mouseState.y);
				MouseUp(this, s_Howto, mouseState.x, mouseState.y);
				MouseUp(this, s_Exit, mouseState.x, mouseState.y);
				MouseUp(this, s_Credit, mouseState.x, mouseState.y);
				break;
			case 1:
				MouseUp(this, m_Return, mouseState.x, mouseState.y);
				MouseUp(this, m_Rain, mouseState.x, mouseState.y);
				MouseUp(this, m_Play, mouseState.x, mouseState.y);

				MouseUp(this, msc1, mouseState.x, mouseState.y);
				MouseUp(this, msc2, mouseState.x, mouseState.y);
				MouseUp(this, msc3, mouseState.x, mouseState.y);
				MouseUp(this, msc4, mouseState.x, mouseState.y);
				MouseUp(this, msc5, mouseState.x, mouseState.y);

				for (int i = 0; i < 5; i++)
				{
					MouseUp(this, _Object[i]->_btn, mouseState.x, mouseState.y);
				}

				MouseUp(this, m_Special, mouseState.x, mouseState.y);
				if (IsPill)
				{
					MouseUp(this, m_Blue, mouseState.x, mouseState.y);
					MouseUp(this, m_Red, mouseState.x, mouseState.y);
				}
				break;
			case 2:
			case 3:
			case 4:
			case 5:
				MouseUp(this, s_ExitWin, mouseState.x, mouseState.y);
				break;
			case 6:
			case 7:
			case 8:
			case 9:
				for (int i = 0; i < 5; i++)
				{
					MouseUp(this,_Special[i]->_btn, mouseState.x, mouseState.y);
				}
				break;
			}
		}
	}
	if (mouseState.btn[M_Btn::RIGHT] == true)
	{

	}
	switch (currentNum)
	{
	case 0:
		OverClick(this,s_Start, mouseState.x, mouseState.y);
		OverClick(this,s_Howto, mouseState.x, mouseState.y);
		OverClick(this,s_Exit, mouseState.x, mouseState.y);
		OverClick(this,s_Credit, mouseState.x, mouseState.y);
		break;
	case 1:
		OverClick(this,m_Return, mouseState.x, mouseState.y);
		OverClick(this,m_Rain, mouseState.x, mouseState.y);
		OverClick(this,m_Play, mouseState.x, mouseState.y);

		OverClick(this,msc1, mouseState.x, mouseState.y);
		OverClick(this,msc2, mouseState.x, mouseState.y);
		OverClick(this,msc3, mouseState.x, mouseState.y);
		OverClick(this,msc4, mouseState.x, mouseState.y);
		OverClick(this,msc5, mouseState.x, mouseState.y);

		for (int i = 0; i < 5; i++)
		{
			OverClick(this, _Object[i]->_btn, mouseState.x, mouseState.y);
		}

		if (!IsPill) {
			OverClick(this, m_Special, mouseState.x, mouseState.y);
			if (!IsOver(m_Special, mouseState.x, mouseState.y) && !IsPill) pillVisible = false;
		}
		if (IsPill)
		{
			OverClick(this, m_Blue, mouseState.x, mouseState.y);
			OverClick(this, m_Red, mouseState.x, mouseState.y);
		}
		break;
	case 2:
	case 3:
	case 4:
	case 5:
		OverClick(this,s_ExitWin, mouseState.x, mouseState.y);
		break;
	case 6:
	case 7:
	case 8:
	case 9:
		for (int i = 0; i < 5; i++)
		{
			OverClick(this, _Special[i]->_btn, mouseState.x, mouseState.y);
		}
		break;
	}
}

void CSystem::changeScene(int sceneNum)
{
	currentNum = sceneNum;
	_sceneSur = SDL_LoadBMP(_imgAdr[sceneNum]);
	_sceneTex = SDL_CreateTextureFromSurface(m_pRender, _sceneSur);
}

void CSystem::choice(int num)
{
	_currentPill = _pillTex[num];
	if (num == 3)
	{
		IsPill = true;
	}
	pillVisible = true;
}

void CSystem::isblue()
{
	IsPill = false;
}

void CSystem::isRed()
{
	changeScene(6);
	isReal = true;
	FPS = 0;
	TickStack = 0;
}

void CSystem::startPill()
{
	plusPill++;
	if (plusPill == 60)
	{
		currentNum = pillIndex;
		_sceneSur = SDL_LoadBMP(_imgAdr[pillIndex]);
		if (pillIndex == 9) pillIndex = 5;
		pillIndex++;
		_sceneTex = SDL_CreateTextureFromSurface(m_pRender, _sceneSur);
		plusPill = 0;
	}
}

void CSystem::startRain()
{

	plusDelay++;
	if (plusDelay == 30)
	{
		_sceneSur = SDL_LoadBMP(_rainAdr[rainIndex]);
		if (rainIndex == 3) rainIndex = -1;
		colorkey = SDL_MapRGB(_sceneSur->format, 255, 0, 255);
		SDL_SetColorKey(_sceneSur, SDL_TRUE, colorkey);
		rainIndex++;
		_rainTex = SDL_CreateTextureFromSurface(m_pRender, _sceneSur);
		plusDelay = 0;
	}

	SDL_RenderCopy(m_pRender, _rainTex, NULL, _rt);
}

void CSystem::startCredit()
{
	creditIndex++;
	if (creditIndex == 30)
	{
		currentNum = creditNum;
		_sceneSur = SDL_LoadBMP(_imgAdr[creditNum]);
		if (creditNum == 5) creditNum = 2;
		creditNum++;
		_sceneTex = SDL_CreateTextureFromSurface(m_pRender, _sceneSur);
		creditIndex = 0;
	}
}

void CSystem::playSong(int num)
{
	wchar_t strTemp[128];
	NowPlaying = num;
	switch (num)
	{
	case 0:
		wsprintf(strTemp, L"play sound/비1.mp3");
		break;
	case 1:
		wsprintf(strTemp, L"play sound/Song1.mp3");
		FPS = 30;
		break;
	case 2:
		wsprintf(strTemp, L"play sound/Song2.mp3");
		FPS = 40;
		break;
	case 3:
		wsprintf(strTemp, L"play sound/Song3.mp3");
		FPS = 37;
		break;
	case 4:
		wsprintf(strTemp, L"play sound/Song4.mp3");
		FPS = 35;
		break;
	case 5:
		wsprintf(strTemp, L"play sound/Song5.mp3");
		FPS = 60;
		break;
	case 6:
		wsprintf(strTemp, L"play sound/SP1.mp3");
		FPS = 30;
		PillReset(0);
		break;
	case 7:
		wsprintf(strTemp, L"play sound/SP2.mp3");
		FPS = 30;
		PillReset(1);
		break;
	case 8:
		wsprintf(strTemp, L"play sound/SP3.mp3");
		FPS = 30;
		PillReset(2);
		break;
	case 9:
		wsprintf(strTemp, L"play sound/SP4.mp3");
		FPS = 30;
		PillReset(3);
		break;
	}
	isPause = false;
	IsPlaySong = true;
	mciSendString(strTemp, NULL, 0, NULL);
}
void CSystem::stopSong()
{
	wchar_t strTemp[128];
	switch (NowPlaying)
	{
	case 0:
		wsprintf(strTemp, L"stop sound/비1.mp3");
		break;
	case 1:
		wsprintf(strTemp, L"stop sound/Song1.mp3");
		Reset(msc1);
		break;
	case 2:
		wsprintf(strTemp, L"stop sound/Song2.mp3");
		Reset(msc2);
		break;
	case 3:
		wsprintf(strTemp, L"stop sound/Song3.mp3");
		Reset(msc3);
		break;
	case 4:
		wsprintf(strTemp, L"stop sound/Song4.mp3");
		Reset(msc4);
		break;
	case 5:
		wsprintf(strTemp, L"stop sound/Song5.mp3");
		Reset(msc5);
		break;
	case 6:
		wsprintf(strTemp, L"stop sound/SP1.mp3");
		Reset(_Special[0]->_btn);
		break;
	case 7:
		wsprintf(strTemp, L"stop sound/SP2.mp3");
		Reset(_Special[1]->_btn);
		break;
	case 8:
		wsprintf(strTemp, L"stop sound/SP3.mp3");
		Reset(_Special[2]->_btn);
		break;
	case 9:
		wsprintf(strTemp, L"stop sound/SP4.mp3");
		Reset(_Special[3]->_btn);
		break;
	}
	IsPlaySong = false;
	Reset(m_Play);
	for (int i = 0; i < 5; i++)
	{
		_Object[i]->_CurrentTex = _Object[i]->_AniTex[0];
	}
	FPS = 0;
	TickStack = 0;
	mciSendString(strTemp, NULL, 0, NULL);
}
void CSystem::pauseSong()
{
	wchar_t strTemp[128];
	switch (NowPlaying)
	{
	case 1:
		wsprintf(strTemp, L"pause sound/Song1.mp3");
		break;
	case 2:
		wsprintf(strTemp, L"pause sound/Song2.mp3");
		break;
	case 3:
		wsprintf(strTemp, L"pause sound/Song3.mp3");
		break;
	case 4:
		wsprintf(strTemp, L"pause sound/Song4.mp3");
		break;
	case 5:
		wsprintf(strTemp, L"pause sound/Song5.mp3");
		break;
	case 6:
		wsprintf(strTemp, L"pause sound/SP1.mp3");
		break;
	case 7:
		wsprintf(strTemp, L"pause sound/SP2.mp3");
		break;
	case 8:
		wsprintf(strTemp, L"pause sound/SP3.mp3");
		break;
	case 9:
		wsprintf(strTemp, L"pause sound/SP4.mp3");
		break;
	}
	isPause = true;
	IsPlaySong = false;
	mciSendString(strTemp, NULL, 0, NULL);
}
void CSystem::restartSong()
{
	wchar_t strTemp[128];
	switch (NowPlaying)
	{
	case 1:
		wsprintf(strTemp, L"play sound/Song1.mp3");
		break;
	case 2:
		wsprintf(strTemp, L"play sound/Song2.mp3");
		break;
	case 3:
		wsprintf(strTemp, L"play sound/Song3.mp3");
		break;
	case 4:
		wsprintf(strTemp, L"play sound/Song4.mp3");
		break;
	case 5:
		wsprintf(strTemp, L"play sound/Song5.mp3");
		break;
	case 6:
		wsprintf(strTemp, L"play sound/SP1.mp3");
		break;
	case 7:
		wsprintf(strTemp, L"play sound/SP2.mp3");
		break;
	case 8:
		wsprintf(strTemp, L"play sound/SP3.mp3");
		break;
	case 9:
		wsprintf(strTemp, L"play sound/SP4.mp3");
		break;
	}
	isPause = false;
	IsPlaySong = true;
	mciSendString(strTemp, NULL, 0, NULL);
}
void CSystem::rainBTn(bool PorS)
{
	wchar_t strTemp[128];
	if (PorS) wsprintf(strTemp, L"play sound/비2.mp3");
	else wsprintf(strTemp, L"stop sound/비2.mp3");
	mciSendString(strTemp, NULL, 0, NULL);
}

void CSystem::restartGame()
{
	Reset(m_Return);
	Reset(m_Rain);
	Reset(m_Play);

	Reset(msc1);
	Reset(msc2);
	Reset(msc3);
	Reset(msc4);
	Reset(msc5);
}

void CSystem::AniSwich(int AniNum)
{
	if (IsPlaySong)
	{
		if (!isReal)
		{
			if (!_Object[AniNum]->isPlaying)
			{
				_Object[AniNum]->isPlaying = true;
			}
			else
			{
				_Object[AniNum]->isPlaying = false;
			}
		}
		else
		{
			if (!_Special[AniNum]->isPlaying)
			{
				_Special[AniNum]->isPlaying = true;
			}
			else
			{
				_Special[AniNum]->isPlaying = false;
			}
		}
	}
}

void CSystem::UpdateAni()
{
	if (TickStack >= FPS)
	{
		for (int i = 0; i < 5; i++)
		{
			if (!isReal)
			{
				if (_Object[i]->isPlaying)
				{
					if (_Object[i]->checkInd < 4)
					{
						_Object[i]->index++;
					}
					else if (_Object[i]->checkInd >= 4)
					{
						_Object[i]->index--;
					}
					_Object[i]->checkInd++;
					if (_Object[i]->checkInd == 8) _Object[i]->checkInd = 0;
				}
				else
				{
					_Object[i]->index = 0;
					_Object[i]->checkInd = 0;
				}
				_Object[i]->_CurrentTex = _Object[i]->_AniTex[_Object[i]->index];
			}
			else
			{
				if (_Special[i]->isPlaying)
				{
					if (_Special[i]->checkInd < 4)
					{
						_Special[i]->index++;
					}
					else if (_Special[i]->checkInd >= 4)
					{
						_Special[i]->index--;
					}
					_Special[i]->checkInd++;
					if (_Special[i]->checkInd == 8) _Special[i]->checkInd = 0;
				}
				else
				{
					_Special[i]->index = 0;
					_Special[i]->checkInd = 0;
				}
				_Special[i]->_CurrentTex = _Special[i]->_AniTex[_Special[i]->index];
			}
		}
		TickStack = 0;
	}
	TickStack++;
}

void CSystem::RenderAni(int num)
{
	if (!isReal)
	{
	SDL_RenderCopy(m_pRender, _Object[num]->_CurrentTex, NULL, _Object[num]->_RectSize);
	}
	else
	{
		SDL_RenderCopy(m_pRender, _Special[num]->_CurrentTex, NULL, _Special[num]->_RectSize);
	}
}

void CSystem::PillReset(int num)
{
	for (int i = 0; i < 4; i++)
	{
		if (num != i)
		{
			_Special[i]->_CurrentTex = _Special[i]->_AniTex[0];
			_Special[i]->isPlaying = false;
		}
	}
}
/*
void CSystem::MissingPost()
{
	for (int i = 0; i < 3; i++)
	{

	}

}*/

int s_Start_F()
{
	return S_START;
}
int s_Howto_F()
{
	return S_HOWTO;
}
int s_Exit_F()
{
	return S_EXIT;
}
int s_Credit_F()
{
	return S_CREDIT;
}
int s_ExitWin_F()
{
	return S_EXITWIN;
}

int m_Return_F()
{
	return M_RETURN;
}
int m_Rain_F()
{
	return M_RAIN;
}
int m_Play_F()
{
	return M_PLAY;
}

int m_Special_F()
{
	return M_SPECIAL;
}

int m_Blue_F()
{
	return M_BLUE;
}

int m_Red_F()
{
	return M_RED;
}

int m_Song1_F()
{
	return M_MSC1;
}
int m_Song2_F()
{
	return M_MSC2;
}
int m_Song3_F()
{
	return M_MSC3;
}
int m_Song4_F()
{
	return M_MSC4;
}
int m_Song5_F()
{
	return M_MSC5;
}

int m_Monster()
{
	return M_MONSTER;
}
int m_Bird()
{
	return M_BIRD;
}
int m_Boy()
{
	return M_BOY;
}
int m_Girl()
{
	return M_GIRL;
}
int m_Speaker()
{
	return M_SPEAKER;
}

int Spmsc1()
{
	return SP_1;
}

int Spmsc2()
{
	return SP_2;
}

int Spmsc3()
{
	return SP_3;
}

int Spmsc4()
{
	return SP_4;
}

int ghost()
{
	return SP_G;
}

int choice_F()
{
	return 0;
}

int choiceBlue_F()
{
	return 1;
}

int choiceRed_F()
{
	return 2;
}
