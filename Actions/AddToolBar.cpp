#include"AddToolBar.h"
#include"..\ApplicationManager.h"
AddToolBar::AddToolBar(ApplicationManager *x) : Action(x)
{
}

AddToolBar::~AddToolBar()
{
}

void AddToolBar::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMsg("Add ToolBar created");
}

void AddToolBar::Execute()
{
	ReadActionParameters();
	pManager->GetOutput()->CreateAddToolBar();

//	Undo();
}

void AddToolBar::Undo()
{
	pManager->GetOutput()->EraseAddToolBar();
}

void AddToolBar::Redo()
{
	pManager->GetOutput()->CreateDesignToolBar();
}
