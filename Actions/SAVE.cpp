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
