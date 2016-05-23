#include "ToolBar.h"
#include"..\Components\Button.h"

ToolBar::ToolBar()
{
}

void ToolBar::ButtonsToDraw(vector<int>m_Indices)
{
	Indices = m_Indices;
}

void ToolBar::SetPosition(GraphicsInfo m_GfxInfo)
{
	r_GfxInfo = m_GfxInfo;
}

void ToolBar::SetOrientation(Orientation r_Direction)
{
	Direction = r_Direction;
}
void ToolBar::SetDistance(int r_HDistance,int r_VDistnace)
{
	HDistance = r_HDistance;
	VDistance = r_VDistnace;
}
void ToolBar::CreateButtons(Output*pOut)
{
	int counter = 0;
	if (Direction == Horizontal)
	{
		for (int i = 0; i < Indices.size(); i++)
		{
			Buttons.push_back(Button(Indices[i], GraphicsInfo(r_GfxInfo.x1 + counter++*HDistance, r_GfxInfo.y1)));
		}
	}
	else
	{
		for (int i = 0; i < Indices.size(); i++)
		{
			Buttons.push_back(Button(Indices[i], GraphicsInfo(r_GfxInfo.x1, r_GfxInfo.y1 + counter++*VDistance)));
		}
	}
	for (int i = 0; i < Indices.size(); i++)
	{
		Buttons[i].SetAction(pOut->GetReturnedAction(Indices[i]));
	}
}

void ToolBar::Draw(Output * pOut)
{
	for (int i = 0; i < Indices.size(); i++)
	{
		Buttons[i].Draw(pOut);
	}
}

GraphicsInfo ToolBar::Erase(Output * pOut)
{
	GraphicsInfo tmp(0, 0, 0, 0);
	for (int i = 0; i < Indices.size(); i++)
	{
		tmp=Buttons[i].Erase(pOut);
	}
	if (Direction == Vertical)
		return GraphicsInfo(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + tmp.x1, r_GfxInfo.y1 + Indices.size()*tmp.y1);
	else return GraphicsInfo(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + Indices.size()*tmp.x1, r_GfxInfo.y1 + tmp.y1);
}


ToolBar::~ToolBar()
{
}
