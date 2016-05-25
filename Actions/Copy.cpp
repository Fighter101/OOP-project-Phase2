#include"Copy.h"
#include"..\ApplicationManager\ApplicationManager.h"
void Copy::ReadActionParameters()
{
	pManager->GetOutput()->PrintMsg("Selected Gates Copied");
}

void Copy::Execute()
{
	ReadActionParameters();
	pManager->setClipboard(pManager->getSelected());


}

void Copy::Undo()
{

}

void Copy::Redo()
{

}

Copy::Copy(ApplicationManager* x) :Action(x)
{

}

Copy::~Copy()
{

}
