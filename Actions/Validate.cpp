#include"Validate.h"
#include"..\ApplicationManager\ApplicationManager.h"
#include<vector>
#include"..\Components\Gate.h"
Validate::Validate(ApplicationManager *x) : Action(x)
{

}

Validate::~Validate()
{
}

void Validate::ReadActionParameters()
{
}

void Validate::Execute()
{
	bool y = false;
	ReadActionParameters();
	auto x = pManager->getComponents();
	Gate* temp;
	for (size_t i = 0; i < x.size(); i++)
	{
		temp = dynamic_cast<Gate*>(x[i]);
		if (temp)
		{
			if (!temp->CheckPins())
			{
				y = true;
				temp->SetState(true);
			}
		}
	}
	if (y)
		pManager->GetOutput()->PrintMsg("Circuit Not Valid...There Exits a Pin Floating for these selected gates");
	else
	{
		pManager->setValid(true);
		pManager->GetOutput()->PrintMsg("Circuit Valid...You can Simulate");

	}
}

void Validate::Undo()
{
}

void Validate::Redo()
{
}
