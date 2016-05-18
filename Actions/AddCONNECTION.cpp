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
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Connection building : Click on the Source pin of the connection");
	//Wait for user Input
	pIn->GetPointClicked(x1, y1);

//A lot of Validations is needed here before calling the next functions!
	//application Manager should validate here the previus clicked point is pin of gate 
	// it doesnt' matter it's an input pin or output pin just apin is needed and the next pin must be validated to insure it is the  the oppisite type
	//Print Action Message
	pOut->PrintMsg("Connection building : Click on the Destination pin of the connection");
	//Wait for user Input
	pIn->GetPointClicked(x2, y2);

	//clear sattus bar
	pOut->ClearStatusBar();
}


void AddCONNECTION::Execute()
{
	//Get Connection Source and destination points
	ReadActionParameters();
	GraphicsInfo GInfo;
	GInfo.x1 = this->x1;
	GInfo.x2 = this->x2;
	GInfo.y1 = this->y1;
	GInfo.y2 = this->y2;


	//Connection *pA = new Connection(GInfo);

}

void AddCONNECTION::Undo()
{
}

void AddCONNECTION::Redo()
{
}
