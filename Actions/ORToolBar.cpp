#include"ORToolBar.h"
#include"..\ApplicationManager\ApplicationManager.h"
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
	pManager->DrawToolBar(TOOLBARS::ADDORBAR);


}

void ORToolBar::Undo()
{
}

void ORToolBar::Redo()
{
}
