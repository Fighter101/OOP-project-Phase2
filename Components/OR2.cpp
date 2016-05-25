#include "OR2.h"
#include"Connection.h"
OR2::OR2(const GraphicsInfo &r_GfxInfo) :Gate(2)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void OR2::Operate()
{
	//caclulate the output status as the ORing of the two input pins


	m_InputPins[0].getConnection()->Operate();
	m_InputPins[1].getConnection()->Operate();


	m_OutputPin.setStatus(LOW);
	for (int i = 1; i <= 2; i++)
	{
		m_OutputPin.setStatus(m_OutputPin.getStatus() | m_InputPins[i].getStatus());
	}


}


// Function Draw
// Draws 2-input OR gate
void OR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawOR2(this);
}

OR2::OR2(Gate * ptr)
	:Gate(ptr)
{
}

//returns status of outputpin
bool  OR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
bool  OR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void OR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void OR2::Erase(Output * pOut)
{
	pOut->EraseOR2(this);
}
void OR2::Save(ofstream & Out)
{
	Out << "OR2" << " " << ID << " " << Component::GetLabel() << " " << Gate::GetPosition() << endl;
}

void OR2::Load(ifstream & In)
{
	string s;
	int x, y;
	In >> ID >> s >> x >> y;
	SetPosition(GraphicsInfo(x, y));
	SetLabel(s);

}

Component * OR2::Copy(Gate * ptr)
{
	return new OR2(ptr);
}
