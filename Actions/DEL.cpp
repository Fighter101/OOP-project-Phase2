#include "DEL.h"
#include"..\ApplicationManager\ApplicationManager.h"
#include<vector>
Delete::Delete(ApplicationManager *x) : Action(x)
{
}

Delete::~Delete()
{
}

void Delete::ReadActionParameters()
{
	pManager->GetOutput()->PrintMsg("Selected objects Deleted");
}

void Delete::Execute()
{
	pManager->DeleteThis(pManager->getMetaData());
}

void Delete::Undo()
{
}

void Delete::Redo()
{
}
