#include "Connection.h"

Connection::Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin):Component(r_GfxInfo)	
	
{
	x = false;
	SrcPin = pSrcPin;
	DstPin = pDstPin;
	DstPin->setConnection(this);	//MDawod
}

ActionType Connection::Leftpress()
{
	return CONNECT_TWO_PINS;
}

ActionType Connection::RightPress()
{
	return CONNECT_TWO_PINS;
}

void Connection::hover()
{
}

void Connection::released()
{
}



void Connection::setSourcePin(OutputPin *pSrcPin)
{	SrcPin = pSrcPin;	}

OutputPin* Connection::getSourcePin()
{	return SrcPin;	}


void Connection::setDestPin(InputPin *pDstPin)
{	
	DstPin = pDstPin;	
}

InputPin* Connection::getDestPin()
{	
	return DstPin;	
}

void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	SrcPin->getComponent()->Operate();
	DstPin->setStatus((STATUS)SrcPin->getStatus());

}

void Connection::Draw(Output* pOut)
{
	x = pOut->Connect(this).size() == 0;
}

bool Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


bool Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}

void Connection::SetState(bool r_selected)
{
	Selected = r_selected;
}

bool Connection::GetState()
{
	return Selected;
}

bool Connection::isConnected()
{
	return x;
}
