#include "GameScene.h"
#include "HelloWorldScene.h"
#include "Block.h"


USING_NS_CC;

/*
GameScene * GameScene::create()
{
	GameScene * pt = new (std::nothrow) GameScene();
	if (pt&&pt->init())
	{
		pt->autorelease();
		return pt;
	}
	else 
	{
		delete pt;
		pt = nullptr;
		return nullptr;
	}
}
*/
Scene* GameScene::createScene()
{
	return GameScene::create();
}
bool GameScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	//公用成员定义

	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	this->init2();

	draw = DrawNode::create();
	this->addChild(draw);

/*
	//添加键盘监听
	auto listener2 = EventListenerKeyboard::create();
	listener2->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		keys[keyCode] = true;
	};
	listener2->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		keys[keyCode] = false;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener2, this);

	*/
	//
	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//默认update调度开启
	this->scheduleUpdate();
	//	this->schedule(schedule_selector(GameScene::myupdate), 0.3);


	


	return true;

}

bool GameScene::init2()
{
	live = false;

	//画背景框
	Vec2 * vp2 = new Vec2[4];

	int left = origin.x + 4 * Block::width;
	int right = left + 16 * Block::width;
	int down = origin.y + 4 * Block::width;
	int up = down + 30 * Block::width;

	vp2[0] = Vec2(left, down);
	vp2[1] = Vec2(left, up);
	vp2[2] = Vec2(right, up);
	vp2[3] = Vec2(right, down);

	auto draw2 = DrawNode::create();
	this->addChild(draw2);

	draw2->drawPolygon(vp2, 4, Color4F(1, 0, 0, 0), 1, Color4F(1, 1, 1, 1));
	
	//画操作按钮

	//left
	Vec2 p1 = Vec2(left, down - 2*Block::width );
	Vec2 p2 = Vec2(left + 2*Block::width, down - Block::width );
	Vec2 p3 = Vec2(left + 2*Block::width, down - 3*Block::width);
	draw2->drawTriangle(p1, p2, p3, Color4F(1, 1, 1, 1));

	//right
	p1 = Vec2(left+6* Block::width, down - 2 * Block::width);
	p2 = Vec2(left + 4 * Block::width, down - Block::width);
	p3 = Vec2(left + 4 * Block::width, down - 3 * Block::width);
	draw2->drawTriangle(p1, p2, p3, Color4F(1, 1, 1, 1));

	//turnR
	p1= Vec2(left + 9 * Block::width, down - 2 * Block::width);
	draw2->drawSolidCircle(p1, Block::width, 0,24,Color4F(1, 1, 1, 1));

	//down
	p1= Vec2(left + 12 * Block::width, down -  Block::width);
	p2 = Vec2(left + 14 * Block::width, down - Block::width);
	p3 = Vec2(left + 13 * Block::width, down - 3 * Block::width);
	draw2->drawTriangle(p1, p2, p3, Color4F(1, 1, 1, 1));

//	delete[]vp2;
//	delete vp2;

	//画按钮
	auto label = Label::createWithTTF("BACK", "fonts/Marker Felt.ttf", 14);
	label->setColor(Color3B(255, 255, 255));

	auto back = MenuItemLabel::create(label, CC_CALLBACK_1(GameScene::replaceSceneCallback, this));

	back->setPosition(Vec2(origin.x + visibleSize.width - 40, origin.y + 40));

	// create menu, it's an autorelease object
	auto menu = Menu::create(back, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	//分数初始化
	label2 = Label::createWithTTF("SCORE:0", "fonts/Marker Felt.ttf", 24);

	label2->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - label->getContentSize().height));

	this->addChild(label2, 1);




	return true;
}

void GameScene::update(float delta)
{
	Node::update(delta);

	time++;
	if (time == 30) { time = 0; }
/*
	
	time2++;
	
	if (time2 == 5) { time2 = 0; }
	*/

	if (!live) 
	{
		mainMass=new Mass();

		live = true;
	
	}


	draw->clear();

	

/*
	if (keys[EventKeyboard::KeyCode::KEY_LEFT_ARROW] == true && mainMass->checkL(world))  { mainMass->moveL(); }
	else if (keys[EventKeyboard::KeyCode::KEY_RIGHT_ARROW] == true && mainMass->checkR(world)) { mainMass->moveR(); }
	else if (keys[EventKeyboard::KeyCode::KEY_SPACE] == true && mainMass->checkL(world)&& mainMass->checkR(world) && mainMass->check(world)) { mainMass->turnR(); }
	else if (keys[EventKeyboard::KeyCode::KEY_DOWN_ARROW] == true && mainMass->check(world)) { mainMass->quickD(world); }
	else if (mainMass->check(world)) { mainMass->y--; }
	*/
	if (mainMass->check(world)&&time==29) { mainMass->y--; }

	

	if (touched)
	{
		touched = false;

		auto x1 = touch1->getLocation().x;
		auto y1 = touch1->getLocation().y;

		/*
		int x2 = touch2->getLocation().x;
		int y2 = touch2->getLocation().y;

		
		if (x2 - x1 > 30 && (y2 - y1)*(y2 - y1)<900 && mainMass->checkR(world))
		{
			mainMass->moveR();
		}
		else if (x1 - x2 > 30 && (y2 - y1)*(y2 - y1)<900 && mainMass->checkL(world))
		{
			mainMass->moveL();
		}
		else if ((x2 - x1)*(x2 - x1)<900 && (y2 - y1)*(y2 - y1)<900 && mainMass->checkL(world) && mainMass->checkR(world) && mainMass->check(world))
		{
			mainMass->turnR();
		}
		else if (mainMass->check(world)) { mainMass->y--; }
		
		*/
		if (x1 > origin.x + 4 * Block::width&&x1<origin.x + 6 * Block::width&&y1>origin.y + Block::width&&y1 < origin.y + 3 * Block::width&&mainMass->checkL(world))
		{
	//		mainMass->y++;
			mainMass->moveL();
		}
		else if (x1 > origin.x + 8 * Block::width&&x1<origin.x + 10 * Block::width&&y1>origin.y + Block::width&&y1 < origin.y + 3 * Block::width&&mainMass->checkR(world))
		{
	//		mainMass->y++;
			mainMass->moveR();
		}
		else if (x1 > origin.x + 12 * Block::width&&x1<origin.x + 14 * Block::width&&y1>origin.y + Block::width&&y1 < origin.y + 3 * Block::width&&mainMass->checkT(world))
		{
	//		mainMass->y++;
			mainMass->turnR();
		}
		else if (x1 > origin.x + 16 * Block::width&&x1<origin.x + 18 * Block::width&&y1>origin.y + Block::width&&y1 < origin.y + 3 * Block::width)
		{
			mainMass->quickD(world);
		}
		
	}
	

	if (!mainMass->check(world))
	{
		live = false;
		mainMass->addMap(world);
	}

	int flag = 0;
	int  * rows=&flag;

	while (getscore(rows))
	{
		++score;

		for (int i = 0; i < 16; ++i)
		{
			int j = flag;
			while (j<29)
			{
				world[j][i] = world[j + 1][i];
				++j;
			}
	//		log("test1");
		}

	}

	mainMass->init();

	mainMass->drawMass(draw, origin);
	
	for (int i = 0; i<30; ++i)
	{
		for (int j = 0; j<16; ++j)
		{
			if (world[i][j] == 1)
			{
				int newX = origin.x + 4 * Block::width + j*Block::width;
				int newY = origin.y + 4 * Block::width + i*Block::width;;

				Vec2 * vp=new Vec2[4];

				vp[0] = Vec2(newX, newY);
				vp[1] = Vec2(newX + Block::width, newY);
				vp[2] = Vec2(newX + Block::width, newY + Block::width);
				vp[3] = Vec2(newX, newY + Block::width);
				
				draw->drawPolygon(vp, 4, Color4F(1, 0, 0, 1), 1, Color4F(0, 1, 0, 1));
			}
		}
	}
	 	
	
	std::string s = "SCORE:";
	std::stringstream ss;
	ss << s << score;
	label2->setString(ss.str());
}

void GameScene::replaceSceneCallback(cocos2d::Ref * pSender)
{
	auto scene = HelloWorld::createScene();
	auto director = Director::getInstance();
	director->replaceScene(scene);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

bool GameScene::getscore(int * rows)
{
	for (int j = 0; j < 30; ++j)
	{
		int sum = 0;
		for (int i = 0;	i < 16; ++i)
		{
			sum += world[j][i];
		}
		if (sum == 16)
		{
			*rows = j;
			return true;
		}	
	}
	return false;
}
