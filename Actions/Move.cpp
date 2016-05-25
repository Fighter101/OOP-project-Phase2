#include "Move.h"
#include"..\Components\Gate.h"
#include<vector>
#include"..\Defs.H"
Move::Move(ApplicationManager * pApp) : Action(pApp)
{
}

void Move::ReadActionParameters()
{
	pManager->GetOutput()->PrintMsg("Click on New Position to Move Gate and Connection to.");
}

void Move::Execute()
{
	ReadActionParameters();
	int x, y;

	pManager->CheckPoint(x, y);

	GraphicsInfo Gfx(x,y);
	
	auto temp= pManager->getSelected();
	GraphicsInfo temp2;
	GraphicsInfo temp3= ((Gate*)temp[0])->GetPosition();

	for (size_t i = 0; i < temp.size(); i++)
	{
		temp2 = Gfx - temp3 + ((Gate*)temp[i])->GetPosition();
		if (IsInDesign(temp2))
			((Gate*)temp[i])->SetPosition(temp2);
		else
			pManager->GetOutput()->PrintMsg("Position Not Available");
	}
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
