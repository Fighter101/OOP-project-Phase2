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

	
	auto x=pManager->getMetaData();
	auto y = x.back();
	y->SetState(!y->GetState());
	if (y->GetState())
		pManager->DrawToolBar(TOOLBARS::GATE);
	else
		pManager->DrawToolBar(TOOLBARS::DSGN);
}

void Select::Redo()
{
}

void Select::Undo()
{
}
