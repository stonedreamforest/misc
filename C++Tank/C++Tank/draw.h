#pragma once
#include "data.h"
class draw:public data
{
public:
	
	void ClrDrawStyle(TANK Tank);
	void DrawStyle(TANK Tank);
	void DrawMap();

	char GetKey();
	void SkeletonKnight();
	void GraphicsInterface();
	void ScoringSystem();
	void GameMenu();
	void DrawStyleID( TANK Tank);

	

	void ForestObstacle(TANK Tank);//森林障碍
	void SpaceStorm();//空间风暴
	void PropRefresh();//天降神器
	void Interface();
	void CustomMap();
public:
	void MouseClicks(MOUSE_EVENT_RECORD mou);//鼠标点击
	void KeyEventProc(KEY_EVENT_RECORD key);   //按键操作
	void TankCursor(int x,int y,char *pszChar,WORD wArr);
	void Treat(MOUSE_EVENT_RECORD mou);//吃饭
	void PrintInterface();
public:
	
	//INPUT_RECORD  stcRecord;
	int index;
	draw(void);
	~draw(void);
};


