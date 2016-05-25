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
protected:
	static int counter;
	int ID;
	InputPin* m_InputPins;	//Array of input pins of the Gate
	OutputPin m_OutputPin;	//The Gate output pin
	int m_Inputs;		//No. of input pins of that Gate.
public:
	bool CheckPins();
	Gate(int r_Inputs);
	InputPin*GetInputPins();
	OutputPin & GetOutputPin();
	virtual void SetState(bool r_selected);
	virtual bool GetState();
	virtual GraphicsInfo GetPosition();
	virtual ActionType Leftpress();
	virtual ActionType RightPress();
	virtual void hover();
	virtual void released();
	//Same7
	Pin* GetFreeInputPins();
	virtual void Save(ofstream& Out) = 0;
	virtual void Load(ifstream &In) = 0;
};

#endif
