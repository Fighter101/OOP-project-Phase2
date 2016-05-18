#pragma once
#include"Defs.H"
#include"Essentials.h"
class Button;
class Output;
class ToolBar
{
	Orientation Direction;
	GraphicsInfo r_GfxInfo;
	vector<Button> Buttons;
	vector<int> Indices;
	int HDistance;
	int VDistance;
public:
	ToolBar();
	void ButtonsToDraw(vector<int> m_Indices);
	void SetPosition(GraphicsInfo m_GfxInfo);
	void SetOrientation(Orientation r_Direction);
	void SetDistance(int r_HDistance,int r_VDistance);
	/*Must be called only after setting position and orientation and giving the tool bar the list of buttons */
	void CreateButtons(Output*pOut);
	void Draw(Output *pOut);
	void Erase(Output*pOut);
	~ToolBar();
};