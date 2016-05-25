#ifndef _OUTPUTPIN_H
#define _OUTPUTPIN_H

/*class OutputPin 
  ---------------
 An output pin obtains its value as a result of calculating the outputs of
 a component. The output pin propagates its value immediately to the associated connections
*/

#include "Pin.h"
class Connection;	//Forward class declaration
class Component;  //MDawod

class OutputPin: public Pin	//inherited from class Pin
{
private:
	//Array of connections (pointers) to be connected to that OutputPin
	//For simplicity, we consider it a constant length
	Connection* m_Connections[MAX_CONNS];	
	Component* m_component; //MDawod
	int m_FanOut;	//Maximum No. of connections connected to that output pin (depends on the component)
	int m_Conn;		//Actual No. of connections connected to that output pin
public:
	virtual ActionType Leftpress();
	virtual ActionType RightPress();
	virtual void hover();
	virtual void released();

	bool CheckPin();

	
	OutputPin(int r_FanOut=MAX_CONNS);	
	bool ConnectTo(Connection *r_Conn);	//connect to a new connection
	void setComponent(Component* pComp);
	Component* getComponent();


	Connection** getConnection(int&);
	bool nullConnection(Connection*);
	vector<Component*>  DeleteAllOutConnections();
};

#endif