#pragma once


#include "cocos2d.h"


//ÿ��С����
class Block
{
public:

	//�������½�
	int x;
	int y;

	//������
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


