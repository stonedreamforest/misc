#include "stdafx.h"
#include "data.h"
data::data(void)
{
	 hstdin=GetStdHandle(STD_INPUT_HANDLE);
	 hout=GetStdHandle(STD_OUTPUT_HANDLE);
	 pos.X=30;
	 pos.Y=10;
	 memset(g_TankBullet,0,sizeof(TANK*)*160);
	 filePath="111.mapsb"; 
	 filePath1="222.mapsb"; 
	  
}
data::~data(void){}

int data::DoubleGame=0;//控制双人游戏静态变量
int data::TankQuantity=0;//敌方坦克数量
int data::EliteTankQuantity=0;//精英坦克数量
int data::EliteTankValue=0;	////精英坦克生命值
int data::flag=0;		//刷新一次
int data::LifeValue=0;//坦克1生命值
int data::LifeValue1=0;//坦克2生命值
int data::LifeNumber=0;//坦克1生命数
int data::LifeNumber1=0;//坦克2生命数
int data::num=0;//计分
int data::n_TransferMatrix=0;//传送阵


int data::MapFlag=0;

int data::ClickCount=0;

int data::SpaceStormflag=0;

int data::n_SkeletonKnight=0;//骸骨骑士

int data::TreatFlag=0;//是否吃饭

int data::MapFlag1=0;//是否存档

int data::AReward=0;//是否打赏

bool data::writeData(char * filePath)
{
	int result = 0;
	FILE *pFile;
	//DoubleGame
	if (0 == fopen_s(&pFile,filePath , "wb")){
		result = fwrite(&m_g_nMapData,	sizeof(int) * 40 * 55, 1, pFile);
		result = fwrite(&n_SkeletonKnight,	sizeof(int) , 1, pFile);
		result = fwrite(&DoubleGame,	sizeof(int) , 1, pFile);
		result = fwrite(&EliteTankQuantity,	sizeof(int) , 1, pFile);
		result = fwrite(&EliteTankValue,	sizeof(int) , 1, pFile);
		result = fwrite(&m_g_nMapData1,	sizeof(int)*40*55 , 1, pFile);
		//result = fwrite(&MapFlag,	sizeof(int) , 1, pFile);
		/*
		result = fwrite(&m_playTanks,		sizeof(m_playTanks) * 40 * 40, 1, pFile);
		result = fwrite(&m_playMissiles,	sizeof(m_playMissiles) * 40 * 40, 1, pFile);
		result = fwrite(&m_NPCTanks,		sizeof(m_NPCTanks) * 40 * 40, 1, pFile);
		result = fwrite(&m_NPCMissiles,		sizeof(m_NPCMissiles) * 40 * 40, 1, pFile);
		*/
		fclose(pFile);
		pFile = NULL;
	}

	return true;
}

bool data::readData(char * filePath)
{
	
	int result = 0;
	FILE *pFile;

	if (0 == fopen_s(&pFile, filePath, "rb")){		
		result = fread(&m_g_nMapData,	sizeof(int)*40*55, 1, pFile);	
		result = fread(&n_SkeletonKnight,	sizeof(int) , 1, pFile);
		result = fread(&DoubleGame,	sizeof(int) , 1, pFile);
		result = fread(&EliteTankQuantity,	sizeof(int) , 1, pFile);
		result = fread(&EliteTankValue,	sizeof(int) , 1, pFile);
		result = fread(&m_g_nMapData1,	sizeof(int)*40*55 , 1, pFile);
		//result = fread(&MapFlag,	sizeof(int) , 1, pFile);
		/*调试一下vector能不能直接这样存储
		result = fread(&m_playTanks,		sizeof(m_playTanks) * 40 * 40, 1, pFile); 
		result = fread(&m_playMissiles,		sizeof(m_playMissiles) * 40 * 40, 1, pFile);
		result = fread(&m_NPCTanks,			sizeof(m_NPCTanks) * 40 * 40, 1, pFile);
		result = fread(&m_NPCMissiles,		sizeof(m_NPCMissiles) * 40 * 40, 1, pFile);
		*/
		fclose(pFile);
		pFile = NULL;
	}
	return true;
}



wchar_t data::szStr[15][40]={ L"欢  迎  来  到  坦  克  大  战！",
	L"|1.单人游戏",L"|2.双人游戏",L"|4.读取自定义游戏",L"按1开始单人游戏 按2开始双人游戏 按3进入游戏设置 ESC退出任意界面",
	L"程序员在努力加班中...",L"一秒后开始游戏...",L"您的输入有误",
	L"游戏结束",L"W（上）A（左）S（下）D（右）移动  J:发射子弹",
	L"↑（上）←（左）↓（下）→（右）移动 .(小数点):发射子弹",
	L"字母按键p/P暂停游戏 字母按键o/O继续游戏",
	L"是否召唤深渊恶魔(Y)[抹掉这个肮脏的世界]  (N)[我要公平战斗]",
	L"|3.编辑地图",L"|5.读取存档"
};
int data::g_PlayerTankStyle[4][3][3] = 
{
	{
		{1,2,3},
		{4,5,6},
		{7,8,9},
	},
	{
		{1,2,3},
		{4,5,6},
		{7,8,9},

		},
		{
			{1,2,3},
			{4,5,6},
			{7,8,9},
		},
		{
			{1,2,3},
			{4,5,6},
			{7,8,9},
			}
};
int data::m_g_nMapData[40][55]={0};

int data::m_g_nMapData1[40][55]={0};

int data::g_nMapData[40][55]={
	WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,WALL_A,WALL_A,WALL_A,WALL_A,WALL_A,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,WALL_A,WALL_A,WALL_A,WALL_A,WALL_A,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,WALL_A,WALL_A,WALL_A,WALL_A,WALL_A,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,WALL_A,WALL_A,WALL_A,WALL_A,WALL_A,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,WALL_A,WALL_A,WALL_A,WALL_A,WALL_A,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,WALL_A,WALL_A,WALL_A,WALL_A,WALL_A,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_D,WALL_D,WALL_D,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_D,WALL_D,WALL_D,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_D,WALL_D,WALL_D,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_D,WALL_D,WALL_D,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_D,WALL_D,WALL_D,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_D,WALL_D,WALL_D,WALL_D,WALL_D,WALL_D,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_D,WALL_D,WALL_D,WALL_D,WALL_D,WALL_D,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_D,WALL_D,WALL_D,WALL_D,WALL_D,WALL_D,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_D,WALL_D,WALL_D,WALL_D,WALL_D,WALL_D,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,	   0,     0,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_D,WALL_D,WALL_D,WALL_D,WALL_D,WALL_D,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,     0,     0,     0,     0,     0,WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,     0,     0,WALL_F,     0,     0,WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,     0,WALL_F,WALL_F,WALL_F,     0,WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,     0,WALL_F,     0,WALL_F,     0,WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0
};
int data::g_nMapDataTemp[40][40]={0};