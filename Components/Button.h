#pragma once
#include "Component.h"
#include"..\GUI\Essentials.h"
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
	GraphicsInfo Erase(Output* pOut);
	void Draw(Output*pOut);
	virtual ActionType Leftpress();
	virtual ActionType RightPress();
	virtual void hover();
	virtual void released();
	~Button();


};

