#include "AddANDgate2.h"
#include "..\ApplicationManager\ApplicationManager.h"

AddANDgate2::AddANDgate2(ApplicationManager *pApp):Action(pApp)
{
}

AddANDgate2::~AddANDgate2(void)
{

}

void AddANDgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	
	//Print Action Message
	pOut->PrintMsg("2-Input AND Gate: Click to add the gate");

	//Wait for User Input
	pManager->CheckPoint(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
	
}

void AddANDgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	
	//Calculate the rectangle Corners
	int Len =  UI.AllGateDimensions;
	int Wdth = UI.AllGateDimensions;

	//int Len =  UI.AND2_Width;
	//int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo(Cx,Cy); //Gfx info to be used to construct the AND2 gate
	

	AND2 *pA=new AND2(GInfo); 
	pManager->AddComponent(pA);
	pA->Draw(pManager->GetOutput());
}

void AddANDgate2::Undo()
{}

void AddANDgate2::Redo()
{}

