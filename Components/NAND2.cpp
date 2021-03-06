#include "NAND2.h"
#include"Connection.h"
NAND2::NAND2(const GraphicsInfo &r_GfxInfo) :Gate(2)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void NAND2::Operate()
{
	//caclulate the output status as the NANDing of the two input pins

	m_InputPins[0].getConnection()->Operate();
	m_InputPins[1].getConnection()->Operate();


	m_OutputPin.setStatus(HIGH);
	for (int i = 0; i <= 1; i++)
	{
		m_OutputPin.setStatus(m_OutputPin.getStatus() & m_InputPins[i].getStatus());
	}
	m_OutputPin.setStatus(~(m_OutputPin.getStatus()));



}


// Function Draw
// Draws 2-input NAND gate
void NAND2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNAND2(this);
}

NAND2::NAND2(Gate * ptr)
	:Gate(ptr)
{
}



//returns status of outputpin
bool  NAND2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
bool  NAND2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NAND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void NAND2::Erase(Output * pOut)
{
	pOut->EraseNAND2(this);
}
void NAND2::Save(ofstream & Out)
{
	Out << "NAND2" << " " << ID << " " << Component::GetLabel() << " " << Gate::GetPosition() << endl;
}

void NAND2::Load(ifstream & In)
{
	string s;
	int x, y;
	In >> ID >> s >> x >> y;
	SetPosition(GraphicsInfo(x, y));
	SetLabel(s);

}

Component * NAND2::Copy(Gate * ptr)
{
	return new NAND2(ptr);
}
