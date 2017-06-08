#pragma once

#include "cocos2d.h"
#include "Mass.h"
#include <map>
#include <vector>

class GameScene : public cocos2d::Scene 
{
public:

	CREATE_FUNC(GameScene);

//	static GameScene * create();

	static cocos2d::Scene* createScene();

	virtual bool init();

	bool init2();

	//void update(float delta) override;

	void update(float delta) override ;

	void replaceSceneCallback(cocos2d::Ref* pSender);

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event  *event)
	{
		touch1 = touch;
		touched = true;
		return true;
	}
	bool onTouchMoved(cocos2d::Touch* touch, cocos2d::Event  *event)
	{
		
		
		return true;
	}
	bool onTouchEnded(cocos2d::Touch* touch, cocos2d::Event  *event)
	{
		touch2 = touch;
		
		return true;
	}

	
	bool getscore(int * rows);


	//一些共用指针
	cocos2d::DrawNode * draw;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;

	cocos2d::Label * label2;

	int time=0;
//	int time2 = 0;


private:

	//键盘监听map
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;

	int world[30][16];

	Mass * mainMass;

	bool live;

	int score=0;

	cocos2d::Touch* touch1;

	cocos2d::Touch* touch2;

	bool touched=false;


};

