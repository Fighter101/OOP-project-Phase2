#include"Paste.h"
#include"..\ApplicationManager\ApplicationManager.h"
#include"..\Components\Gate.h"
Paste::Paste(ApplicationManager *x) : Action(x)
{
}

Paste::~Paste()
{
}

void Paste::ReadActionParameters()
{
	pManager->GetOutput()->PrintMsg("Click on where you want to paste");
	pManager->CheckPoint(x, y);
}

void Paste::Execute()
{
	ReadActionParameters();
	auto temp=pManager->getClipboard();
	GraphicsInfo Gfx(this->x, y);
	GraphicsInfo tmp3 = ((Gate*)temp[0])->GetPosition();
	for (size_t i = 0; i < temp.size(); i++)
	{
		if (IsInDesign(GraphicsInfo(Gfx - tmp3 + ((Gate*)temp[i])->GetPosition())))
		{
			temp[i]->SetPosition(GraphicsInfo(Gfx - tmp3 + ((Gate*)temp[i])->GetPosition()));
		}
		pManager->AddComponent(temp[i]);
	}
}

void Paste::Undo()
{
	//erase
}

void Paste::Redo()
{
}
