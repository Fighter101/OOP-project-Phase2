#include "InputPin.h"

ActionType InputPin::Leftpress()
{
	return SELECT;
}

ActionType InputPin::RightPress()
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