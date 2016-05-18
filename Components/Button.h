#pragma once
#include "Component.h"
class Button :
	public GridItem
{
private:
	int DrawingFunctionIndex;
	GraphicsInfo r_GfxInfo;
	GraphicsInfo Dimensions;
	PressType State;
	ActionType ReturnedAction;
public:
	Button();
	Button(int index, GraphicsInfo pos);
	void SetPosition(GraphicsInfo pos);
	void SetDrawingFunction(int index);
	void SetAction(ActionType m_Action);
	void SetState(PressType m_State);
	void SetDimension(GraphicsInfo r_Dimensions);
	GraphicsInfo GetDimensions();
	GraphicsInfo GetPosition();
	void Erase(Output* pOut);
	void Draw(Output*pOut);
	virtual ActionType Leftpress(GridItem*);
	virtual ActionType RightPress(GridItem*);
	virtual void hover();
	virtual void released();
	~Button();


};

