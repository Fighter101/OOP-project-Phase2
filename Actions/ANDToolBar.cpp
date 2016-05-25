#include"ANDToolBar.h"
#include"..\ApplicationManager\ApplicationManager.h"
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
	pManager->DrawToolBar(TOOLBARS::ADDANDBAR);


}

void ANDToolBar::Undo()
{
}

void ANDToolBar::Redo()
{
}
