#include "game.h"
#include "gameConfig.h"
#include "ball.h"
#include "CMUgraphicsLib/auxil.h"
#include "keyqueue.h"

game::game()
{
	//Initialize playgrond parameters
	gameMode = MODE_DSIGN;


	//Create the main window
	pWind = CreateWind(config.windWidth, config.windHeight, config.wx, config.wy);

	//Create and draw the toolbar
	point toolbarUpperleft;
	toolbarUpperleft.x = 0;
	toolbarUpperleft.y = 0;

	gameToolbar = new toolbar(toolbarUpperleft,0,config.toolBarHeight, this);
	gameToolbar->draw();

	//Create and draw the grid
	point gridUpperleft;
	gridUpperleft.x = 0;
	gridUpperleft.y = config.toolBarHeight;
	bricksGrid = new grid(gridUpperleft, config.windWidth, config.gridHeight, this);
	bricksGrid->draw();
	
	//Construct pointer to Paddle
	point paddleUpperleft;
	paddleUpperleft.x = config.inPaddleX;
	paddleUpperleft.y = config.inPaddleY;
	/*gamePaddle->setWidth(config.paddleWidth);*/
	gamePaddle = new Paddle(paddleUpperleft,config.paddleWidth, config.paddleHeight, this);

	//Contruct pointer to Ball
	point ballUpperleft;
	ballUpperleft.x = config.inBallx;
	ballUpperleft.y = config.inBally;
	gameBall = new Ball(ballUpperleft, 20, 20, this);

	clearStatusBar();
}

game::~game()
{
	delete pWind;
	delete gameToolbar;
	delete bricksGrid;
	delete gameBall;
	delete gamePaddle;
}


clicktype game::getMouseClick(int& x, int& y) const
{
	return pWind->WaitMouseClick(x, y);	//Wait for mouse click
}


keytype game::getKeyPress(char &cKey) const
{
	return pWind->GetKeyPress(cKey); //Wait for a key press
}


//////////////////////////////////////////////////////////////////////////////////////////
window* game::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(config.bkGrndColor);
	pW->SetPen(config.bkGrndColor, 1);
	pW->DrawRectangle(0, 0, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void game::clearStatusBar() const
{
	//Clear Status bar by drawing a filled rectangle
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////

void game::printMessage(string msg) const	//Prints a message on status bar
{
	clearStatusBar();	//First clear the status bar

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - (int)(0.85 * config.statusBarHeight), msg);
}



window* game::getWind() const		//returns a pointer to the graphics window
{
	return pWind;
}



string game::getSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		printMessage(Label);
	}
}

grid* game::getGrid() const
{
	// TODO: Add your implementation code here.
	return bricksGrid;
}

void game::stopgame()
{
	designMode();
	setPause(true);
	gameBall->resetBallcentre();
	gamePaddle->resetPaddlecenter();
	pWind->SetPen(LAVENDER);
	pWind->SetBrush(LAVENDER);
	pWind->DrawRectangle(config.inBallx, config.inBally, config.inBallx+2*config.BallRad, config.inBally + 2 * config.BallRad);
	pWind->DrawRectangle(config.inPaddleX,config.inPaddleY,config.inPaddleX+config.paddleWidth,config.inPaddleY+config.paddleHeight);
}

//Ball pointer accessor
Ball* game::getBall()
{
	return gameBall;
}

//Paddle pointer accessor
Paddle* game::getPaddle()
{
	return gamePaddle;
}
//Ball setter
void game::setBall(Ball* p)
{
	p = gameBall;
}
//Paddle setter
void game::setPaddle(Paddle* p)
{
	p = gamePaddle;
}
//gameMode setters
void game::playMode()
{
	gameMode = MODE_PLAY;
}
void game::designMode()
{
	gameMode = MODE_DSIGN;
}
//Drawing the paddle and ball
void game::drawPaddleBall()
{
	gameBall->draw();
	gamePaddle->draw();
}
//Ball Pause state getter
bool game::getPause()
{
	return isPause;
}
//Ball Pause state setter
void game::setPause(bool x)
{
	isPause = x;
}
toolbar* game::getToolBar()
{
	return gameToolbar;
}
void game::status()
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(KHAKI);
	pWind->DrawString((config.windWidth - config.windWidth * 0.19), config.windHeight - config.statusBarHeight + config.windWidth * 0.008, "Score: ");
	pWind->DrawInteger(config.windWidth - config.windWidth * 0.13, config.windHeight - config.statusBarHeight + config.windWidth * 0.008, gameScore);
	pWind->DrawString((config.windWidth - config.windWidth * 0.10), config.windHeight - config.statusBarHeight + config.windWidth * 0.008, "Lives: ");
	pWind->DrawInteger(config.windWidth - config.windWidth * 0.05, config.windHeight - config.statusBarHeight + config.windWidth * 0.008, gameLives);
	pWind->DrawString((config.windWidth - config.windWidth * 0.30), config.windHeight - config.statusBarHeight + config.windWidth * 0.008, "Timer: ");
	pWind->DrawInteger(config.windWidth - config.windWidth * 0.24, config.windHeight - config.statusBarHeight + config.windWidth * 0.008, gameMin);
	pWind->DrawString((config.windWidth - config.windWidth * 0.23), config.windHeight - config.statusBarHeight + config.windWidth * 0.008, " : ");
	pWind->DrawInteger(config.windWidth - config.windWidth * 0.21, config.windHeight - config.statusBarHeight + config.windWidth * 0.008, gameSec);
}

void game::drawCollectable(int x,point p)
{
	switch (x) {
	case 0:
		gameColl[x] = new Fireball(p, config.collectableWidth, config.collectableHeight, this);
		gameColl[x]->draw();
		break;
	case 1:
		gameColl[x] = new Windglide(p, config.collectableWidth, config.collectableHeight, this);
		gameColl[x]->draw();
		break;
	case 2:
		gameColl[x] = new Widepaddle(p, config.collectableWidth, config.collectableHeight, this);
		gameColl[x]->draw();
		break;
	case 3:
		gameColl[x] = new Narrowpaddle(p, config.collectableWidth, config.collectableHeight, this);
		gameColl[x]->draw();
		break;
	case 4:
		gameColl[x] = new Magnet(p, config.collectableWidth, config.collectableHeight, this);
		gameColl[x]->draw();
		break;
	case 5:
		gameColl[x] = new Multipleball(p, config.collectableWidth, config.collectableHeight, this);
		gameColl[x]->draw();
		break;
	case 6:
		gameColl[x] = new Reverse(p, config.collectableWidth, config.collectableHeight, this);
		gameColl[x]->draw();
		break;
	case 7:
		gameColl[x] = new Quicksand(p, config.collectableWidth, config.collectableHeight, this);
		gameColl[x]->draw();
		break;
	}
}

void game::gameCollectableMove(int x)
{
	gameColl[x]->collectableMove();
}

void game::CheckBallPosition()
{
	if (gameBall->getBallCenterY() > config.inPaddleY) {
		if (gameLives > 0) {
			gameLives--;
		}
		else if (gameLives == 0) {
			stopgame();
		}
	}
}

////////////////////////////////////////////////////////////////////////
void game::go()
{
	//This function reads the position where the user clicks to determine the desired operation
	int x, y;
	bool isExit = false;
	char key;
	keytype kType;
	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - Brick Breaker (CIE202-project) - - - - - - - - - -");
	
	do
	{
		
		if (gameMode == MODE_DSIGN)		//Game is in the Desgin mode
		{
			printMessage("Ready...");
			getMouseClick(x, y);	//Get the coordinates of the user click
			//[1] If user clicks on the Toolbar
			if (y >= 0 && y < config.toolBarHeight)
			{
				isExit=gameToolbar->handleClick(x, y);
			}
		}
		else if (gameMode == MODE_PLAY) {
			printMessage("Play Mode");
			pWind->GetMouseClick(x, y);
			if (y >= 0 && y < config.toolBarHeight)
			{
				isExit = gameToolbar->handleClick(x, y);
			}
 			getKeyPress(key);
			if (key == ' ') {
				isPause = false;
			}
			if (!isPause) {
				status();
				gameBall->ballMove(key);
				gamePaddle->movePaddle(key);
				gamePaddle->collisionAction();
				for (int i = 0; i < rows; i++) {
					for (int j = 0; j < cols; j++) {
						if (bricksGrid->getbrick(i, j) != nullptr) {
							bricksGrid->getbrick(i, j)->collisionAction();
							bricksGrid->checkStrength();
						}
					}
				}
			}
		}
	} while (!isExit);
}