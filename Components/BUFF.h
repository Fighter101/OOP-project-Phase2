#ifndef _BUFF_H
#define _BUFF_H

/*
Class BUFF
-----------
represent the BUFF 
*/

#include "Gate.h"
class Connection;
class BUFF :public Gate
{
public:
	BUFF(const GraphicsInfo &r_GfxInfo);
	virtual void Operate();	//Calculates the output of the BUFF gate
	virtual void Draw(Output* pOut);	//Draws 1-input gate
	virtual void Erase(Output*pOut);
	virtual bool  GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual bool  GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

	virtual void Save(ofstream & Out);

	virtual void Load(ifstream & In);


};

#endif