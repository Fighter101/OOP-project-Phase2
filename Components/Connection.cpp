#include "Connection.h"
#include"Gate.h"
Connection::Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin):Component(r_GfxInfo)	
{
	x = false;
	SrcPin = pSrcPin;
	DstPin = pDstPin;
	DstPin->setConnection(this);	//MDawod
	SrcPin->ConnectTo(this);
	Selected = false;
	ON = false;
}

Connection::Connection()
{
	Selected = false;
	ON = false;
}

ActionType Connection::Leftpress()
{
	return SELECT;
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

vector<pair<int, int>> Connection::GetPoints()
{
	return points;
}

void Connection::Erase(Output * pOut)
{
	pOut->EraseConnection(this);
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
	points=pOut->Connect(this);
	x = points.size() == 0;
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

bool Connection::GetOn()
{
	return ON;
}

void Connection::SetOn(bool r_ON)
{
	ON = r_ON;
}

int Connection::GetSrcID()
{
	return SrcID;
}

int Connection::GetTrgtID()
{
	return TrgtID;
}

int Connection::GetPinID()
{
	return PinID;
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

void Connection::Save(ofstream & Out)
{
	Out << ((Gate*)SrcPin->getComponent())->GetID() << " " << ((Gate*)DstPin->getComponent())->GetID() << " " << ((Gate*)DstPin->getComponent())->getPinNo(DstPin) << endl;
}

void Connection::Load(ifstream & In)
{
	In >> SrcID >> TrgtID >> PinID;
}
