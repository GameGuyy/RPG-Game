#pragma once
#include "Components.h"

class PositionComponent : public Component
{
private:
	int xpos = 0, ypos = 0;
public:
	PositionComponent()
	{
		xpos = 0;
		ypos = 0;
	}

	PositionComponent(int x, int y)
	{
		xpos = x;
		ypos = y;
	}

	int x() { return xpos; }
	int y() { return ypos; }

	void init() override
	{
		xpos = 0;
		ypos = 0;
	}
	void update() override
	{
		xpos++;
		ypos++;
	}
	void SetPos(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
};

