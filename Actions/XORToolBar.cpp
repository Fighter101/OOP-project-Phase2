#include"XORToolBar.h"
#include"..\ApplicationManager.h"
XORToolBar::XORToolBar(ApplicationManager *x) : Action(x)
{
}

XORToolBar::~XORToolBar()
{
}

void XORToolBar::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMsg("XOR ToolBar created");
}

void XORToolBar::Execute()
{
	ReadActionParameters();
	pManager->GetOutput()->CreateXORToolBar();


}

void XORToolBar::Undo()
{
	pManager->GetOutput()->EraseXORToolBar();
}

void XORToolBar::Redo()
{
	pManager->GetOutput()->CreateXORToolBar();
}
