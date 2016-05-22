#pragma once
//#include"Defs.H"
#include"..\GUI\UI_Info.h"
class Graph;
class GridItem
{
public:
	GridItem();
	virtual ActionType Leftpress() = 0;
	virtual ActionType RightPress() = 0;
	virtual void hover() = 0;
	virtual void released() = 0;
	~GridItem();
};

