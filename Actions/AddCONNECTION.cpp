#include "AddCONNECTION.h"
#include "..\ApplicationManager\ApplicationManager.h"
#include"..\Components\Gate.h"
#include"..\Components\Button.h"

AddCONNECTION::AddCONNECTION(ApplicationManager *pApp) :Action(pApp)
{
	SrcPin = nullptr;
	DstPin = nullptr;
}

AddCONNECTION::~AddCONNECTION()
{
}

void AddCONNECTION::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	GridItem* x, *y;

	pOut->PrintMsg("Connection building : Click on a Gate/Pin to Connect(1)");
	//Print Action Message
	bool success = SrcPin && DstPin;
	bool q=true, w=true;
	while (!success)
	{
		q = true, w = true;
		while (q)
		{
			x = pIn->GetPointClicked(x1, y1);
			SrcPin = dynamic_cast<OutputPin*>(x);
			SrcGate = dynamic_cast<Gate*>(x);
			if (x1 == -1 || y1 == -1)
			{
				pOut->PrintMsg("Cannot Connect to Empty Space... Please Try Again");
				continue;
			}
			if (dynamic_cast<Button*> (x))
			{
				pOut->PrintMsg("Cannot Connect on a ToolBar Button");
				continue;
			}
			q = false;
		}
	


		pOut->PrintMsg("Connection building : Click on a Gate/Pin to Connect(2)");

		while (w)
		{
		y = pIn->GetPointClicked(x2, y2);
		DstPin = dynamic_cast<InputPin*>(y);
		DstGate = dynamic_cast<Gate*>(y);
		if (x2 == -1 || y2 == -1)
		{
			pOut->PrintMsg("Cannot Connect to Empty Space... Please Try Again");
			continue;
		}
		if (dynamic_cast<Button*> (x))
		{
			pOut->PrintMsg("Cannot Connect on a ToolBar Button");
			continue;
		}
		w = false;
		}



		
		if (!(SrcPin || SrcPin || DstPin || DstGate))
		{
			SrcPin = dynamic_cast<OutputPin*>(y);
			DstPin = dynamic_cast<InputPin*>(x);
		}

		if (SrcGate)
		{
			SrcPin = &SrcGate->GetOutputPin();
		
		}
		if (DstGate)
		{
			DstPin = DstGate->GetFreeInputPins();
			if (!DstPin)
			{
				pOut->PrintMsg("Connection Error... No Free Input Pins");
				continue;
			}
		}
		if (dynamic_cast<OutputPin*>(SrcPin)->getComponent() == dynamic_cast<InputPin*>(DstPin)->getComponent())
		{
			pOut->PrintMsg("Connection Error : Can't Connect gate to itelf....Go to MultiSim :D :D");
			continue;
		}
		if (SrcPin && DstPin)
		{
			x1 = SrcPin->GetPosition().x1;
			y1 = SrcPin->GetPosition().y1;
			x2 = DstPin->GetPosition().x2;
			y2 = DstPin->GetPosition().y2;
			success = true;
		}
		else
		{
			pOut->PrintMsg("Connection Error : Please Try Again.... Click A Gate/Pin to Connect(1)");
		}

	}
	//clear status bar
	pOut->ClearStatusBar();
}


void AddCONNECTION::Execute()
{
	//Get Connection Source and destination points
	ReadActionParameters();

	GraphicsInfo GInfo(x1,y1,x2,y2);

	Connection *pA = new Connection(GInfo, dynamic_cast<OutputPin*>(SrcPin), dynamic_cast<InputPin*>(DstPin));

	pA->Draw(pManager->GetOutput());

}

void AddCONNECTION::Undo()
{
}

void AddCONNECTION::Redo()
{
}
