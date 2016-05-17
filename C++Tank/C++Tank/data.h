#pragma once
#include <vector>
using std::vector;

class data
{
public:
	typedef struct _TANK 
	{
		unsigned int TankY;
		unsigned int TankX;
		unsigned int Orientation;	//当前方向
		unsigned int ChangeOrientation;//改变方向
		unsigned int Bullet;           //子弹
		unsigned int Shape   	 ; // 显示类型(256)
		unsigned int Bullft   	 ; // 生命值(64)
		unsigned int Direction	 ; // 运动方向(4)
		unsigned int Collide  	 ; // 碰撞体积(4)
		unsigned int IsBullft	 ; // 是否为炮弹(2)
		unsigned int IsTank	     ; // 是否为坦克(2)
		unsigned int ID       	 ; // 对象ID(256)
		unsigned int Type     	 ; // 对象类型(256)
		unsigned int isvalid     ; // 是否有效
		unsigned int Bulletflag	 ;
	}TANK,*pTANK;
public:
	data(void);
	~data(void);

public:
	 TANK Tank;
	 TANK FTank;
	 vector<TANK>tanks;
	 TANK * g_TankBullet[160];
	static wchar_t szStr[15][40];
	static int g_PlayerTankStyle[4][3][3];
	static int g_nMapData[40][55];//g_nMapData[y][x] x在40以外为计分系统
	static int g_nMapDataTemp[40][40];

	static int m_g_nMapData[40][55];//镜像地图
	static int m_g_nMapData1[40][55];//镜像地图1
	char *filePath;
	char *filePath1;
	 DWORD dwRet;
	 HANDLE hout ;
	 COORD pos;
	 HANDLE hstdin;
 
public:								
	static int DoubleGame;			 //控制双人游戏静态变量
	static int TankQuantity;		 //敌方坦克数量
	static int EliteTankQuantity;	//精英坦克数量
	static int EliteTankValue;	//精英坦克生命值
	static int flag;		//刷新一次
	static int LifeValue;		 //坦克1生命值
	static int LifeValue1;				 //坦克2生命值
	static int LifeNumber;			 //坦克1生命数
	static int LifeNumber1;			 //坦克2生命数
	static int num;				//计分
	static int n_TransferMatrix;//传送阵
	static int MapFlag;//地图标记
	static int ClickCount;//物体类型
	static int SpaceStormflag;//空间风暴启动标记
	static int n_SkeletonKnight;//骸骨骑士
	static int TreatFlag;//吃饭标志
	static int MapFlag1;
	static int AReward;
public:
	bool writeData(char * filePath);
	bool readData(char * filePath);

	
	

};
//随机数
#define Random(x) (rand() % x)

//坦克移动
#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code)&0x8000)?1:0)
#define KEYUP(vk_code) ((GetAsyncKeyState(vk_code)&0x8000)?0:1)
// 字体显示相关
#define REVERSE    COMMON_LVB_REVERSE_VIDEO // 反色
#define UNDERSCORE COMMON_LVB_UNDERSCORE    // 下划线

// 字体颜色
#define F_BLUE     FOREGROUND_BLUE      // 深蓝
#define F_H_BLUE   0x0001|0x0008        // 亮蓝
#define F_GREEN    0x0002               // 深绿
#define F_H_GREEN  0x0002|0x0008        // 亮绿
#define F_RED      0x0004               // 深红
#define F_H_RED    0x0004|0x0008        // 亮红
#define F_YELLOW   0x0002|0x0004        // 深黄
#define F_H_YELLOW 0x0002|0x0004|0x0008 // 亮黄
#define F_PURPLE   0x0001|0x0004        // 深紫
#define F_H_PURPLE 0x0001|0x0004|0x0008 // 亮紫
#define F_CYAN     0x0002|0x0004        // 深青
#define F_H_CYAN   0x0002|0x0004|0x0008 // 亮青
#define F_WHITE    0x0004|0x0002|0x0001
#define F_H_WHITE  0x0004|0x0002|0x0001|0x0008

// 背景颜色
#define B_BLUE     BACKGROUND_BLUE      // 深蓝
#define B_H_BLUE   0x0010|0x0080        // 亮蓝
#define B_GREEN    0x0020               // 深绿
#define B_H_GREEN  0x0020|0x0080        // 亮绿
#define B_RED      0x0040               // 深红
#define B_H_RED    0x0040|0x0080        // 亮红
#define B_YELLOW   0x0020|0x0040        // 深黄
#define B_H_YELLOW 0x0020|0x0040|0x0080 // 亮黄
#define B_PURPLE   0x0010|0x0040        // 深紫
#define B_H_PURPLE 0x0010|0x0040|0x0080 // 亮紫
#define B_CYAN     0x0020|0x0040        // 深青
#define B_H_CYAN   0x0020|0x0040|0x0080 // 亮青
#define B_WHITE    0x0010|0x0020|0x0040
#define B_H_WHITE  0x0010|0x0020|0x0040|0x0080

/*
*        1       23           4                56          78
*  0x    0       00           0                00          00
*     对象类型 对象ID 坦克/炮弹/碰撞体积 运动方向/血值 显示控制
*/



#define TANK_BODY          0x1
#define TANK_STYLE_BODY    0x10090001 // ■ 坦克组成部分
#define TANK_STYLE_UP_L    0x10090002 // ◢  敌军坦克-上 
#define TANK_STYLE_UP_R    0x10090003 // ◣  敌军坦克-上
#define TANK_STYLE_DOWN_L  0x10090004 // ◤  敌军坦克-下
#define TANK_STYLE_DOWN_R  0x10090005 // ◥  敌军坦克-下
#define TANK_STYLE_LEFT_L  0x10090006 // ◥  敌军坦克-左
#define TANK_STYLE_LEFT_R  0x10090007 // ◢  敌军坦克-左
#define TANK_STYLE_RIGHT_L 0x10090008 // ◣  敌军坦克-右
#define TANK_STYLE_RIGHT_R 0x10090009 // ◤  敌军坦克-右
#define TANK_HEART         0x2
#define TANK_LEVEL_1       0x20090011 // ①  血量1
#define TANK_LEVEL_2       0x20090012 // ②  血量2
#define TANK_LEVEL_3       0x20090013 // ③  血量3
#define TANK_LEVEL_4       0x20090014 // ④  血量4
#define TANK_LEVEL_5       0x20090015 // ⑤  血量5
#define TANK_LEVEL_6       0x20090016 // ⑥  血量6
#define TANK_LEVEL_7       0x20090017 // ⑦  血量7
#define TANK_LEVEL_8       0x20090018 // ⑧  血量8
#define TANK_LEVEL_9       0x20090019 // ⑨  血量9
#define TANK_LEVEL_10      0x2009001A // ⑩  血量10

#define WALL_A_Type        0x5
#define WALL_B_Type        0x6
#define WALL_A             0x50010030 // ▓  土墙（可破坏）
#define WALL_B             0x60010031 // 〓 铁墙
#define WALL_C             0x70000032 // ≈  河流（减速）  坦克左右可移动并加速 上下不可移动
#define WALL_D             0x80000033 //     异空间  特定方向才可以进
#define WALL_F             0x80000034 // ■   坦克老板
#define GOODS_STYLE_A      0x90010040 // ☆  五星-空心
#define GOODS_STYLE_B      0xA0010041 // ★  五星-实心
#define WALL_T			   0xA0010042 // \传送阵
#define  WALL_G			   0xA0010043 // ∷ 空间风暴

//∷ 行动减缓
#define BULLET             0xF
#define BULLET_A           0xF0050042 // ¤  榴弹
#define BULLET_B           0xF0050043 // ☉  炮弹
#define BULLET_C           0xF0050044 // ⊕ 穿甲弹
#define BULLET_D           0xF0050045 // ⊙ 贫轴弹
#define BULLET_E           0xF0050046 // ◎  坦克杀手子母弹

#define NULL_A             0x00000047 // □  普通空白
#define NULL_COL           0x00010047 // □  带碰撞体积的空白


#define COLLIDE_1          0x00001000
#define COLLIDE_2          0x00002000


#define UP    0
#define DOWN  1
#define LEFT  2
#define RIGHT 3




    
//◤┬◥←→↘↙↓
//├┼┤
//◣┴◢
//123
//456
//789

//↗┼┬↖
//| ↓ |
//↘↓↙

//╭╰┎╓╖
//│╳│    
//╰━╯╙╜
//