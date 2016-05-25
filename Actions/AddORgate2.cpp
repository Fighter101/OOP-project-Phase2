#include "AddORgate2.h"
#include "..\ApplicationManager\ApplicationManager.h"

AddORgate2::AddORgate2(ApplicationManager *pApp) :Action(pApp)
{
}

AddORgate2::~AddORgate2(void)
{
}

void AddORgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();


	//Print Action Message
	pOut->PrintMsg("2-Input OR Gate: Click to add the gate");

	//Wait for User Input
	pManager->CheckPoint(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddORgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AllGateDimensions;
	int Wdth = UI.AllGateDimensions;

	//int Len =  UI.OR2_Width;
	//int Wdth = UI.OR2_Height;

	GraphicsInfo GInfo(Cx, Cy); //Gfx info to be used to construct the OR2 gate

	
	OR2 *pA = new OR2(GInfo);
	pManager->AddComponent(pA);
	pA->Draw(pManager->GetOutput());
}

void AddORgate2::Undo()
{}

void AddORgate2::Redo()
{}

