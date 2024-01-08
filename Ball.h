#pragma once
#include"collidable.h"
#include"gameConfig.h"
#include"auxil.h"
class game;
class Ball:public collidable
{
	point PrevUprlft;
	int Xinc = 20;
	int Yinc = 20;
	bool IsFireBall = false;
	char key;
public:
	
	bool bDragging = false;
	char cKeyData;
	keytype kType;
	Ball(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void ballMove(char& key);
	void collisionAction() override;
	void wallDeflect();
	void paddleDeflect();
	void resetBallcentre();
	void collidableDeflect(point& p);
	void FireBallON();
	void FireBallOF();
	bool GetIsFireBall();
	void Magnet();
	int getBallCenterY();
};

