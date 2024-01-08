#pragma once

//This file contains all classes bricks classes 
#include "collidable.h"
#include<cstdlib>
#include<time.h>

enum BrickType	//add more brick types
{
	BRK_NRM,	//Normal Brick
	BRK_LIFE,   //Life Brick
	BRK_HRD,	//Hard Brick
	BRK_BMB,    // Bomb Brick
	BRK_Rock,    // Rock Brick
	BRK_PRUP,	// Powerup Brick
	BRK_PRDN	// Powerdown Brick
};

////////////////////////////////////////////////////  class brick  ///////////////////////////////////////
//Base class for all bricks
class brick :public collidable
{
public:
	int currstrength;
	BrickType type;
	brick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	int getBrickType();
};

//class game;
////////////////////////////////////////////////////  class normalBrick  /////////////////////////////////
class normalBrick :public brick
{
	const int NStrength = 1;
public:
	normalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction() override;
	
};
////////////////////////////////////////////////////  class LifeBrick  /////////////////////////////////
class LifeBrick :public brick
{
	const int LStrength = 1;
public:
	LifeBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction() override;

};
////////////////////////////////////////////////////  class bombBrick  /////////////////////////////////
class bombBrick :public brick
{
	const int BStrength = 1;
public:
	bombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction() override;
};

////////////////////////////////////////////////////  class rockBrick  /////////////////////////////////
class rockBrick :public brick
{
	const int RStrength = 1000;
public:
	rockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction() override;
};

////////////////////////////////////////////////////  class hardBrick  /////////////////////////////////
class hardBrick :public brick
{
	const int HStrength=3;
public:
	hardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction() override;
};

////////////////////////////////////////////////////  class powerupBrick  /////////////////////////////////
class powerupBrick :public brick
{
public:
	powerupBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction() override;
};

//////////////////////////////////////////////////////  class powerdownBrick  /////////////////////////////////
class powerdownBrick :public brick
{
public:
	powerdownBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction() override;
};



