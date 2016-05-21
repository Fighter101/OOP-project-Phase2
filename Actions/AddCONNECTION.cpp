#include "AddCONNECTION.h"
#include "..\ApplicationManager.h"

AddCONNECTION::AddCONNECTION(ApplicationManager *pApp) :Action(pApp)
{
}

AddCONNECTION::~AddCONNECTION()
{
}

void AddCONNECTION::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	
	//Print Action Message
	pOut->PrintMsg("Connection building : Click on the Source pin of the connection");
	//Wait for user Input
	Src=(OutputPin*)pManager->CheckPoint(x1, y1);

//A lot of Validations is needed here before calling the next functions!
	//application Manager should validate here the previous clicked point is pin of gate 
	// it doesn't' matter it's an input pin or output pin just a pin is needed and the next pin must be validated to insure it is the opposite type
	//Print Action Message
	pOut->PrintMsg("Connection building : Click on the Destination pin of the connection");
	//Wait for user Input
	Dst=(InputPin*)pManager->CheckPoint(x2, y2);

	//clear status bar
	pOut->ClearStatusBar();
}


void AddCONNECTION::Execute()
{
	//Get Connection Source and destination points
	ReadActionParameters();
	GraphicsInfo GInfo(x1,y1,x2,y2);
	Connection *pA = new Connection(GInfo, Src, Dst);
	pA->Draw(pManager->GetOutput());

}

void AddCONNECTION::Undo()
{
}

void AddCONNECTION::Redo()
{
}
