#include"SAVE.h"
#include"..\ApplicationManager.h"

Save::Save(ApplicationManager *x) : Action (x)
{

}

Save::~Save()
{
}

void Save::ReadActionParameters()
{
	pManager->GetOutput()->PrintMsg("Now Saving This Project Onto a File....Insert Path to Save onto or leave empty for DEFAULT");
	pManager->GetOutput();
}

void Save::Execute()
{
	ReadActionParameters();
}

void Save::Undo()
{
}

void Save::Redo()
{
}
