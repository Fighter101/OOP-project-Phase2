#include "Gate.h"

//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(int r_Inputs)
{
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;	//set no. of inputs of that gate
	
	//Associate all input pins to this gate
	for(int i=0; i<m_Inputs; i++)
		m_InputPins[i].setComponent(this);
}

InputPin * Gate::GetInputPins()
{
	return m_InputPins;
}

OutputPin  Gate::GetOutputPin()
{
	return m_OutputPin;
}

void Gate::SetState(bool r_selected)
{
	Selected = r_selected;
}

GraphicsInfo Gate::GetPosition()
{
	return Component::m_GfxInfo;
}

bool Gate::GetState()
{
	return Selected;
}

ActionType Gate::Leftpress(GridItem *)
{
	return ActionType();
}

ActionType Gate::RightPress(GridItem *)
{
	return ActionType();
}

void Gate::hover()
{
}

void Gate::released()
{
}
