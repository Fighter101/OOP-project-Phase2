#include "EditeLabel.h"
#include"..\ApplicationManager\ApplicationManager.h"
EditLabel::EditLabel(ApplicationManager * pApp):Action(pApp)
{

}

void EditLabel::ReadActionParameters()
{
	Output*pOut = pManager->GetOutput();
	ptr = pManager->getMetaData().front();
	pOut->PrintMsg("Now enter the new label");
	NewLabel = pManager->GetInput()->GetString(pOut);
}

void EditLabel::Execute()
{
	ReadActionParameters();
	ptr->SetLabel(NewLabel);
	pManager->GetOutput()->PrintMsg("The New label is : "+ ptr->GetLabel());
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
