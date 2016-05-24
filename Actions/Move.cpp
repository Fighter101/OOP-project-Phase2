#include "Move.h"
#include"..\Components\Gate.h"
Move::Move(ApplicationManager * pApp)
	:Action(pApp)
{
}

void Move::ReadActionParameters()
{
	int x, y;
	ptr=pManager->getMetaData().front();
	pManager->GetOutput()->PrintMsg("Click on the Gate's New position");
	pManager->CheckPoint(x,y);
	New = GraphicsInfo(x, y);

}

void Move::Execute()
{
	ReadActionParameters();
	ptr->Erase(pManager->GetOutput());
	//for (int i = 0; i < 2; i++)
	//{
	//	((Gate*)ptr)->GetInputPins()[i].EraseConnection();
	//}
	//((Gate*)ptr)->GetOutputPin().EraseConnection();
	
	ptr->SetPosition(New);
	ptr->Draw(pManager->GetOutput());
	((Gate*)ptr)->GetInputPins()->EraseConnection();
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
