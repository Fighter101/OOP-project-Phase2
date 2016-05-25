#include "MultiSELECT.h"
#include"..\ApplicationManager\ApplicationManager.h"
#include"..\Components\Gate.h"
MultiSelect::MultiSelect(ApplicationManager *x) : Action(x)
{

}

MultiSelect::~MultiSelect()
{

}

void MultiSelect::ReadActionParameters()
{
	pManager->GetOutput()->PrintMsg("Start Selecting Items");
}

void MultiSelect::Execute()
{
	ReadActionParameters();
}

void MultiSelect::Redo()
{

}

void MultiSelect::Undo()
{

}
