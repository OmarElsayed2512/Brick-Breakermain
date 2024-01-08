#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "toolbar.h"
#include"Ball.h"
#include"Wall.h"
#include"Collectable.h"
#include"Paddle.h"

//Declaring the Paddle and Ball of the game

//Declaring gameScore, gameLives, gameTime
//int gameScore;
//int gameLives;
//int gameTime;
//Main class that coordinates the game operation
class game
{
	

	enum MODE	//Game mode
	{
		MODE_DSIGN,	//Desing mode (startup mode)
		MODE_PLAY	//Playing mode
	};

	MODE gameMode;

	/// Add more members if needed

	bool isPause = true;
	
	window* pWind;	//Pointer to the CMU graphics window
	toolbar* gameToolbar;
	grid* bricksGrid;

	Paddle* gamePaddle; //Game Paddle
	Ball* gameBall; //Game Ball
	Collectable* gameColl[8]; //Game Colectable items

	int rows = config.gridHeight / config.brickHeight;
	int cols = config.windWidth / config.brickWidth;
public:

	int gameScore = 0;
	int gameLives = 3;
	int gameMin = 0;
	int gameSec = 0;

	game();
	~game();

	clicktype getMouseClick(int& x, int& y) const;//Get coordinate where user clicks and returns click type (left/right)
	keytype getKeyPress(char& cKey) const; //Get the key press the user presses on the keyboard from enum keytype
	string getSrting() const;	 //Returns a string entered by the user

	window* CreateWind(int, int, int, int) const; //creates the game window

	void clearStatusBar() const;	//Clears the status bar

	void printMessage(string msg) const;	//Print a message on Status bar

	void go();

	window* getWind() const;		//returns a pointer to the graphics window

	grid* getGrid() const;

	void stopgame();

	Ball* getBall();

	Paddle* getPaddle();

	void setBall(Ball* p);

	void setPaddle(Paddle* p);

	void playMode();

	void designMode();

	void drawPaddleBall();

	bool getPause();

	void setPause(bool x);

	toolbar* getToolBar();

	void status();

	void drawCollectable(int x, point p);

	void gameCollectableMove(int x);

	void CheckBallPosition();
};