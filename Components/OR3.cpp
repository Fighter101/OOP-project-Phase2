#include "OR3.h"
#include"Connection.h"
OR3::OR3(const GraphicsInfo &r_GfxInfo) :Gate(3)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void OR3::Operate()
{
	//caclulate the output status as the ORing of the three input pins



	m_InputPins[1].getConnection()->Operate();
	m_InputPins[2].getConnection()->Operate();
	m_InputPins[3].getConnection()->Operate();



	m_OutputPin.setStatus(LOW);
	for (int i = 1; i <= 3; i++)
	{
		m_OutputPin.setStatus(m_OutputPin.getStatus() | m_InputPins[i].getStatus());
	}
}


// Function Draw
// Draws 3-input OR gate
void OR3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawOR3(this);
}

//returns status of outputpin
bool  OR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
bool  OR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void OR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void OR3::Erase(Output * pOut)
{
	pOut->EraseOR3(this);
}
