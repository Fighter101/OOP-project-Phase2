#ifndef _COMPONENT_H
#define _COMPONENT_H

//#include "..\Defs.h"
#include "..\GUI\Output.h"

//Base class for classes Gate, Switch, and LED.
class Component:public GridItem
{
private:
	string m_Label;
	
protected:
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	bool Selected;
public:
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself
	virtual void Erase(Output*pOut) = 0;
	virtual ActionType Leftpress() = 0;
	virtual ActionType RightPress() = 0;
	virtual void hover() = 0;
	virtual void released() = 0;
	virtual bool GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual bool GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1
	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	virtual void SetState(bool x) = 0;
	virtual bool GetState() = 0;
	virtual void SetPosition(GraphicsInfo);
	Component();	
	virtual void Save(ofstream& Out)=0;
	virtual void Load(ifstream & In)=0;
	
	//Hassan
	string GetLabel();
	void SetLabel(string r_label);

	//Destructor must be virtual
	virtual ~Component();
};

#endif