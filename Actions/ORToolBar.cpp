#include"ORToolBar.h"
#include"..\ApplicationManager.h"
ORToolBar::ORToolBar(ApplicationManager *x) : Action(x)
{
}

ORToolBar::~ORToolBar()
{
}

void ORToolBar::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMsg("OR ToolBar created");
}

void ORToolBar::Execute()
{
	ReadActionParameters();
	pManager->GetOutput()->CreateORToolBar();


}

void ORToolBar::Undo()
{
	pManager->GetOutput()->EraseORToolBar();
}

void ORToolBar::Redo()
{
	pManager->GetOutput()->CreateORToolBar();
}
