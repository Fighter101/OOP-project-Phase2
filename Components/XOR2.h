#ifndef _XOR2_H
#define _XOR2_H

/*
Class XOR2
-----------
represent the 2-input XOR gate
*/

#include "Gate.h"
class Connection;
class XOR2 :public Gate
{
public:
	XOR2(const GraphicsInfo &r_GfxInfo);
	virtual void Operate();	//Calculates the output of the XOR gate
	virtual void Draw(Output* pOut);	//Draws 2-input gate

	virtual bool  GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual bool  GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual void Erase(Output*pOut);

	virtual void Save(ofstream & Out);

	virtual	void Load(ifstream & In);

};

#endif