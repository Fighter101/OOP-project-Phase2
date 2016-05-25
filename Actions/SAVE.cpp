#include"SAVE.h"
#include"..\ApplicationManager\ApplicationManager.h"
#include"..\Components\Gate.h"
#include"..\Components\Connection.h"
Save::Save(ApplicationManager *x) : Action (x)
{

}

Save::~Save()
{
}

void Save::ReadActionParameters()
{
	pManager->GetOutput()->PrintMsg("Saving Done");
}

void Save::Execute()
{
	ReadActionParameters();
	ofstream Out("Save.3lawd3o");
	vector<Component*> vec = pManager->getComponents();
	for (int i = 0; i < vec.size(); i++)
	{
		if (dynamic_cast<Gate*>(vec[i]))
		{
			vec[i]->Save(Out);
		}
	}
	Out << "Connections" << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		if (dynamic_cast<Connection*>(vec[i]))
		{
			vec[i]->Save(Out);
		}
	}
	Out << "-1";
}

void Save::Undo()
{
}

void Save::Redo()
{
}
