#include "LOAD.h"
#include"..\ApplicationManager\ApplicationManager.h"
#include"..\GUI\Essentials.h"
#include"..\Components\AND2.h"
#include"..\Components\AND3.h"
#include"..\Components\BUFF.h"
#include"..\Components\Connection.h"
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


Load::Load(ApplicationManager * pApp)
	:Action(pApp)
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
	ifstream In("Save.3lawd3o");
	Component*ptr=NULL;
	string s;
	do
	{
		In >> s;
		ptr = NULL;
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
		else if (s == "BUFF")
		{
			ptr = new BUFF(GraphicsInfo(0, 0, 0, 0));
			ptr->Load(In);
		}
		else if (s == "INV")
		{
			ptr = new INV(GraphicsInfo(0, 0, 0, 0));
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
	do
	{
		In >> x;
		if (x != -1)
		{
			ptr = new Connection(GraphicsInfo(0, 0, 0, 0), NULL, NULL);
			ptr->Load(In);
		}

	} while (x!=-1);
}

void Load::Undo()
{
}

void Load::Redo()
{
}
