#include"AddLED.h"
#include"..\ApplicationManager.h"
#include"..\Components\LED.h"
AddLED::AddLED(ApplicationManager*x) : Action(x)
{
}

AddLED::~AddLED()
{
}

void AddLED::ReadActionParameters()
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

void AddLED::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	GraphicsInfo GInfo(Cx, Cy); //Gfx info to be used to construct the Buffer

	LED *pA = new LED(GInfo);
	pManager->AddComponent(pA);
	pA->Draw(pManager->GetOutput());
}

void AddLED::Undo()
{
}

void AddLED::Redo()
{
}
