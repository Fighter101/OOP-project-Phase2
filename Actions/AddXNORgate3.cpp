#include "AddXNORgate3.h"
#include "..\ApplicationManager\ApplicationManager.h"

AddXNORgate3::AddXNORgate3(ApplicationManager *pApp) :Action(pApp)
{
}

AddXNORgate3::~AddXNORgate3(void)
{
}

void AddXNORgate3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();


	//Print Action Message
	pOut->PrintMsg("3-Input XNOR Gate: Click to add the gate");

	//Wait for User Input
	pManager->CheckPoint(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddXNORgate3::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AllGateDimensions;
	int Wdth = UI.AllGateDimensions;

	//int Len =  UI.XNOR3_Width;
	//int Wdth = UI.XNOR3_Height;

	GraphicsInfo GInfo(Cx, Cy); //Gfx info to be used to construct the XNOR3 gate

	
	XNOR3 *pA = new XNOR3(GInfo);
	pManager->AddComponent(pA);
	pA->Draw(pManager->GetOutput());
}

void AddXNORgate3::Undo()
{}

void AddXNORgate3::Redo()
{}

