#include "INV.h"
#include"Connection.h"
INV::INV(const GraphicsInfo &r_GfxInfo) :Gate(1)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void INV::Operate()
{
	//calculate the output status as the Inverting of the input pin
	m_InputPins[0].getConnection()->Operate();

	m_OutputPin.setStatus(~m_InputPins[0].getStatus());

}


// Function Draw
// Draws  INVer 
void INV::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawInverter(this);
}

INV::INV(Gate * ptr)
	:Gate(ptr)
{
}

//returns status of output-pin
bool  INV::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Input-pin #n
bool  INV::GetInputPinStatus(int n)
{
	return (bool) m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

void INV::Erase(Output * pOut)
{
	pOut->EraseInverter(this);
}

//Set status of an input pin to HIGH or LOW
void INV::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
void INV::Save(ofstream & Out)
{
	Out << "INVERTER" << " " << ID << " " << Component::GetLabel() << " " << Gate::GetPosition() << endl;
}

void INV::Load(ifstream & In)
{
	string s;
	int x, y;
	In >> ID >> s >> x >> y;
	SetPosition(GraphicsInfo(x, y));
	SetLabel(s);

}

Component * INV::Copy(Gate * ptr)
{
	return new INV(ptr);
}
