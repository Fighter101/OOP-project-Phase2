#ifndef _NAND3_H
#define _NAND3_H

/*
Class NAND3
-----------
represent the 3-input NAND gate
*/

#include "Gate.h"
class Connection;
class NAND3 :public Gate
{
public:
	NAND3(const GraphicsInfo &r_GfxInfo);
	virtual void Operate();	//Calculates the output of the NAND gate
	virtual void Draw(Output* pOut);	//Draws 3-input gate
	NAND3(Gate*ptr);
	virtual bool  GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual bool  GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual void Erase(Output*pOut);

	virtual void Save(ofstream & Out);

	virtual void Load(ifstream & In);
	virtual Component* Copy(Gate* ptr);
};

#endif