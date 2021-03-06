#pragma once
#include "component.h"
#include "..\Pin\InputPin.h"
#include "..\Pin\OutputPin.h"

class Connection :	public Component
{
	//Component*	SrcCmpnt;	//Connection source component
	//Component*	DstCmpnt;	//Connection Destination component
	//int		DstPin;		//The Input pin to which this connection is linked
	OutputPin* SrcPin;	//The Source pin of this connection (an output pin of certain Component)
	InputPin* DstPin;	//The Destination pin of this connection (an input pin of certain Component)
	vector<pair<int, int> >points;
	int SrcID;
	int TrgtID;
	int PinID;
	bool x;
	bool ON;
public:
	
	//Connection(const GraphicsInfo &r_GfxInfo, Component *pS=NULL,Component *pD=NULL, int Pin=0);
	Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin);
	Connection();
	virtual void Operate() ;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut);	//for each component to Draw itself
	virtual ActionType Leftpress();
	virtual ActionType RightPress();

	virtual void hover();
	virtual void released();
	vector<pair<int, int> > GetPoints();
	virtual void Erase(Output*pOut);
	void setSourcePin(OutputPin *pSrcPin);
	void setDestPin(InputPin *pDstPin);
	OutputPin* getSourcePin();
	InputPin* getDestPin();

	virtual bool GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual bool GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	bool GetOn();
	void SetOn(bool r_ON);
	int GetSrcID();
	int GetTrgtID();
	int GetPinID();

	//sam7
	virtual void SetState(bool r_selected);
	virtual bool GetState();
	bool isConnected();
	virtual void Save(ofstream & Out);
	virtual void Load(ifstream & In);
};
