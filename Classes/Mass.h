#pragma once

#include "cocos2d.h"

class Mass
{
public:
	Mass();

	void init();

	bool drawMass(cocos2d::DrawNode * draw, cocos2d::Vec2 origin);

	bool turnR();

	bool moveL();

	bool moveR();

	

	bool quickD(int(*world)[16]);

	bool check(int (* world)  [16]);

	bool checkL(int(*world)[16]);

	bool checkR(int(*world)[16]);

	bool checkT(int(*world)[16]);

	bool addMap(int(*world)[16]);


	int type;
	int	turn;

	int x;
	int y;

	int data[4][4];




};