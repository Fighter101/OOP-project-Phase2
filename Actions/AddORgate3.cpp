#include "AddORgate3.h"
#include "..\ApplicationManager.h"

AddORgate3::AddORgate3(ApplicationManager *pApp) :Action(pApp)
{
}

AddORgate3::~AddORgate3(void)
{
}

void AddORgate3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("3-Input OR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddORgate3::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AllGateDimensions;
	int Wdth = UI.AllGateDimensions;

	//int Len =  UI.OR3_Width;
	//int Wdth = UI.OR3_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the OR3 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	OR3 *pA = new OR3(GInfo);
	pManager->AddComponent(pA);
	pA->Draw(pManager->GetOutput());
}

void AddORgate3::Undo()
{}

void AddORgate3::Redo()
{}

