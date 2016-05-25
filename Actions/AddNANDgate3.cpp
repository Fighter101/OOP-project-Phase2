#include "AddNANDgate3.h"
#include "..\ApplicationManager\ApplicationManager.h"

AddNANDgate3::AddNANDgate3(ApplicationManager *pApp) :Action(pApp)
{
}

AddNANDgate3::~AddNANDgate3(void)
{
}

void AddNANDgate3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();


	//Print Action Message
	pOut->PrintMsg("3-Input NAND Gate: Click to add the gate");

	//Wait for User Input
	pManager->CheckPoint(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddNANDgate3::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AllGateDimensions;
	int Wdth = UI.AllGateDimensions;

	//int Len =  UI.NAND3_Width;
	//int Wdth = UI.NAND3_Height;

	GraphicsInfo GInfo(Cx, Cy); //Gfx info to be used to construct the NAND3 gate


	NAND3 *pA = new NAND3(GInfo);
	pManager->AddComponent(pA);
	pA->Draw(pManager->GetOutput());
}

void AddNANDgate3::Undo()
{}

void AddNANDgate3::Redo()
{}

