#include "ApplicationManager.h"
#include"AddToolBar.h"
#include"Actions\AddBUFF.h"
#include"Actions\AddINV.h"
#include"Actions\AddANDgate2.h"
#include"Actions\AddORgate2.h"
#include"Actions\AddNANDgate2.h"
#include"Actions\AddNORgate2.h"
Action * ApplicationManager::ActionCreator(ActionType x)
{
	switch (x)
	{
	case ADD:
		return new AddToolBar(this);
		break;
	case ADD_Buff:
		return new AddBUFF(this);
		break;
	case ADD_INV:
		return new AddINV(this);
		break;
	case ADD_AND_GATE_2:
		return new AddANDgate2(this);
		break;
	case ADD_OR_GATE_2:
		return new AddORgate2(this);
		break;
	case ADD_NAND_GATE_2:
		return new AddNANDgate2(this);
		break;
	case ADD_NOR_GATE_2:

		break;
	case ADD_XOR_GATE_2:
		break;
	case ADD_XNOR_GATE_2:
		break;
	case ADD_AND_GATE_3:
		break;
	case ADD_NOR_GATE_3:
		break;
	case ADD_XOR_GATE_3:
		break;
	case ADD_Switch:
		break;
	case ADD_LED:
		break;
	case ADD_CONNECTION:
		break;
	case ADD_Label:
		break;
	case EDIT_Label:
		break;
	case Create_TruthTable:
		break;
	case Change_Switch:
		break;
	case SELECT:
		break;
	case DEL:
		break;
	case MOVE:
		break;
	case COPY:
		break;
	case CUT:
		break;
	case PASTE:
		break;
	case VALIDATE:
		break;
	case SAVE:
		break;
	case LOAD:
		break;
	case PROBE:
		break;
	case UNDO:
		break;
	case REDO:
		break;
	case DSN_MODE:
		break;
	case SIM_MODE:
		break;
	case EXIT:
		break;
	case STATUS_BAR:
		break;
	case DSN_TOOL:
		break;
	case DSN_AREA:
		break;
	default:
		return nullptr;
		break;
	}
}

ApplicationManager::ApplicationManager()
{
	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	ComponentList.push_back(pComp);
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is required from the user
	pair<ActionType, vector<GridItem*>> x= InputInterface->GetUserAction(); 
	for (size_t i = 0; i < x.second.size(); i++)
	{
		temp.push_back((Component*) x.second[i]);
	}
	return x.first;

}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = ActionCreator(ActType);
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = nullptr;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
		//null

}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for (size_t i = 0; i < ComponentList.size(); i++)
	{
		delete ComponentList[i];
	}
	for (size_t i = 0; i < temp.size(); i++)
	{
		delete temp[i];
	}
	delete OutputInterface;
	delete InputInterface;
	
}