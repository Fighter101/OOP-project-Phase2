#include "InputPin.h"
#include "Connection.h"
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
{
	pConn = NULL;
}

bool InputPin::CheckPin()
{
	return pConn == NULL ? false : true;
}


void InputPin::setComponent(Component *pCmp)
{
	this->pComp = pCmp;
}

Component* InputPin::getComponent()
{
	return pComp;
}


void InputPin::setConnection(Connection* pCon)
{
	this->pConn = pCon;
}
Connection* InputPin::getConnection()
{
	return pConn;
}


void InputPin::EraseConnection()
{
	pConn = NULL;
}
