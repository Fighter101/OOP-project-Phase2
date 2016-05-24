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
	Component* y;
	for (size_t i = 0; i < x.size(); i++)
	{
		if (dynamic_cast<Gate*>(x[i]) || dynamic_cast<Connection*>(x[i]))
		{
			y = x[i];
		}
	}
	y->SetState(!y->GetState());
	y->Draw(pManager->GetOutput());
}

void Select::Redo()
{
}

void Select::Undo()
{
}
