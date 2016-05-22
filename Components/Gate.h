#ifndef _GATE_H
#define _GATE_H

/*
  Class Gate
  -----------
  - Base class for all types of gates
  - Each gate has n inputs pins and one output pin
*/


#include "..\Pin\InputPin.h"
#include "..\Pin\OutputPin.h"
#include "Component.h"

class LED;
class SWITCH;




class Gate:public Component
{
	bool Selected;
protected:
	InputPin* m_InputPins;	//Array of input pins of the Gate
	OutputPin m_OutputPin;	//The Gate output pin
	int m_Inputs;		//No. of input pins of that Gate.
public:
	bool CheckPins();
	Gate(int r_Inputs);
	InputPin*GetInputPins();
	OutputPin & GetOutputPin();
	virtual void SetState(bool r_selected);
	virtual GraphicsInfo GetPosition();
	virtual bool GetState();
	virtual ActionType Leftpress();
	virtual ActionType RightPress();
	virtual void hover();
	virtual void released();



};

#endif
