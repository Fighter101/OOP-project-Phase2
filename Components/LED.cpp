#include "LED.h"
#include"Connection.h"
LED::LED(const GraphicsInfo &r_GfxInfo) :Gate(1)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void LED::Operate()
{
	//caclulate the output status as the ANDing of the input pin

	//Add you code here
	

	m_InputPins[1].getConnection()->Operate();



	//DRAW IT HIGH IF NEEDED ! MDawod


}


// Function Draw
// Draws 2-input AND gate
void LED::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawLED(this);
}

LED::LED(Gate * ptr)
	:Gate(ptr)
{
}

//returns status of outputpin
bool  LED::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
bool  LED::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void LED::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void LED::Erase(Output * pOut)
{
	pOut->EraseLED(this);
}
void LED::Save(ofstream & Out)
{
	Out << "LED" << " " << ID << " " << Component::GetLabel() << " " << Gate::GetPosition() << endl;
}

void LED::Load(ifstream & In)
{
	string s;
	int x, y;
	In >> ID >> s >> x >> y;
	SetPosition(GraphicsInfo(x, y));
	SetLabel(s);

}

Component * LED::Copy(Gate * ptr)
{
	return new LED(ptr);
}
