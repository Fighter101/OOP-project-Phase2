#include "NOR2.h"
#include"Connection.h"
NOR2::NOR2(const GraphicsInfo &r_GfxInfo) :Gate(2)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void NOR2::Operate()
{
	//caclulate the output status as the NORing of the two input pins

	m_InputPins[1].getConnection()->Operate();
	m_InputPins[2].getConnection()->Operate();



	m_OutputPin.setStatus(LOW);
	for (int i = 1; i <= 2; i++)
	{
		m_OutputPin.setStatus(m_OutputPin.getStatus() | m_InputPins[i].getStatus());
	}
	m_OutputPin.setStatus(~(m_OutputPin.getStatus()));

}


// Function Draw
// Draws 2-input NOR gate
void NOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNOR2(this);
}

//returns status of outputpin
bool  NOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
bool  NOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void NOR2::Erase(Output * pOut)
{
	pOut->EraseNOR2(this);
}
