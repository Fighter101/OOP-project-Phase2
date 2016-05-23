#ifndef _INPUTPIN_H
#define _INPUTPIN_H

#include "Pin.h"
class Component; //Forward class declaration
class Connection;
class InputPin: public Pin	//inherited from class Pin
{
	Component* pComp; //Component at which this pin is associated
	Connection* pConn; //MDawod
public:


	void EraseConnection();
	bool CheckPin();
	virtual ActionType Leftpress();
	virtual ActionType RightPress();
	virtual void hover();
	virtual void released();
	InputPin();
	void setComponent(Component* pCmp);	//sets the component of this input pin
	Component* getComponent();	//returns the component of this input pin
	void setConnection(Connection* pCon);
	Connection* getConnection();
};

#endif