#include "BUFF.h"
#include"Connection.h"
BUFF::BUFF(const GraphicsInfo &r_GfxInfo) :Gate(1)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void BUFF::Operate()
{
	//caclulate the output status as the BUFFering of the the input pin

	//Add you code here
	m_InputPins[1].getConnection()->Operate();
	m_OutputPin.setStatus(m_InputPins[1].getStatus());

}


// Function Draw
// Draws  BUFFer 
void BUFF::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawBuffer(this);
}

void BUFF::Erase(Output * pOut)
{
	pOut->EraseBuffer(this);
}

//returns status of outputpin
bool  BUFF::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
bool  BUFF::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void BUFF::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
