#include "Collectable.h"
#include"game.h"
//Collectable base class constructor 
Collectable::Collectable(point r_uprleft, int r_width, int r_height, game* r_pGame):
	collidable(r_uprleft, r_width, r_height, r_pGame)
{
}
//Collectable movement function
void Collectable::collectableMove()
{
		window* pWind = pGame->getWind();
		//Declare the previous points of the movement
		this->PrevUprlft.x = this->uprLft.x;
		this->PrevUprlft.y = this->uprLft.y;
		//Apply one-step movement to the coordinates
		this->uprLft.y += Yinc / 2;
		//Draw a background-filling rectangle for the previous ball poisition
		pWind->SetPen(LAVENDER);
		pWind->SetBrush(LAVENDER);
		pWind->DrawRectangle(this->PrevUprlft.x, this->PrevUprlft.y, this->PrevUprlft.x + 2 * config.BallRad, this->PrevUprlft.y + 2 * config.BallRad);
		this->draw();
		pWind->UpdateBuffer();
		pWind->SetBuffering(false);
		Pause(20);
		grid* gameGrid = pGame->getGrid();
		gameGrid->draw();
}
//Fireball child class
Fireball::Fireball(point r_uprleft, int r_width, int r_height, game* r_pGame):
	Collectable(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\Collectable\\Fireball.jpg";
}
void Fireball::collisionAction()
{
	if (checkCollision(pGame->getPaddle(), this).x!=-1 && checkCollision(pGame->getPaddle(), this).x != -1) {
		pGame->getBall()->FireBallON();
	}
}
//Windglide child class
Windglide::Windglide(point r_uprleft, int r_width, int r_height, game* r_pGame):
	Collectable(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\Collectable\\Windglide.jpg";
}
void Windglide::collisionAction()
{
	window* pWind = pGame->getWind();
	Paddle* gamePaddle = pGame->getPaddle();
	time_t startTime = time(nullptr); // Get the current time

	while (time(nullptr) - startTime < 60) {
		// Loop body
		pWind->GetKeyPress(key);
		gamePaddle->movePaddleWind(key);
	}
	// Sleep for a short period to reduce CPU usage
	clock_t delay = 100 * CLOCKS_PER_SEC / 1000; // 100 milliseconds
	clock_t start = clock();
	while (clock() - start < delay) {}
}
//Widepaddle child class
Widepaddle::Widepaddle(point r_uprleft, int r_width, int r_height, game* r_pGame):
	Collectable(r_uprleft,r_width,r_height,r_pGame)
{
	imageName = "images\\Collectable\\Widepaddle.jpg";
}
void Widepaddle::collisionAction()
{
	if (checkCollision(pGame->getPaddle(), this).x != -1 && checkCollision(pGame->getPaddle(), this).y != -1) {
		pGame->getPaddle()->ChangeWidth();
	}
}
//Narrowpaddle child class
Narrowpaddle::Narrowpaddle(point r_uprleft, int r_width, int r_height, game* r_pGame):
	Collectable(r_uprleft,r_width, r_height, r_pGame)
{
	imageName = "images\\Collectable\\Narrowpaddle.jpg";
}
void Narrowpaddle::collisionAction()
{
	if (checkCollision(pGame->getPaddle(), this).x != -1 && checkCollision(pGame->getPaddle(), this).y != -1) {
		pGame->getPaddle()->ChangeWidth();
	}
}
//Magnet child class
Magnet::Magnet(point r_uprleft, int r_width, int r_height, game* r_pGame):
	Collectable(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\Collectable\\Magnet.jpg";
}
void Magnet::collisionAction()
{
	if (checkCollision(pGame->getPaddle(), this).x != -1 && checkCollision(pGame->getPaddle(), this).x != -1) {
		pGame->getBall()->Magnet();
	}
}
//Multipleball child class
Multipleball::Multipleball(point r_uprleft, int r_width, int r_height, game* r_pGame):
	Collectable(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\Collectable\\Multipleballs.jpg";
}
void Multipleball::collisionAction()
{

}
//Reverse child class
Reverse::Reverse(point r_uprleft, int r_width, int r_height, game* r_pGame):
	Collectable(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\Collectable\\Reversedirection.jpg";
}
void Reverse::collisionAction()
{
	window* pWind = pGame->getWind();
	Paddle* gamePaddle = pGame->getPaddle();
	time_t startTime = time(nullptr); // Get the current time

	while (time(nullptr) - startTime < 120) {
		// Loop body
		pWind->GetKeyPress(key);
		gamePaddle->movePaddleReverse(key);
	}
	// Sleep for a short period to reduce CPU usage
	clock_t delay = 100 * CLOCKS_PER_SEC / 1000; // 100 milliseconds
	clock_t start = clock();
	while (clock() - start < delay) {}
}
//Quicksand child class
Quicksand::Quicksand(point r_uprleft, int r_width, int r_height, game* r_pGame):
	Collectable(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\Collectable\\Quicksand.jpg";
}

void Quicksand::collisionAction()
{
}
