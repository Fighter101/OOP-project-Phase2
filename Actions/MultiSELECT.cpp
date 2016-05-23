#include "MultiSELECT.h"
#include"..\ApplicationManager.h"
#include"..\Components\Gate.h"
MultiSelect::MultiSelect(ApplicationManager *x) : Action(x)
{

}

MultiSelect::~MultiSelect()
{

}

void MultiSelect::ReadActionParameters()
{
	pManager->GetOutput()->PrintMsg("Start Selecting Items");
}

void MultiSelect::Execute()
{
	Output* pOut = pManager->GetOutput();
	int i=0;
	
	ActionType act;
	GridItem* temp;
	Component* Selection;
	
	ReadActionParameters();
	while (true)
	{
		pOut->PrintMsg(to_string(i) +" Items Selected....To Stop Press on Select Again");
		auto x = pManager->GetInput()->GetUserAction();
		act = x.first;
		temp = x.second.front();
		if (act  == ActionType::MultiSELECT)
		{
			pOut->PrintMsg(to_string(i) + " Items Selected....Selection stooped");
			break;
		}
		if (temp == nullptr)
			continue;
		Selection = dynamic_cast<Component*>(temp);
		if (Selection == nullptr)
			continue;
		Selection->SetState(!Selection->GetState());
		Selection->Draw(pOut);

		if (Selection->GetState())
		{
			i++;
			pManager->AppendMetaData(Selection);
		}
		else
		{
			i--;
			pManager->RemoveMetaData(Selection);
		}
	}
}

void MultiSelect::Redo()
{

}

void MultiSelect::Undo()
{

}
