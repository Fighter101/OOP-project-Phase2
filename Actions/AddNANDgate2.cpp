#include "AddNANDgate2.h"
#include "..\ApplicationManager.h"

AddNANDgate2::AddNANDgate2(ApplicationManager *pApp) :Action(pApp)
{
}

AddNANDgate2::~AddNANDgate2(void)
{
}


void AddNANDgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	

	//Print Action Message
	pOut->PrintMsg("2-Input NAND Gate: Click to add the gate");

	//Wait for User Input
	pManager->CheckPoint(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddNANDgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AllGateDimensions;
	int Wdth = UI.AllGateDimensions;

	//int Len =  UI.NAND2_Width;
	//int Wdth = UI.NAND2_Height;

	GraphicsInfo GInfo(Cx, Cy); //Gfx info to be used to construct the NAND2 gate

	
	NAND2 *pA = new NAND2(GInfo);
	pManager->AddComponent(pA);
	pA->Draw(pManager->GetOutput());
}

void AddNANDgate2::Undo()
{}

void AddNANDgate2::Redo()
{}

