#include "Output.h"
Graph *Input::Interface = new Graph;
Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

GridItem* Input::GetPointClicked(int &x, int &y,Comps Comp)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
	if (x<UI.GateItemWidth || x>UI.width-UI.GateItemWidth || y<UI.ToolBarHeight || y>UI.height-UI.StatusBarHeight)
	{
		x = -1;
		y = -1;
	}
	GridItem*tmp=Interface->getAction(GraphicsInfo(x, y));
	if (tmp != NULL)
	{
		x = -2;
		y = -2;
	}
	switch (Comp)	
	{
	case _GATE_:
		return Interface->Available(GraphicsInfo(x - UI.AllGateDimensions/2-5, y -UI.AllGateDimensions/2-5, x-UI.AllGateDimensions/2+UI.InverterDimensions+UI.ConnectionDimensions, y + UI.AllGateDimensions/2));
		break;
	case _BUFFER_:
		return Interface->Available(GraphicsInfo(x - UI.BufferDimensions / 2 - UI.ConnectionDimensions, y - UI.BufferDimensions, x + UI.BufferDimensions / 2 + UI.ConnectionDimensions, y + UI.BufferDimensions / 2));
	case _SWITCH_:
		return Interface->Available(GraphicsInfo(x - UI.SwitchWidth / 2 - UI.ConnectionDimensions - 5, y - UI.SwitchHeight / 2, x + UI.SwitchWidth / 2 + UI.ConnectionDimensions + 5, y + UI.SwitchHeight / 2));
		break;
	default:
		break;
	}
}

string Input::GetSrting(Output *pOut)
{
	///TODO: Implement this Function
	//Read a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" should be also supported
	//User should see what he is typing at the status bar

	return NULL;
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
