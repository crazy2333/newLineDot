#include "Mass.h"
#include "Block.h"
#include <iostream>
#include <time.h>

USING_NS_CC;

#define t2data(_TYPE_) for (int i = 0; i < 4; ++i) { for (int j = 0; j < 4; ++j) { data[i][j] = _TYPE_[i][j]; } } 


Mass::Mass()
{
	srand(time(NULL));
	type = rand() % 7;


//	type = 2;
	turn = 0;

	x = 8;
	y = 30;

//	data[4][4] = { 0 };
}

void Mass::init()
{

	if (type == 0)
	{
		int tdata[4][4] = { 0,0,0,0, 0,1,1,0 , 0,1,1,0 , 0,0,0,0 };
		t2data(tdata)
	}
	else if (type == 1)
	{
		if(turn==0||turn==2)
		{
			int tdata[4][4] = { 0,0,1,0, 0,0,1,0 , 0,0,1,0 , 0,0,1,0 };
			t2data(tdata)
		}
		else if (turn == 1||turn==3)
		{
			int tdata[4][4] = { 0,0,0,0, 0,0,0,0 , 1,1,1,1 , 0,0,0,0 };
			t2data(tdata)
		}
		
	}
	else if (type == 2)
	{
		if (turn == 0) 
		{
			int tdata[4][4] = { 0,0,0,0, 0,0,1,0 , 0,0,1,0 , 0,1,1,0 };
			t2data(tdata)	
		}
		else if (turn == 1)
		{
			int tdata[4][4] = { 0,0,0,0, 0,0,0,0 , 0,1,1,1 , 0,0,0,1 };
			t2data(tdata)
		}
		else if (turn == 2) 
		{
			int tdata[4][4] = { 0,0,0,0, 0,0,1,1 , 0,0,1,0 , 0,0,1,0 };
			t2data(tdata)
		}
		else if (turn == 3)
		{
			int tdata[4][4] = { 0,0,0,0, 0,1,0,0 , 0,1,1,1 , 0,0,0,0 };
			t2data(tdata)

		}
	}
	else if (type == 3)
	{
		if (turn == 0)
		{
			int tdata[4][4] = { 0,0,0,0, 0,0,1,0 , 0,0,1,0 , 0,0,1,1 };
			t2data(tdata)
		}
		else if (turn == 1)
		{
			int tdata[4][4] = { 0,0,0,0, 0,0,0,1 , 0,1,1,1 , 0,0,0,0 };
			t2data(tdata)
		}
		else if (turn == 2)
		{
			int tdata[4][4] = { 0,0,0,0, 0,1,1,0 , 0,0,1,0 , 0,0,1,0 };
			t2data(tdata)
		}
		else if (turn == 3)
		{
			int tdata[4][4] = { 0,0,0,0, 0,0,0,0 , 0,1,1,1 , 0,1,0,0 };
			t2data(tdata)
		}
	}
	else if (type == 4)
	{
		if (turn == 0|| turn == 2)
		{
			int tdata[4][4] = { 0,0,0,0, 0,0,1,0 , 0,1,1,0 , 0,1,0,0 };
			t2data(tdata)
		}
		else if (turn == 1|| turn == 3)
		{
			int tdata[4][4] = { 0,0,0,0, 0,0,0,0 , 0,1,1,0 , 0,0,1,1 };
			t2data(tdata)
		}
		
	}
	else if (type == 5)
	{
		if (turn == 0 || turn == 2)
		{
			int tdata[4][4] = { 0,0,0,0, 0,0,1,0 , 0,0,1,1 , 0,0,0,1 };
			t2data(tdata)
		}
		else if (turn == 1 || turn == 3)
		{
			int tdata[4][4] = { 0,0,0,0, 0,0,0,0 , 0,0,1,1 , 0,1,1,0 };
			t2data(tdata)
		}

	}
	else if (type == 6)
	{
		if (turn == 0)
		{
			int tdata[4][4] = { 0,0,0,0, 0,0,0,0 , 0,1,1,1 , 0,0,1,0 };
			t2data(tdata)
		}
		else if (turn == 1)
		{
			int tdata[4][4] = { 0,0,0,0, 0,0,1,0 , 0,0,1,1 , 0,0,1,0 };
			t2data(tdata)
		}
		else if (turn == 2)
		{
			int tdata[4][4] = { 0,0,0,0, 0,0,1,0 , 0,1,1,1 , 0,0,0,0 };
			t2data(tdata)
		}
		else if (turn == 3)
		{
			int tdata[4][4] = { 0,0,0,0, 0,0,1,0 , 0,1,1,0 , 0,0,1,0 };
			t2data(tdata)
		}
	}
	else
	{
		int tdata[4][4] = { 0,0,0,0, 0,0,0,0 , 0,0,0,0 , 0,0,0,0 };
		t2data(tdata)
	}

}

bool Mass::drawMass(DrawNode * draw, cocos2d::Vec2 origin)
{

	for(int i=0;i<4;++i)
	{
		for (int j = 0; j<4; ++j)
		{
			if (data[i][j] == 1)
			{
				int newX= origin.x + 4 * Block::width + (x+j-2)*Block::width;
				int newY= origin.y + 4 * Block::width + (y+i-2)*Block::width;;

				draw->drawRect(Vec2(newX, newY), Vec2(newX + Block::width, newY), Vec2(newX + Block::width, newY + Block::width), Vec2(newX, newY + Block::width), Color4F(1, 0, 0, 1));

			}	
		}
	}



	return true;
}

bool Mass::turnR()
{
	turn++;

	if (turn == 4)
	{
		turn = 0;
	}

	return true;
}

bool Mass::moveL()
{
	x--;
	return true;
}

bool Mass::moveR()
{
	x++;
	return true;
}

bool Mass::quickD(int(*world)[16])
{
	while (this->check(world))
	{
		--y;
	}
	++y;
	return true;
}

bool Mass::check(int(*world)[16])
{
	
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (data[i][j] == 1) {
				
				--y;
				if (i + y - 2 < 0) { ++y; return false;}
				if (world[i + y - 2][j + x - 2] == 1)
				{
					++y;
					return false;
				}

				++y;				
			}

		}
	}
	
	return true;
}

bool Mass::checkL(int(*world)[16])
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (data[i][j] == 1) {

				--x;
				if (j + x - 2 < 0) { ++x; return false; }
				if (world[i + y - 2][j + x - 2] == 1)
				{
					++x;
					return false;
				}
				++x;
			}

		}
	}

	return true;
}

bool Mass::checkR(int(*world)[16])
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (data[i][j] == 1) {

				++x;
				if (j + x - 2 >= 16) { --x; return false; }
				if (world[i + y - 2][j + x - 2] == 1)
				{
					--x;
					return false;
				}
				--x;
			}

		}
	}

	return true;
}

bool Mass::checkT(int(*world)[16])
{
	turn++;

	this->init();

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (data[i][j] == 1) {
				
				if (world[i + y - 2][j + x - 2] == 1)
				{	
					turn--;
					return false;
				}
				if (j + x - 2 >= 16) { turn--; return false; }
				if (j + x - 2 < 0) { turn--; return false; }
			}
		}
	}

	turn--;

	return true;
}

bool Mass::addMap(int(*world)[16])
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (data[i][j] == 1) 
			{		
				world[i + y - 2][j + x - 2] = 1;	
			}

		}
	}

	return true;
}
