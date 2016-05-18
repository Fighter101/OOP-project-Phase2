#include"Button.h"

Button::Button()
{
}

Button::Button(int index, GraphicsInfo pos)
{
	SetPosition(pos);
	SetDrawingFunction(index);
}

void Button::SetPosition(GraphicsInfo pos)
{
	r_GfxInfo = pos;
}

void Button::SetDrawingFunction(int index)
{
	DrawingFunctionIndex = index;
}

void Button::SetAction(ActionType m_Action)
{
	ReturnedAction = m_Action;
}

void Button::SetState(PressType m_State)
{
	State = m_State;
}

void Button::SetDimension(GraphicsInfo r_Dimensions)
{
	Dimensions.x1 = r_Dimensions.x1;
	Dimensions.y1 = r_Dimensions.y1;
	Dimensions.x2 = Dimensions.y2 = 0;
}

GraphicsInfo Button::GetDimensions()
{
	return Dimensions;
}

GraphicsInfo Button::GetPosition()
{
	return r_GfxInfo;
}



void Button::Draw(Output * pOut)
{
	SetDimension(pOut->DrawButon(DrawingFunctionIndex, r_GfxInfo, Normal));
	pOut->RegisterButton(this);
}

ActionType Button::Leftpress(GridItem *)
{
	return ReturnedAction;
}

ActionType Button::RightPress(GridItem *)
{
	return ReturnedAction;
}

void Button::hover()
{
}

void Button::released()
{
}

void Button::Erase(Output * pOut)
{
	pOut->EraseButton(this);
}

Button::~Button()
{
}
