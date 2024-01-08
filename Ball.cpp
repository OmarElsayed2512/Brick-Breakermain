#include "Ball.h"
#include "gameConfig.h"
#include "CMUgraphicsLib/CMUgraphics.h"
#include "CMUgraphicsLib/auxil.h"
#include <sstream>
#include <cmath>
#include"game.h"


Ball::Ball(point r_uprleft, int r_width, int r_height, game* r_pGame) :
    collidable(r_uprleft, r_width, r_height, r_pGame)
{
    imageName = "images\\Ball\\Ball.jpg";

    pGame = r_pGame;
}


void Ball::ballMove(char& key)
{
        window* pWind = pGame->getWind();
        //Check for any of the Wall collidableDeflection conditions
        this->wallDeflect();
        //Declare the previous points of the movement
        this->PrevUprlft.x = this->uprLft.x;
        this->PrevUprlft.y = this->uprLft.y;
        //Apply one-step movement to the coordinates
        this->uprLft.x += Xinc / 2;
        this->uprLft.y -= Yinc / 2;
        //Draw a background-filling rectangle for the previous ball poisition
        pWind->SetPen(LAVENDER);
        pWind->SetBrush(LAVENDER);
        pWind->DrawRectangle(this->PrevUprlft.x, this->PrevUprlft.y, this->PrevUprlft.x + 2 * config.BallRad, this->PrevUprlft.y + 2 * config.BallRad);
        this->draw();
        pWind->UpdateBuffer();
        pWind->SetBuffering(false);
        Pause(50);
        //set the pause time
        grid* gameGrid = pGame->getGrid();
        gameGrid->draw();
}

void Ball::collisionAction()
{

}

void Ball::wallDeflect()
{
    if (uprLft.y <= config.toolBarHeight) {
        Yinc = -Yinc;
    }
    else if (uprLft.x <= 0 || uprLft.x + (2*config.BallRad)>=config.windWidth) {
        Xinc = -Xinc;
    }
    else if (uprLft.y + 2 * config.BallRad >= config.windHeight) {
        resetBallcentre();
        if (pGame->gameLives > 0) {
            pGame->gameLives -= 1;
        }
        else if(pGame->gameLives==0)
        {
            pGame->stopgame();
        }
    }
}

void Ball::paddleDeflect()
{
    Yinc = -Yinc;
}

void Ball::resetBallcentre()
{
    uprLft.x = config.inBallx;
    uprLft.y = config.inBally;
    draw();
    Xinc = 20;
    Yinc = 20;
    pGame->setPause(true);
    pGame->getKeyPress(key);
    if (key == ' ') {
        pGame->setPause(false);
    }
}

void Ball::collidableDeflect(point& p)
{
    p = getCollisionPoint();
    int gridCellRowIndex = (p.y - config.toolBarHeight) / config.brickHeight;
    int gridCellColIndex = p.x / config.brickWidth;
    double distance = abs(p.x - ((gridCellColIndex * config.brickWidth) - (config.brickWidth / 2)));
    if (distance <= config.brickWidth) {
        double angle = atan(distance / (config.brickWidth / 2));
        int x_inc = Xinc;
        Xinc = Xinc * cos(angle) + Yinc * sin(angle);
        Yinc = -x_inc * cos(angle) + Yinc * cos(angle);

    }
}

void  Ball::FireBallON()
{
    IsFireBall = true;
}

void Ball::FireBallOF()
{
    IsFireBall = false;
}

bool Ball::GetIsFireBall()
{
    return IsFireBall;
}

void Ball::Magnet()
{
    //write magnet code
}

int Ball::getBallCenterY()
{
    return uprLft.y;
}



