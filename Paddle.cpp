#include "Paddle.h"
#include"game.h"
#include<mmsystem.h>
#include<Windows.h>

#pragma comment(lib, "winmm.lib")
void Paddle::ChangeWidth()
{
		if (IsWide) {
			setWidth(config.WidePaddleWidth);
		}
		else if (IsWide == false) {
			setWidth(config.NarrowPaddleWidth);
		}
}

int Paddle::getWidth()
{
	return paddleWidth;
}

void Paddle::setWidth(int x)
{
	/*paddleWidth=x;*/
}

Paddle::Paddle(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	collidable(r_uprleft, r_width, r_height, r_pGame)
{
	imageName="images\\Paddle\\Paddle.jpg";
}

void Paddle::movePaddle(char& key)
{
	if (key == 6) {
		if (uprLft.x + config.paddleWidth <= config.windWidth) {
			pGame->getWind()->SetPen(LAVENDER);
			pGame->getWind()->SetBrush(LAVENDER);
			pGame->getWind()->DrawRectangle(uprLft.x, uprLft.y, uprLft.x + config.paddleWidth, uprLft.y + config.paddleHeight);
			uprLft.x += config.paddleWidth / 2;
			draw();
		}
	}
	else if (key == 4) {
		if (uprLft.x >= 0) {
			pGame->getWind()->SetPen(LAVENDER);
			pGame->getWind()->SetBrush(LAVENDER);
			pGame->getWind()->DrawRectangle(uprLft.x, uprLft.y, uprLft.x + config.paddleWidth, uprLft.y + config.paddleHeight);
			uprLft.x -= config.paddleWidth / 2;
			draw();
		}
	}
	
}

void Paddle::movePaddleWind(char& key)
{
	if (key == 6) {
		if (uprLft.x + config.paddleWidth <= config.windWidth) {
			pGame->getWind()->SetPen(LAVENDER);
			pGame->getWind()->SetBrush(LAVENDER);
			pGame->getWind()->DrawRectangle(uprLft.x, uprLft.y, uprLft.x + config.paddleWidth, uprLft.y + config.paddleHeight);
			uprLft.x += 3 * config.paddleWidth / 2;
			draw();
		}
	}
	else if (key == 4) {
		if (uprLft.x >= 0) {
			pGame->getWind()->SetPen(LAVENDER);
			pGame->getWind()->SetBrush(LAVENDER);
			pGame->getWind()->DrawRectangle(uprLft.x, uprLft.y, uprLft.x + config.paddleWidth, uprLft.y + config.paddleHeight);
			uprLft.x -= 3 * config.paddleWidth / 2;
			draw();
		}
	}
}

void Paddle::movePaddleReverse(char& key)
{
	if (key == 4) {
		if (uprLft.x + config.paddleWidth <= config.windWidth) {
			pGame->getWind()->SetPen(LAVENDER);
			pGame->getWind()->SetBrush(LAVENDER);
			pGame->getWind()->DrawRectangle(uprLft.x, uprLft.y, uprLft.x + config.paddleWidth, uprLft.y + config.paddleHeight);
			uprLft.x += config.paddleWidth / 2;
			draw();
		}
	}
	else if (key == 6) {
		if (uprLft.x >= 0) {
			pGame->getWind()->SetPen(LAVENDER);
			pGame->getWind()->SetBrush(LAVENDER);
			pGame->getWind()->DrawRectangle(uprLft.x, uprLft.y, uprLft.x + config.paddleWidth, uprLft.y + config.paddleHeight);
			uprLft.x -= config.paddleWidth / 2;
			draw();
		}
	}
}

void Paddle::collisionAction()
{
	Ball* b = pGame->getBall();
	checkCollision(this, b);
	if (getCollisionPoint().x != -1 && getCollisionPoint().y != -1) {
		PlaySound(TEXT("Sounds\\PaddleSound.wav"), NULL, SND_FILENAME | SND_ASYNC);
		b->collidableDeflect(checkCollision(this,b));
	}
}

void Paddle::resetPaddlecenter()
{
	uprLft.x = config.inPaddleX;
	uprLft.y = config.inPaddleY;
	draw();
}
