#include "OutputPin.h"

#include "..\Components\Component.h"
#include "..\Components\Connection.h"


ActionType OutputPin::Leftpress()
{
	return SELECT;
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
	for (size_t i = 0; i < MAX_CONNS; i++)
	{
		m_Connections[i] = nullptr;
	}
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

Connection ** OutputPin::getConnection(int& x)
{
	x = MAX_CONNS;
	return m_Connections;

}

bool OutputPin::nullConnection(Connection *x)
{
	for (size_t i = 0; i < MAX_CONNS; i++)
	{
		if (x == m_Connections[i])
		{
			m_Connections[i] = nullptr;
			return true;
		}
	}
	return false;
}

vector<Component*> OutputPin::DeleteAllOutConnections()
{
	vector<Component*>temp;
	for (size_t i = 0; i < MAX_CONNS; i++)
	{
		if (m_Connections[i])
		{
			m_Connections[i]->getDestPin()->setConnection(nullptr);
			m_Connections[i]->getSourcePin()->nullConnection(m_Connections[i]);
			temp.push_back(m_Connections[i]);
		}
	}
	return temp;
}
