#include "Move.h"
#include"..\Components\Gate.h"
Move::Move(ApplicationManager * pApp)
	:Action(pApp)
{
}

void Move::ReadActionParameters()
{

}

void Move::Execute()
{
	ReadActionParameters();
}

void Move::Undo()
{
}

void Move::Redo()
{
}

Move::~Move()
{
}
