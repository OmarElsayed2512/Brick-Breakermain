#include "collidable.h"
#include <math.h>
collidable::collidable(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	drawable(r_uprleft, r_width, r_height, r_pGame)
{
}
point collidable::checkCollision(collidable* obj1, collidable* obj2)
{
	collpoint.x = -1;
	collpoint.y = -1;
	int x1 = obj1->uprLft.x; //encoding the uprleft, width and height info of the two objects for readability
	int x2 = obj2->uprLft.x;
	int y1 = obj1->uprLft.y;
	int y2 = obj2->uprLft.y;
	int h1 = obj1->height;
	int h2 = obj2->height;
	int w1 = obj1->width;
	int w2 = obj2->width;

	if (y2 == y1 + h1) { //Test the collision for the Up case
		collpoint.y = y2;
		if (x2<x1 && (x2 + w2)>x1) {
			collpoint.x = (x1 + x2 + w2) / 2;
		}
		else if (x2 >= x1 && (x2 + w2) <= (x1 + w1)) {
			collpoint.x = ((2 * x2) + w2) / 2;
		}
		else if (x2<(x1 + w1) && (x2 + w2)>(x1 + w1)) {
			collpoint.x = (x2 + x1 + w1) / 2;
		}
	}
	else if (y1 == y2 + h2) { //Test the collision for the Down case
		collpoint.y = y1;
		if (x2<x1 && (x2 + w2)>x1) {
			collpoint.x = (x1 + x2 + w2) / 2;
		}
		else if (x2 >= x1 && (x2 + w2) <= (x1 + w1)) {
			collpoint.x = ((2 * x2) + w2) / 2;
		}
		else if (x2<(x1 + w1) && (x2 + w2)>(x1 + w1)) {
			collpoint.x = (x2 + x1 + w1) / 2;
		}
	}
	else if (x1 == x2 + w2) { //Text the collision for the left case
		collpoint.x = x1;
		if (y2<y1 && (y2 + h2)>y1) {
			collpoint.y = (y1 + y2 + h2) / 2;
		}
		else if (y2 >= y1 && (y2 + h2) <= (y1 + h1)) {
			collpoint.y = (2 * y2 + h2) / 2;
		}
		else if (y2<(y1 + h1) && (y2 + h2)>(y1 + h1)) {
			collpoint.y = (y2 + y1 + h1) / 2;
		}
	}
	else if (x2 == x1 + w1) { //Test the collision for the right case
		collpoint.x = x2;
		if (y2<y1 && (y2 + h2)>y1) {
			collpoint.y = (y1 + y2 + h2) / 2;
		}
		else if (y2 >= y1 && (y2 + h2) <= (y1 + h1)) {
			collpoint.y = (2 * y2 + h2) / 2;
		}
		else if (y2<(y1 + h1) && (y2 + h2)>(y1 + h1)) {
			collpoint.y = (y2 + y1 + h1) / 2;
		}
	}
	return collpoint;
}

point collidable::getCollisionPoint()
{
	return collpoint;
}
