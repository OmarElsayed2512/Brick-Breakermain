#include "Bricks.h"
#include "grid.h"
#include"game.h"
#include<mmsystem.h>
#include<Windows.h>

#pragma comment(lib, "winmm.lib")

////////////////////////////////////////////////////  class brick  ///////////////////////////////////////
brick::brick(point r_uprleft, int r_width, int r_height, game* r_pGame):
	collidable(r_uprleft, r_width, r_height, r_pGame)
{

}

int brick::getBrickType()
{
    if (type == BRK_NRM) 
    {
        return 1;
    }
    if (type == BRK_BMB)
    {
        return 2;
    }
    if (type == BRK_HRD)
    {
        return 3;
    }
    if (type == BRK_Rock)
    {
        return 4;
    }
    if (type == BRK_LIFE)
    {
        return 5;
    }
    if (type == BRK_PRUP)
    {
        return 6;
    }
    if (type == BRK_PRDN)
    {
        return 7;
    }
    
}


////////////////////////////////////////////////////  class normalBrick  /////////////////////////////////
normalBrick::normalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame):
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	currstrength = NStrength;
	imageName = "images\\bricks\\NormalBrickIcon.jpg";
    type = BRK_NRM;
}

void normalBrick::collisionAction()
{
    if (checkCollision(pGame->getBall(), this).x!= -1 && checkCollision(pGame->getBall(), this).y != -1) {
        PlaySound(TEXT("Sounds\\NormalBrickSound.wav"), NULL, SND_FILENAME | SND_ASYNC);
        Ball* pball = pGame->getBall();
        pball->collidableDeflect(checkCollision(pGame->getBall(), this));    
        pball = nullptr;
        currstrength -= 1;
        pGame->gameScore+=NStrength;
    }
}
////////////////////////////////////////////////////  class LifeBrick  /////////////////////////////////
LifeBrick::LifeBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
    brick(r_uprleft, r_width, r_height, r_pGame)
{
    currstrength = LStrength;
    imageName = "images\\bricks\\LifeBrick.jpg";
    type = BRK_LIFE;
}

void LifeBrick::collisionAction()
{
    if (checkCollision(pGame->getBall(), this).x != -1 && checkCollision(pGame->getBall(), this).y != -1) {
        PlaySound(TEXT("Sounds\\LifeBrickSound.wav"), NULL, SND_FILENAME | SND_ASYNC);
        Ball* pball = pGame->getBall();
        pball->collidableDeflect(checkCollision(pGame->getBall(), this));
        pball = nullptr;
        currstrength -= 1;
        pGame->gameLives++;
        pGame->gameScore += LStrength;
    }
}
////////////////////////////////////////////////////  class bombBrick  /////////////////////////////////
bombBrick::bombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
    currstrength = BStrength;
    imageName = "images\\bricks\\BombBrick.jpg";
    type = BRK_BMB;
}

void bombBrick::collisionAction()
{
    //if (checkCollision(pGame->getBall(), this).x != -1 && checkCollision(pGame->getBall(), this).y != -1) {
    //    PlaySound(TEXT("Sounds\\BombBrickSound.wav"), NULL, SND_FILENAME | SND_ASYNC);
    //    pGame->gameScore += BStrength;
    //    int gridCellRowIndex = (this->uprLft.y - config.toolBarHeight) / config.brickHeight;
    //    int gridCellColIndex = this->uprLft.x / config.brickWidth;


    //    int upgridCellColIndex = gridCellColIndex;
    //    int upgridCellRowIndex = gridCellRowIndex - 1;


    //    int lowgridCellColIndex = gridCellColIndex;
    //    int lowgridCellRowIndex = gridCellRowIndex + 1;

    //    int leftgridCellColIndex = gridCellColIndex - 1;
    //    int leftgridCellRowIndex = gridCellRowIndex;


    //    int rightgridCellColIndex = gridCellColIndex + 1;
    //    int rightgridCellRowIndex = gridCellRowIndex;

    //    grid* pgrid = pGame->getGrid();
    //    pgrid->getbrick(lowgridCellColIndex, lowgridCellRowIndex)->currstrength = currstrength - 3;
    //    /*pgrid->getbrick(lowgridCellColIndex, lowgridCellRowIndex)->collisionAction();*/
    //    pgrid->getbrick(lowgridCellColIndex, lowgridCellRowIndex)->currstrength = currstrength - 3;
    //    /*pgrid->getbrick(lowgridCellColIndex, lowgridCellRowIndex)->collisionAction();*/
    //    pgrid->getbrick(leftgridCellColIndex, leftgridCellRowIndex)->currstrength = currstrength - 3;
    //    /*pgrid->getbrick(leftgridCellColIndex, leftgridCellRowIndex)->collisionAction();*/
    //    pgrid->getbrick(rightgridCellColIndex, rightgridCellRowIndex)->currstrength = currstrength - 3;
    //    /*pgrid->getbrick(rightgridCellColIndex, rightgridCellRowIndex)->collisionAction();*/
    // }
    if (checkCollision(pGame->getBall(), this).x != -1 && checkCollision(pGame->getBall(), this).y != -1) {
        int gridCellRowIndex = (this->uprLft.y - config.toolBarHeight) / config.brickHeight;
        int gridCellColIndex = this->uprLft.x / config.brickWidth;
        Ball* pball = pGame->getBall();
        pball->collidableDeflect(checkCollision(pGame->getBall(), this));
        pball = nullptr;
        currstrength -= 1;
        int upgridCellColIndex = gridCellColIndex;
        int upgridCellRowIndex = gridCellRowIndex - 1;


        int lowgridCellColIndex = gridCellColIndex;
        int lowgridCellRowIndex = gridCellRowIndex + 1;

        int leftgridCellColIndex = gridCellColIndex - 1;
        int leftgridCellRowIndex = gridCellRowIndex;


        int rightgridCellColIndex = gridCellColIndex + 1;
        int rightgridCellRowIndex = gridCellRowIndex;

        grid* pgrid = pGame->getGrid();
        if (pgrid->getbrick(upgridCellColIndex, upgridCellRowIndex) != nullptr) {
            pgrid->getbrick(upgridCellColIndex, upgridCellRowIndex)->currstrength = currstrength - 3;
        }
        if (pgrid->getbrick(lowgridCellColIndex, lowgridCellRowIndex) != nullptr) {
            pgrid->getbrick(lowgridCellColIndex, lowgridCellRowIndex)->currstrength = currstrength - 3;
        }
        if (pgrid->getbrick(leftgridCellColIndex, leftgridCellRowIndex) != nullptr) {
            pgrid->getbrick(leftgridCellColIndex, leftgridCellRowIndex)->currstrength = currstrength - 3;
        }
        if (pgrid->getbrick(rightgridCellColIndex, rightgridCellRowIndex) != 0) {
            pgrid->getbrick(rightgridCellColIndex, rightgridCellRowIndex)->currstrength = currstrength - 3;
        }

    }
}

////////////////////////////////////////////////////  class rockBrick  /////////////////////////////////
rockBrick::rockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
    currstrength = RStrength;
    pGame->getGrid()->inc_c_rock();
    imageName = "images\\bricks\\RockBrickIcon.jpg";
    type = BRK_Rock;
}

void rockBrick::collisionAction()
{
    if (checkCollision(pGame->getBall(), this).x != -1 && checkCollision(pGame->getBall(), this).y != -1) {
        Ball* pball = pGame->getBall();
        pball->collidableDeflect(checkCollision(pGame->getBall(), this));
        pball = nullptr;

    }
    Ball* pball = pGame->getBall();
    if (checkCollision(pGame->getBall(), this).x != -1 && checkCollision(pGame->getBall(), this).y != -1 && pball->GetIsFireBall() == true) {
        Ball* pball = pGame->getBall();
        pball->collidableDeflect(checkCollision(pGame->getBall(), this));
        pball = nullptr;
        currstrength = 0;
        pGame->gameScore ++;
    }
}

////////////////////////////////////////////////////  class hardBrick  /////////////////////////////////
hardBrick::hardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	currstrength = HStrength;
	imageName = "images\\bricks\\HardBrick.jpg";
    type = BRK_HRD;
}

void hardBrick::collisionAction()
{
    if (checkCollision(pGame->getBall(), this).x != -1 && checkCollision(pGame->getBall(), this).y != -1) {
        Ball* pball = pGame->getBall();
        pball->collidableDeflect(checkCollision(pGame->getBall(), this));
        pball = nullptr;
        currstrength -= 1;
        pGame->gameScore ++;
    }
    Ball* pball = pGame->getBall();
    if (checkCollision(pGame->getBall(), this).x != -1 && checkCollision(pGame->getBall(), this).y != -1 && pball->GetIsFireBall() == true) {
        Ball* pball = pGame->getBall();
        pball->collidableDeflect(checkCollision(pGame->getBall(), this));
        pball = nullptr;
        currstrength = 0;
        pGame->gameScore += HStrength;
    }
}

////////////////////////////////////////////////////  class powerupBrick  /////////////////////////////////
powerupBrick::powerupBrick(point r_uprleft, int r_width, int r_height, game* r_pGame):
    brick(r_uprleft,r_width,r_height,r_pGame)
{
    currstrength = 1;
    imageName = "images\\Bricks\\PowerupBrick.jpg";
    type = BRK_PRUP;
}
void powerupBrick::collisionAction()
{
    if (checkCollision(pGame->getBall(), this).x != -1 && checkCollision(pGame->getBall(), this).y != -1) {
        Ball* pball = pGame->getBall();
        pball->collidableDeflect(checkCollision(pGame->getBall(), this));
        pball = nullptr;
        currstrength -= 1;
        srand(time(0));
        int z = rand() % (6);
        switch (z) {
        case 0:
            point p;
            p.x = uprLft.x;
            p.y = uprLft.y;
            pGame->drawCollectable(0, p);
            pGame->gameCollectableMove(0);
        case 1:
            p.x = uprLft.x;
            p.y = uprLft.y;
            pGame->drawCollectable(1, p);
            pGame->gameCollectableMove(1);
        case 2:
            p.x = uprLft.x;
            p.y = uprLft.y;
            pGame->drawCollectable(2, p);
            pGame->gameCollectableMove(2);
        case 3:
            p.x = uprLft.x;
            p.y = uprLft.y;
            pGame->drawCollectable(4, p);
            pGame->gameCollectableMove(4);
        case 4:
            p.x = uprLft.x;
            p.y = uprLft.y;
            pGame->drawCollectable(5, p);
            pGame->gameCollectableMove(5);
        case 5:
            p.x = uprLft.x;
            p.y = uprLft.y;
            pGame->drawCollectable(7, p);
            pGame->gameCollectableMove(7);
        }
    }
}

//////////////////////////////////////////////////////  class powerdownBrick  /////////////////////////////////
powerdownBrick::powerdownBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
    brick(r_uprleft, r_width, r_height, r_pGame)
{
    currstrength = 1;
    imageName = "images\\Bricks\\PowerdownBrick.jpg";
    type = BRK_PRDN;
}
void powerdownBrick::collisionAction()
{
    if (checkCollision(pGame->getBall(), this).x != -1 && checkCollision(pGame->getBall(), this).y != -1) {
        Ball* pball = pGame->getBall();
        pball->collidableDeflect(checkCollision(pGame->getBall(), this));
        pball = nullptr;
        currstrength -= 1;
        srand(time(0));
        int z = rand() % (1);
        switch (z) {
        case 0:
            point p;
            p.x = uprLft.x;
            p.y = uprLft.y;
            pGame->drawCollectable(3, p);
            pGame->gameCollectableMove(3);
        case 1:
            p.x = uprLft.x;
            p.y = uprLft.y;
            pGame->drawCollectable(6, p);
            pGame->gameCollectableMove(6);
        }
    }
}