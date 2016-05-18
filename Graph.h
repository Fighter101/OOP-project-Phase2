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
	void UNRegister(GraphicsInfo r_GfxInfo);
	GridItem * getAction(GraphicsInfo Click);
	~Graph();
};
