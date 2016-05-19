#include"CUT.h"
#include"..\ApplicationManager.h"
void Cut::ReadActionParameters()
{
	pManager->GetOutput()->PrintMsg("Selected Gates Copied");
}

void Cut::Execute()
{
	ReadActionParameters();
	pManager->setClipboard(pManager->getMetaData());
	pManager->DeleteThis(pManager->getMetaData());
	
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
