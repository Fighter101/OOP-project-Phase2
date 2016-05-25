#include "Select.h"
#include"..\ApplicationManager\ApplicationManager.h"
#include<vector>
#include"..\Components\Connection.h"
#include"..\Components\Gate.h"
#include"..\Components\SWITCH.h"
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
	if(!pManager->getSim())
		pManager->getTemp()->SetState(!pManager->getTemp()->GetState());
	
	SWITCH* x = dynamic_cast<SWITCH*>(pManager->getTemp());
	if (x && pManager->getSim())
	{
		x->turnONOFF(!x->getONOFF());
	}
}

void Select::Redo()
{
}

void Select::Undo()
{
}
