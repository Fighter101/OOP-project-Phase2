#include "SWITCH.h"
#include"Connection.h"
SWITCH::SWITCH(const GraphicsInfo &r_GfxInfo) :Gate(2)
{
	ONOFF = false; //MDawod
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void SWITCH::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
	ONOFF ? m_OutputPin.setStatus(HIGH) : m_OutputPin.setStatus(LOW);


}


// Function Draw
// Draws 2-input AND gate
void SWITCH::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawSwitch(this);
}

//returns status of outputpin
bool  SWITCH::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
bool  SWITCH::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void SWITCH::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void SWITCH::Erase(Output * pOut)
{
	pOut->EraseSwitch(this);
}
void SWITCH::Save(ofstream & Out)
{
	Out << "SWITCH" << " " << ID << " " << Component::GetLabel() << " " << Gate::GetPosition() << endl;
}

void SWITCH::Load(ifstream & In)
{
	string s;
	int x, y;
	In >> ID >> s >> x >> y;
	SetPosition(GraphicsInfo(x, y));
	SetLabel(s);

}