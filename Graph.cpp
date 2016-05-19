#include "Graph.h"
bool Graph::Valid(int x, int y)
{
	return (x >= 0) && (y >= 0) && (x < UI.GridWidth) && (y < UI.GridHeight) && (Grid[y][x] == NULL) && (parent[y][x].first == -1);
}
void Graph::BFS(GraphicsInfo r_GfxInfo)
{
	int dx[] = { 1,-1,0,0 };
	int dy[] = { 0,0,1,-1 };
	queue<pair<int, int> > myq;
	myq.push(pair<int, int>(r_GfxInfo.x1, r_GfxInfo.y1));
	parent[myq.front().second][myq.front().first] = pair<int, int>(-2, -2);
	while (!myq.empty())
	{
		pair<int, int> parnt = myq.front();
		myq.pop();
		for (int i = 0; i < 4; i++)
		{
			if (Valid(parnt.first + dx[i], parnt.second + dy[i]))
			{
				parent[parnt.second + dy[i]][parnt.first + dx[i]] = parnt;
				myq.push(pair<int, int>(parnt.first + dx[i], parnt.second + dy[i]));
			}
		}
	}

}
void Graph::GetPoints(int x, int y)
{
	if (parent[y][x] == pair<int, int>(-2, -2))
		return;
	GetPoints(parent[y][x].first, parent[y][x].second);
	Points.push_back(pair<int, int>(x * 5, y * 5));
}
vector<pair<int, int>> Graph::Connect(GraphicsInfo r_GfxInfo)
{
	parent = new pair<int, int>*[UI.GridHeight];
	for (int i = 0; i < UI.GridHeight; i++)
	{
		parent[i] = new pair<int, int>[UI.GridWidth];
		for (int j = 0; j < UI.GridWidth; j++)
		{
			parent[i][j] = pair<int, int>(-1, -1);
		}
	}
	if ((Grid[r_GfxInfo.y1 / 5][r_GfxInfo.x1 / 5] != NULL)/* || (Components[r_GfxInfo.y2 / 5][r_GfxInfo.x2 / 5] != Empty)*/)
		return Points;
	BFS(GraphicsInfo(r_GfxInfo.x1 / UI.PixelDenisty, r_GfxInfo.y1 / UI.PixelDenisty, r_GfxInfo.x2 / UI.PixelDenisty, r_GfxInfo.y2 / UI.PixelDenisty));
	if (parent[r_GfxInfo.y2 / 5][r_GfxInfo.x2 / 5] == pair<int, int>(-1, -1))
		return Points;
	GetPoints(r_GfxInfo.x2 / UI.PixelDenisty, r_GfxInfo.y2 / UI.PixelDenisty);
	for (int i = 0; i < UI.GridHeight; i++)
	{
		delete[]parent[i];
	}
	delete[]parent;
	return Points;
}
Graph::Graph()
{
	Grid = new GridItem**[UI.width/5+1];
	for (int i = 0; i < UI.GridWidth; i++)
	{
		Grid[i] = new GridItem*[UI.height / 5];
		for (int j = 0; j < UI.GridHeight; j++)
		{
			Grid[i][j] = NULL;
		}
	}
}
void Graph::Register(GraphicsInfo r_GfxInfo, GridItem * ptr)
{
	int ix = r_GfxInfo.x1 / UI.PixelDenisty;
	int iy = r_GfxInfo.y1 / UI.PixelDenisty;
	int fx = ceil(r_GfxInfo.x2 / (double)UI.PixelDenisty);
	int fy = ceil(r_GfxInfo.y2 / (double)UI.PixelDenisty);
	for (int i = 0; i <= fx - ix; i++)
	{
		for (int j = 0;j <= fy - iy;j++)
			Grid[ix + i][iy + j] = ptr;
	}
}
void Graph::UNRegister(GraphicsInfo r_GfxInfo)
{
	Register(r_GfxInfo, NULL);
}
GridItem * Graph::getAction(GraphicsInfo Click)
{
	return Grid[Click.x1/5][Click.y1/5];
}
Graph::~Graph()
{
}
