#ifndef _SWITCH_H
#define _SWITCH_H

/*
Class SWITCH
-----------
represent the switch
*/

#include "Gate.h"
class Connection;
class SWITCH :public Gate
{
private:
	bool ONOFF;
public:
	SWITCH(const GraphicsInfo &r_GfxInfo);
	virtual void Operate();	//Calculates the output of switch
	virtual void Draw(Output* pOut);	//Draws switch
	virtual bool  GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual bool  GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	SWITCH(Gate*ptr);
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual void Erase(Output*pOut);
	void turnONOFF(bool x);
	bool getONOFF();
	virtual void Save(ofstream & Out);

	virtual void Load(ifstream & In);
	virtual Component* Copy(Gate* ptr);

};

#endif