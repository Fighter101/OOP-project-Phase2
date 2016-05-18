#pragma once
#include"GridItem.h"
//#include"Defs.H"
class Graph
{
private:
	GridItem ***Grid;
public:
	Graph();
	void Register(GraphicsInfo r_GfxInfo, GridItem * ptr);
	GridItem * getAction(GraphicsInfo Click);
	~Graph();
};
