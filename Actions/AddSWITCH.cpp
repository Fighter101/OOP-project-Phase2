#include"AddSWITCH.h"
#include"..\ApplicationManager\ApplicationManager.h"
#include"..\Components\SWITCH.h"
AddSwitch::AddSwitch(ApplicationManager *x):Action(x)
{
}

AddSwitch::~AddSwitch()
{
}

void AddSwitch::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();


	//Print Action Message
	pOut->PrintMsg("Adding a Led Gate; Click to add the gate");

	//Wait for User Input
	pManager->CheckPoint(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void AddSwitch::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	GraphicsInfo GInfo(Cx, Cy); //Gfx info to be used to construct the Buffer

	SWITCH *pA = new SWITCH(GInfo);
	pManager->AddComponent(pA);
	pA->Draw(pManager->GetOutput());
}

void AddSwitch::Undo()
{
}

void AddSwitch::Redo()
{
}
