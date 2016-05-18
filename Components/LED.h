#ifndef _LED_H
#define _LED_H

/*
Class LED
-----------
represent the LED
*/

#include "Gate.h"

class LED :public Gate
{
public:
	LED(const GraphicsInfo &r_GfxInfo);
	virtual void Operate();	//Calculates the output of the LED gate
	virtual void Draw(Output* pOut);	//Draws LED

	virtual bool  GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual bool  GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.


};

#endif