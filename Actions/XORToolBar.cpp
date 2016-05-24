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
	pManager->DrawToolBar(TOOLBARS::ADDXORBAR);
}

void XORToolBar::Undo()
{
	
}

void XORToolBar::Redo()
{
}
