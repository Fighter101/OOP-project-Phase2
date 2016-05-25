#include "AND3.h"
#include"Connection.h"
AND3::AND3(const GraphicsInfo &r_GfxInfo) :Gate(3)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void AND3::Operate()
{
	//caclulate the output status as the ANDing of the three input pins

	//Add you code here
	m_InputPins[1].getConnection()->Operate();

	m_OutputPin = HIGH;
	for (int i = 1; i <= 3; i++)
	{
		m_OutputPin = m_OutputPin.getStatus() & m_InputPins[i].getStatus();
	}


}


// Function Draw
// Draws 3-input AND gate
void AND3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawAND3(this);
}

void AND3::Erase(Output * pOut)
{
	pOut->EraseAND3(this);
}

//returns status of outputpin
bool  AND3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
bool  AND3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void AND3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
void AND3::Save(ofstream & Out)
{
	Out << "AND3" << " " << ID << " " << Component::GetLabel() << " " << Gate::GetPosition() << endl;
}

void AND3::Load(ifstream & In)
{
	string s;
	int x, y;
	In >> ID >> s >> x >> y;
	SetPosition(GraphicsInfo(x, y));
	SetLabel(s);

}