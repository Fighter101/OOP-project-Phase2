#include "EditeLabel.h"
#include"..\ApplicationManager.h"
EditLabel::EditLabel(ApplicationManager * pApp):Action(pApp)
{

}

void EditLabel::ReadActionParameters()
{
	Output*pOut = pManager->GetOutput();
	pOut->PrintMsg("Starting Change Label Process..Press a Gate to select it");
	ptr = dynamic_cast<Component*>(pManager->GetInput()->GetUserAction().second.front());
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
