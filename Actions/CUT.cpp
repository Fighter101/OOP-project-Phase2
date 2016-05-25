#include"CUT.h"
#include"..\ApplicationManager\ApplicationManager.h"
void Cut::ReadActionParameters()
{
	pManager->GetOutput()->PrintMsg("Selected Gates Removed and Added to Clipboard");
}

void Cut::Execute()
{
	ReadActionParameters();
	pManager->setClipboard(pManager->getSelected());
	pManager->DeleteThis(pManager->getSelected());
	
}

void Cut::Undo()
{

}

void Cut::Redo()
{

}

Cut::Cut(ApplicationManager* x) :Action(x)
{

}

Cut::~Cut()
{

}
