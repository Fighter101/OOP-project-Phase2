#include "EditeLabel.h"
#include"..\ApplicationManager\ApplicationManager.h"
EditLabel::EditLabel(ApplicationManager * pApp):Action(pApp)
{

}

void EditLabel::ReadActionParameters()
{
	Output*pOut = pManager->GetOutput();
	ptr = pManager->getSelected();
	pOut->PrintMsg("Now enter the new label");
	NewLabel = pManager->GetInput()->GetString(pOut);
}

void EditLabel::Execute()
{
	ReadActionParameters();
	for (size_t i = 0; i < ptr.size(); i++)
	{
		ptr[i]->SetLabel(NewLabel);
	}

	pManager->GetOutput()->PrintMsg("The New label is : "+ ptr[0]->GetLabel());
}

void EditLabel::Undo()
{
}

void EditLabel::Redo()
{
}

EditLabel::~EditLabel()
{
}
