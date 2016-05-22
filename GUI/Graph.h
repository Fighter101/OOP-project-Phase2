#pragma once
#include"GridItem.h"
#include"Essentials.h"
class Graph
{
private:
	GridItem ***Grid;
	pair<int, int>**parent;
	bool Valid(int x, int y,int);
	void BFS(GraphicsInfo r_GfxInfo);
	void GetPoints(int x, int y);
	vector < pair<int, int> > Points;
	
public:
	Graph();
	GridItem* Available(GraphicsInfo r_GfxInfo);
	set<GridItem*>Check(GraphicsInfo r_GfxInfo);
	void Register(GraphicsInfo r_GfxInfo, GridItem * ptr);
	void UNRegister(GraphicsInfo r_GfxInfo);
	GridItem * getAction(GraphicsInfo Click);
	vector< pair<int, int> > Connect(GraphicsInfo r_GfxInfo);
	~Graph();
};
