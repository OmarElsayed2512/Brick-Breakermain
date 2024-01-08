#pragma once

//This file contains all classes related to toolbar (toolbar icon classes & toolbar class itself)
#include "drawable.h"
#include<iostream>
using namespace std;

////////////////////////////////////////////////////  class toolbarIcon   ////////////////////////////////////////////////////
//Base class for all toolbar icons 
class toolbarIcon :public drawable
{
public:
	toolbarIcon(point r_uprleft, int r_width, int r_height, game* r_pGame);
    virtual void onClick()=0;   //The action that should be taken when this icon is clicked
};

////////////////////////////////////////////////////  class iconAddNormalBrick   //////////////////////////////////////////////
class iconAddNormalBrick :public toolbarIcon
{
public:
	iconAddNormalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick() ;
};
///////////////////////////////////////////////////// class iconAddBombBrick /////////////////////////////////////////////
class iconAddBombBrick :public toolbarIcon
{
public:
	iconAddBombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};
////////////////////////////////////////////////////  class iconAddRockBrick   //////////////////////////////////////////////
class iconAddRockBrick :public toolbarIcon
{
public:
	iconAddRockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};
////////////////////////////////////////////////////  class iconLifeBrick   //////////////////////////////////////////////
class iconAddLifeBrick :public toolbarIcon
{
public:
	iconAddLifeBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};
////////////////////////////////////////////////////  class iconAddHardBrick   //////////////////////////////////////////////
class iconAddHardBrick :public toolbarIcon
{
public:
	iconAddHardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};
////////////////////////////////////////////////////  class iconAddPRUPBrick   //////////////////////////////////////////////
class iconAddPRUPBrick :public toolbarIcon
{
public:
	iconAddPRUPBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};
//////////////////////////////////////////////////////  class iconAddPRDNBrick   //////////////////////////////////////////////
class iconAddPRDNBrick :public toolbarIcon
{
public:
	iconAddPRDNBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};
////////////////////////////////////////////////////  class DeleteBrickIcon   //////////////////////////////////////////////
class iconDeleteBrick : public toolbarIcon
{
public:
	iconDeleteBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};
////////////////////////////////////////////////////  class PauseIcon   //////////////////////////////////////////////
class iconPause : public toolbarIcon
{
public:
	iconPause(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};
////////////////////////////////////////////////////  class ContinueIcon   //////////////////////////////////////////////
class iconContinue : public toolbarIcon
{
public:
	iconContinue(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};

////////////////////////////////////////////////////  class PlayIcon   //////////////////////////////////////////////
class iconPlay : public toolbarIcon
{
public:
	iconPlay(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};

////////////////////////////////////////////////////  class LoadIcon   //////////////////////////////////////////////
class iconLoad : public toolbarIcon
{
public:
	iconLoad(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};

////////////////////////////////////////////////////  class SaveIcon   //////////////////////////////////////////////
class iconSave : public toolbarIcon
{
public:
	iconSave(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};

////////////////////////////////////////////////////  class StopIcon   //////////////////////////////////////////////
class iconStop : public toolbarIcon
{
public:
	iconStop(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};

////////////////////////////////////////////////////  class iconExit   //////////////////////////////////////////////
class iconExit :public toolbarIcon
{
public:
	iconExit(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};
////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
class toolbar:public drawable
{

	enum ICONS //The icons of the toolbar (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		ICON_ADD_NORM,	//add normal brick

		ICON_ADD_BOMB,	//add bomb brick

		ICON_ADD_ROCK,	//add rock brick

		ICON_ADD_HARD,	//add hard brick

		ICON_ADD_LIFE,  //add life Brick

		ICON_ADD_PRUP, //add power-up brick

		ICON_ADD_PRDN, //add power-down brick

		ICON_PAUSE, //pause game

		ICON_CONTINUE, //continue game

		ICON_DEL_BRICK, //delete brick

		ICON_STOP, //Stop game

		ICON_SAVE, //Save game

		ICON_LOAD, //Load game

		ICON_PLAY, //Play game

		ICON_EXIT, //Exit icon

		ICON_COUNT //no. of menu icons ==> This should be the last line in this enum

	};

private:
    toolbarIcon** iconsList; //an array of toolbarIcon pointers
	string iconsImages[ICON_COUNT];
	game* pGame;

public:
	toolbar(point r_uprleft, int r_width, int r_height, game* r_pGame);
	~toolbar();
    void draw() const;
	bool handleClick(int x, int y);	//handles clicks on toolbar icons, returns true if exit is clicked
};

