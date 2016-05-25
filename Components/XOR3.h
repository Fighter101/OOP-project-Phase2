#ifndef _XOR3_H
#define _XOR3_H

/*
Class XOR3
-----------
represent the 3-input XOR gate
*/

#include "Gate.h"
class Connection;

class XOR3 :public Gate
{
public:
	XOR3(const GraphicsInfo &r_GfxInfo);
	virtual void Operate();	//Calculates the output of the XOR gate
	virtual void Draw(Output* pOut);	//Draws 3-input gate

	virtual bool  GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual bool  GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual void Erase(Output*pOut);
	
	virtual void Load(ifstream & In);
	XOR3(Gate * ptr);
	Component * Copy(Gate * ptr);
	virtual void Save(ofstream & Out);
};

#endif