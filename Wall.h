#pragma once
#include "grid.h"
class Wall : public drawable
{

public:
	Wall(point r_uprleft, int r_width, int r_height, game* r_pGame);
};

