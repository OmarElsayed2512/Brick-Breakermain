#pragma once
#include "drawable.h"
///////////////////////////////////////   collidable classes   /////////////////////////////////
//Base class for all collidable (objects that may collide with other objects)

class collidable :public drawable
{
private:
    point collpoint;
    
public:
    
    collidable(point r_uprleft, int r_width, int r_height, game* r_pGame);
   
    virtual void collisionAction() = 0;    //action that should be performed upon collision

    point checkCollision(collidable* obj1, collidable* obj2);    //Checks whether a collision happened between two collidable objects and returns a struct containing collision info

    point getCollisionPoint();
};