#pragma once
#include "CMUgraphicsLib/CMUgraphics.h"

__declspec(selectany) //This line to prevent "redefinition error"
struct 		//contains all game configurations (MAY be loaded from a configuration file later)
{
	int	windWidth=1200, windHeight=600,	//Window width and height
		wx=5, wy=5,			//Window starting coordinates

		//The window is divded into 4 areas: toolbar, bricks grid area, paddle area, statusbar
		toolBarHeight=40,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		statusBarHeight=50;	//Status Bar Height
	
	int remainingHeight = windHeight - toolBarHeight - statusBarHeight;

	int gridHeight = int(remainingHeight * (2 / 3.0)); 		//The grid is where bricks can be drawn
	int paddleAreaHeight = remainingHeight - gridHeight;	//The area dedicated for paddle

	color	penColor = BLUE,			//color used to draw lines/write messages
			bkGrndColor= LAVENDER,		//Background color
			statusBarColor = LIGHTSEAGREEN;	//background color of the status
	int penWidth=3;			//width of the pen that draws shapes


	int brickWidth = 60;
	int brickHeight = 30;
	color gridLinesColor = WHITE;


	int	iconWidth=70;			//Width of each icon in toolbar
	int inPaddleX = 535;	//Initial paddle position
	int inPaddleY = 450;	//Initial paddle position
	int paddleWidth = 150;		//Paddle width
	int paddleHeight = 25;		//Paddle height

	int ballWidth = 50;		//Ball width
	int ballHeight = 50;		//ball height

	int inBallx = windWidth / 2;
	int inBally=420;
	int BallRad = 10;

	int nrm_brickscore = 1;
	int hrd_brickscore = 3;

	int collectableWidth = 60;
	int collectableHeight = 20;

	int WidePaddleWidth = 210;   //wide paddle width    
	int NarrowPaddleWidth = 75;  //narrow paddle width

}config;
