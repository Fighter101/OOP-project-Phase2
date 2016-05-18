#include "AddINV.h"
#include "..\ApplicationManager.h"

AddINV::AddINV(ApplicationManager *pApp) :Action(pApp)
{
}

AddINV::~AddINV(void)
{
}

void AddINV::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Buffer : Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddINV::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.BufferDimensions;
	int Wdth = UI.BufferDimensions;


	GraphicsInfo GInfo; //Gfx info to be used to construct the Buffer

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	INV *pA = new INV(GInfo);
	pManager->AddComponent(pA);
}

void AddINV::Undo()
{}

void AddINV::Redo()
{}

