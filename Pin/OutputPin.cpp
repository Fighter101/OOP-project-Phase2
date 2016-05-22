#include "OutputPin.h"
<<<<<<< HEAD:Components/OutputPin.cpp
#include "Connection.h"
#include "Component.h"
=======
#include "..\Components\Connection.h"
>>>>>>> 942d643003f8efe01264ebfdb122406bb35feaff:Pin/OutputPin.cpp

ActionType OutputPin::Leftpress()
{
	return ADD_CONNECTION;
}

ActionType OutputPin::RightPress()
{
	return ADD_CONNECTION;
}

void OutputPin::hover()
{
}

void OutputPin::released()
{
}

OutputPin::OutputPin(int r_FanOut)
{
	
	m_Conn = 0;		//initially Pin is not connected to anything.
	m_FanOut = r_FanOut > MAX_CONNS ? MAX_CONNS: r_FanOut;	//set the fan out of the pin.
}

//Functionn ConnectTo:
//Connects the ouput pin the the passed connection if the fan out permits
//if the no. of connections is already equals to the fan out, no more connections can be created.

bool OutputPin::CheckPin()
{
	return m_Conn;
}





bool OutputPin::ConnectTo(Connection *r_Conn)
{
	if(m_Conn < m_FanOut)
	{
		m_Connections[m_Conn++] = r_Conn;	//add a new connection the the array of connections
		return true;
	}
	
	return false;	//can't connect to any more connections
}


void OutputPin::setComponent(Component* pComp)
{
	m_component = pComp;
}

Component* OutputPin::getComponent()
{
	return m_component;
}
