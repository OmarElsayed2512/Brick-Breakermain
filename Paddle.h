#pragma once
#include"collidable.h"
#include"gameConfig.h"
#include"Ball.h"
#include"auxil.h"
class Paddle:public collidable
{
	char cKeyData;
	keytype kType;
	bool IsWide = true;
	int paddleWidth = config.paddleWidth;
public:
	void ChangeWidth();
	int getWidth();
	void setWidth(int x);
	Paddle(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void movePaddle(char& key);
	void movePaddleWind(char& key);
	void movePaddleReverse(char& key);
	void collisionAction() override;
	void resetPaddlecenter();
};

