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
	pManager->DrawToolBar(6);
	if(pManager->getToolBar(4))
		pManager->GetOutput()->EraseDesignToolBar();
	if(pManager->getToolBar(5))
		pManager->GetOutput()->EraseSimulationToolBar();
	pManager->GetOutput()->CreateGatesToolBar();
	auto x=pManager->getMetaData();
	
	x[0]->SetState(!x[0]->GetState());
	x[0]->Draw(pManager->GetOutput());
}

void Select::Redo()
{
}

void Select::Undo()
{
}
