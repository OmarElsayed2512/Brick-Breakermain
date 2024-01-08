#pragma once
#include"collidable.h"
#include<time.h>
#include"Paddle.h"
//Declare the collectables base class

class game;
class Collectable:public collidable
{
	point PrevUprlft;
	int Xinc = 20;
	int Yinc = 20;
public:
	Collectable(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collectableMove();
};

//Declare the Power-Up Collectables
//////////////////////////////Class Fireball collectable/////////////////////////////
class Fireball :public Collectable {
public:
	Fireball(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction() override;
};

//////////////////////////////Class Windglide collectable/////////////////////////////
class Windglide :public Collectable {
	char key;
public:
	Windglide(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction() override;
};

//////////////////////////////Class Widepaddle collectable/////////////////////////////
class Widepaddle :public Collectable {
public:
	Widepaddle(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction() override;
};

//////////////////////////////Class Narrowpaddle collectable/////////////////////////////
class Narrowpaddle :public Collectable {
public:
	Narrowpaddle(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction() override;
};

//////////////////////////////Class Magnet collectable/////////////////////////////
class Magnet :public Collectable {
public:
	Magnet(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction() override;
};

//////////////////////////////Class Multipleball collectable/////////////////////////////
class Multipleball :public Collectable {
public:
	Multipleball(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction() override;
};

//////////////////////////////Class Reverse collectable/////////////////////////////
class Reverse :public Collectable {
	char key;
public:
	Reverse(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction() override;
};

//////////////////////////////Class Quicksand collectable/////////////////////////////
class Quicksand :public Collectable {
public:
	Quicksand(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction() override;
};