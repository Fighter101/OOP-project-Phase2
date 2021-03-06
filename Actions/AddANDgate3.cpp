#include "AddANDgate3.h"
#include "..\ApplicationManager\ApplicationManager.h"

AddANDgate3::AddANDgate3(ApplicationManager *pApp) :Action(pApp)
{
}

AddANDgate3::~AddANDgate3(void)
{
}

void AddANDgate3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	

	//Print Action Message
	pOut->PrintMsg("3-Input AND Gate: Click to add the gate");

	//Wait for User Input
	pManager->CheckPoint(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddANDgate3::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AllGateDimensions;
	int Wdth = UI.AllGateDimensions;

	//int Len =  UI.AND3_Width;
	//int Wdth = UI.AND3_Height;

	GraphicsInfo GInfo(Cx,Cy); //Gfx info to be used to construct the AND2 gate

	
	AND3 *pA = new AND3(GInfo);
	pManager->AddComponent(pA);
	pA->Draw(pManager->GetOutput());
}

void AddANDgate3::Undo()
{}

void AddANDgate3::Redo()
{}

