#include "stdafx.h"
#include "draw.h"


draw::draw(void)
{
}


draw::~draw(void)
{
}

//按键
char draw::GetKey()
{
	char ch;
	if(_kbhit())
	{
		ch=_getch();	
	}
	else
	{
		return 0;
	}
	return ch;
}
//召唤恶魔
void draw::SkeletonKnight()
{

	while (1)
	{
		char ch;
		if( !(ch = GetKey())){
			continue;
		}		
		if(ch==27)
		{
			exit(0);
		}			
		switch (ch)
		{
		case 'Y':
		case 'y':			
			n_SkeletonKnight=100;
			EliteTankQuantity=3;
			EliteTankValue=10000;	
			return;

		case 'N':
		case 'n':
			return;
		}		
	}
}
//坦克或子弹的中心坐标TankCursor
void draw::TankCursor(int x,int y,char *pszChar,WORD wArr)
{
	CONSOLE_CURSOR_INFO Cui={1,FALSE};
	HANDLE hout;
	COORD coord;
		hout=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(hout,&Cui);//取消光标
	coord.X=2*x;
	coord.Y=y;

	SetConsoleTextAttribute(hout,wArr);
	SetConsoleCursorPosition(hout,coord);//光标位置
	printf(pszChar);
	//WriteConsoleInputA()
	//WriteConsoleOutputCharacter
}
//吃饭
void draw::Treat(MOUSE_EVENT_RECORD mou)
{
	int row=mou.dwMousePosition.Y;//行
	int col=(mou.dwMousePosition.X)/2;//列
	switch(mou.dwEventFlags)
	{
	case 0:
		if (mou.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED&&
			row>=1&&row<3&&col>=42&&col<47//博客
			)
		{
			TreatFlag++;
			system("StoneDreamForest.htm");
			
		}
		if (mou.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED&&
			row>=1&&row<3&&col>=47&&col<52//打赏
			)
		{
			TreatFlag++;
			system("mm_facetoface_collect_qrcode_144645.png");

		}
	/*TankCursor(49,36,"■■■■■■",F_YELLOW);
		TankCursor(49,37,"■点击打赏■",F_YELLOW);
		TankCursor(49,38,"■■■■■■",F_YELLOW);*/
	}
}
//打印界面
void draw::PrintInterface()
{
	pos.X=42;//42 6
	pos.Y=6;
	WriteConsoleOutputCharacter(hout,szStr[0],40,pos,&dwRet); //在指定位置打印相应字符串

	pos.X=50;
	pos.Y=12;
	WriteConsoleOutputCharacter(hout,szStr[1],40,pos,&dwRet); 

	pos.X=50;
	pos.Y=15;
	WriteConsoleOutputCharacter(hout,szStr[2],40,pos,&dwRet); 

	pos.X=50;
	pos.Y=18;
	WriteConsoleOutputCharacter(hout,szStr[13],40,pos,&dwRet); 

	pos.X=50;
	pos.Y=21;
	WriteConsoleOutputCharacter(hout,szStr[3],40,pos,&dwRet); 

	pos.X=50;
	pos.Y=24;
	WriteConsoleOutputCharacter(hout,szStr[14],40,pos,&dwRet);

	pos.X=30;
	pos.Y=29;
	WriteConsoleOutputCharacter(hout,szStr[4],40,pos,&dwRet); 

	pos.X=37;
	pos.Y=32;
	WriteConsoleOutputCharacter(hout,szStr[9],40,pos,&dwRet); 

	pos.X=31;
	pos.Y=35;
	WriteConsoleOutputCharacter(hout,szStr[10],40,pos,&dwRet); 

	pos.X=36;
	pos.Y=38;
	WriteConsoleOutputCharacter(hout,szStr[11],40,pos,&dwRet); 

	pos.X=84;
	pos.Y=1;
	WriteConsoleOutputCharacter(hout,L"【博客】",4,pos,&dwRet); 
	pos.X=94;
	pos.Y=1;
	WriteConsoleOutputCharacter(hout,L"【打赏】",4,pos,&dwRet); 

	pos.X=75;
	pos.Y=3;
	WriteConsoleOutputCharacter(hout,L"无法开始游戏？点击博客或打赏试试？",17,pos,&dwRet); 

	//吃饭
	//pos.X=98;
	//pos.Y=36;
	//WriteConsoleOutputCharacter(hout,szStr[13],40,pos,&dwRet); 

	/*TankCursor(49,36,"■■■■■■",F_YELLOW);
	TankCursor(49,37,"■点击打赏■",F_YELLOW);
	TankCursor(49,38,"■■■■■■",F_YELLOW);*/
}

//绘制坦克
void draw::DrawStyle( TANK Tank)
{
	for(unsigned int i=0,y=Tank.TankY-1;y<=Tank.TankY+1;i++,y++)
	{
		for(unsigned int j=0,x=Tank.TankX-1;x<=Tank.TankX+1;j++,x++)
		{
			if (n_SkeletonKnight==100&&Tank.ID>=100)
			{
				//◤┬◥←→↘↙↓
				//├┼┤
				//◣┴◢
				if(g_PlayerTankStyle[Tank.Orientation][i][j]==1)
				{
					TankCursor(x,y,"◤", F_H_YELLOW);
				}
				else if(g_PlayerTankStyle[Tank.Orientation][i][j]==2)
				{
					TankCursor(x,y,"┬",F_H_YELLOW);
				}
				else if(g_PlayerTankStyle[Tank.Orientation][i][j]==3)
				{
					TankCursor(x,y,"◥",F_H_YELLOW);
				}
				else if(g_PlayerTankStyle[Tank.Orientation][i][j]==4)
				{
					TankCursor(x,y,"├",F_H_YELLOW);
				}
				else if(g_PlayerTankStyle[Tank.Orientation][i][j]==5)
				{
					TankCursor(x,y,"┼",F_H_YELLOW);
				}
				else if(g_PlayerTankStyle[Tank.Orientation][i][j]==6)
				{
					TankCursor(x,y,"┤",F_H_YELLOW);
				}
				else if(g_PlayerTankStyle[Tank.Orientation][i][j]==7)
				{
					TankCursor(x,y,"◣",F_H_YELLOW);
				}
				else if(g_PlayerTankStyle[Tank.Orientation][i][j]==8)
				{
					TankCursor(x,y,"┴",F_H_YELLOW);
				}
				else if(g_PlayerTankStyle[Tank.Orientation][i][j]==9)
				{
					TankCursor(x,y,"◢",F_H_YELLOW);
				}
				else
				{
					TankCursor(x,y,"  ",F_H_YELLOW);
				}
			}
			//╱  ╲
			//  ◎
			//╲  ╱
			else if (EliteTankQuantity==3&&flag==1)
			{
				if(g_PlayerTankStyle[Tank.Orientation][i][j]==1)
				{
					TankCursor(x,y,"╱",F_H_YELLOW);
				}
				else if(g_PlayerTankStyle[Tank.Orientation][i][j]==2)
				{
					TankCursor(x,y,"  ",F_H_YELLOW);
				}
				else if(g_PlayerTankStyle[Tank.Orientation][i][j]==3)
				{
					TankCursor(x,y,"╲",F_H_YELLOW);
				}
				else if(g_PlayerTankStyle[Tank.Orientation][i][j]==4)
				{
					TankCursor(x,y,"  ",F_H_YELLOW);
				}
				else if(g_PlayerTankStyle[Tank.Orientation][i][j]==5)
				{
					TankCursor(x,y,"◎",F_H_YELLOW);
				}
				else if(g_PlayerTankStyle[Tank.Orientation][i][j]==6)
				{
					TankCursor(x,y,"  ",F_H_YELLOW);
				}
				else if(g_PlayerTankStyle[Tank.Orientation][i][j]==7)
				{
					TankCursor(x,y,"╲",F_H_YELLOW);
				}
				else if(g_PlayerTankStyle[Tank.Orientation][i][j]==8)
				{
					TankCursor(x,y,"  ",F_H_YELLOW);
				}
				else if(g_PlayerTankStyle[Tank.Orientation][i][j]==9)
				{
					TankCursor(x,y,"╱",F_H_YELLOW);
				}
				else
				{
					TankCursor(x,y,"  ",F_H_YELLOW);
				}
			}
			else
			{
				if(g_PlayerTankStyle[Tank.Orientation][i][j]==1)
				{
					TankCursor(x,y,"■",F_H_YELLOW);
				}
				else if(g_PlayerTankStyle[Tank.Orientation][i][j]==2)
				{
					TankCursor(x,y,"■",F_H_YELLOW);
				}
				else if(g_PlayerTankStyle[Tank.Orientation][i][j]==3)
				{
					TankCursor(x,y,"■",F_H_YELLOW);
				}
				else if(g_PlayerTankStyle[Tank.Orientation][i][j]==4)
				{
					TankCursor(x,y,"■",F_H_YELLOW);
				}
				else if(g_PlayerTankStyle[Tank.Orientation][i][j]==5)
				{
					TankCursor(x,y,"○",F_H_YELLOW);
				}
				else if(g_PlayerTankStyle[Tank.Orientation][i][j]==6)
				{
					TankCursor(x,y,"■",F_H_YELLOW);
				}
				else if(g_PlayerTankStyle[Tank.Orientation][i][j]==7)
				{
					TankCursor(x,y,"■",F_H_YELLOW);
				}
				else if(g_PlayerTankStyle[Tank.Orientation][i][j]==8)
				{
					TankCursor(x,y,"■",F_H_YELLOW);
				}
				else if(g_PlayerTankStyle[Tank.Orientation][i][j]==9)
				{
					TankCursor(x,y,"■",F_H_YELLOW);
				}
				else
				{
					TankCursor(x,y,"  ",F_H_YELLOW);
				}
			}
			
		}
	}
}



//清除坦克
void draw::ClrDrawStyle( TANK Tank )
{
	for(unsigned int i=0,y=Tank.TankY-1;y<=Tank.TankY+1;i++,y++)
	{
		for(unsigned int j=0,x=Tank.TankX-1;x<=Tank.TankX+1;j++,x++)
		{
			TankCursor(x,y,"  ",F_YELLOW);
			g_nMapDataTemp[y][x]=0;
		}

	}
}

//画地图
void draw::DrawMap()
{
	if (MapFlag==1)
	{
		for (int i=0;i<40;i++)
		{
			for (int j=0;j<55;j++)
			{
				if( (i==0||j==39||j==0||i==39)&&j<40)
				{
					m_g_nMapData[i][j]=WALL_B;

				}
			}
		}
		memcpy(g_nMapData,m_g_nMapData,40*55*sizeof(int));
		for(int i=0;i<40;i++)
		{
			for(int j=0;j<55;j++)
			{
				
				if(g_nMapData[i][j]==WALL_B)
				{
					TankCursor(j,i,"■",F_YELLOW);
					//	printf("■");
				}
				else if(g_nMapData[i][j]==WALL_A)
				{
					TankCursor(j,i,"▓",F_YELLOW);
					//printf("▓");
				}
				else if(g_nMapData[i][j]==WALL_F)
				{
					TankCursor(j,i,"◆",F_YELLOW);
					//printf("◆");
				}
				else if (g_nMapData[i][j]==WALL_T)
				{					
					printf("╲");
				}
				else if (g_nMapData[i][j]==WALL_G)
				{
					printf("∷");
				}
				else if (g_nMapData[i][j]==WALL_D)
				{
					TankCursor(j,i,"  ",F_YELLOW);
					//	printf("≡");
				}
				else
				{
					printf("  ");
				}
			}
		}
		
	}
	else if (MapFlag==2)
	{
		memcpy(g_nMapData ,m_g_nMapData1,40*55*sizeof(int));
		for(int i=0;i<40;i++)
		{
			for(int j=0;j<55;j++)
			{

				if(g_nMapData[i][j]==WALL_B)
				{
					TankCursor(j,i,"■",F_YELLOW);
					//	printf("■");
				}
				else if(g_nMapData[i][j]==WALL_A)
				{
					TankCursor(j,i,"▓",F_YELLOW);
					//printf("▓");
				}
				else if(g_nMapData[i][j]==WALL_F)
				{
					TankCursor(j,i,"◆",F_YELLOW);
					//printf("◆");
				}
				else if (g_nMapData[i][j]==WALL_T)
				{					
					printf("╲");
				}
				else if (g_nMapData[i][j]==WALL_G)
				{
					printf("∷");
				}
				else if (g_nMapData[i][j]==WALL_D)
				{
					TankCursor(j,i,"  ",F_YELLOW);
					//	printf("≡");
				}
				else
				{
					printf("  ");
				}
			}
		}
	}
	else
	{
		for(int i=0;i<40;i++)
		{
			for(int j=0;j<55;j++)
			{
				if(g_nMapData[i][j]==WALL_B)
				{

					TankCursor(j,i,"■",F_YELLOW);
					//	printf("■");
				}
				else if(g_nMapData[i][j]==WALL_A)
				{
					printf("▓");
				}
				else if(g_nMapData[i][j]==WALL_F)
				{
					printf("◆");
				}
				else if (g_nMapData[i][j]==WALL_T)
				{
					printf("╲");
				}
				else if (g_nMapData[i][j]==WALL_D)
				{
					TankCursor(j,i,"  ",F_YELLOW);
					//	printf("≡");
				}
				else if (g_nMapData[i][j]==WALL_G)
				{
					printf("∷");
				}
				else
				{
					printf("  ");
				}
			}
		}
	}
}

//图形界面
void draw::GraphicsInterface()
{
	Tank.TankY=37;
	Tank.TankX=14;
	Tank.ID = 100;
	Tank.Bulletflag=1;
	Tank.Orientation=UP;
	Tank.isvalid = true;


	//敌方坦克初始值
	TANK Tank1;
	Tank1.TankY=2;
	Tank1.TankX=2;
	Tank1.Orientation=DOWN;
	Tank1.ChangeOrientation=DOWN;
	Tank1.isvalid = true;
	Tank1.ID = 1;
	tanks.push_back(Tank1);
	TANK Tank2;
	Tank2.TankY=20;
	Tank2.TankX=2;
	Tank2.Orientation=RIGHT;
	Tank2.ChangeOrientation=RIGHT;
	Tank2.isvalid = true;
	Tank2.ID = 2;
	tanks.push_back(Tank2);
	TANK Tank3;
	Tank3.TankY=2;
	Tank3.TankX=37;
	Tank3.Orientation=DOWN;
	Tank3.ChangeOrientation=DOWN;
	Tank3.isvalid = true;
	Tank3.ID = 3;
	tanks.push_back(Tank3);
	TANK Tank4;
	Tank4.TankY=2;
	Tank4.TankX=20;
	Tank4.Orientation=DOWN;
	Tank4.ChangeOrientation=DOWN;
	Tank4.isvalid = true;
	Tank4.ID = 4;
	tanks.push_back(Tank4);
	TANK Tank5;
	Tank5.TankY=20;
	Tank5.TankX=37;
	Tank5.Orientation=LEFT;
	Tank5.ChangeOrientation=LEFT;
	Tank5.isvalid = true;
	Tank5.ID = 5;
	tanks.push_back(Tank5);
	GameMenu();
	DrawMap();
	ScoringSystem();
	DrawStyle(Tank);
	DrawStyleID(Tank);
	if (DoubleGame==2)
	{
		FTank.TankY=37;
		FTank.TankX=24;
		FTank.ID = 101;
		FTank.Orientation=UP;
		FTank.isvalid = true;
		FTank.Bulletflag=1;
		DrawStyle(FTank);
		DrawStyleID(FTank);
	}
	DrawStyle(Tank1);
	DrawStyleID(Tank1);
}

//计分系统
void draw::ScoringSystem()
{
	TankCursor(43,0,"[第一阶段C++项目作品]",F_YELLOW);
	TankCursor(40,2," 8 :SML",F_YELLOW);
	TankCursor(45,3,"XXX ",F_YELLOW);
	TankCursor(40,5,"敌方普通坦克数量:",F_YELLOW);
	TankCursor(45,7,"★★★★★",F_YELLOW);
	TankQuantity=5;
	TankCursor(40,9,"敌方精英坦克数量:",F_YELLOW);
	TankCursor(45,11,"△△△",F_YELLOW);
	TankCursor(40,13,"计分系统:",F_YELLOW);
	TankCursor(45,15,"NUM:",F_YELLOW);
	TankCursor(40,17,"友军1剩余生命值:",F_YELLOW);
	TankCursor(42,19,"♂♂♂♂♂♂♂♂♂♂",F_YELLOW);
	TankCursor(45,21,"＊＊＊",F_YELLOW);
	LifeValue=10;
	LifeNumber=3;
	if (DoubleGame==2&&n_SkeletonKnight==100)
	{
		TankCursor(40,23,"友军2剩余生命数:",F_YELLOW);
		TankCursor(42,25,"♀♀♀♀♀♀♀♀♀♀",F_YELLOW);
		TankCursor(45,27,"＊＊＊",F_YELLOW);
		LifeValue1=10;
		LifeNumber1=3;
		TankCursor(48,30,"太空堡垒[2]：",F_YELLOW);
		TankCursor(52,31,"■■■",F_YELLOW);
		TankCursor(52,32,"■○■",F_YELLOW);
		TankCursor(52,33,"■■■",F_YELLOW);
		TankCursor(48,35,"骸骨骑士[2]：",F_YELLOW);
		TankCursor(52,36,"◤┬◥",F_YELLOW);
		TankCursor(52,37,"├┼┤",F_YELLOW);
		TankCursor(52,38,"◣┴◢",F_YELLOW);
	}
	else if(DoubleGame==2)
	{
		TankCursor(40,23,"友军2剩余生命数:",F_YELLOW);
		TankCursor(42,25,"♀♀♀♀♀♀♀♀♀♀",F_YELLOW);
		TankCursor(45,27,"＊＊＊",F_YELLOW);
		LifeValue1=10;
		LifeNumber1=3;
		TankCursor(48,30,"太空堡垒[2]：",F_YELLOW);
		TankCursor(52,31,"■■■",F_YELLOW);
		TankCursor(52,32,"■○■",F_YELLOW);
		TankCursor(52,33,"■■■",F_YELLOW);
	}

	TankCursor(40,30,"太空堡垒[1]：",F_YELLOW);
	TankCursor(44,31,"■■■",F_YELLOW);
	TankCursor(44,32,"■○■",F_YELLOW);
	TankCursor(44,33,"■■■",F_YELLOW);
	if (n_SkeletonKnight==100)
	{
		TankCursor(40,35,"骸骨骑士[1]：",F_YELLOW);
		TankCursor(44,36,"◤┬◥",F_YELLOW);
		TankCursor(44,37,"├┼┤",F_YELLOW);
		TankCursor(44,38,"◣┴◢",F_YELLOW);
	}
}

//菜单
void draw::GameMenu()
{
GameInterface:
	SetConsoleTitle(L"坦克大战");
	CONSOLE_CURSOR_INFO Cui={1,FALSE};
	COORD pos={52,6};
	SetConsoleCursorInfo(hout,&Cui);
	COORD BufferSize={111,41};//为设定窗口的两倍
	SetConsoleScreenBufferSize(hout,BufferSize);//设置控制台 缓冲区大小 
	SMALL_RECT srctWindow={0,0,110,40};
	SetConsoleWindowInfo(hout,true,&srctWindow);//设置控制窗口大小
	INPUT_RECORD stcRecord={0};
	
	PrintInterface();
	SetConsoleMode(hstdin,ENABLE_WINDOW_INPUT|ENABLE_MOUSE_INPUT);
	while(1)
	{
		ReadConsoleInput(hstdin,&stcRecord,1,&dwRet);
		if (stcRecord.EventType==MOUSE_EVENT)//获取鼠标点击
		{
			Treat(stcRecord.Event.MouseEvent);
			//break;
		}
		if (TreatFlag==1)
		{
			break;
		}
	}
	char ch;
	while (1)
	{
		if( !(ch = GetKey()))
		{
			continue;
		}		
		if(ch==27)
		{
			exit(0);
		}
		switch (ch)
		{
		case '1':
			pos.X=50;
			pos.Y=15;
			system("cls");
			WriteConsoleOutputCharacter(hout,szStr[6],40,pos,&dwRet);
			Sleep(1000);
			system("cls");
			pos.X=30;
			pos.Y=15;
			WriteConsoleOutputCharacter(hout,szStr[12],40,pos,&dwRet);
			SkeletonKnight();
			goto GameStart;		
		case '2':
			pos.X=50;
			pos.Y=15;
			system("cls");
			WriteConsoleOutputCharacter(hout,szStr[6],40,pos,&dwRet);
			Sleep(1000);
			system("cls");
			pos.X=30;
			pos.Y=15;
			WriteConsoleOutputCharacter(hout,szStr[12],40,pos,&dwRet);
			DoubleGame=2;
			SkeletonKnight();
			goto GameStart;
		case '3':
			system("cls");
			/*TankCursor(40,5,"按[S]保存地图并回到主界面",F_YELLOW);
			TankCusor(40,10,"按[Q]不保存地图并直接退出",F_YELLOW);
			TankCursor(40,15,"按[D]设置为双人游戏",F_YELLOW);
			TankCursor(40,20,"按[A]开启深渊模式",F_YELLOW);*/
			pos.X=80;
			pos.Y=5;
			WriteConsoleOutputCharacter(hout,L"按[S]保存地图并回到主界面",14,pos,&dwRet); //在指定位置打印相应字符串
			pos.Y=10;
			WriteConsoleOutputCharacter(hout,L"按[Q]不保存地图并直接退出",14,pos,&dwRet); //在指定位置打印相应字符串
			pos.X=80;
			pos.Y=15;
			WriteConsoleOutputCharacter(hout,L"按[2]设置为双人游戏",11,pos,&dwRet); //在指定位置打印相应字符串
			pos.X=80;
			pos.Y=20;
			WriteConsoleOutputCharacter(hout,L"按[A]开启深渊模式",10,pos,&dwRet); //在指定位置打印相应字符串
			SetConsoleMode(hstdin,ENABLE_WINDOW_INPUT|ENABLE_MOUSE_INPUT);
			while(1)
			{
				ReadConsoleInput(hstdin,&stcRecord,1,&dwRet);
				if (stcRecord.EventType==MOUSE_EVENT)//获取鼠标点击
				{
					MouseClicks(stcRecord.Event.MouseEvent);
				}

				else if (stcRecord.EventType==KEY_EVENT)//获取键盘按键
				{
					if( stcRecord.Event.KeyEvent.bKeyDown)
					{
						if (stcRecord.Event.KeyEvent.wVirtualKeyCode == 's'||stcRecord.Event.KeyEvent.wVirtualKeyCode == 'S')
						{

							writeData("111.mapsb");
							system("cls");
							goto GameInterface;

						}
						else if (stcRecord.Event.KeyEvent.wVirtualKeyCode == 27)
						{
							exit(0);
						}
						else if (stcRecord.Event.KeyEvent.wVirtualKeyCode == 'a'||stcRecord.Event.KeyEvent.wVirtualKeyCode == 'A')
						{
							n_SkeletonKnight=100;
							EliteTankValue=10000;
							EliteTankQuantity=3;
							pos.X=84;
							pos.Y=17;
							WriteConsoleOutputCharacter(hout,L"已设置",3,pos,&dwRet); //在指定位置打印相应字符串
						}
						else if (stcRecord.Event.KeyEvent.wVirtualKeyCode == 'D'||stcRecord.Event.KeyEvent.wVirtualKeyCode == 'd')
						{
							DoubleGame=2;
							pos.X=84;
							pos.Y=22;
							WriteConsoleOutputCharacter(hout,L"已开启",3,pos,&dwRet); //在指定位置打印相应字符串
						}
					}
				}
			}

		case '4':
			SpaceStormflag=1;
			MapFlag=1;
			readData("111.mapsb");
			goto GameStart;//返回开始界面		
		case  '5':
			SpaceStormflag=1;
			MapFlag=2;
			readData("222.mapsb");
			goto GameStart;//返回开始界面
		default:
			pos.X=50;
			pos.Y=15;
			system("cls");
			WriteConsoleOutputCharacter(hout,szStr[7],40,pos,&dwRet);
			Sleep(1000);
			system("cls");
			goto GameInterface;
		}
	}
GameStart:
	system("cls");
}

//坦克ID  坦克与坦克之间碰撞检测
void draw::DrawStyleID( TANK Tank)
{
	for(unsigned int i=0,y=Tank.TankY-1;y<=Tank.TankY+1;i++,y++)
	{
		for(unsigned int j=0,x=Tank.TankX-1;x<=Tank.TankX+1;j++,x++)
		{
			g_nMapDataTemp[y][x]=Tank.ID;
		}
	}
}
//鼠标点击
void draw::MouseClicks(MOUSE_EVENT_RECORD mou)
{
		
		int row=mou.dwMousePosition.Y;//行
		int col=(mou.dwMousePosition.X)/2;//列
		int ObjectType[5]={0,WALL_A,WALL_D,WALL_F,WALL_G};//要画的物体类型
		switch(mou.dwEventFlags)
		{
		case 0:
			if (mou.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED&&
				row<39&&col<39&&row>0&&col>0
				)
			{
				if(ClickCount ==5){
					ClickCount = 0;
				}
				switch (ClickCount)
				{
				case 0:break;
				case 1:TankCursor(col,row,"▓",F_YELLOW);break;
				case 2:TankCursor(col,row,"≈",F_YELLOW);SpaceStormflag=1;break;
				case 3:TankCursor(col,row,"■",F_YELLOW);break;
				case 4:TankCursor(col,row,"∷",F_YELLOW);break;
				}
				
				//int temprow=col;//行
				//int tempcol=row;//列
				 m_g_nMapData[row][col]=ObjectType[ClickCount];//
				 ClickCount++;
				
			}
		case MOUSE_MOVED:
			if (mou.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED&&
				row<39&&col<39&&row>0&&col>0
				)
			{
	
				switch (ClickCount)
				{
				case 0:break;
				case 1:TankCursor(col,row,"▓",F_YELLOW);break;
				case 2:TankCursor(col,row,"≈",F_YELLOW);break;
				case 3:TankCursor(col,row,"■",F_YELLOW);break;
				case 4:TankCursor(col,row,"∷",F_YELLOW);break;
				}
				m_g_nMapData[row][col]=ObjectType[ClickCount];//

			}
	/*		else if (mou.dwButtonState==RIGHTMOST_BUTTON_PRESSED)
			{
			
				TankCursor(mou.dwMousePosition.X,mou.dwMousePosition.Y,"**",F_YELLOW);
			}*/
			break;
		}

}
//按键操作
void draw::KeyEventProc(KEY_EVENT_RECORD key)
{
	/*if (key.bKeyDown)
	{
		printf("1");
	}
	else
	{
		printf("2");
	}*/
}

//森林障碍
void draw::ForestObstacle(TANK Tank)
{
	for(unsigned int i=0,y=Tank.TankY-1;y<=Tank.TankY+1;i++,y++)
	{
		for(unsigned int j=0,x=Tank.TankX-1;x<=Tank.TankX+1;j++,x++)
		{
			if(g_PlayerTankStyle[Tank.Orientation][i][j]==1)
			{
				TankCursor(x,y,"  ",F_YELLOW);
			}
			else if(g_PlayerTankStyle[Tank.Orientation][i][j]==2)
			{
				TankCursor(x,y,"  ",F_YELLOW);
			}
			else if(g_PlayerTankStyle[Tank.Orientation][i][j]==3)
			{
				TankCursor(x,y,"  ",F_YELLOW);
			}
			else if(g_PlayerTankStyle[Tank.Orientation][i][j]==4)
			{
				TankCursor(x,y,"  ",F_YELLOW);
			}
			else if(g_PlayerTankStyle[Tank.Orientation][i][j]==5)
			{
				TankCursor(x,y,"  ",F_YELLOW);
			}
			else if(g_PlayerTankStyle[Tank.Orientation][i][j]==6)
			{
				TankCursor(x,y,"  ",F_YELLOW);
			}
			else if(g_PlayerTankStyle[Tank.Orientation][i][j]==7)
			{
				TankCursor(x,y,"  ",F_YELLOW);
			}
			else if(g_PlayerTankStyle[Tank.Orientation][i][j]==8)
			{
				TankCursor(x,y,"  ",F_YELLOW);
			}
			else if(g_PlayerTankStyle[Tank.Orientation][i][j]==9)
			{
				TankCursor(x,y,"  ",F_YELLOW);
			}
			else
			{
				TankCursor(x,y,"  ",F_YELLOW);
			}

		}
	}
}
//空间风暴
void draw::SpaceStorm()
{
	for(int i=0;i<40;i++)
	{
		for(int j=0;j<55;j++)
		{
			 if (g_nMapData[i][j]==WALL_G)
			{
				
				TankCursor(j,i,"∷",F_YELLOW);
			}
		}
	}
}
//天降神器
void draw::PropRefresh()
{
	//rand() %38    0-37
	//rand() %38+1  1-38
	int x=rand() %38+1;
	int y=rand() %38+1;
	//最多保存三个
	if (g_nMapData[x][y]!=WALL_A&&
		g_nMapData[x][y]!=WALL_B&&
		g_nMapData[x][y]!=WALL_G&&
		g_nMapData[x][y]!=WALL_D
		)
	{
		if (n_TransferMatrix<3)
		{
			n_TransferMatrix++;
			g_nMapData[x][y]=WALL_T;
			TankCursor(y,x,"╲",F_YELLOW);
		}	
	}	
}
