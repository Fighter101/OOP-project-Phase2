#include "InputPin.h"

ActionType InputPin::Leftpress(GridItem *)
{
	return SELECT;
}

ActionType InputPin::RightPress(GridItem *)
{
	return SELECT;
}

void InputPin::hover()
{
}

void InputPin::released()
{
}

InputPin::InputPin()
{}

void InputPin::setComponent(Component *pCmp)
{
	this->pComp = pCmp;
}

Component* InputPin::getComponent()
{
	return pComp;
}