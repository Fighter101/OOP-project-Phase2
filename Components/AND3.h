#ifndef _AND3_H
#define _AND3_H

/*
Class AND3
-----------
represent the 3-input AND gate
*/

#include "Gate.h"
class Connection;
class AND3 :public Gate
{
public:
	AND3(const GraphicsInfo &r_GfxInfo);
	AND3(Gate*ptr);
	virtual Component* Copy(Gate* ptr);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	//Draws 3-input gate
	virtual void Erase(Output*pOut);
	virtual bool  GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual bool  GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual void Save(ofstream & Out);
	virtual void Load(ifstream & In);


};

#endif