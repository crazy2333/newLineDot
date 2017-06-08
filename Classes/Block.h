#pragma once


#include "cocos2d.h"


//每个小方格
class Block
{
public:

	//方格左下角
	int x;
	int y;

	//方格宽度
	const static int width = 20;

//	static bool drawBlock(int x, int y, cocos2d::DrawNode * draw);


};

//
//bool Block::drawBlock(int x, int y,cocos2d::DrawNode * draw) {
//
//
//	draw->drawRect(cocos2d::Vec2(x, y), cocos2d::Vec2(x+width, y), cocos2d::Vec2(x + width, y + width), cocos2d::Vec2(x, y + width), cocos2d::Color4F(0, 1, 0, 1));
//
//	return true;
//}


