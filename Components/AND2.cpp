#include "AND2.h"
#include"Connection.h"
AND2::AND2(const GraphicsInfo &r_GfxInfo):Gate(2)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void AND2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here

	m_InputPins[1].getConnection()->Operate();
	m_InputPins[2].getConnection()->Operate();



	m_OutputPin.setStatus(HIGH);
	for (int i = 1; i <= 2; i++)
	{
		m_OutputPin.setStatus((STATUS)m_OutputPin.getStatus() & (STATUS)m_InputPins[i].getStatus());
	}



}


// Function Draw
// Draws 2-input AND gate
void AND2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawAND2(this);
}

void AND2::Erase(Output * pOut)
{
	pOut->EraseAND2(this);
}

//returns status of outputpin
bool AND2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
bool AND2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}


//Set status of an input pin ot HIGH or LOW
void AND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}

