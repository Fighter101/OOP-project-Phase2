#include "Select.h"
#include"..\ApplicationManager.h"
#include<vector>
#include"..\Components\Connection.h"
#include"..\Components\Gate.h"
Select::Select(ApplicationManager * x) : Action(x)
{
	
}

Select::~Select()
{
}

void Select::ReadActionParameters()
{
	pManager->GetOutput()->PrintMsg("Gate Selected");
}

void Select::Execute()
{
	ReadActionParameters();

	pManager->DrawToolBar(TOOLBARS::GATE);
	
	auto x=pManager->getMetaData();

	x[0]->SetState(!x[0]->GetState());
}

void Select::Redo()
{
}

void Select::Undo()
{
}
