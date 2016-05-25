#include"CUT.h"
#include"..\ApplicationManager\ApplicationManager.h"
#include"..\Components\Gate.h"
void Cut::ReadActionParameters()
{
	pManager->GetOutput()->PrintMsg("Selected Gates Removed and Added to Clipboard");
}

void Cut::Execute()
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
	pManager->DeleteThis(pManager->getSelected());
}


void Cut::Undo()
{

}

void Cut::Redo()
{

}

Cut::Cut(ApplicationManager* x) :Action(x)
{

}

Cut::~Cut()
{

}
