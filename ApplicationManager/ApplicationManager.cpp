#include "ApplicationManager.h"
#include"..\Actions\AddToolBar.h"
#include"..\Actions\AddCONNECTION.h" 
#include"..\Actions\AddNANDgate2.h"
#include"..\Actions\AddORgate3.h"    
#include"..\Actions\AddXORgate2.h"       
#include"..\Actions\DEL.h"
#include"..\Actions\EXIT.h"  
#include"..\Actions\MultiSELECT.h"
#include"..\Actions\AddANDgate2.h"  
#include"..\Actions\AddGATEBAR.h"     
#include"..\Actions\AddNANDgate3.h"  
#include"..\Actions\AddOR.h"
#include"..\Actions\AddXORgate3.h"       
#include"..\Actions\DrwngArea.h"   
#include"..\Actions\LOAD.h"
#include"..\Actions\SIMMODE.h"
#include"..\Actions\AddANDgate3.h"
#include"..\Actions\AddINV.h"
#include"..\Actions\AddNORgate2.h"
#include"..\Actions\AddSWITCH.h"
#include"..\Actions\AddXOR.h"
#include"..\Actions\DSNMODE.h"     
#include"..\Actions\CUT.h"  
#include"..\Actions\STATUSBAR.h"
#include"..\Actions\AddAND.h"
#include"..\Actions\AddLabel.h"
#include"..\Actions\AddNORgate3.h"
#include"..\Actions\AddXNORgate2.h"
#include"..\Actions\ChangeSwitch.h"
#include"..\Actions\DSNTOOL.h"
#include"..\Actions\REDO.h"
#include"..\Actions\UNDO.h"
#include"..\Actions\AddBUFF.h"      
#include"..\Actions\AddLED.h"   
#include"..\Actions\AddORgate2.h"
#include"..\Actions\AddXNORgate3.h"
#include"..\Actions\CreateTruthTable.h"
#include"..\Actions\EditeLabel.h"
#include"..\Actions\SAVE.h"
#include"..\Actions\ANDToolBar.h"
#include"..\Actions\ORToolBar.h"
#include"..\Actions\XORToolBar.h"
#include"..\Actions\Select.h"
#include"..\Actions\Move.h"
#include"..\Components\Button.h"
Action * ApplicationManager::ActionCreator(ActionType x)
{
	switch (x)
	{
	case ADD:
		return new AddToolBar(this);
		break; 
	case ADD_AND:
		return new ANDToolBar(this);
		break;
	case ADD_OR:
		return new ORToolBar(this);
		break;
	case ADD_XOR:
		return new XORToolBar(this);
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
		return new AddNORgate2(this);
		break;
	case ADD_XOR_GATE_2:
		return new AddXORgate2(this);
		break;
	case ADD_XNOR_GATE_2:
		return new AddXNORgate2(this);
		break;
	case ADD_AND_GATE_3:
		return new AddANDgate3(this);
		break;
	case ADD_NAND_GATE_3:
		return new AddNANDgate3(this);
		break;
	case ADD_NOR_GATE_3:
		return new AddNORgate3(this);
		break;
	case ADD_XOR_GATE_3:
		return new AddXORgate3(this);
		break;
	case ADD_XNOR_GATE_3:
		return new AddXNORgate3(this);
		break;
	case ADD_OR_GATE_3:
		return new AddORgate3(this);
	case ADD_Switch:
		return new AddSwitch(this);
		break;
	case ADD_LED:
		return new AddLED(this);
		break;
	case ADD_CONNECTION:
		return new AddCONNECTION(this);
		break;
	case ADD_Label:
		return new EditLabel(this);
		break;
	case EDIT_Label:
		return new EditLabel(this);
		break;
	case Create_TruthTable:
		return nullptr;
		break;
	case Change_Switch:
		return nullptr;
		break;
	case MultiSELECT:
		return new MultiSelect(this);
		break;
	case DEL:
		return nullptr;
		break;
	case MOVE:
		return new Move(this);
		break;
	case COPY:
		return nullptr;
		break;
	case CUT:
		return nullptr;
		break;
	case PASTE:
		return nullptr;
		break;
	case VALIDATE:
		return nullptr;
		break;
	case SAVE:
		return nullptr;
		break;
	case LOAD:
		return nullptr;
		break;
	case PROBE:
		return nullptr;
		break;
	case UNDO:
		return nullptr;
		break;
	case REDO:
		return nullptr;
		break;
	case DSN_MODE:
		return nullptr;
		break;
	case SIM_MODE:
		return nullptr;
		break;
	case EXIT:
		return nullptr;
		break;
	case STATUS_BAR:
		return nullptr;
		break;
	case DSN_TOOL:
		return nullptr;
		break;
	case DSN_AREA:
	{
		if (sim)
			DrawToolBar(TOOLBARS::SIMU);
		else
			DrawToolBar(TOOLBARS::DSGN);
		for (size_t i = 0; i < ComponentList.size(); i++)
		{
			ComponentList[i]->SetState(false);
		}
	}
		return nullptr;
		break;
	case SELECT:
		return new Select(this);
		break;
	default:
		return nullptr;
		break;
	}
	

}
//////////////////////////////////////////////////////////////////////////////
GridItem* ApplicationManager::CheckPoint(int & Cx, int & Cy)
{

	bool success = true;
	GridItem*tmp;
	while (success)
	{
		tmp=InputInterface->GetPointClicked(Cx, Cy);
		if (Cx == -1 || Cy == -1)
			OutputInterface->PrintMsg("Out of Design Area, Please Click Inside the Drawing Area");
		else if ((Cx == -2 || Cy == -2) && ((dynamic_cast<Pin*>(tmp)) == NULL))
			OutputInterface->PrintMsg("You've Clicked on an Existing Component, Please Click Somewhere Free");
		else	
		success = false;
	}
	return tmp;
}
void ApplicationManager::DrawToolBar(TOOLBARS x)
{
	switch (x)
	{
	case DSGN:
	{
		Toolbars[4] = true;
		Toolbars[5] = false;
		Toolbars[6] = false;
	}
		break;
	case GATE:
	{
		Toolbars[4] = false;
		Toolbars[5] = false;
		Toolbars[6] = true;
	}
		break;
	case SIMU:
	{
		Toolbars[4] = false;
		Toolbars[5] = true;
		Toolbars[6] = false;
	}
		break;
	case ADDBAR:
		Toolbars[0] = true;
		break;
	case ADDANDBAR:
		{
			Toolbars[1] = true;
			Toolbars[2] = false;
			Toolbars[3] = false;
		}
			break;
	case ADDORBAR:
	{
		Toolbars[1] = false;
		Toolbars[2] = true;
		Toolbars[3] = false;
	}
		break;
	case ADDXORBAR:
	{
		Toolbars[1] = false;
		Toolbars[2] = false;
		Toolbars[3] = true;
	}
		break;
	case GATERightClick:
		break;
	case SWITCHRightClick:
		break;
	case LEDRightClick:
		break;

	default:
		break;
	}
}

/////////////////////////////////////////////////////////////////////////////////////
vector<Component*> ApplicationManager::getMetaData()
{
	return MetaData;
}
void ApplicationManager::setMetaData(vector<Component*>x)
{
	MetaData = x;
}
void ApplicationManager::AppendMetaData(Component *x)
{
	MetaData.push_back(x);
}
vector<Component*> ApplicationManager::getClipboard()
{
	return	clip.pull();
}
vector<Component*> ApplicationManager::getComponents()
{
	return ComponentList;
}
void ApplicationManager::setClipboard(vector<Component*>x)
{
	clip.push(x);
}
void ApplicationManager::DeleteThis(vector<Component*>x)
{
	for (size_t i = 0; i < x.size(); i++)
	{
		for (size_t j = 0; j < ComponentList.size(); j++)
		{
			if (x[i] == ComponentList[j])
			{
				delete x[i];
				x.erase(x.begin() + j);
				ComponentList.erase(ComponentList.begin() + j);
				//Erase Interface
				break;
			}
		}
	}
}
void ApplicationManager::RemoveMetaData(Component *x)
{
	for (size_t i = 0; i < MetaData.size(); i++)
	{
		if (MetaData[i] == x)
		{
			MetaData.erase(MetaData.begin() + i);
			break;
		}
	}
}
void ApplicationManager::EraseThisBitch(Component *)
{
}
ApplicationManager::ApplicationManager()
{
	//Creates the Input / Output Objects & Initialize the GUI
	for (size_t i = 0; i < 7; i++)
	{
		Toolbars[i] = false;
	}
	sim = false;
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
	OutputInterface->CreateStatusBar();
	Toolbars[4] = true;
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
		if(!dynamic_cast<Button*>(x.second[i]))
			MetaData.push_back((Component*) x.second[i]);
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
	if (Toolbars[0])
		OutputInterface->CreateAddToolBar();

	if (Toolbars[1])
		OutputInterface->CreateAndToolBar();
	else if (Toolbars[2])
		OutputInterface->CreateORToolBar();
	else if (Toolbars[3])
		OutputInterface->CreateXORToolBar();

	if (Toolbars[4])
		OutputInterface->CreateDesignToolBar();
	else if (Toolbars[5])
		OutputInterface->CreateSimulationToolBar();
	else if (Toolbars[6])
		OutputInterface->CreateGatesToolBar();


	for (size_t i = 0; i < ComponentList.size(); i++)
	{
		ComponentList[i]->Draw(OutputInterface);
	}
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
	
	delete OutputInterface;
	delete InputInterface;
	
}