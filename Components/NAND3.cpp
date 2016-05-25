#include "NAND3.h"
#include"Connection.h"
NAND3::NAND3(const GraphicsInfo &r_GfxInfo) :Gate(3)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void NAND3::Operate()
{
	//caclulate the output status as the NANDing of the three input pins
	m_InputPins[1].getConnection()->Operate();
	m_InputPins[2].getConnection()->Operate();
	m_InputPins[3].getConnection()->Operate();



	m_OutputPin.setStatus(HIGH);
	for (int i = 1; i <= 3; i++)
	{
		m_OutputPin.setStatus(m_OutputPin.getStatus() & m_InputPins[i].getStatus());
	}
	m_OutputPin.setStatus(~(m_OutputPin.getStatus()));

}


// Function Draw
// Draws 3-input NAND gate
void NAND3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNAND3(this);
}


//returns status of outputpin
bool  NAND3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
bool  NAND3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NAND3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void NAND3::Erase(Output * pOut)
{
	pOut->EraseNAND3(this);
}
void NAND3::Save(ofstream & Out)
{
	Out << "NAND3" << " " << ID << " " << Component::GetLabel() << " " << Gate::GetPosition() << endl;
}

void NAND3::Load(ifstream & In)
{
	string s;
	int x, y;
	In >> ID >> s >> x >> y;
	SetPosition(GraphicsInfo(x, y));
	SetLabel(s);

}