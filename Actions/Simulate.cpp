#include "Simulate.h"
#include"..\ApplicationManager\ApplicationManager.h"
Simulate::Simulate(ApplicationManager* x) : Action(x)
{
}

Simulate::~Simulate()
{
}

void Simulate::ReadActionParameters()
{
	pManager->GetOutput()->PrintMsg("Simulation Started....");
}

void Simulate::Execute()
{
	pManager->setSim(true);
	auto x = pManager->getLeds();
	for (size_t i = 0; i < x.size(); i++)
	{
		x[i]->Operate();
	}
}

void Simulate::Redo()
{
}

void Simulate::Undo()
{
}
