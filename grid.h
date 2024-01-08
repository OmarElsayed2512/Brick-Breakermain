#pragma once
#include "drawable.h"
#include "Bricks.h"
#include"Paddle.h"

class game;

class grid:public drawable
{
	
			//2D array of brick pointers
	int c_rock = 0;
	int rows, cols;
public:
	brick*** brickMatrix;
	grid(point r_uprleft, int r_width, int r_height, game* r_pGame);
	~grid();
	void draw() const;
	int addBrick(BrickType brkType, point clickedPoint);
	/*int removeBrick(point clickedpoint);*/
	void removeBrick(int gridCellRowIndex, int gridCellColIndex);
	brick* getbrick(int x, int y);
	brick*** getBrickMatrix();
	void checkStrength();
	void inc_c_rock();
	void clearscreen();
};

