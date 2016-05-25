#include "XOR2.h"
#include"Connection.h"
XOR2::XOR2(const GraphicsInfo &r_GfxInfo) :Gate(2)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void XOR2::Operate()
{
	//caclulate the output status as the XORing of the two input pins


	m_InputPins[0].getConnection()->Operate();
	m_InputPins[1].getConnection()->Operate();



	m_OutputPin.setStatus(LOW);
	for (int i = 0; i <= 1; i++)
	{
		m_OutputPin.setStatus(m_OutputPin.getStatus() ^ m_InputPins[i].getStatus());
	}

}


// Function Draw
// Draws 2-input XOR gate
void XOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXOR2(this);
}

//returns status of outputpin
bool  XOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
bool  XOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH XOR LOW
void XOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void XOR2::Erase(Output * pOut)
{
	pOut->EraseXOR2(this);
}
void XOR2::Save(ofstream & Out)
{
	Out << "XOR2" << " " << ID << " " << Component::GetLabel() << " " << Gate::GetPosition() << endl;
}

void XOR2::Load(ifstream & In)
{
	string s;
	int x, y;
	In >> ID >> s >> x >> y;
	SetPosition(GraphicsInfo(x, y));
	SetLabel(s);

}
XOR2::XOR2(Gate * ptr)
	:Gate(ptr)
{
}

Component * XOR2::Copy(Gate * ptr)
{
	return new XOR2(ptr);
}
