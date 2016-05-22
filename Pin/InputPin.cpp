#include "InputPin.h"

ActionType InputPin::Leftpress()
{
	return ADD_CONNECTION;
}

ActionType InputPin::RightPress()
{
	return ADD_CONNECTION;
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