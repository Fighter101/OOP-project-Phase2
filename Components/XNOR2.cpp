#include "XNOR2.h"
#include"Connection.h"
XNOR2::XNOR2(const GraphicsInfo &r_GfxInfo) :Gate(2)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void XNOR2::Operate()
{
	//caclulate the output status as the XNORing of the two input pins

	m_InputPins[1].getConnection()->Operate();
	m_InputPins[2].getConnection()->Operate();



	m_OutputPin.setStatus(LOW);
	for (int i = 1; i <= 2; i++)
	{
		m_OutputPin.setStatus(m_OutputPin.getStatus() ^ m_InputPins[i].getStatus());
	}
	m_OutputPin.setStatus(~(m_OutputPin.getStatus()));



}


// Function Draw
// Draws 2-input XNOR gate
void XNOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXNOR2(this);
}

//returns status of outputpin
bool  XNOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
bool  XNOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XNOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void XNOR2::Erase(Output * pOut)
{
	pOut->EraseXNOR2(this);
}
void XNOR2::Save(ofstream & Out)
{
	Out << "XNOR2" << " " << ID << " " << Component::GetLabel() << Gate::GetPosition() << endl;
}

void XNOR2::Load(ifstream & In)
{
	string s;
	int x, y;
	In >> ID >> s >> x >> y;
	SetPosition(GraphicsInfo(x, y));
	SetLabel(s);

}