#ifndef _INV_H
#define _INV_H

/*
Class INV
-----------
represent the INV
*/

#include "Gate.h"
class Connection;
class INV :public Gate
{
public:
	INV(const GraphicsInfo &r_GfxInfo);
	virtual void Operate();	//Calculates the output of the INV gate
	virtual void Draw(Output* pOut);	//Draws 1-input gate

	virtual bool  GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual bool  GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual void Erase(Output*pOut);
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

	virtual void Save(ofstream & Out);

	 virtual void Load(ifstream & In);

	InputPin* GetPin(int);
};

#endif