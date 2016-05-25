#include "Select.h"
#include"..\ApplicationManager\ApplicationManager.h"
#include<vector>
#include"..\Components\Connection.h"
#include"..\Components\Gate.h"
Select::Select(ApplicationManager * x, Component* y) : Action(x)
{
	
}

Select::~Select()
{
}

void Select::ReadActionParameters()
{
	pManager->GetOutput()->PrintMsg("Component Selected");
}

void Select::Execute()
{
	ReadActionParameters();
	pManager->getTemp()->SetState(!pManager->getTemp()->GetState());
}

void Select::Redo()
{
}

void Select::Undo()
{
}
