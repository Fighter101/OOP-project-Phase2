#include "Graph.h"
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
GridItem * Graph::getAction(GraphicsInfo Click)
{
	return Grid[Click.x1/5][Click.y1/5];
}
Graph::~Graph()
{
}
