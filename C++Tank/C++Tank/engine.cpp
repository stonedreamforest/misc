#include "stdafx.h"
#include "engine.h"


engine::engine(void)
{

}


engine::~engine(void)
{
}






//击中坦克
bool engine::HitTank(TANK * bullet,int x,int y)
{
//子弹相互击中销毁
		/*if(g_nMapDataTemp[y][x]>=1000)
		{
		bullet->isvalid = false;
		return false;
		}*/
		//打中的别的坦克
		if (g_nMapDataTemp[y][x]<1000)
		{
			//遍历所有坦克，找到打中的坦克到底是谁,并把有效性置为false /
			//敌军子弹ID少于1100
			if((g_nMapDataTemp[y][x]==Tank.ID||g_nMapDataTemp[y][x]==FTank.ID)&&bullet->ID<1100)
			{			
				//检测打到的坦克
				int tankID = g_nMapDataTemp[y][x];
				//坦克1生命值 初始值为10
				if (tankID==100)
				{
					TankCursor(43+(LifeValue-=1),19,"  ",F_YELLOW);
				}					
				//判断坦克1生命值是否为空
				if (LifeValue==0&&tankID==100)
				{
					Tank.isvalid = false;
					ClrDrawStyle(Tank);
					ClrDrawStyleID(Tank);
					TankCursor(45+(LifeNumber-=1),21,"  ",F_YELLOW);
				//	LifeNumber-=1;//生命数减一
				}
				//坦克1重生点
				if (LifeNumber>0&&LifeValue==0)
				{
					Tank.TankY=37;
					Tank.TankX=14;
					Tank.ID = 100;
					Tank.Orientation=UP;
					Tank.isvalid = true;
					TankCursor(42,22,"♂♂♂♂♂♂♂♂♂♂",F_YELLOW);
					LifeValue=10;
					DrawStyle(Tank);
				}
				//坦克2生命值 初始值为10
				if (tankID==101&&DoubleGame==2)
				{
					TankCursor(43+(LifeValue1-=1),25,"  ",F_YELLOW);
				}
				//判断坦克2生命值是否为空
				if (LifeValue1==0&&DoubleGame==2)
				{
					FTank.isvalid = false;
					ClrDrawStyle(FTank);
					ClrDrawStyleID(FTank);
					TankCursor(45+(LifeNumber1-=1),27,"  ",F_YELLOW);
					//LifeNumber1-=1;//生命数减一
				}		
				//坦克2重生点
				if (LifeNumber1>0&&LifeValue1==0)
				{
					FTank.TankY=37;
					FTank.TankX=24;
					FTank.ID = 101;
					FTank.Orientation=UP;
					FTank.isvalid = true;
					DrawStyle(FTank);
					TankCursor(42,25,"♀♀♀♀♀♀♀♀♀♀",F_YELLOW);
					LifeValue1=10;
				}
				// 双人游戏 坦克1 坦克2 都没有生命数游戏结束
				if ((LifeNumber==0&&LifeNumber1==0)&&DoubleGame==2)
				{
					system("cls");
					pos.X=55;
					WriteConsoleOutputCharacter(hout,szStr[8],35,pos,&dwRet);
					Sleep(2000);
					exit(0);
					return false;
				}
				else   //单人游戏  坦克1没有生命数游戏结束
				{
					if (LifeNumber==0)
					{
						system("cls");
						pos.X=55;
						WriteConsoleOutputCharacter(hout,szStr[8],35,pos,&dwRet);
						Sleep(2000);
						exit(0);
						return false;
					}
				}
			}						
		}
		//遍历子弹打中敌方坦克
		for(unsigned int i=0;i<tanks.size();i++)
		{
			
			if(g_nMapDataTemp[y][x]==tanks[i].ID&&bullet->ID>=1100){			
				if (num<5)
				{
					tanks[i].isvalid = false;
					ClrDrawStyle(tanks[i]);
					ClrDrawStyleID(tanks[i]);
					TankCursor(45+(TankQuantity-=1),7,"☆",F_YELLOW);
					TankCursor(49,15," ",F_YELLOW);
					printf("00%d",++num);
				}				
				//当有骸骨骑士 时  才有 精英怪(三位一体)
				else if(n_SkeletonKnight==100)
				{
					EliteTankValue-=1;
			
				}
				//当有骸骨骑士 并且 普通怪全死时  才刷新 精英怪 flag表示只刷新一次
				if (num>=5&&n_SkeletonKnight==100&&flag==0)
				{
					flag=1;
					//中间坦克刷新
					TANK Tank4;
					Tank4.TankY=2;
					Tank4.TankX=20;
					Tank4.Orientation=DOWN;
					Tank4.ChangeOrientation=DOWN;
					Tank4.isvalid = true;
					Tank4.ID = 4;
					tanks.push_back(Tank4);

					//左边坦克刷新
					TANK Tank2;
					Tank2.TankY=20;
					Tank2.TankX=2;
					Tank2.Orientation=RIGHT;
					Tank2.ChangeOrientation=RIGHT;
					Tank2.isvalid = true;
					Tank2.ID = 2;
					tanks.push_back(Tank2);

					//右边坦克刷新
					TANK Tank5;
					Tank5.TankY=20;
					Tank5.TankX=37;
					Tank5.Orientation=LEFT;
					Tank5.ChangeOrientation=LEFT;
					Tank5.isvalid = true;
					Tank5.ID = 5;
					tanks.push_back(Tank5);
					DrawStyle(Tank4);
					DrawStyleID(Tank4);

				
				}
				if (num>=5&&EliteTankValue==0)
				{
					//游戏结束
					system("cls");
					pos.X=55;
					WriteConsoleOutputCharacter(hout,szStr[8],35,pos,&dwRet);
					Sleep(2000);
					exit(0);
					return false;
				}
				 if(num>=5&&n_SkeletonKnight==0)
				{
					//游戏结束
					system("cls");
					pos.X=55;
					WriteConsoleOutputCharacter(hout,szStr[8],35,pos,&dwRet);
					Sleep(2000);
					exit(0);
					return false;
				}
			}
		}
		return true;
}

//判断森林障碍
bool engine::JudgeForestObstacle(TANK Tank)
{
	switch (Tank.ChangeOrientation)
	{
	case UP:
		if(
			g_nMapData[Tank.TankY-2][Tank.TankX]==WALL_D||
			g_nMapData[Tank.TankY-2][Tank.TankX+1]==WALL_D||
			g_nMapData[Tank.TankY-2][Tank.TankX-1]==WALL_D
			)
		{
			return true;
		}
		break;
	case DOWN:
		if(
			g_nMapData[Tank.TankY+2][Tank.TankX]==(WALL_D)||
			g_nMapData[Tank.TankY+2][Tank.TankX+1]==(WALL_D)||
			g_nMapData[Tank.TankY+2][Tank.TankX-1]==(WALL_D)
			)
		{
			return false;
		}
		break;
	case LEFT:
		if(
			g_nMapData[Tank.TankY][Tank.TankX-2]==(WALL_D)||
			g_nMapData[Tank.TankY+1][Tank.TankX-2]==(WALL_D)||
			g_nMapData[Tank.TankY-1][Tank.TankX-2]==(WALL_D)
			)
		{
			return false;
		}		
		break;
	case RIGHT:
		if(
			g_nMapData[Tank.TankY][Tank.TankX+2]==(WALL_D)||
			g_nMapData[Tank.TankY+1][Tank.TankX+2]==(WALL_D)||
			g_nMapData[Tank.TankY-1][Tank.TankX+2]==(WALL_D)
			)
			//碰撞实现
		{
			return false;
		}
		break;
	}
	return false;
}

//传送阵
void engine::TransferMatrix(TANK &Tank)
{
	int x=rand() %35+2;
	int y=rand() %35+2;
	//判断前方是不是传送阵
	if (WALL_T==g_nMapData[Tank.TankY-1][Tank.TankX-1]||	//上左
		WALL_T==g_nMapData[Tank.TankY+1][Tank.TankX]||	//中上
		WALL_T==g_nMapData[Tank.TankY+1][Tank.TankX+1]||	//上右
		WALL_T==g_nMapData[Tank.TankY][Tank.TankX+1]||	//中右
		WALL_T==g_nMapData[Tank.TankY][Tank.TankX-1]||	//中左
		WALL_T==g_nMapData[Tank.TankY][Tank.TankX]||	//中心点
		WALL_T==g_nMapData[Tank.TankY-1][Tank.TankX]||	//中下
		WALL_T==g_nMapData[Tank.TankY-1][Tank.TankX+1]||	//下右
		WALL_T==g_nMapData[Tank.TankY-1][Tank.TankX-1]	//下左	
	)
	{
		CTransferMatrix();
		
		//如果当前x点y点 没任何物体才传送 x表示行 y表示列
		if (CanTransferMatrix(x,y))
		{
			Tank.isvalid = false;
			ClrDrawStyle(Tank);
			ClrDrawStyleID(Tank);
			Tank.TankY=y;
			Tank.TankX=x;
			Tank.ID = 100;
			Tank.Bulletflag=1;
			Tank.Orientation=UP;
			Tank.isvalid = true;
			n_TransferMatrix--;
			TankCursor(43,28,"当前传送成功",F_YELLOW);
		}
		else
		{
			n_TransferMatrix--;
			TankCursor(43,28,"当前传送失败",F_YELLOW);
		}
		
//		DrawStyle(Tank);
//	DrawStyleID(Tank);
	}
}
//清除传送阵
void engine::CTransferMatrix()//如何传参数？
{
	if (g_nMapData[Tank.TankY+1][Tank.TankX+1]==WALL_G)	//下左
	{
		g_nMapData[Tank.TankY+1][Tank.TankX+1]=WALL_G;
	}
	else
	{
		g_nMapData[Tank.TankY-1][Tank.TankX-1]=0;
	}
	if (g_nMapData[Tank.TankY+1][Tank.TankX]==WALL_G)//下种
	{
		g_nMapData[Tank.TankY+1][Tank.TankX]=WALL_G;
	}
	else
	{
		g_nMapData[Tank.TankY+1][Tank.TankX]=0;
	}
	if (g_nMapData[Tank.TankY+1][Tank.TankX+1]==WALL_G)//下右
	{
		g_nMapData[Tank.TankY+1][Tank.TankX+1]=WALL_G;
	}
	else
	{
		g_nMapData[Tank.TankY+1][Tank.TankX+1]=0;
	}
	if (g_nMapData[Tank.TankY][Tank.TankX+1]==WALL_G)//中右
	{
		g_nMapData[Tank.TankY][Tank.TankX+1]=WALL_G;
	}
	else
	{
		g_nMapData[Tank.TankY][Tank.TankX+1]=0;
	}
	if (g_nMapData[Tank.TankY][Tank.TankX-1]==WALL_G)//中左
	{
		g_nMapData[Tank.TankY][Tank.TankX-1]=WALL_G;
	}
	else
	{
		g_nMapData[Tank.TankY][Tank.TankX-1]=0;
	}
		g_nMapData[Tank.TankY][Tank.TankX]	=0;  //中心点
	if (g_nMapData[Tank.TankY-1][Tank.TankX]==WALL_G)//上中
	{
		g_nMapData[Tank.TankY-1][Tank.TankX]=WALL_G;
	}
	else
	{
		g_nMapData[Tank.TankY-1][Tank.TankX]=0;
	}
	if (g_nMapData[Tank.TankY-1][Tank.TankX+1]==WALL_G)//上右
	{
		g_nMapData[Tank.TankY-1][Tank.TankX+1]=WALL_G;
	}
	else
	{
		g_nMapData[Tank.TankY-1][Tank.TankX+1]=0;
	}
	if (g_nMapData[Tank.TankY-1][Tank.TankX-1]==WALL_G)//上左
	{
		g_nMapData[Tank.TankY-1][Tank.TankX-1]=WALL_G;
	}
	else
	{
		g_nMapData[Tank.TankY-1][Tank.TankX-1]=0;
	}
}
//是否可以传送
bool engine::CanTransferMatrix(int x,int y)
{
	if (0==g_nMapData[y-1][x-1]&&	//上左
		0==g_nMapData[y+1][x]&&	//中上
		0==g_nMapData[y+1][x+1]&&	//上右
		0==g_nMapData[y][x+1]&&	//中右
		0==g_nMapData[y][x-1]&&	//中左
		0==g_nMapData[y][x]&&	//中心点
		0==g_nMapData[y-1][x]&&	//中下
		0==g_nMapData[y-1][x+1]&&	//下右
		0==g_nMapData[y-1][x-1]	//下左
		)
	{
		return true;
	}
		return false;
}

//判断子弹是否能够移动
//true  能移动
//false 不能移动
bool engine::isAllowMove( TANK * bullet,int x,int y)
{
	//比较地图元素
	if(g_nMapData[y][x]==WALL_A)
	{
		g_nMapData[y][x] = 0;
		TankCursor(x,y,"  ",F_YELLOW);
		bullet->isvalid = false;

		return false;
	}
	if(g_nMapData[y][x]==WALL_B)
	{
		bullet->isvalid = false;
		return false;
	}
	if (g_nMapData[0])
	{
	}
	if(g_nMapData[y][x]==WALL_T) //大于等于才是我方子弹
	{
		if (bullet->ID>=1100)
		{
			n_TransferMatrix--;
			g_nMapData[y][x]=0;//(至少有一次传送)
			TankCursor(x,y,"  ",F_YELLOW);
			ClrDrawStyle(Tank);
			ClrDrawStyleID(Tank);
			Tank.TankY=37;
			Tank.TankX=37;
			Tank.ID = 100;
			Tank.Bulletflag=1;
			Tank.Orientation=UP;
			Tank.isvalid = true;
			bullet->isvalid = false;
			return false;
		}
		else
		{
			g_nMapData[y][x]=0;//(至少有一次传送)
			TankCursor(x,y,"  ",F_YELLOW);
			bullet->isvalid = false;
			return false;
		}
	}
	if(g_nMapData[y][x]==WALL_F)
	{
		system("cls");
		pos.X=55;
		WriteConsoleOutputCharacter(hout,szStr[8],35,pos,&dwRet);
		Sleep(2000);
		exit(0);
		return false;
	}
	//子弹相互击中销毁
	if(g_nMapDataTemp[y][x]>=1000)
	{
		bullet->isvalid = false;
		return false;
	}
	//打中坦克
	if(g_nMapDataTemp[y][x]>0)
	{ 
		HitTank(bullet,x,y);
		//再清子弹
		bullet->isvalid = false;
		return false;
	}
	return true;
}

//移动一颗子弹
void engine::BulletMove( TANK * bullet){
	//清除子弹

	TankCursor(bullet->TankX,bullet->TankY,"  ",F_YELLOW);
	ClrDrawBulletID(*bullet);
	//碰撞判断
	switch(bullet->Orientation){
	case UP: 
		if(isAllowMove(bullet,bullet->TankX-1,bullet->TankY-1)&
			isAllowMove(bullet,bullet->TankX  ,bullet->TankY-1)&
			isAllowMove(bullet,bullet->TankX+1,bullet->TankY-1)){
				bullet->TankY--;
		}else{
			return;
		}
		break;
	case DOWN: 
		if(isAllowMove(bullet,bullet->TankX-1,bullet->TankY+1)&
			isAllowMove(bullet,bullet->TankX  ,bullet->TankY+1)&
			isAllowMove(bullet,bullet->TankX+1,bullet->TankY+1)){
				bullet->TankY++;
		}else{
			return;
		}
		break;
	case LEFT: 
		if(isAllowMove(bullet,bullet->TankX-1,bullet->TankY-1)&
			isAllowMove(bullet,bullet->TankX-1,bullet->TankY  )&
			isAllowMove(bullet,bullet->TankX-1,bullet->TankY+1)){
				bullet->TankX--;
		}else{
			return;
		}
		break;
	case RIGHT: 
		if(isAllowMove(bullet,bullet->TankX+1,bullet->TankY-1)&
			isAllowMove(bullet,bullet->TankX+1,bullet->TankY  )&
			isAllowMove(bullet,bullet->TankX+1,bullet->TankY+1)){
				bullet->TankX++;
		}else{
			return;
		}
		break;
	}
	//画出子弹
	if (n_SkeletonKnight==100&&bullet->Bulletflag==1)
	{
		TankCursor(bullet->TankX,bullet->TankY,"卐",F_YELLOW);
	}
	else if(n_SkeletonKnight==100&&flag==1)
	{
		TankCursor(bullet->TankX,bullet->TankY,"◎",F_YELLOW);
	}
	else
	{
		TankCursor(bullet->TankX,bullet->TankY,"○",F_YELLOW);
	}
	DrawBulletID(*bullet);

}
//坦克（子弹、移动碰撞）引擎
void engine::BulletsMove()
{	
	int i;
	for ( i = 0; i < 160; i++)
	{
		if ( g_TankBullet[i] != 0)
		{
			if(g_TankBullet[i]->isvalid == false)
			{
				free(g_TankBullet[i]);
				g_TankBullet[i] = 0;
				continue;
			}
			BulletMove( g_TankBullet[i]);
		}
	}
}

//CollisionDetection(碰撞检测)
bool engine::Collisionetection(TANK Tank)
{
	switch (Tank.ChangeOrientation)
	{
	case UP:
		if(g_nMapData[Tank.TankY-2][Tank.TankX]==(WALL_B)||//坦克1移动  可卡BUG 
			g_nMapData[Tank.TankY-2][Tank.TankX]==WALL_A||
			g_nMapData[Tank.TankY-2][Tank.TankX+1]==WALL_A||
			g_nMapData[Tank.TankY-2][Tank.TankX-1]==WALL_A||
			g_nMapData[Tank.TankY-2][Tank.TankX]==WALL_F||
			g_nMapData[Tank.TankY-2][Tank.TankX+1]==WALL_F||
			g_nMapData[Tank.TankY-2][Tank.TankX-1]==WALL_F||
			g_nMapDataTemp[Tank.TankY-2][Tank.TankX]>0||
			g_nMapDataTemp[Tank.TankY-2][Tank.TankX+1]>0||
			g_nMapDataTemp[Tank.TankY-2][Tank.TankX-1]>0)
		{
			return false;
		}
		break;
	case DOWN:
		if((g_nMapData[Tank.TankY+2][Tank.TankX]==WALL_B)||
			g_nMapData[Tank.TankY+2][Tank.TankX]==(WALL_A)||
			g_nMapData[Tank.TankY+2][Tank.TankX+1]==(WALL_A)||
			g_nMapData[Tank.TankY+2][Tank.TankX-1]==(WALL_A)||
			g_nMapData[Tank.TankY+2][Tank.TankX]==(WALL_F)||
			g_nMapData[Tank.TankY+2][Tank.TankX+1]==(WALL_F)||
			g_nMapData[Tank.TankY+2][Tank.TankX-1]==(WALL_F)||
			g_nMapDataTemp[Tank.TankY+2][Tank.TankX]>0||
			g_nMapDataTemp[Tank.TankY+2][Tank.TankX+1]>0||
			g_nMapDataTemp[Tank.TankY+2][Tank.TankX-1]>0)
		{
			return false;
		}
		break;
	case LEFT:
		if((g_nMapData[Tank.TankY][Tank.TankX-2]==WALL_B)||
			g_nMapData[Tank.TankY][Tank.TankX-2]==(WALL_A)||
			g_nMapData[Tank.TankY+1][Tank.TankX-2]==(WALL_A)||
			g_nMapData[Tank.TankY-1][Tank.TankX-2]==(WALL_A)||
			g_nMapData[Tank.TankY][Tank.TankX-2]==(WALL_F)||
			g_nMapData[Tank.TankY+1][Tank.TankX-2]==(WALL_F)||
			g_nMapData[Tank.TankY-1][Tank.TankX-2]==(WALL_F)||
			g_nMapDataTemp[Tank.TankY][Tank.TankX-2]>0||
			g_nMapDataTemp[Tank.TankY+1][Tank.TankX-2]>0||
			g_nMapDataTemp[Tank.TankY-1][Tank.TankX-2]>0)
		{
			return false;
		}		
		break;
	case RIGHT:
		if((g_nMapData[Tank.TankY][Tank.TankX+2]==WALL_B)||
			g_nMapData[Tank.TankY][Tank.TankX+2]==(WALL_A)||
			g_nMapData[Tank.TankY+1][Tank.TankX+2]==(WALL_A)||
			g_nMapData[Tank.TankY-1][Tank.TankX+2]==(WALL_A)||
			g_nMapData[Tank.TankY][Tank.TankX+2]==(WALL_F)||
			g_nMapData[Tank.TankY+1][Tank.TankX+2]==(WALL_F)||
			g_nMapData[Tank.TankY-1][Tank.TankX+2]==(WALL_F)||
			g_nMapDataTemp[Tank.TankY][Tank.TankX+2]>0||
			g_nMapDataTemp[Tank.TankY+1][Tank.TankX+2]>0||
			g_nMapDataTemp[Tank.TankY-1][Tank.TankX+2]>0)
			//碰撞实现
		{
			return false;
		}
		break;
	}
	return true;
}


//清除坦克ID 
void engine::ClrDrawStyleID(TANK Tank)
{
	for(unsigned int i=0,y=Tank.TankY-1;y<=Tank.TankY+1;i++,y++)
	{
		for(unsigned int j=0,x=Tank.TankX-1;x<=Tank.TankX+1;j++,x++)
		{
			g_nMapDataTemp[y][x]=0;
		}

	}
}
//画子弹id
void engine::DrawBulletID(TANK  bullet)
{
	g_nMapDataTemp[bullet.TankY][bullet.TankX]=bullet.ID;
}
//清除子弹ID
void engine::ClrDrawBulletID(TANK bullet)
{
	g_nMapDataTemp[bullet.TankY][bullet.TankX]=0;

}
//Tank1移动及碰撞检测
void engine::Tank1Collisionetection(TANK & Tank1,int caozuo)
{
	//caozuo = 20;
	if(Tank1.isvalid == false){
		ClrDrawStyle(Tank1);
		return;
	}
	if(caozuo<4){
		Tank1.ChangeOrientation=caozuo;
		ClrDrawStyle(Tank1);
		ClrDrawStyleID(Tank1);
		if(Tank1.Orientation==Tank1.ChangeOrientation)
		{
			Tank1.Orientation=Tank1.ChangeOrientation;
			switch(Tank1.ChangeOrientation)
			{
			case UP:		
				if ( Collisionetection(Tank1))
				{

					Tank1.TankY--;	
				}
				else
				{
					break ;
				}
			case DOWN:
				if ( Collisionetection(Tank1))
				{
					Tank1.TankY++;	
				}
				else
				{
					break ;
				}
			case LEFT:
				if ( Collisionetection(Tank1))
				{
					Tank1.TankX--;	
				}
				else
				{
					break ;
				}		
			case RIGHT:
				if ( Collisionetection(Tank1))
				{
					Tank1.TankX++;	
				}
				else
				{
					break ;
				}	
			}
		}
		Tank1.Orientation=Tank1.ChangeOrientation;
	}
	DrawStyle(Tank1);
	DrawStyleID(Tank1);
	if(caozuo>3&&caozuo<7)
	{
		FireBullet(Tank1);
	}
}
//Tank移动及碰撞检测
void engine::TankCollisionetection(TANK & Tank )
{
	int Forestflag=0,Forestflag1=0;
	if(Tank.isvalid == false){
		ClrDrawStyle(Tank);
		return;
	}
	ClrDrawStyle(Tank);
	ClrDrawStyleID(Tank);
	if(Tank.Orientation==Tank.ChangeOrientation)
	{
		Tank.Orientation=Tank.ChangeOrientation;
		switch(Tank.ChangeOrientation)
		{
		case UP:		
			if ( Collisionetection(Tank))
			{
				if(JudgeForestObstacle(Tank))
				{
					ForestObstacle(Tank);
					Tank.TankY--;
					Forestflag=1;
					break;
				}
				Tank.TankY--;
			}
			break;
		case DOWN:
			if ( Collisionetection(Tank))
			{

				Tank.TankY++;	
			}
			break ;
		case LEFT:
			if ( Collisionetection(Tank))
			{
				Tank.TankX--;	
			}
			break ;			
		case RIGHT:
			if ( Collisionetection(Tank))
			{
				Tank.TankX++;	
			}
			break ;		
		}
	}
	//
	TransferMatrix(Tank);
	Tank.Orientation=Tank.ChangeOrientation;
	if (Forestflag!=1)
	{
		DrawStyle(Tank);
	}	
	DrawStyleID(Tank);
}
//定义开火
void engine::FireBullet(TANK Tank)
{
	TANK *bullet = (TANK *)malloc(sizeof(TANK));
	bullet->TankX = Tank.TankX;
	bullet->TankY = Tank.TankY;
	bullet->ID    = Tank.ID+1000;
	bullet->Orientation = Tank.Orientation;
	bullet->Bulletflag = Tank.Bulletflag;

	switch(bullet->Orientation){
	case UP:	bullet->TankY--;	break;
	case DOWN:	bullet->TankY++;	break;
	case LEFT:	bullet->TankX--;	break;
	case RIGHT:	bullet->TankX++;	break;
	}

	for (int i = 0; i < 160; i++)
	{
		if ( g_TankBullet[i] == 0)
		{
			g_TankBullet[i] = bullet;
			BulletMove( g_TankBullet[i]);
			DrawStyle(Tank);
			break;
		}
	}
}

//骸骨骑士
void engine::SpeedTANK(clock_t start2,clock_t finish2,clock_t start3,clock_t start4)
{
	clock_t finish3 ;
	clock_t finish4 ;
	if( (finish2 -start2 )>2)
	{
		start2 = finish2 ;	
		if (KEYDOWN('w')||KEYDOWN('W'))
		{
			Tank.ChangeOrientation=0;
			TankCollisionetection(Tank);
		}
		if (KEYDOWN('s')||KEYDOWN('S'))
		{
			Tank.ChangeOrientation=1;
			TankCollisionetection(Tank);
		}
		if (KEYDOWN('a')||KEYDOWN('A'))
		{
			Tank.ChangeOrientation=2;
			TankCollisionetection(Tank);
		}
		if (KEYDOWN('d')||KEYDOWN('D'))
		{
			Tank.ChangeOrientation=3;
			TankCollisionetection(Tank);
		}
		finish3=clock();
		if ((finish3-start3)>500)
		{
			start3=finish3;
			if(KEYDOWN('j')||KEYDOWN('J'))
			{
				FireBullet(Tank);
			}
		}
		if (KEYDOWN('k')||KEYDOWN('K'))
		{
			//memcpy(g_nMapData,m_g_nMapData,40*55*sizeof(int));
			memcpy(m_g_nMapData1,g_nMapData,40*55*sizeof(int));

			writeData("222.mapsb");
			exit(0);
		}
		finish3=clock();
		//坦克2控制移动
		if (DoubleGame==2)
		{
			if (KEYDOWN(VK_UP))
			{
				FTank.ChangeOrientation=0;
				TankCollisionetection(FTank);
			}
			if (KEYDOWN(VK_DOWN))
			{
				FTank.ChangeOrientation=1;
				TankCollisionetection(FTank);
			}
			if (KEYDOWN(VK_LEFT))
			{
				FTank.ChangeOrientation=2;
				TankCollisionetection(FTank);
			}
			if (KEYDOWN(VK_RIGHT))
			{
				FTank.ChangeOrientation=3;
				TankCollisionetection(FTank);
			}

			finish4= clock();
			if ((finish4-start4)>500)
			{
				start4=finish4;
				if (KEYDOWN(VK_DECIMAL))
				{
					FireBullet(FTank);
				}
			}
			finish4=clock();
		}
	}
	
}

//进入(指引)游戏
void engine::index()
{

	char ch=GetKey();
	GraphicsInterface();//图形界面
	//敌方坦克时钟
	clock_t start = clock();
	clock_t finish ;
	clock_t start1= clock();
	clock_t finish1 ;
	//己方坦克时钟
	clock_t start2 = clock();
	clock_t finish2 ;
	//己方坦克1子弹时钟
	clock_t start3= clock();
	clock_t finish3 ;
	//己方坦克2子弹时钟
	clock_t start4= clock();
	clock_t finish4;
	//天降神器
	clock_t start5= clock();
	clock_t finish5;
	clock_t start6= clock();
	clock_t finish6;
	srand((unsigned)time(NULL));//随机值
	while(1)
	{
		finish1=clock();
		if( (finish1 -start1 )>500)//控制敌方坦克方向及移动
		{
			start1  = finish1 ;	
			vector<TANK>::iterator  it = tanks.begin();
			for (;it!=tanks.end();)
			{				
				if (it->isvalid==false)
				{
					it = tanks.erase(it);
				}else{
					Tank1Collisionetection(*it,rand()%15);
					it++;
				}
			}		
		}	
		finish = clock();
		if( (finish -start )>50)//控制子弹频率
		{
			start  = finish ;
			BulletsMove();
		}		
		//坦克1控制移动
		finish2 =clock();
		if (n_SkeletonKnight==100)
		{
			SpeedTANK( start2 , finish2,start3, start4);
		}		
		else
		{
			if( (finish2 -start2 )>30)
			{
				start2 = finish2 ;	
				if (KEYDOWN('w')||KEYDOWN('W'))
				{
					Tank.ChangeOrientation=0;
					TankCollisionetection(Tank);
				}
				if (KEYDOWN('s')||KEYDOWN('S'))
				{
					Tank.ChangeOrientation=1;
					TankCollisionetection(Tank);
				}
				if (KEYDOWN('a')||KEYDOWN('A'))
				{
					Tank.ChangeOrientation=2;
					TankCollisionetection(Tank);
				}
				if (KEYDOWN('d')||KEYDOWN('D'))
				{
					Tank.ChangeOrientation=3;
					TankCollisionetection(Tank);
				}
				finish3=clock();
				if ((finish3-start3)>70)
				{
					start3=finish3;
					if(KEYDOWN('j')||KEYDOWN('J'))
					{
						FireBullet(Tank);
					}
				}
				if (KEYDOWN('k')||KEYDOWN('K'))
				{
					//memcpy(g_nMapData,m_g_nMapData,40*55*sizeof(int));
					memcpy(m_g_nMapData1,g_nMapData,40*55*sizeof(int));

					writeData("222.mapsb");
					exit(0);
				}
				finish3=clock();
				//坦克2控制移动
				if (DoubleGame==2)
				{
					if (KEYDOWN(VK_UP))
					{
						FTank.ChangeOrientation=0;
						TankCollisionetection(FTank);
					}
					if (KEYDOWN(VK_DOWN))
					{
						FTank.ChangeOrientation=1;
						TankCollisionetection(FTank);
					}
					if (KEYDOWN(VK_LEFT))
					{
						FTank.ChangeOrientation=2;
						TankCollisionetection(FTank);
					}
					if (KEYDOWN(VK_RIGHT))
					{
						FTank.ChangeOrientation=3;
						TankCollisionetection(FTank);
					}

					finish4= clock();
					if ((finish4-start4)>70)
					{
						start4=finish4;
						if (KEYDOWN(VK_DECIMAL))
						{
							FireBullet(FTank);
						}
					}
					finish4=clock();
				}
			}
			finish5=clock();
			if ((finish5-start5)>1000*10)
			{
				start5=finish5;
				PropRefresh();
			}
			finish5=clock();
		}	
		finish2=clock();

		finish6 = clock();
		if (finish6-start6>1 )
		{
			start6 = finish6;
			if (MapFlag!=1||SpaceStormflag==1)
			{
				SpaceStorm();
			}
		}
		if (GetKey()=='p'||GetKey()=='P')
		{
			while (1)
			{
				if (GetKey()=='o'||GetKey()=='O')
				{
					break;
				}
			}
		}

	}
	
}

