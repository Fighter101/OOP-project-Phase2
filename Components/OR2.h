#ifndef _OR2_H
#define _OR2_H

/*
Class OR2
-----------
represent the 2-input OR gate
*/

#include "Gate.h"
class Connection;
class OR2 :public Gate
{
public:
	OR2(const GraphicsInfo &r_GfxInfo);
	virtual void Operate();	//Calculates the output of the OR gate
	virtual void Draw(Output* pOut);	//Draws 2-input gate

	virtual bool  GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual bool  GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

	virtual void Erase(Output*pOut);
};

#endif