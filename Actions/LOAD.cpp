#include "LOAD.h"
#include"..\ApplicationManager\ApplicationManager.h"
#include"..\Components\AND.h"
#include"..\Components\AND2.h"
#include"..\Components\AND3.h"
#include"..\Components\BUFF.h"
#include"..\Components\Button.h"
#include"..\Components\Component.h"
#include"..\Components\Connection.h"
#include"..\Components\Gate.h"
#include"..\Components\gateBAR.h"
#include"..\Components\INV.h"
#include"..\Components\LED.h"
#include"..\Components\NAND2.h"
#include"..\Components\NAND3.h"
#include"..\Components\NOR2.h"
#include"..\Components\NOR3.h"
#include"..\Components\OR.h"
#include"..\Components\OR2.h"
#include"..\Components\OR3.h"
#include"..\Components\SWITCH.h"
#include"..\Components\XNOR2.h"
#include"..\Components\XNOR3.h"
#include"..\Components\XOR.h"
#include"..\Components\XOR2.h"
#include"..\Components\XOR3.h"
Load::Load(ApplicationManager *x):Action(x)
{
}

Load::~Load()
{
}

void Load::ReadActionParameters()
{
	pManager->GetOutput()->PrintMsg("Loading Done");
}

void Load::Execute()
{
	ReadActionParameters();
	Component*ptr = NULL;
	string s;
	ifstream In("Save.3lawd3o");
	do {
		ptr = NULL;
		In >> s;
		if (s == "AND2")
		{
			ptr = new AND2(GraphicsInfo(0, 0, 0, 0));
			ptr->Load(In);
		}
		else if (s == "AND3")
		{
			ptr = new AND3(GraphicsInfo(0, 0, 0, 0));
			ptr->Load(In);
		}
		else if (s == "BUFFER")
		{
			ptr = new BUFF(GraphicsInfo(0, 0, 0, 0));
			ptr->Load(In);
		}
		else if (s == "INVERTER")
		{
			ptr = new INV (GraphicsInfo(0, 0, 0, 0));
			ptr->Load(In);
		}
		else if (s == "LED")
		{
			ptr = new LED(GraphicsInfo(0, 0, 0, 0));
			ptr->Load(In);
		}
		else if (s == "NAND2")
		{
			ptr = new NAND2(GraphicsInfo(0, 0, 0, 0));
			ptr->Load(In);
		}
		else if (s == "NAND3")
		{
			ptr = new NAND3(GraphicsInfo(0, 0, 0, 0));
			ptr->Load(In);
		}
		else if (s == "NOR2")
		{
			ptr = new NOR2(GraphicsInfo(0, 0, 0, 0));
			ptr->Load(In);
		}
		else if (s == "NOR3")
		{
			ptr = new NOR3(GraphicsInfo(0, 0, 0, 0));
			ptr->Load(In);
		}
		else if (s == "OR2")
		{
			ptr = new OR2(GraphicsInfo(0, 0, 0, 0));
			ptr->Load(In);
		}
		else if (s == "OR3")
		{
			ptr = new OR3(GraphicsInfo(0, 0, 0, 0));
			ptr->Load(In);
		}
		else if (s == "SWITCH")
		{
			ptr = new SWITCH(GraphicsInfo(0, 0, 0, 0));
			ptr->Load(In);
		}
		else if (s == "XNOR2")
		{
			ptr = new XNOR2(GraphicsInfo(0, 0, 0, 0));
			ptr->Load(In);
		}
		else if (s == "XNOR3")
		{
			ptr = new XNOR3(GraphicsInfo(0, 0, 0, 0));
			ptr->Load(In);
		}
		else if (s == "XOR2")
		{
			ptr = new XOR2(GraphicsInfo(0, 0, 0, 0));
			ptr->Load(In);
		}
		else if (s == "XOR3")
		{
			ptr = new XOR3(GraphicsInfo(0, 0, 0, 0));
			ptr->Load(In);
		}
		if (ptr != NULL)
			pManager->AddComponent(ptr);
	} while (s != "Connections");
	int x, y, z;
	auto vec = pManager->getComponents();
	int l = vec.size();
	Connection*tmp = NULL;
	pManager->UpdateInterface();
	do
	{
		tmp = NULL;
		
		{
			tmp = new Connection;
			tmp->Load(In);
			if (tmp->GetSrcID() != -1)
			{
				for (int i = 0; i < l; i++)
				{
					if (((Gate*)vec[i])->GetID() == tmp->GetSrcID())
					{
						tmp->setSourcePin(&((Gate*)vec[i])->GetOutputPin());
					}
					if (((Gate*)vec[i])->GetID() == tmp->GetTrgtID())
					{
						tmp->setDestPin(&((Gate*)vec[i])->GetInputPins()[tmp->GetPinID()]);
					}
				}
				if (tmp != NULL)
					pManager->AddComponent(tmp);
			}
		}
	} while (tmp->GetSrcID()!=-1);

}

void Load::Undo()
{
}

void Load::Redo()
{
}




