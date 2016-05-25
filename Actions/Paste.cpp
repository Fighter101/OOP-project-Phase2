#include"Paste.h"
#include"..\ApplicationManager\ApplicationManager.h"
Paste::Paste(ApplicationManager *x) : Action(x)
{
}

Paste::~Paste()
{
}

void Paste::ReadActionParameters()
{
	pManager->GetOutput()->PrintMsg("Pasting Items From Clipboard");
}

void Paste::Execute()
{
	ReadActionParameters();
	auto x=pManager->getClipboard();
	for (size_t i = 0; i < x.size(); i++)
	{
		pManager->AddComponent(x[i]);
	}
}

void Paste::Undo()
{
	//erase
}

void Paste::Redo()
{
}
