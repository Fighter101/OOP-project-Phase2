#ifndef _XNOR3_H
#define _XNOR3_H

/*
Class XNOR3
-----------
represent the 3-input XNOR gate
*/

#include "Gate.h"
class Connection;
class XNOR3 :public Gate
{
public:
	XNOR3(const GraphicsInfo &r_GfxInfo);
	virtual void Operate();	//Calculates the output of the XNOR gate
	virtual void Draw(Output* pOut);	//Draws 3-input gate

	virtual bool  GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual bool  GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual void Erase(Output*pOut);

	virtual void Save(ofstream & Out);

	virtual  void Load(ifstream & In);

	XNOR3(Gate * ptr);

	Component * Copy(Gate * ptr);

};

#endif