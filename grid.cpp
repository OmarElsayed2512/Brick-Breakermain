#include "grid.h"
#include "gameConfig.h"
#include"game.h"
grid::grid(point r_uprleft, int wdth, int hght, game* pG):
	drawable(r_uprleft, wdth, hght, pG)
{

	rows = height / config.brickHeight;
	cols = width / config.brickWidth;

	brickMatrix = new brick ** [rows];
	for (int i = 0; i < rows; i++)
		brickMatrix[i] = new brick * [cols];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			brickMatrix[i][j] = nullptr;

}

grid::~grid()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (brickMatrix[i][j])
				delete brickMatrix[i][j];	//delete all allocated bricks

	for (int i = 0; i < rows; i++)
		delete brickMatrix[i];

	delete brickMatrix;

}

void grid::draw() const
{
	window* pWind = pGame->getWind();
	//draw lines showing the grid
	pWind->SetPen(config.gridLinesColor,1);

	//draw horizontal lines
	for (int i = 0; i < rows; i++) {
		int y = uprLft.y + (i + 1) * config.brickHeight;
		pWind->DrawLine(0, y, width, y);
	}
	//draw vertical lines
	for (int i = 0; i < cols; i++) {
		int x = (i + 1) * config.brickWidth;
		pWind->DrawLine(x, uprLft.y, x, uprLft.y+ rows* config.brickHeight);
	}

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (brickMatrix[i][j])
				brickMatrix[i][j]->draw();	//draw exisiting bricks


}

int grid::addBrick(BrickType brkType, point clickedPoint)
{
	//From the clicked point, find out the index (row,col) of the corrsponding cell in the grid
	int gridCellRowIndex = (clickedPoint.y - uprLft.y) / config.brickHeight;
	int gridCellColIndex = clickedPoint.x / config.brickWidth;

	//TODO:
	// 1- Check that the clickedPoint is within grid range (and return -1)
	if (clickedPoint.y < uprLft.y || clickedPoint.y >= uprLft.y + rows * config.brickHeight)
		return -1;
	// 2- Check that the clickedPoint doesnot overlap with an exisiting brick (return 0)
	if (brickMatrix[gridCellRowIndex][gridCellColIndex] != nullptr)
		return 0;

	//Here we assume that the above checks are passed
	

	//Now, align the upper left corner of the new brick with the corner of the clicked grid cell
	point newBrickUpleft;
	newBrickUpleft.x = uprLft.x + gridCellColIndex * config.brickWidth;
	newBrickUpleft.y = uprLft.y+ gridCellRowIndex * config.brickHeight;

	switch (brkType)
	{
	case BRK_NRM:	//The new brick to add is Normal Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new normalBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_LIFE:	//The new brick to add is Life Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new LifeBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_BMB:	//The new brick to add is Bomb Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new bombBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_Rock:	//The new brick to add is Rock Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new rockBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_HRD:	//The new brick to add is Hard Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new hardBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_PRUP: //The new brick to add is Power Up Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new powerupBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_PRDN: //The new brick to add is Power down Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new powerdownBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	}
	
	return 1;
}

brick* grid::getbrick(int x, int y)
{
	return brickMatrix[x][y];
}

void grid::removeBrick(int gridCellRowIndex, int gridCellColIndex)
{
	point Pin;
	point Pfi;
	Pin.x = gridCellColIndex * config.brickWidth;
	Pin.y = config.toolBarHeight + (gridCellRowIndex * config.brickHeight);
	window* pWind = pGame->getWind();
	if (brickMatrix[gridCellRowIndex][gridCellColIndex] != nullptr) {
			delete brickMatrix[gridCellRowIndex][gridCellColIndex];
		brickMatrix[gridCellRowIndex][gridCellColIndex] = nullptr;
		pWind->SetPen(config.bkGrndColor);
		pWind->SetBrush(config.bkGrndColor);
		pWind->DrawRectangle(Pin.x, Pin.y, Pin.x + config.brickWidth, Pin.y + config.brickHeight, FILLED);
	}
}

brick*** grid::getBrickMatrix()
{
	return brickMatrix;
}

void grid::checkStrength()
{
	int c = 0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (brickMatrix[i][j] != nullptr) {
				if (brickMatrix[i][j]->currstrength <= 0) {
					removeBrick(i, j);
					c++;
				}
			}
	if ((c + c_rock) == rows * cols) {

	}
}

void grid::inc_c_rock()
{
	c_rock++;
}

void grid::clearscreen()
{
	pGame->stopgame();
}