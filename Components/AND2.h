#ifndef _AND2_H
#define _AND2_H

/*
  Class AND2
  -----------
  represent the 2-input AND gate
*/

#include "Gate.h"
class Connection;
class AND2:public Gate
{
public:
	AND2(const GraphicsInfo &r_GfxInfo);
	AND2(Gate*ptr);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	//Draws 2-input gate
	virtual void Erase(Output*pOut);
	virtual bool GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual bool GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual void Save(ofstream &Out);
	virtual void Load(ifstream &In);
	virtual Component* Copy(Gate* ptr);
};

#endif