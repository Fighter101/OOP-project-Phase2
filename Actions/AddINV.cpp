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


	//Print Action Message
	pOut->PrintMsg("Adding an Inverter Gate; Click to add the gate");

	//Wait for User Input
	pManager->CheckPoint(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddINV::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	GraphicsInfo GInfo(Cx,Cy); //Gfx info to be used to construct the Buffer

	
	INV *pA = new INV(GInfo);
	pManager->AddComponent(pA);
	pA->Draw(pManager->GetOutput());
}

void AddINV::Undo()
{}

void AddINV::Redo()
{}

