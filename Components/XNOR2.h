#ifndef _XNOR2_H
#define _XNOR2_H

/*
Class XNOR2
-----------
represent the 2-input XNOR gate
*/

#include "Gate.h"
class Connection;
class XNOR2 :public Gate
{
public:
	XNOR2(const GraphicsInfo &r_GfxInfo);
	virtual void Operate();	//Calculates the output of the XNOR gate
	virtual void Draw(Output* pOut);	//Draws 2-input gate
	InputPin* GetPin(int);
	virtual bool  GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual bool  GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual void Erase(Output*pOut);

	virtual void Save(ofstream & Out);

	virtual void Load(ifstream & In);

};

#endif