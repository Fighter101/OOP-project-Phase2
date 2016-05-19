#include"ANDToolBar.h"
#include"..\ApplicationManager.h"
ANDToolBar::ANDToolBar(ApplicationManager *x) : Action(x)
{
}

ANDToolBar::~ANDToolBar()
{
}

void ANDToolBar::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMsg("AND ToolBar created");
}

void ANDToolBar::Execute()
{
	ReadActionParameters();
	pManager->GetOutput()->CreateAndToolBar();


}

void ANDToolBar::Undo()
{
	pManager->GetOutput()->EraseAndToolBar();
}

void ANDToolBar::Redo()
{
	pManager->GetOutput()->CreateAndToolBar();
}
