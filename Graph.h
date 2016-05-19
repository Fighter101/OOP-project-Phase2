#pragma once
#include"GridItem.h"
#include"Essentials.h"
class Graph
{
private:
	GridItem ***Grid;
	pair<int, int>**parent;
	bool Valid(int x, int y);
	void BFS(GraphicsInfo r_GfxInfo);
	void GetPoints(int x, int y);
	vector < pair<int, int> > Points;
	
public:
	Graph();
	void Register(GraphicsInfo r_GfxInfo, GridItem * ptr);
	void UNRegister(GraphicsInfo r_GfxInfo);
	GridItem * getAction(GraphicsInfo Click);
	vector< pair<int, int> > Connect(GraphicsInfo r_GfxInfo);
	~Graph();
};
