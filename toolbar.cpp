#include "toolbar.h"
#include "game.h"
#include "grid.h"
#include "gameConfig.h"
#include<fstream>

////////////////////////////////////////////////////  class toolbarIcon   ////////////////////////////////////////////////////
toolbarIcon::toolbarIcon(point r_uprleft, int r_width, int r_height, game* r_pGame):
	drawable(r_uprleft, r_width, r_height,  r_pGame)
{}

////////////////////////////////////////////////////  class iconAddNormalBrick   //////////////////////////////////////////////
iconAddNormalBrick::iconAddNormalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame):
	toolbarIcon(r_uprleft, r_width, r_height,  r_pGame)
{}
void iconAddNormalBrick::onClick()
{
	
	pGame->printMessage("Click on empty cells to add Normal Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_NRM, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");
}
////////////////////////////////////////////////////  class iconAddBombBrick   //////////////////////////////////////////////
iconAddBombBrick::iconAddBombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddBombBrick::onClick()
{
	pGame->printMessage("Click on empty cells to add Bomb Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_BMB, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");
}

////////////////////////////////////////////////////  class iconAddRockBrick   //////////////////////////////////////////////
iconAddRockBrick::iconAddRockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddRockBrick::onClick()
{
	pGame->printMessage("Click on empty cells to add Rock Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_Rock, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");
}
////////////////////////////////////////////////////  class iconAddLifeBrick   //////////////////////////////////////////////
iconAddLifeBrick::iconAddLifeBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}
void iconAddLifeBrick::onClick()
{

	pGame->printMessage("Click on empty cells to add Life Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_LIFE, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");
}

////////////////////////////////////////////////////  class iconAddHardBrick   //////////////////////////////////////////////
iconAddHardBrick::iconAddHardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddHardBrick::onClick()
{
	pGame->printMessage("Click on empty cells to add Hard Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_HRD, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");
}
////////////////////////////////////////////////////  class iconAddPRUPBrick   //////////////////////////////////////////////
iconAddPRUPBrick::iconAddPRUPBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddPRUPBrick::onClick()
{
	pGame->printMessage("Click on empty cells to add Power Up Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_PRUP, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");
}
////////////////////////////////////////////////////  class iconAddPRDNBrick   //////////////////////////////////////////////
iconAddPRDNBrick::iconAddPRDNBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddPRDNBrick::onClick()
{
	pGame->printMessage("Click on empty cells to add Power Down Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_PRDN, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");
}
////////////////////////////////////////////////////  class DeleteBrickIcon   //////////////////////////////////////////////
iconDeleteBrick::iconDeleteBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconDeleteBrick::onClick()
{
	// TO DO: Write onClick action of Delete Brick button
	pGame->printMessage("Click on filled cells to remove Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		int gridCellRowIndex = (clicked.y - config.toolBarHeight) / config.brickHeight;
		int gridCellColIndex = clicked.x / config.brickWidth;
		grid* pGrid = pGame->getGrid();
		pGrid->removeBrick(gridCellRowIndex, gridCellColIndex);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");
	
}
////////////////////////////////////////////////////  class PauseIcon   //////////////////////////////////////////////
iconPause::iconPause(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconPause::onClick()
{
	pGame->setPause(true);
}
////////////////////////////////////////////////////  class ContinueIcon   //////////////////////////////////////////////
iconContinue::iconContinue(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconContinue::onClick()
{
	pGame->setPause(false);
}

///////////////////////////////////////////////////  class PlayIcon   ////////////////////////////////////////////////
iconPlay::iconPlay(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconPlay::onClick()
{
	pGame->drawPaddleBall();
	pGame->playMode();
}

///////////////////////////////////////////////////  class LoadIcon   ////////////////////////////////////////////////
iconLoad::iconLoad(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconLoad::onClick()
{
	fstream file;
	grid* gameGrid = pGame->getGrid();
	brick*** brickMatrix = gameGrid->getBrickMatrix();
	int rows = config.gridHeight / config.brickHeight;
	int cols = config.windWidth / config.brickWidth;
	point Pin;
	point Pfi;
	
	window* pWind = pGame->getWind();
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (brickMatrix[i][j] != nullptr) {
				Pin.x = j * config.brickWidth;
				Pin.y = config.toolBarHeight + (i * config.brickHeight);
				delete brickMatrix[i][j];
				brickMatrix[i][j] = nullptr;
				pWind->SetPen(config.bkGrndColor);
				pWind->SetBrush(config.bkGrndColor);
				pWind->DrawRectangle(Pin.x, Pin.y, Pin.x + config.brickWidth, Pin.y + config.brickHeight, FILLED);
			}
	gameGrid->draw();
	
	int rowi, coli, typi;
	file.open("Saved\\test.txt", ios::in);
	if (!file)
		cout << "open failure";
	else
	{
		while (file >> rowi >> coli >> typi)
		{
			point p;
			p.x = coli * config.brickWidth;
			p.y = config.toolBarHeight + (rowi * config.brickHeight);
			if (typi == 1)
				brickMatrix[rowi][coli] = new normalBrick(p, config.brickWidth, config.brickHeight, pGame);
			if (typi == 2)
				brickMatrix[rowi][coli] = new bombBrick(p, config.brickWidth, config.brickHeight, pGame);
			if (typi == 3)
				brickMatrix[rowi][coli] = new hardBrick(p, config.brickWidth, config.brickHeight, pGame);
			if (typi == 4)
				brickMatrix[rowi][coli] = new rockBrick(p, config.brickWidth, config.brickHeight, pGame);
			if (typi == 5)
				brickMatrix[rowi][coli] = new LifeBrick(p, config.brickWidth, config.brickHeight, pGame);
			if (typi == 6)
				brickMatrix[rowi][coli] = new powerupBrick(p, config.brickWidth, config.brickHeight, pGame);
			if (typi == 7)
				brickMatrix[rowi][coli] = new powerdownBrick(p, config.brickWidth, config.brickHeight, pGame);
			brickMatrix[rowi][coli]->draw();
		}
	}
	file.close();
}

///////////////////////////////////////////////////  class SaveIcon   ////////////////////////////////////////////////
iconSave::iconSave(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconSave::onClick()
{
	fstream file;
	int gridCellRowIndex = config.gridHeight / config.brickHeight;
	int gridCellColIndex = config.windWidth / config.brickWidth;
	grid* gameGrid = pGame->getGrid();
	brick*** brickMatrix = gameGrid->getBrickMatrix();
	file.open("Saved\\test.txt", ios::out);
	if (!file)
		cout << "open failure";
	else
	{
		for (int i = 0; i < gridCellRowIndex; i++)
			for (int j = 0; j < gridCellColIndex; j++)
				if (brickMatrix[i][j] != nullptr)
					file << i << "\t" << j << "\t" << brickMatrix[i][j]->getBrickType() << endl;
	}
	file.close();
}

///////////////////////////////////////////////////  class StopIcon   ////////////////////////////////////////////////
iconStop::iconStop(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconStop::onClick()
{
	pGame->stopgame();
}

////////////////////////////////////////////////////  class iconExit   //////////////////////////////////////////////
iconExit::iconExit(point r_uprleft, int r_width, int r_height, game* r_pGame):
	toolbarIcon(r_uprleft, r_width, r_height,  r_pGame)
{}

void iconExit::onClick()
{
	//TO DO: add code for cleanup and game exit here
}


////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
toolbar::toolbar(point r_uprleft, int wdth, int hght, game* pG):
	drawable(r_uprleft, wdth, hght, pG)
{	
	
	height = hght;
	pGame = pG;

	//First prepare List of images for each icon
	//To control the order of these images in the menu, reoder them in enum ICONS above	
	iconsImages[ICON_ADD_NORM] = "images\\ToolbarIcons\\NormalBrickIcon.jpg";
	iconsImages[ICON_ADD_BOMB] = "images\\ToolbarIcons\\BombBrickIcon.jpg";
	iconsImages[ICON_ADD_ROCK] = "images\\ToolbarIcons\\RockBrickIcon.jpg";
	iconsImages[ICON_ADD_HARD] = "images\\ToolbarIcons\\HardBrickIcon.jpg";
	iconsImages[ICON_ADD_LIFE] = "images\\ToolbarIcons\\LifeBrickIcon.jpg";
	iconsImages[ICON_ADD_PRUP] = "images\\ToolbarIcons\\PowerupBrickIcon.jpg";
	iconsImages[ICON_ADD_PRDN] = "images\\ToolbarIcons\\PowerdownBrickIcon.jpg";
	iconsImages[ICON_PAUSE] = "images\\ToolbarIcons\\Pause.jpg";
	iconsImages[ICON_CONTINUE] = "images\\ToolbarIcons\\ContinueIcon.jpg";
	iconsImages[ICON_DEL_BRICK] = "images\\ToolbarIcons\\DeleteBrickIcon.jpg";
	iconsImages[ICON_STOP] = "images\\ToolbarIcons\\StopIcon.jpg";
	iconsImages[ICON_SAVE] = "images\\ToolbarIcons\\SaveIcon.jpg";
	iconsImages[ICON_LOAD] = "images\\ToolbarIcons\\LoadIcon.jpg";
	iconsImages[ICON_PLAY] = "images\\ToolbarIcons\\PlayIcon.jpg";
	iconsImages[ICON_EXIT] = "images\\ToolbarIcons\\ExitIcon.jpg";


	point p;
	p.x = 0;
	p.y = 0;

	iconsList = new toolbarIcon* [ICON_COUNT];

	//For each icon in the tool bar
	//	1- Create an object setting its upper left corner, width and height
	iconsList[ICON_ADD_NORM] = new iconAddNormalBrick(p, config.iconWidth, height, pGame);
	p.x+= config.iconWidth;
	iconsList[ICON_ADD_BOMB] = new iconAddBombBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ADD_ROCK] = new iconAddRockBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ADD_HARD] = new iconAddHardBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ADD_LIFE] = new iconAddLifeBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ADD_PRUP] = new iconAddPRUPBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ADD_PRDN] = new iconAddPRDNBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_PAUSE] = new iconPause(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_CONTINUE] = new iconContinue(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_DEL_BRICK] = new iconDeleteBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_STOP] = new iconStop(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_SAVE] = new iconSave(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_LOAD] = new iconLoad(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_PLAY] = new iconPlay(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_EXIT] = new iconExit(p, config.iconWidth, height, pGame);

	//	2-Set its image (from the above images list)
	for (int i = 0; i < ICON_COUNT; i++)
	{
		iconsList[i]->setImageName(iconsImages[i]);

	}
}

toolbar::~toolbar()
{
	for (int i = 0; i < ICON_COUNT; i++)
		delete iconsList[i];
	delete iconsList;
}

void toolbar::draw() const
{
	for (int i = 0; i < ICON_COUNT; i++)
		iconsList[i]->draw();
	window* pWind = pGame->getWind();
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, height, pWind->GetWidth(), height);

}

//handles clicks on toolbar icons, returns true if exit is clicked
bool toolbar::handleClick(int x, int y)
{
	if (x > ICON_COUNT * config.iconWidth)	//click outside toolbar boundaries
		return false;
	
	
	//Check whick icon was clicked
	//==> This assumes that menu icons are lined up horizontally <==
	//Divide x coord of the point clicked by the icon width (int division)
	//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

	int clickedIconIndex = (x / config.iconWidth);
	iconsList[clickedIconIndex]->onClick();	//execute onClick action of clicled icon

	if (clickedIconIndex == ICON_EXIT) return true;	
	
	return false;


}


