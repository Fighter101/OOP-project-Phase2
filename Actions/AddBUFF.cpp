#include "AddBUFF.h"
#include "..\ApplicationManager.h"

AddBUFF::AddBUFF(ApplicationManager *pApp) :Action(pApp)
{
}

AddBUFF::~AddBUFF(void)
{

}

void AddBUFF::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	

	//Print Action Message
	pOut->PrintMsg("Adding a Buffer Gate; Click to add the gate");

	//Wait for User Input
	pManager->CheckPoint(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddBUFF::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.BufferDimensions;
	int Wdth = UI.BufferDimensions;

	
	GraphicsInfo GInfo(Cx, Cy); //Gfx info to be used to construct the Buffer


	BUFF *pA = new BUFF(GInfo);
	pManager->AddComponent(pA);
	pA->Draw(pManager->GetOutput());
}

void AddBUFF::Undo()
{
	
}

void AddBUFF::Redo()
{
}

