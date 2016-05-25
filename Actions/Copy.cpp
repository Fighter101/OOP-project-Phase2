#include"Copy.h"
#include"..\ApplicationManager\ApplicationManager.h"
#include"..\Components\Gate.h"
void Copy::ReadActionParameters()
{
	pManager->GetOutput()->PrintMsg("Selected Gates Copied");
}

void Copy::Execute()
{
	ReadActionParameters();
	auto vec = pManager->getSelected();
	vector<Component*>tmp;
	for (int i = 0; i < vec.size(); i++)
	{
		if (dynamic_cast<Gate*>(vec[i]))
		{
			tmp.push_back(((Gate*)vec[i])->Copy(((Gate*)vec[i])));
			tmp.back()->SetPosition(((Gate*)vec[i])->GetPosition());
		}
	}
	pManager->setClipboard(tmp);
}

void Copy::Undo()
{

}

void Copy::Redo()
{

}

Copy::Copy(ApplicationManager* x) :Action(x)
{

}

Copy::~Copy()
{

}
