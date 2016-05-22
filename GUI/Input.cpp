#include "Output.h"
Graph *Input::Interface = new Graph;
Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

GridItem* Input::GetPointClicked(int &x, int &y,Comps Comp)
{
	GridItem*Returned;
	
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
	if (x<UI.GateItemWidth || x>UI.width - UI.GateItemWidth || y<UI.ToolBarHeight || y>UI.height - UI.StatusBarHeight)
	{
		x = -1;
		y = -1;
		return NULL;
	}
	GridItem*tmp = Interface->getAction(GraphicsInfo(x, y));
	if (tmp != NULL)
	{
		x = -2;
		y = -2;
		return tmp;
	}
	switch (Comp)
	{
	case _GATE_:
		Returned = Interface->Available(GraphicsInfo(x - UI.AllGateDimensions / 2 - 5, y - UI.AllGateDimensions / 2 - 5, x + UI.AllGateDimensions / 2 + UI.InverterDimensions + UI.ConnectionDimensions, y + UI.AllGateDimensions / 2));
		break;
	case _BUFFER_:
		Returned = Interface->Available(GraphicsInfo(x - UI.BufferDimensions / 2 - UI.ConnectionDimensions, y - UI.BufferDimensions, x + UI.BufferDimensions / 2 + UI.ConnectionDimensions, y + UI.BufferDimensions / 2));
	case _SWITCH_:
		Returned = Interface->Available(GraphicsInfo(x - UI.SwitchWidth / 2 - UI.ConnectionDimensions - 5, y - UI.SwitchHeight / 2, x + UI.SwitchWidth / 2 + UI.ConnectionDimensions + 5, y + UI.SwitchHeight / 2));
		break;
	default:
		break;
	}


	return Returned;
}

string Input::GetSrting(Output *pOut)
{
	keytype ktInput;

	char cKeyData;
	string str = "";

	pWind->FlushKeyQueue();
	do
	{
		pWind->FlushKeyQueue();
		ktInput = pWind->WaitKeyPress(cKeyData);

		// Figure out what key was pressed
		if (ktInput == ESCAPE) {
			pOut->ClearStatusBar();
			return "";
		}
		else if (ktInput == ASCII)
		{
			if (cKeyData == '\b'&&str.length() != 0)
			{
				str.erase(str.length() - 1, 1);
				pOut->PrintMsg(str);
				continue;
			}
			else
			{
				str += cKeyData;
				pOut->PrintMsg(str);
			}
		}
	} while ((int)cKeyData != 13);
	pWind->SetPen(BLACK, 3);
	pWind->DrawString(500, 500, str);
	return str;
}

Graph * Input::GetGraph()
{
	return Interface;
}

//This function reads the position where the user clicks to determine the desired action
pair< ActionType, vector<GridItem*> > Input::GetUserAction() const
{	
	vector<GridItem*> ReturnedPointers;
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
	GridItem*tmp = NULL;
	tmp = Interface->getAction(GraphicsInfo(x, y));
	if (tmp == NULL)
		return make_pair(DSN_AREA,ReturnedPointers);
	else

	{
		ReturnedPointers.push_back(tmp);
		return make_pair(tmp->Leftpress(), ReturnedPointers);
	}

}


Input::~Input()
{
}
