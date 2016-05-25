#include "AddXNORgate2.h"
#include "..\ApplicationManager\ApplicationManager.h"

AddXNORgate2::AddXNORgate2(ApplicationManager *pApp) :Action(pApp)
{
}

AddXNORgate2::~AddXNORgate2(void)
{

}

void AddXNORgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();


	//Print Action Message
	pOut->PrintMsg("2-Input XNOR Gate: Click to add the gate");

	//Wait for User Input
	pManager->CheckPoint(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddXNORgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AllGateDimensions;
	int Wdth = UI.AllGateDimensions;

	//int Len =  UI.XNOR2_Width;
	//int Wdth = UI.XNOR2_Height;

	GraphicsInfo GInfo(Cx, Cy); //Gfx info to be used to construct the XNOR2 gate

	
	XNOR2 *pA = new XNOR2(GInfo);
	pManager->AddComponent(pA);
	pA->Draw(pManager->GetOutput());
}

void AddXNORgate2::Undo()
{}

void AddXNORgate2::Redo()
{}

