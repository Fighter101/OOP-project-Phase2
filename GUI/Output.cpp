#include "Output.h"
#include"..\ToolBar.h"
#include"..\Components\Button.h"
#include"..\Components\Gate.h"
void Output::CreateToolBars()
{
	Toolbars = new ToolBar[TOOLBARCNT];
	//////////////////////////////////////Design Tool Bar////////////////
	Toolbars[DSGN].SetPosition(GraphicsInfo(230, 0));
	vector<int>vec;
	for (int i = 6; i < 15; i++)
	{
		vec.push_back(i);
	}
	Toolbars[DSGN].ButtonsToDraw(vec);
	Toolbars[DSGN].SetOrientation(Horizontal);
	Toolbars[DSGN].SetDistance(UI.ToolItemWidth, UI.ToolBarHeight);
	Toolbars[DSGN].CreateButtons(this);
	///////////////////Simulation Tool Bar/////////////////////
	Toolbars[SIMU].SetPosition(GraphicsInfo(290, 0));
	Toolbars[SIMU].SetOrientation(Horizontal);
	vec.clear();
	for (int i = 12; i < 18; i++)
	{
		vec.push_back(i);
	}
	vec.push_back(11);
	Toolbars[SIMU].ButtonsToDraw(vec);
	Toolbars[SIMU].SetDistance(UI.ToolItemWidth, UI.ToolBarHeight);
	Toolbars[SIMU].CreateButtons(this);
	//////////////////////////////////////////Gate Tool bar////////////////////////
	vec.clear();
	for (int i = 0; i < 6; i++)
	{
		vec.push_back(i);
	}
	Toolbars[GATE].ButtonsToDraw(vec);
	Toolbars[GATE].SetOrientation(Horizontal);
	Toolbars[GATE].SetDistance(UI.GateItemWidth, UI.ToolBarHeight);
	Toolbars[GATE].SetPosition(GraphicsInfo(350, 0));
	Toolbars[GATE].CreateButtons(this);
	////////////////////////////////////
	vec.clear();
	for (int i = 20; i < 25; i++)
	{
		vec.push_back(i);
	}
	Toolbars[RightClick].ButtonsToDraw(vec);
	Toolbars[RightClick].SetOrientation(Vertical);
	Toolbars[RightClick].SetDistance(UI.RightClickItemWidth, UI.RightClickItemHeight);
	////////////////////////////////
	vec.clear();
	for (int i = 25; i < 32; i++)
	{
		vec.push_back(i);
	}
	Toolbars[ADDBAR].ButtonsToDraw(vec);
	Toolbars[ADDBAR].SetDistance(UI.ToolBarHeight, UI.GateBarHeight);
	Toolbars[ADDBAR].SetOrientation(Vertical);
	Toolbars[ADDBAR].SetPosition(GraphicsInfo(1000 - UI.GateItemWidth, 165));
	Toolbars[ADDBAR].CreateButtons(this);
	///////////////////////////////////////////////
	vec.clear();
	for (int i = 32; i < 36; i++)
	{
		vec.push_back(i);
	}
	Toolbars[ADDANDBAR].ButtonsToDraw(vec);
	Toolbars[ADDANDBAR].SetDistance(UI.GateItemWidth, UI.GateBarHeight);
	Toolbars[ADDANDBAR].SetOrientation(Vertical);
	Toolbars[ADDANDBAR].SetPosition(GraphicsInfo(0, 255));
	Toolbars[ADDANDBAR].CreateButtons(this);
	//////////////////////////////////////////////
	vec.clear();
	for (int i = 36; i < 40; i++)
	{
		vec.push_back(i);
	}
	Toolbars[ADDORBAR].ButtonsToDraw(vec);
	Toolbars[ADDORBAR].SetDistance(UI.GateItemWidth, UI.GateBarHeight);
	Toolbars[ADDORBAR].SetOrientation(Vertical);
	Toolbars[ADDORBAR].SetPosition(GraphicsInfo(0, 255));
	Toolbars[ADDORBAR].CreateButtons(this);
	//////////////////////////////////
	vec.clear();
	for (int i = 40; i < 44; i++)
	{
		vec.push_back(i);
	}
	Toolbars[ADDXORBAR].ButtonsToDraw(vec);
	Toolbars[ADDXORBAR].SetDistance(UI.GateItemWidth, UI.GateBarHeight);
	Toolbars[ADDXORBAR].SetOrientation(Vertical);
	Toolbars[ADDXORBAR].SetPosition(GraphicsInfo(0, 255));
	Toolbars[ADDXORBAR].CreateButtons(this);
}
	Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = WHITE;
	UI.BkGrndColor = WHITE;
	this->Interface = Input::GetGraph();
	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);	
	ChangeTitle("Programming Techniques Project");

	CreateToolBars();
	CreateDesignToolBar();
	CreateStatusBar();		//Create Status bar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(BLACK,3);
	pWind->SetBrush(BLACK);
	pWind->DrawRectangle(UI.SatusBarStart, UI.height, 100+UI.StatusBarWidth, UI.height-UI.StatusBarHeight,FILLED,5,5);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(UI.MsgColor); 
	pWind->DrawString(UI.SatusBarStart+MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	CreateStatusBar();
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() 
{
	UI.AppMode = DESIGN;	//Design Mode
	Toolbars[DSGN].Draw(this);
	////You can draw the tool bar icons in any way you want.

	////First prepare List of images for each menu item
	//string MenuItemImages[ITM_DSN_CNT];
	//MenuItemImages[ITM_AND2] = "images\\Menu\\Menu_AND2.jpg";
	//MenuItemImages[ITM_OR2]  = "images\\Menu\\Menu_OR2.jpg";
	//MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";

	////TODO: Prepare image for each menu item and add it to the list

	////Draw menu item one image at a time
	//for(int i=0; i<ITM_DSN_CNT; i++)
	//	pWind->DrawImage(MenuItemImages[i],i*UI.ToolItemWidth,0,UI.ToolItemWidth, UI.ToolBarHeight);


	////Draw a line under the toolbar
	//pWind->SetPen(RED,3);
	//pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
void Output::EraseDesignToolBar()
{
	Toolbars[DSGN].Draw(this);
}
void Output::CreateGatesToolBar()
{
	Toolbars[GATE].Draw(this);
}
void Output::EraseGatesToolBar()
{
	Toolbars[GATE].Erase(this);
}
void Output::CreateSimulationToolBar()
{
	Toolbars[SIMU].Draw(this);
}
void Output::EraseSimulationToolBar()
{
	Toolbars[SIMU].Erase(this);
}
void Output::CreateRightClickToolBar(GraphicsInfo r_GfxInfo)
{
	Toolbars[RightClick].SetPosition(r_GfxInfo);
	Toolbars[RightClick].CreateButtons(this);
	Toolbars[RightClick].Draw(this);
}
void Output::EraseRightClickToolBar()
{
	Toolbars[RightClick].Erase(this);
}
void Output::CreateAndToolBar()
{
	Toolbars[ADDANDBAR].Draw(this);
}
void Output::EraseAndToolBar()
{
	Toolbars[ADDANDBAR].Erase(this);
}
void Output::CreateORToolBar()
{
	Toolbars[ADDORBAR].Draw(this);
}
void Output::EraseORToolBar()
{
	Toolbars[ADDORBAR].Erase(this);
}
void Output::CreateXORToolBar()
{
	Toolbars[ADDXORBAR].Draw(this);
}
void Output::EraseXORToolBar()
{
	Toolbars[ADDXORBAR].Erase(this);
}
void Output::EraseAddToolBar()
{
	Toolbars[ADDBAR].Erase(this);
}
//////////////////////////////////////////////////////////////////////////////////////////

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

GraphicsInfo Output::DetermineState(GraphicsInfo r_GfxInfo, PressType State)
{
	switch (State)
	{
	case Normal:
		pWind->SetPen(BLACK, 3);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.RightClickItemWidth, r_GfxInfo.y1 + UI.RightClickItemHeight, FRAME);
		break;
	case Hovered:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(GREY);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.RightClickItemWidth, r_GfxInfo.y1 + UI.RightClickItemHeight, FILLED);
		break;
	case Pressed:
		pWind->SetPen(WHITE, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.RightClickItemWidth, r_GfxInfo.y1 + UI.RightClickItemHeight, FILLED);
		break;
	default:
		break;
	}
	return (GraphicsInfo(UI.RightClickItemWidth, UI.RightClickItemHeight));

}
//======================================================================================//
//								Icon Drawing Functions									//
//======================================================================================//
GraphicsInfo Output:: MoveIcon( GraphicsInfo r_GfxInfo,PressType State)
{
	switch (State)
	{
	case Normal:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FRAME);
		break;
	case Hovered:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(GREY);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		break;
	case Pressed:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		pWind->SetPen(WHITE, 3);
		break;
	default:
		break;
	}
	
	pWind->DrawLine(r_GfxInfo.x1 + (UI.Margain), r_GfxInfo.y1 + UI.Margain + 20, r_GfxInfo.x1 + (UI.Margain) + 40, r_GfxInfo.y1 + UI.Margain + 20);
	pWind->DrawLine(UI.ToolItemWidth / 2 + r_GfxInfo.x1, r_GfxInfo.y1 + UI.Margain, r_GfxInfo.x1 + UI.ToolItemWidth / 2, r_GfxInfo.y1 + UI.Margain + 40);
	pWind->DrawTriangle(r_GfxInfo.x1 + (UI.Margain), r_GfxInfo.y1 + UI.Margain + 20, r_GfxInfo.x1 + (UI.Margain) + 5, r_GfxInfo.y1 + UI.Margain + 25, r_GfxInfo.x1 + (UI.Margain) + 5, r_GfxInfo.y1 + UI.Margain + 15, FILLED);
	pWind->DrawTriangle(r_GfxInfo.x1 + (UI.Margain) + 40, r_GfxInfo.y1 + UI.Margain + 20, r_GfxInfo.x1 + (UI.Margain) + 35, r_GfxInfo.y1 + UI.Margain + 25, r_GfxInfo.x1 + (UI.Margain) + 35, r_GfxInfo.y1 + UI.Margain + 15, FILLED);
	pWind->DrawTriangle(UI.ToolItemWidth / 2 + r_GfxInfo.x1, r_GfxInfo.y1 + UI.Margain, UI.ToolItemWidth / 2 + r_GfxInfo.x1 + 5, r_GfxInfo.y1 + UI.Margain + 5, UI.ToolItemWidth / 2 + r_GfxInfo.x1 - 5, r_GfxInfo.y1 + UI.Margain + 5);
	pWind->DrawTriangle(r_GfxInfo.x1 + UI.ToolItemWidth / 2, r_GfxInfo.y1 + UI.Margain + 40, r_GfxInfo.x1 + UI.ToolItemWidth / 2 + -5, r_GfxInfo.y1 + UI.Margain + 35, r_GfxInfo.x1 + UI.ToolItemWidth / 2 + 5, r_GfxInfo.y1 + UI.Margain + 35);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(r_GfxInfo.x1 + UI.Margain, r_GfxInfo.y1 + UI.ToolItemWidth - 1, "Move");
	return (GraphicsInfo(UI.ToolItemWidth, UI.ToolBarHeight));
}
GraphicsInfo Output::CopyIcon( GraphicsInfo r_GfxInfo,PressType State)
{
	switch (State)
	{
	case Normal:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FRAME);
		break;
	case Hovered:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(GREY);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		break;
	case Pressed:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		pWind->SetPen(WHITE, 3);
		break;
	default:
		break;
	}
	int XV[] = { r_GfxInfo.x1 + UI.Margain,r_GfxInfo.x1 + UI.Margain + 30,r_GfxInfo.x1 + +UI.Margain + 30,r_GfxInfo.x1 + +UI.Margain + 20,r_GfxInfo.x1 + UI.Margain };
	int YV[] = { r_GfxInfo.y1 + UI.Margain + 30,r_GfxInfo.y1 + UI.Margain + 30 ,r_GfxInfo.y1 + UI.Margain + 10,r_GfxInfo.y1 + UI.Margain ,r_GfxInfo.y1 + UI.Margain };
	pWind->DrawPolygon(XV, YV, 5, FRAME);
	pWind->DrawTriangle(r_GfxInfo.x1 + UI.Margain + 20, r_GfxInfo.y1 + UI.Margain + 10, r_GfxInfo.x1 + UI.Margain + 20, r_GfxInfo.y1 + UI.Margain, r_GfxInfo.x1 + +UI.Margain + 30, r_GfxInfo.y1 + UI.Margain + 10, FRAME);
	for (int i = 0; i < 5; i++)
	{
		XV[i] += 10;
		YV[i] += 15;
	}
	switch (State)
	{
	case Normal:
		pWind->SetBrush(WHITE);
		break;
	case Hovered:
		pWind->SetBrush(WHITE);
		break;
	case Pressed:
		pWind->SetBrush(BLACK);
		break;
	default:
		break;
	}
	pWind->DrawPolygon(XV, YV, 5, FILLED);
	pWind->DrawTriangle(r_GfxInfo.x1 + UI.Margain + 30, r_GfxInfo.y1 + UI.Margain + 15, r_GfxInfo.x1 + UI.Margain + 30, r_GfxInfo.y1 + UI.Margain + 25, r_GfxInfo.x1 + +UI.Margain + 40, r_GfxInfo.y1 + UI.Margain + 25, FRAME);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(r_GfxInfo.x1 + UI.Margain, r_GfxInfo.y1 + UI.ToolItemWidth - 1, "Copy");
	return (GraphicsInfo(UI.ToolItemWidth, UI.ToolBarHeight));
}
GraphicsInfo Output::PasteIcon( GraphicsInfo r_GfxInfo,PressType State)
{
	switch (State)
	{
	case Normal:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FRAME);
		break;
	case Hovered:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(GREY);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		break;
	case Pressed:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		pWind->SetPen(WHITE, 3);
		break;
	default:
		break;
	}
	pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FRAME);
	pWind->DrawRectangle(r_GfxInfo.x1 + UI.Margain, r_GfxInfo.y1 + UI.Margain, r_GfxInfo.x1 + UI.Margain + 30, r_GfxInfo.y1 + 40 + UI.Margain, FILLED, 5, 5);
	switch (State)
	{
	case Normal:
		pWind->SetBrush(WHITE);
		pWind->SetPen(WHITE, 3);
		break;
	case Hovered:
		pWind->SetBrush(WHITE);
		pWind->SetPen(WHITE, 3);
		break;
	case Pressed:
		pWind->SetBrush(BLACK);
		pWind->SetPen(BLACK, 3);
		break;
	default:
		break;
	}
	pWind->DrawRectangle(r_GfxInfo.x1 + UI.Margain + 5, r_GfxInfo.y1 + UI.Margain + 5, r_GfxInfo.x1 + UI.Margain + 25, r_GfxInfo.y1 + UI.Margain + 10, FILLED);
	switch (State)
	{
	case Normal:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(WHITE);
		break;
	case Hovered:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(WHITE);
		break;
	case Pressed:
		pWind->SetPen(WHITE, 3);
		pWind->SetBrush(BLACK);
		break;
	default:
		break;
	}

	int XV[] = { r_GfxInfo.x1 + UI.Margain,r_GfxInfo.x1 + UI.Margain + 30,r_GfxInfo.x1 + +UI.Margain + 30,r_GfxInfo.x1 + UI.Margain + 20,r_GfxInfo.x1 + UI.Margain };
	int YV[] = { r_GfxInfo.y1 + UI.Margain + 30,r_GfxInfo.y1 + UI.Margain + 30 ,r_GfxInfo.y1 + UI.Margain + 10,r_GfxInfo.y1 + UI.Margain ,r_GfxInfo.y1 + UI.Margain };
	for (int i = 0; i < 5; i++)
	{
		XV[i] += 10;
		YV[i] += 15;
	}
	pWind->DrawPolygon(XV, YV, 5, FILLED);
	pWind->DrawTriangle(r_GfxInfo.x1 + UI.Margain + 30, r_GfxInfo.y1 + UI.Margain + 15, r_GfxInfo.x1 + UI.Margain + 30, r_GfxInfo.y1 + UI.Margain + 25, r_GfxInfo.x1 + UI.Margain + 40, r_GfxInfo.y1 + UI.Margain + 25, FRAME);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(r_GfxInfo.x1 + UI.Margain, r_GfxInfo.y1 + UI.ToolItemWidth - 1, "Paste");
	return (GraphicsInfo(UI.ToolItemWidth, UI.ToolBarHeight));
}
GraphicsInfo Output::LabelIcon( GraphicsInfo r_GfxInfo,PressType State)
{
	switch (State)
	{
	case Normal:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FRAME);
		break;
	case Hovered:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(GREY);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		break;
	case Pressed:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		pWind->SetPen(WHITE, 3);
		break;
	default:
		break;
	}
	pWind->DrawCircle(r_GfxInfo.x1 + UI.Margain + 20, r_GfxInfo.y1 + UI.Margain + 20, 20, FRAME);
	pWind->SetFont(40, BOLD, BY_NAME, "Arial");
	pWind->DrawString(r_GfxInfo.x1 + UI.Margain + 15, r_GfxInfo.y1 + UI.Margain, "i");
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(r_GfxInfo.x1 + UI.Margain, r_GfxInfo.y1 + UI.ToolItemWidth - 1, "Label");
	return (GraphicsInfo(UI.ToolItemWidth, UI.ToolBarHeight));
}
GraphicsInfo Output::EditIcon( GraphicsInfo r_GfxInfo,PressType State)
{
	switch (State)
	{
	case Normal:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FRAME);
		break;
	case Hovered:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(GREY);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		break;
	case Pressed:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		pWind->SetPen(WHITE, 3);
		break;
	default:
		break;
	}
	pWind->DrawTriangle(r_GfxInfo.x1 + UI.Margain + 20, r_GfxInfo.y1 + UI.Margain + 40, r_GfxInfo.x1 + UI.Margain + 15, r_GfxInfo.y1 + UI.Margain + 25, r_GfxInfo.x1 + UI.Margain + 25, r_GfxInfo.y1 + UI.Margain + 25, FILLED);
	pWind->DrawRectangle(r_GfxInfo.x1 + UI.Margain + 15, r_GfxInfo.y1 + UI.Margain + 22, r_GfxInfo.x1 + UI.Margain + 25, r_GfxInfo.y1 + UI.Margain, FILLED);
	pWind->DrawString(r_GfxInfo.x1 + UI.Margain, r_GfxInfo.y1 + UI.ToolItemWidth - 1, "Edit");
	return (GraphicsInfo(UI.ToolItemWidth, UI.ToolBarHeight));
}
GraphicsInfo Output::DeleteIcon( GraphicsInfo r_GfxInfo,PressType State)
{
	switch (State)
	{
	case Normal:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FRAME);
		break;
	case Hovered:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(GREY);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		break;
	case Pressed:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		pWind->SetPen(WHITE, 3);
		break;
	default:
		break;
	}
	pWind->DrawLine(r_GfxInfo.x1 + +UI.Margain + 10, r_GfxInfo.y1 + UI.Margain + 30, r_GfxInfo.x1 - 10 + UI.Margain + 40, r_GfxInfo.y1 + UI.Margain + 10);
	pWind->DrawLine(r_GfxInfo.x1 + +UI.Margain + 40 - 10, r_GfxInfo.y1 + UI.Margain + 30, r_GfxInfo.x1 + 10 + +UI.Margain, r_GfxInfo.y1 + UI.Margain + 10);
	pWind->DrawString(r_GfxInfo.x1 + UI.Margain - 5, r_GfxInfo.y1 + UI.ToolItemWidth - 1, "Delete");
	return (GraphicsInfo(UI.ToolItemWidth, UI.ToolBarHeight));
}
GraphicsInfo Output::AddIcon( GraphicsInfo r_GfxInfo, PressType State)
{
	switch (State)
	{
	case Normal:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FRAME);
		break;
	case Hovered:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(GREY);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		break;
	case Pressed:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		pWind->SetPen(WHITE, 3);
		break;
	default:
		break;
	}
	
	pWind->DrawLine(r_GfxInfo.x1 + (UI.Margain), r_GfxInfo.y1 + UI.Margain + 20, r_GfxInfo.x1 + UI.Margain + 40, r_GfxInfo.y1 + UI.Margain + 20);
	pWind->DrawLine(UI.ToolItemWidth / 2 + r_GfxInfo.x1, r_GfxInfo.y1 + UI.Margain, r_GfxInfo.x1 + UI.ToolItemWidth / 2, r_GfxInfo.y1 + UI.Margain + 40);
	pWind->SetFont(30, BOLD, BY_NAME, "Arial");
	pWind->DrawString(r_GfxInfo.x1 + 8, r_GfxInfo.y1 + UI.ToolBarHeight - 30, "Add");
	return (GraphicsInfo(UI.ToolItemWidth, UI.ToolBarHeight));
}
GraphicsInfo Output::ConnectIcon( GraphicsInfo r_GfxInfo, PressType State)
{
	switch (State)
	{
	case Normal:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FRAME);
		break;
	case Hovered:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(GREY);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		break;
	case Pressed:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		pWind->SetPen(WHITE, 3);
		break;
	default:
		break;
	}
	pWind->DrawCircle(r_GfxInfo.x1 + UI.Margain, r_GfxInfo.y1 + UI.Margain + 40, 6, FILLED);
	pWind->DrawCircle(r_GfxInfo.x1 + 40 + UI.Margain, r_GfxInfo.y1 + UI.Margain, 6, FILLED);
	Connect(GraphicsInfo(r_GfxInfo.x1 + UI.Margain, r_GfxInfo.y1 + UI.Margain + 40, r_GfxInfo.x1 + 40 + UI.Margain, r_GfxInfo.y1 + UI.Margain),NULL);
	pWind->SetFont(15, BOLD, BY_NAME, "Arial");
	pWind->DrawString(r_GfxInfo.x1 + -2 + UI.Margain, r_GfxInfo.y1 + UI.ToolItemWidth, "Connect");
	return (GraphicsInfo(UI.ToolItemWidth, UI.ToolBarHeight));
}
GraphicsInfo Output::UndoIcon( GraphicsInfo r_GfxInfo, PressType State)
{
	switch (State)
	{
	case Normal:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FRAME);
		break;
	case Hovered:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(GREY);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		break;
	case Pressed:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		pWind->SetPen(WHITE, 3);
		break;
	default:
		break;
	}
	
	pWind->DrawArc(r_GfxInfo.x1 + UI.Margain, r_GfxInfo.y1 + UI.Margain, r_GfxInfo.x1 + UI.Margain + 40, r_GfxInfo.y1 + UI.Margain + 40, 180, 90);
	pWind->DrawTriangle(r_GfxInfo.x1 + +UI.Margain + 20, r_GfxInfo.y1 + UI.Margain, r_GfxInfo.x1 + +27 + UI.Margain, r_GfxInfo.y1 + UI.Margain - 7, r_GfxInfo.x1 + +27 + UI.Margain, r_GfxInfo.y1 + UI.Margain + 17, FILLED);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(r_GfxInfo.x1 - 4 + UI.Margain, r_GfxInfo.y1 + UI.ToolItemWidth, "UNDO");
	return (GraphicsInfo(UI.ToolItemWidth, UI.ToolBarHeight));
}
GraphicsInfo Output::RedoIcon( GraphicsInfo r_GfxInfo, PressType State)
{
	switch (State)
	{
	case Normal:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FRAME);
		break;
	case Hovered:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(GREY);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		break;
	case Pressed:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		pWind->SetPen(WHITE, 3);
		break;
	default:
		break;
	}
	
	pWind->DrawArc(r_GfxInfo.x1 + +UI.Margain, r_GfxInfo.y1 + UI.Margain, r_GfxInfo.x1 + +UI.Margain + 40, r_GfxInfo.y1 + UI.Margain + 40, 90, 0);
	pWind->DrawTriangle(r_GfxInfo.x1 + +UI.Margain + 20, r_GfxInfo.y1 + UI.Margain, r_GfxInfo.x1 + +13 + UI.Margain, r_GfxInfo.y1 + UI.Margain - 7, r_GfxInfo.x1 + +13 + UI.Margain, r_GfxInfo.y1 + UI.Margain + 17, FILLED);
	pWind->DrawString(r_GfxInfo.x1 - 4 + UI.Margain, r_GfxInfo.y1 + UI.ToolItemWidth, "REDO");
	return (GraphicsInfo(UI.ToolItemWidth, UI.ToolBarHeight));
}
GraphicsInfo Output::SaveIcon( GraphicsInfo r_GfxInfo,PressType State)
{
	switch (State)
	{
	case Normal:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FRAME);
		break;
	case Hovered:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(GREY);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		break;
	case Pressed:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		pWind->SetPen(WHITE, 3);
		break;
	default:
		break;
	}
	pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FRAME);
	int XV[] = { r_GfxInfo.x1 + UI.Margain,r_GfxInfo.x1 + UI.Margain + 40,r_GfxInfo.x1 + UI.Margain + 40,r_GfxInfo.x1 + UI.Margain + 35,r_GfxInfo.x1 + UI.Margain };
	int YV[] = { r_GfxInfo.y1 + 40 + UI.Margain,r_GfxInfo.y1 + 40 + UI.Margain ,r_GfxInfo.y1 + UI.Margain + 5,r_GfxInfo.y1 + UI.Margain,r_GfxInfo.y1 + UI.Margain };
	pWind->DrawPolygon(XV, YV, 5, FILLED);
	switch (State)
	{
	case Normal:
		pWind->SetBrush(WHITE);
		pWind->SetPen(WHITE, 3);
		break;
	case Hovered:
		pWind->SetBrush(WHITE);
		pWind->SetPen(WHITE, 3);
		break;
	case Pressed:
		pWind->SetBrush(BLACK);
		pWind->SetPen(BLACK, 3);
		break;
	default:
		break;
	}

	pWind->DrawRectangle(r_GfxInfo.x1 + UI.Margain + 5, r_GfxInfo.y1 + 35 + UI.Margain, r_GfxInfo.x1 + UI.Margain + 35, r_GfxInfo.y1 + UI.Margain + 15, FILLED);
	pWind->DrawRectangle(r_GfxInfo.x1 + UI.Margain + 10, r_GfxInfo.y1 + 5 + UI.Margain, r_GfxInfo.x1 + UI.Margain + 30, r_GfxInfo.y1 + 10 + UI.Margain);
	switch (State)
	{
	case Normal:
		pWind->SetBrush(BLACK);
		pWind->SetPen(BLACK, 1);
		break;
	case Hovered:
		pWind->SetBrush(BLACK);
		pWind->SetPen(BLACK, 1);
		break;
	case Pressed:
		pWind->SetBrush(WHITE);
		pWind->SetPen(WHITE, 1);
		break;
	default:
		break;
	}

	pWind->DrawRectangle(r_GfxInfo.x1 + UI.Margain + 20, r_GfxInfo.y1 + UI.Margain + 6, r_GfxInfo.x1 + UI.Margain + 25, r_GfxInfo.y1 + UI.Margain + 9);
	pWind->SetPen(BLACK, 3);
	pWind->SetFont(25, BOLD, BY_NAME, "Arial");
	pWind->DrawString(r_GfxInfo.x1 - 4 + UI.Margain, r_GfxInfo.y1 + UI.ToolItemWidth - 5, "Save");
	return (GraphicsInfo(UI.ToolItemWidth, UI.ToolBarHeight));
}
GraphicsInfo Output::SelectIcon( GraphicsInfo r_GfxInfo,PressType State)
{
	switch (State)
	{
	case Normal:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FRAME);
		break;
	case Hovered:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(GREY);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		break;
	case Pressed:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		pWind->SetPen(WHITE, 3);
		break;
	default:
		break;
	}
	pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FRAME);
	pWind->DrawRectangle(r_GfxInfo.x1 + UI.Margain, r_GfxInfo.y1 + UI.Margain, r_GfxInfo.x1 + UI.Margain + 40, r_GfxInfo.y1 + UI.Margain + 40, FRAME);
	switch (State)
	{
	case Normal:
		pWind->SetBrush(WHITE);
		break;
	case Hovered:
		pWind->SetBrush(WHITE);
		break;
	case Pressed:
		pWind->SetBrush(BLACK);
		break;
	default:
		break;
	}

	pWind->DrawRectangle(r_GfxInfo.x1 + UI.Margain + 5, r_GfxInfo.y1 + UI.Margain + 5, r_GfxInfo.x1 + UI.Margain + 25, r_GfxInfo.y1 + UI.Margain + 25);
	pWind->DrawRectangle(r_GfxInfo.x1 + UI.Margain + 35, r_GfxInfo.y1 + UI.Margain + 35, r_GfxInfo.x1 + UI.Margain + 15, r_GfxInfo.y1 + UI.Margain + 15);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(r_GfxInfo.x1 - 4 + UI.Margain, r_GfxInfo.y1 + UI.ToolItemWidth - 1, "Select");
	return (GraphicsInfo(UI.ToolItemWidth, UI.ToolBarHeight));
}
GraphicsInfo Output::ExitIcon( GraphicsInfo r_GfxInfo, PressType State)
{

	switch (State)
	{
	case Normal:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FRAME);
		break;
	case Hovered:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(GREY);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		break;
	case Pressed:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		pWind->SetPen(WHITE, 3);
		break;
	default:
		break;
	}
	
	pWind->SetFont(28, BOLD, BY_NAME, "Arial");
	pWind->DrawString(r_GfxInfo.x1 + 5, r_GfxInfo.y1 + UI.Margain + UI.ToolBarHeight / 4, "EXIT");
	return (GraphicsInfo(UI.ToolItemWidth, UI.ToolBarHeight));
}
GraphicsInfo Output::TruthTabelIcon( GraphicsInfo r_GfxInfo, PressType State)
{

	switch (State)
	{
	case Normal:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FRAME);
		break;
	case Hovered:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(GREY);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		break;
	case Pressed:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		pWind->SetPen(WHITE, 3);
		break;
	default:
		break;
	}
	
	pWind->DrawRectangle(r_GfxInfo.x1 + UI.Margain, r_GfxInfo.y1 + UI.Margain, r_GfxInfo.x1 + UI.Margain + 40, r_GfxInfo.y1 + UI.Margain + 40, FRAME);
	for (int i = 0; i <= 40; i += 10)
	{
		pWind->DrawLine(r_GfxInfo.x1 + UI.Margain + i, r_GfxInfo.y1 + UI.Margain, r_GfxInfo.x1 + UI.Margain + i, r_GfxInfo.y1 + UI.Margain + 40);
		pWind->DrawLine(r_GfxInfo.x1 + UI.Margain, r_GfxInfo.y1 + UI.Margain + i, r_GfxInfo.x1 + UI.Margain + 40, r_GfxInfo.y1 + UI.Margain + i);
	}
	pWind->SetFont(10, BOLD, BY_NAME, "Arial");
	pWind->DrawString(r_GfxInfo.x1 - 4 + UI.Margain, r_GfxInfo.y1 + UI.ToolItemWidth - 1, "TruthTable");
	return (GraphicsInfo(UI.ToolItemWidth, UI.ToolBarHeight));
}
GraphicsInfo Output::ValidationIcon( GraphicsInfo r_GfxInfo, PressType State)
{

	switch (State)
	{
	case Normal:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FRAME);
		break;
	case Hovered:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(GREY);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		break;
	case Pressed:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		pWind->SetPen(WHITE, 3);
		break;
	default:
		break;
	}
	
	pWind->DrawLine(r_GfxInfo.x1 + UI.Margain, r_GfxInfo.y1 + UI.Margain + 40, r_GfxInfo.x1 + UI.Margain + 10, r_GfxInfo.y1 + UI.Margain + 50);
	pWind->DrawLine(r_GfxInfo.x1 + UI.Margain + 10, r_GfxInfo.y1 + UI.Margain + 50, r_GfxInfo.x1 + UI.Margain + 40, r_GfxInfo.y1 + UI.Margain);
	pWind->SetFont(17, BOLD, BY_NAME, "Arial");
	pWind->DrawString(r_GfxInfo.x1 + UI.Margain - 7, r_GfxInfo.y1 + UI.ToolItemWidth, "Validate");
	return (GraphicsInfo(UI.ToolItemWidth, UI.ToolBarHeight));
}
GraphicsInfo Output::SimulateIcon( GraphicsInfo r_GfxInfo, PressType State)
{

	switch (State)
	{
	case Normal:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FRAME);
		break;
	case Hovered:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(GREY);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		break;
	case Pressed:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		pWind->SetPen(WHITE, 3);
		break;
	default:
		break;
	}
	
	pWind->SetFont(40, BOLD, BY_NAME, "Arial");
	pWind->DrawInteger(r_GfxInfo.x1 + UI.Margain + 30, r_GfxInfo.y1 + UI.Margain + 10, 1);
	pWind->DrawInteger(r_GfxInfo.x1 + UI.Margain - 5, r_GfxInfo.y1 + UI.Margain + 10, 0);
	pWind->DrawLine(r_GfxInfo.x1 + UI.Margain + 15, r_GfxInfo.y1 + 1 + 28 + UI.Margain, r_GfxInfo.x1 + UI.Margain + 33, r_GfxInfo.y1 + 1 + 28 + UI.Margain);
	pWind->DrawLine(r_GfxInfo.x1 + UI.Margain + 33, r_GfxInfo.y1 + 1 + 28 + UI.Margain, r_GfxInfo.x1 + UI.Margain + 30, r_GfxInfo.y1 + 1 + UI.Margain + 25);
	pWind->DrawLine(r_GfxInfo.x1 + UI.Margain + 15, r_GfxInfo.y1 + 1 + UI.Margain + 32, r_GfxInfo.x1 + UI.Margain + 33, r_GfxInfo.y1 + 1 + UI.Margain + 32);
	pWind->DrawLine(r_GfxInfo.x1 + UI.Margain + 15, r_GfxInfo.y1 + 1 + UI.Margain + 32, r_GfxInfo.x1 + UI.Margain + 18, r_GfxInfo.y1 + 1 + UI.Margain + 35);
	pWind->SetFont(15, BOLD, BY_NAME, "Arial");
	pWind->DrawString(r_GfxInfo.x1 + UI.Margain - 7, r_GfxInfo.y1 + UI.ToolItemWidth, "Simulate");
	return (GraphicsInfo(UI.ToolItemWidth, UI.ToolBarHeight));
}
GraphicsInfo Output::ProbeIcon( GraphicsInfo r_GfxInfo, PressType State)
{

	switch (State)
	{
	case Normal:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FRAME);
		break;
	case Hovered:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(GREY);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		break;
	case Pressed:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		pWind->SetPen(WHITE, 3);
		break;
	default:
		break;
	}
	
	pWind->DrawLine(r_GfxInfo.x1 + UI.Margain + 5, r_GfxInfo.y1 + UI.Margain + 40, r_GfxInfo.x1 + UI.Margain + 20, r_GfxInfo.y1 + UI.Margain + 20);
	pWind->DrawCircle(r_GfxInfo.x1 + UI.Margain + 25, r_GfxInfo.y1 + UI.Margain + 15, 10, FRAME);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(r_GfxInfo.x1 + UI.Margain - 3, r_GfxInfo.y1 + UI.ToolItemWidth, "Probe");
	return (GraphicsInfo(UI.ToolItemWidth, UI.ToolBarHeight));
}
GraphicsInfo Output::BeginSimulationIcon( GraphicsInfo r_GfxInfo, PressType State)
{

	switch (State)
	{
	case Normal:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FRAME);
		break;
	case Hovered:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(GREY);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		break;
	case Pressed:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		pWind->SetPen(WHITE, 3);
		break;
	default:
		break;
	}
	
	pWind->DrawTriangle(r_GfxInfo.x1 + UI.Margain, r_GfxInfo.y1 + UI.Margain, r_GfxInfo.x1 + UI.Margain, r_GfxInfo.y1 + 40 + UI.Margain, r_GfxInfo.x1 + 40 + UI.Margain, r_GfxInfo.y1 + 20 + UI.Margain, FILLED);
	pWind->SetFont(13, BOLD, BY_NAME, "Arial");
	pWind->DrawString(r_GfxInfo.x1 + 1, r_GfxInfo.y1 + UI.ToolItemWidth - 1, "SIMU Mode");
	return (GraphicsInfo(UI.ToolItemWidth, UI.ToolBarHeight));
}
GraphicsInfo Output::ReturnDesign( GraphicsInfo r_GfxInfo,PressType State)
{

	switch (State)
	{
	case Normal:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FRAME);
		break;
	case Hovered:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(GREY);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		break;
	case Pressed:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		pWind->SetPen(WHITE, 3);
		break;
	default:
		break;
	}
	pWind->DrawRectangle(r_GfxInfo.x1 + UI.Margain, r_GfxInfo.y1 + UI.Margain, r_GfxInfo.x1 + UI.ToolItemWidth - UI.Margain, r_GfxInfo.y1 + UI.ToolItemWidth, FILLED, 5, 5);
	pWind->SetFont(11, BOLD, BY_NAME, "Arial");
	pWind->DrawString(r_GfxInfo.x1 + 2, r_GfxInfo.y1 + UI.ToolItemWidth - 1, "DSGN Mode");
	return (GraphicsInfo(UI.ToolItemWidth, UI.ToolBarHeight));
}
GraphicsInfo Output::LoadICon(GraphicsInfo r_GfxInfo, PressType State)
{
	switch (State)
	{
	case Normal:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FRAME);
		break;
	case Hovered:
		pWind->SetPen(BLACK, 3);
		pWind->SetBrush(GREY);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		break;
	case Pressed:
		pWind->SetPen(WHITE, 3);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.ToolItemWidth, r_GfxInfo.y1 + UI.ToolBarHeight, FILLED);
		pWind->SetPen(WHITE, 3);
		break;
	default:
		break;
	}
	int XV[] = { r_GfxInfo.x1 + UI.Margain,r_GfxInfo.x1 + UI.Margain + 40,r_GfxInfo.x1 + UI.Margain + 40,r_GfxInfo.x1 + UI.Margain + 35,r_GfxInfo.x1 + UI.Margain + 35,r_GfxInfo.x1 + UI.Margain + 5,r_GfxInfo.x1 + UI.Margain + 5,r_GfxInfo.x1 + UI.Margain };
	int YV[] = { r_GfxInfo.y1 + UI.Margain + 40,r_GfxInfo.y1 + UI.Margain + 40,r_GfxInfo.y1 + UI.Margain + 20,r_GfxInfo.y1 + UI.Margain + 20,r_GfxInfo.y1 + UI.Margain + 35,r_GfxInfo.y1 + UI.Margain + 35,r_GfxInfo.y1 + UI.Margain + 20,r_GfxInfo.y1 + 20+UI.Margain };
	pWind->DrawPolygon(XV, YV, 8, FILLED);
	pWind->DrawLine(r_GfxInfo.x1 + 20 + UI.Margain, r_GfxInfo.y1 + UI.Margain + 10, r_GfxInfo.x1 + 20+UI.Margain, r_GfxInfo.y1 + UI.Margain + 30);
	pWind->DrawLine(r_GfxInfo.x1 + 20 + UI.Margain, r_GfxInfo.y1 + UI.Margain + 30, r_GfxInfo.x1 + 25 + UI.Margain, r_GfxInfo.y1 + UI.Margain + 25);
	pWind->DrawLine(r_GfxInfo.x1 + 20 + UI.Margain, r_GfxInfo.y1 + UI.Margain + 30, r_GfxInfo.x1 + 15 + UI.Margain, r_GfxInfo.y1 + UI.Margain + 25);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(r_GfxInfo.x1 + UI.Margain, r_GfxInfo.y1 + UI.ToolItemWidth - 1, "Load");
	return (GraphicsInfo(UI.ToolItemWidth, UI.ToolBarHeight));
}
GraphicsInfo Output::MoveString(GraphicsInfo r_GfxInfo, PressType State)
{
	GraphicsInfo tmp=DetermineState(r_GfxInfo,State);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(r_GfxInfo.x1 + UI.Margain, r_GfxInfo.y1 + 1, "Move");
	return tmp;
}
GraphicsInfo Output::CutString(GraphicsInfo r_GfxInfo, PressType State)
{
	GraphicsInfo tmp=DetermineState(r_GfxInfo, State);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(r_GfxInfo.x1 + UI.Margain, r_GfxInfo.y1 + 1, "Cut");
	return tmp;
}
GraphicsInfo Output::PasteString(GraphicsInfo r_GfxInfo, PressType State)
{
	GraphicsInfo tmp=DetermineState(r_GfxInfo, State);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(r_GfxInfo.x1 + UI.Margain, r_GfxInfo.y1 + 1, "Paste");
	return tmp;
}
GraphicsInfo Output::CopyString(GraphicsInfo r_GfxInfo, PressType State)
{
	GraphicsInfo tmp=DetermineState(r_GfxInfo, State);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(r_GfxInfo.x1 + UI.Margain, r_GfxInfo.y1 + 1, "Copy");
	return tmp;
}
GraphicsInfo Output::DeleteString(GraphicsInfo r_GfxInfo, PressType State)
{
	GraphicsInfo tmp=DetermineState(r_GfxInfo, State);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(r_GfxInfo.x1+ UI.Margain, r_GfxInfo.y1 + 1, "Delete");
	return tmp;
}
GraphicsInfo Output::AndIcon(GraphicsInfo r_GfxInfo, PressType State)
{
	pWind->SetPen(BLACK, 3);
	pWind->SetBrush(BLACK);
	DrawAND2(GraphicsInfo(r_GfxInfo.x1 +UI.GateItemWidth/2-UI.Margain, r_GfxInfo.y1+UI.GateBarHeight/2), NULL, State);
	pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.GateItemWidth, r_GfxInfo.y1 + UI.GateBarHeight,FRAME);
	return (GraphicsInfo(UI.GateItemWidth, UI.GateBarHeight));
}
GraphicsInfo Output::ORIcon(GraphicsInfo r_GfxInfo, PressType State)
{
	DrawOR2(GraphicsInfo(r_GfxInfo.x1 + UI.GateItemWidth / 2 - UI.Margain, r_GfxInfo.y1 + UI.GateBarHeight / 2), NULL, false);
	pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.GateItemWidth, r_GfxInfo.y1 + UI.GateBarHeight,FRAME);

	return (GraphicsInfo(UI.GateItemWidth, UI.GateBarHeight));
}
GraphicsInfo Output::XORIcon(GraphicsInfo r_GfxInfo, PressType State)
{
	DrawXOR2(GraphicsInfo(r_GfxInfo.x1 + UI.GateItemWidth / 2 - UI.Margain, r_GfxInfo.y1 + UI.GateBarHeight / 2), NULL, false);
	pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.GateItemWidth, r_GfxInfo.y1 + UI.GateBarHeight,FRAME);

	return (GraphicsInfo(UI.GateItemWidth, UI.GateBarHeight));
}
GraphicsInfo Output::LEDIcon(GraphicsInfo r_GfxInfo, PressType State)
{
	DrawLED(GraphicsInfo(r_GfxInfo.x1 + UI.GateItemWidth / 2 , r_GfxInfo.y1 + UI.GateBarHeight / 2), NULL, false);
	pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.GateItemWidth, r_GfxInfo.y1 + UI.GateBarHeight,FRAME);

	return (GraphicsInfo(UI.GateItemWidth, UI.GateBarHeight));
}
GraphicsInfo Output::SwitchIcon(GraphicsInfo r_GfxInfo, PressType State)
{
	DrawSwitch(GraphicsInfo(r_GfxInfo.x1 + UI.GateItemWidth / 2 - UI.Margain, r_GfxInfo.y1 + UI.GateBarHeight / 2), NULL, false);
	pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.GateItemWidth, r_GfxInfo.y1 + UI.GateBarHeight,FRAME);

	return (GraphicsInfo(UI.GateItemWidth, UI.GateBarHeight));
}
GraphicsInfo Output::BufferIcon(GraphicsInfo r_GfxInfo, PressType State)
{
	DrawBuffer(GraphicsInfo(r_GfxInfo.x1 + UI.GateItemWidth / 2 - UI.Margain, r_GfxInfo.y1 + UI.GateBarHeight / 2), NULL, false,false);
	pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.GateItemWidth, r_GfxInfo.y1 + UI.GateBarHeight,FRAME);
	return (GraphicsInfo(UI.GateItemWidth, UI.GateBarHeight));
}
GraphicsInfo Output::InverterIcon(GraphicsInfo r_GfxInfo, PressType State)
{
	DrawBuffer(GraphicsInfo(r_GfxInfo.x1 + UI.GateItemWidth / 2 - UI.Margain, r_GfxInfo.y1 + UI.GateBarHeight / 2), NULL,false, true);
	pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.GateItemWidth, r_GfxInfo.y1 + UI.GateBarHeight,FRAME);
	return (GraphicsInfo(UI.GateItemWidth, UI.GateBarHeight));
}
GraphicsInfo Output::And2Icon(GraphicsInfo r_GfxInfo, PressType State)
{
	DrawAND2(GraphicsInfo(r_GfxInfo.x1+UI.GateItemWidth / 2 - UI.Margain, r_GfxInfo.y1 + UI.GateBarHeight/2), NULL, false);
	pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.GateItemWidth, r_GfxInfo.y1 + UI.GateBarHeight, FRAME);
	return (GraphicsInfo(UI.GateItemWidth, UI.GateBarHeight));
}
GraphicsInfo Output::Nand2Icon(GraphicsInfo r_GfxInfo, PressType State)
{
	DrawNAND2(GraphicsInfo(r_GfxInfo.x1 + UI.GateItemWidth / 2 - UI.Margain, r_GfxInfo.y1 + UI.GateBarHeight/2), NULL, false);
	pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.GateItemWidth, r_GfxInfo.y1 + UI.GateBarHeight, FRAME);
	return (GraphicsInfo(UI.GateItemWidth, UI.GateBarHeight));
}
GraphicsInfo Output::And3Icon(GraphicsInfo r_GfxInfo, PressType State)
{
	DrawAND3(GraphicsInfo(r_GfxInfo.x1 + UI.GateItemWidth / 2 - UI.Margain, r_GfxInfo.y1 + UI.GateBarHeight/2), NULL, false);
	pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.GateItemWidth, r_GfxInfo.y1 + UI.GateBarHeight, FRAME);
	return (GraphicsInfo(UI.GateItemWidth, UI.GateBarHeight));
}
GraphicsInfo Output::Nand3Icon(GraphicsInfo r_GfxInfo, PressType State)
{
	DrawNAND3(GraphicsInfo(r_GfxInfo.x1 + UI.GateItemWidth / 2 - UI.Margain, r_GfxInfo.y1 + UI.GateBarHeight/2), NULL, false);
	pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.GateItemWidth, r_GfxInfo.y1 + UI.GateBarHeight, FRAME);
	return (GraphicsInfo(UI.GateItemWidth, UI.GateBarHeight));
}
GraphicsInfo Output::OR2Icon(GraphicsInfo r_GfxInfo, PressType State)
{
	DrawOR2(GraphicsInfo(r_GfxInfo.x1 + UI.GateItemWidth / 2 - UI.Margain, r_GfxInfo.y1 + UI.GateBarHeight / 2), NULL, false);
	pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.GateItemWidth, r_GfxInfo.y1 + UI.GateBarHeight, FRAME);
	return (GraphicsInfo(UI.GateItemWidth, UI.GateBarHeight));
}
GraphicsInfo Output::NOR2Icon(GraphicsInfo r_GfxInfo, PressType State)
{
	DrawNOR2(GraphicsInfo(r_GfxInfo.x1 + UI.GateItemWidth / 2 - UI.Margain, r_GfxInfo.y1 + UI.GateBarHeight / 2), NULL, false);
	pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.GateItemWidth, r_GfxInfo.y1 + UI.GateBarHeight, FRAME);
	return (GraphicsInfo(UI.GateItemWidth, UI.GateBarHeight));
}
GraphicsInfo Output::OR3Icon(GraphicsInfo r_GfxInfo, PressType State)
{
	DrawOR3(GraphicsInfo(r_GfxInfo.x1 + UI.GateItemWidth / 2 - UI.Margain, r_GfxInfo.y1 + UI.GateBarHeight / 2), NULL, false);
	pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.GateItemWidth, r_GfxInfo.y1 + UI.GateBarHeight, FRAME);
	return (GraphicsInfo(UI.GateItemWidth, UI.GateBarHeight));
}
GraphicsInfo Output::NOR3Icon(GraphicsInfo r_GfxInfo, PressType State)
{
	DrawNOR3(GraphicsInfo(r_GfxInfo.x1 + UI.GateItemWidth / 2 - UI.Margain, r_GfxInfo.y1 + UI.GateBarHeight / 2), NULL, false);
	pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.GateItemWidth, r_GfxInfo.y1 + UI.GateBarHeight, FRAME);
	return (GraphicsInfo(UI.GateItemWidth, UI.GateBarHeight));
}
GraphicsInfo Output::XOR2Icon(GraphicsInfo r_GfxInfo, PressType State)
{
	DrawXOR2(GraphicsInfo(r_GfxInfo.x1 + UI.GateItemWidth / 2 - UI.Margain, r_GfxInfo.y1 + UI.GateBarHeight / 2), NULL, false);
	pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.GateItemWidth, r_GfxInfo.y1 + UI.GateBarHeight, FRAME);
	return (GraphicsInfo(UI.GateItemWidth, UI.GateBarHeight));
}
GraphicsInfo Output::XNOR2Icon(GraphicsInfo r_GfxInfo, PressType State)
{
	DrawXNOR2(GraphicsInfo(r_GfxInfo.x1 + UI.GateItemWidth / 2 - UI.Margain, r_GfxInfo.y1 + UI.GateBarHeight / 2), NULL, false);
	pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.GateItemWidth, r_GfxInfo.y1 + UI.GateBarHeight, FRAME);
	return (GraphicsInfo(UI.GateItemWidth, UI.GateBarHeight));
}
GraphicsInfo Output::XOR3Icon(GraphicsInfo r_GfxInfo, PressType State)
{
	DrawXOR3(GraphicsInfo(r_GfxInfo.x1 + UI.GateItemWidth / 2 - UI.Margain, r_GfxInfo.y1 + UI.GateBarHeight / 2), NULL, false);
	pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.GateItemWidth, r_GfxInfo.y1 + UI.GateBarHeight, FRAME);
	return (GraphicsInfo(UI.GateItemWidth, UI.GateBarHeight));
}
GraphicsInfo Output::XNOR3Icon(GraphicsInfo r_GfxInfo, PressType State)
{
	DrawXNOR3(GraphicsInfo(r_GfxInfo.x1 + UI.GateItemWidth / 2 - UI.Margain, r_GfxInfo.y1 + UI.GateBarHeight / 2), NULL, false);
	pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.GateItemWidth, r_GfxInfo.y1 + UI.GateBarHeight, FRAME);
	return (GraphicsInfo(UI.GateItemWidth, UI.GateBarHeight));
}
void Output::DrawConnection(vector<pair<int, int>> Points,GridItem*ptr)
{
	pWind->SetPen(BLACK, 3);
	for (int i = 0; i < Points.size() - 1; i++)
	{
		pWind->DrawLine(Points[i].first, Points[i].second, Points[i + 1].first, Points[i + 1].second);
		Interface->Register(GraphicsInfo(Points[i].first, Points[i].second, Points[i + 1].first, Points[i + 1].second), ptr);
	}
}
GraphicsInfo Output::DrawButon(int index,GraphicsInfo r_GfxInfo, PressType State)
{
	return(this->*ButtonFunctions[index])(r_GfxInfo,State);

}
ActionType Output::GetReturnedAction(int index)
{
	return ButtonActions[index];
}
void Output::RegisterButton(GridItem * ptr)
{
	Button*tmp = dynamic_cast<Button*> (ptr);
	Interface->Register(GraphicsInfo(tmp->GetPosition().x1, tmp->GetPosition().y1, tmp->GetDimensions().x1 + tmp->GetPosition().x1, tmp->GetPosition().y1 + tmp->GetDimensions().x1), ptr);
}
void Output::EraseButton(GridItem*ptr)
{
	pWind->SetPen(WHITE, 3);
	pWind->SetBrush(WHITE);
	Button*tmp = dynamic_cast<Button*> (ptr);
	pWind->DrawRectangle(tmp->GetPosition().x1, tmp->GetPosition().y1, tmp->GetDimensions().x1 + tmp->GetPosition().x1, tmp->GetPosition().y1 + tmp->GetDimensions().x1);
	Interface->UNRegister(GraphicsInfo(tmp->GetPosition().x1, tmp->GetPosition().y1, tmp->GetDimensions().x1 + tmp->GetPosition().x1, tmp->GetPosition().y1 + tmp->GetDimensions().x1));
}
//======================================================================================//
//								Gate Drawing Functions									//
//======================================================================================//

/*
////////////////////////////////////////And Gate//////////////////////////////////////////
*/
void Output::DrawAND(GraphicsInfo r_GfxInfo, GridItem*ptr, bool selected, bool invert, bool connections) const
{
	r_GfxInfo.x2 = r_GfxInfo.x1 + UI.AllGateDimensions / 4;
	r_GfxInfo.y2 = r_GfxInfo.y1 + UI.AllGateDimensions / 2;
	r_GfxInfo.x1 -= UI.AllGateDimensions / 4;
	r_GfxInfo.y1 -= UI.AllGateDimensions / 2;
	int raduis = (r_GfxInfo.y2 - r_GfxInfo.y1) / 2;
	raduis += 9;
	pWind->SetPen(BLACK, 3);
	pWind->SetBrush(SKYBLUE);
	pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y1);
	pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);
	pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1, r_GfxInfo.y2);
	pWind->DrawArc(r_GfxInfo.x2 - raduis + 3, r_GfxInfo.y1 - 2, r_GfxInfo.x2 + raduis - 6, r_GfxInfo.y2 + 2, 270, 90);
	if (selected) {
		pWind->DrawArc(r_GfxInfo.x2 - raduis + 3, r_GfxInfo.y1 - 2, r_GfxInfo.x2 + raduis - 6, r_GfxInfo.y2 + 2, 270, 90, FILLED);
		pWind->SetPen(SKYBLUE);
		pWind->DrawRectangle(r_GfxInfo.x1 + 2, r_GfxInfo.y1 + 2, r_GfxInfo.x2, r_GfxInfo.y2 - 1, FILLED);
	}
	if (!invert)
	{
		pWind->SetPen(BLACK, 3);
		pWind->DrawLine(r_GfxInfo.x2 + raduis - 9, r_GfxInfo.y1 + raduis - 9, r_GfxInfo.x2 + raduis + 1, r_GfxInfo.y1 + raduis - 9);
		if (ptr != NULL)
		Interface->Register(GraphicsInfo(r_GfxInfo.x2 + raduis - 9, r_GfxInfo.y1, r_GfxInfo.x2 + raduis + 1, r_GfxInfo.y2), &((Gate*)ptr)->GetOutputPin());//Connection
	}
	if (invert)
	{
		pWind->SetPen(BLACK, 3);
		int y_Center = r_GfxInfo.y1 + raduis - 9;
		int x_Center = r_GfxInfo.x2 + raduis - 1;
		int Raduis = UI.InverterDimensions;
		if (selected)
			pWind->DrawCircle(x_Center - 1, y_Center, Raduis);
		else pWind->DrawCircle(x_Center - 1, y_Center, Raduis, FRAME);
		pWind->DrawLine(x_Center - 1 + Raduis, y_Center, x_Center + Raduis + 9, y_Center);
		if (ptr != NULL)
		{
			Interface->Register(GraphicsInfo(x_Center - 1 + Raduis, r_GfxInfo.y1, x_Center + Raduis + 9, r_GfxInfo.y2), &((Gate*)ptr)->GetOutputPin());//Connection
			Interface->Register(GraphicsInfo(r_GfxInfo.x1 + UI.AllGateDimensions, r_GfxInfo.y1, x_Center - 1 + Raduis, r_GfxInfo.y2), ptr);//Gate
		}
	}
	pWind->SetPen(BLACK, 3);
	if (connections)
	{
		int dist = (r_GfxInfo.y2 - r_GfxInfo.y1) / 4;
		for (size_t i = 1; i <= 3; i++)
		{
			pWind->DrawLine(r_GfxInfo.x1 - UI.ConnectionDimensions, (r_GfxInfo.y1 + i* dist), r_GfxInfo.x1, (r_GfxInfo.y1) + i* dist);


		}
	}
	else
	{
		int dist = (r_GfxInfo.y2 - r_GfxInfo.y1) / 3;
		for (size_t i = 1; i <= 2; i++)
		{
			pWind->DrawLine(r_GfxInfo.x1 - UI.ConnectionDimensions, (r_GfxInfo.y1 + i* dist), r_GfxInfo.x1, (r_GfxInfo.y1) + i*dist);
		}
	}
	if (ptr != NULL)
	{
		Interface->Register(GraphicsInfo(r_GfxInfo.x1 - UI.ConnectionDimensions, r_GfxInfo.y1, r_GfxInfo.x1, r_GfxInfo.y2), ((Gate*)ptr)->GetInputPins());//Connection
		Interface->Register(GraphicsInfo(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + UI.AllGateDimensions, r_GfxInfo.y2), ptr);//Gate
	}
}

void Output::DrawAND2(GraphicsInfo r_GfxInfo, GridItem*ptr, bool selected)
{
	DrawAND(r_GfxInfo,ptr, selected);
}

void Output::DrawNAND2(GraphicsInfo r_GfxInfo, GridItem*ptr, bool selected)
{
	DrawAND(r_GfxInfo,ptr, selected,true);
}

void Output::DrawAND3(GraphicsInfo r_GfxInfo, GridItem*ptr, bool selected)
{
	DrawAND(r_GfxInfo,ptr, selected, false, true);
}

void Output::DrawNAND3(GraphicsInfo r_GfxInfo, GridItem*ptr, bool selected)
{
	DrawAND(r_GfxInfo,ptr, selected, true, true);
}
void Output::CreateAddToolBar()
{
	Toolbars[ADDBAR].Draw(this);
}
void Output::DrawAND2(Gate * ptr)
{
	DrawAND2(ptr->GetPosition(), ptr, ptr->GetState());
}
void Output::DrawNAND2(Gate * ptr)
{
	DrawNAND2(ptr->GetPosition(), ptr, ptr->GetState());
}
void Output::DrawAND3(Gate * ptr)
{
	DrawAND3(ptr->GetPosition(), ptr, ptr->GetState());
}
void Output::DrawNAND3(Gate * ptr)
{
	DrawNAND3(ptr->GetPosition(), ptr, ptr->GetState());
}
/*
////////////////////////OR Gate////////////////////////////////
*/
void Output::DrawOr(GraphicsInfo r_GfxInfo, GridItem*ptr, bool selected, bool invert, bool connections) const
{
	pWind->SetPen(BLACK, 3);
	r_GfxInfo.x2 = r_GfxInfo.x1 + UI.AllGateDimensions / 4;
	r_GfxInfo.y2 = r_GfxInfo.y1 + UI.AllGateDimensions / 2;
	r_GfxInfo.x1 -= UI.AllGateDimensions / 4;
	r_GfxInfo.y1 -= UI.AllGateDimensions / 2;
	int ArcHeight = (r_GfxInfo.x2 - r_GfxInfo.x1) / 2;
	int Midpoint = (r_GfxInfo.y2 - r_GfxInfo.y1) / 2;
	int iHeight = (r_GfxInfo.x2 - r_GfxInfo.x1);
	if (!invert)
	{
		pWind->DrawLine(r_GfxInfo.x2 + iHeight, r_GfxInfo.y1 + Midpoint, r_GfxInfo.x2 + iHeight + 10, r_GfxInfo.y1 + Midpoint);
		if (ptr != NULL)
		Interface->Register(GraphicsInfo(r_GfxInfo.x2 + iHeight, r_GfxInfo.y1, r_GfxInfo.x2 + iHeight + 10, r_GfxInfo.y2), &((Gate*)ptr)->GetOutputPin());
	}
	if (selected)
	{
		pWind->SetPen(SKYBLUE, 3);
		pWind->SetBrush(SKYBLUE);
		pWind->DrawRectangle(r_GfxInfo.x1 + ArcHeight, r_GfxInfo.y1 + 2, r_GfxInfo.x2 + 1, r_GfxInfo.y2 - 1, FILLED, 0, 0);
		pWind->SetPen(SKYBLUE, 3);
		pWind->SetBrush(SKYBLUE);
		pWind->DrawArc(r_GfxInfo.x1, r_GfxInfo.y1 + 1, r_GfxInfo.x2 + iHeight - 2, r_GfxInfo.y2 - 1, 270, 90, FILLED);
		pWind->SetPen(SKYBLUE, 1);
		for (int i = 0;i <= ArcHeight; i++)
		{
			pWind->DrawArc(r_GfxInfo.x1 - ArcHeight + i, r_GfxInfo.y1, r_GfxInfo.x1 + ArcHeight + i, r_GfxInfo.y2, 270, 90);
		}
	}
	if (invert)
	{
		pWind->SetPen(BLACK, 3);
		int y_Center = r_GfxInfo.y2 - Midpoint;
		int x_Center = r_GfxInfo.x2 + iHeight + 3;
		int Raduis = UI.InverterDimensions;
		if (selected)
			pWind->DrawCircle(x_Center - 1, y_Center, Raduis);
		else pWind->DrawCircle(x_Center - 1, y_Center, Raduis, FRAME);
		pWind->DrawLine(x_Center - 1 + Raduis, y_Center, x_Center + Raduis + 10, y_Center);
		if (ptr != NULL)
		{
			Interface->Register(GraphicsInfo(r_GfxInfo.x2 + iHeight + 2 * Raduis, r_GfxInfo.y1, x_Center + Raduis + 10, r_GfxInfo.y2), &((Gate*)ptr)->GetOutputPin());
			Interface->Register(GraphicsInfo(r_GfxInfo.x2 + iHeight, r_GfxInfo.y1, r_GfxInfo.x2 + iHeight + 2 * Raduis, r_GfxInfo.y2), ptr);
		}
	}
	if (connections)
	{
		pWind->SetPen(BLACK, 3);
		int dist = (r_GfxInfo.y2 - r_GfxInfo.y1) / 4;
		for (size_t i = 1; i <= 3; i++)
		{
			pWind->DrawLine(r_GfxInfo.x1 - UI.ConnectionDimensions, r_GfxInfo.y1 + (i*dist), r_GfxInfo.x1 + ArcHeight - 1, r_GfxInfo.y1 + i*dist);

		}
	}
	else
	{
		pWind->SetPen(BLACK, 3);
		int dist = (r_GfxInfo.y2 - r_GfxInfo.y1) / 3;
		for (size_t i = 1; i < 3; i++)
		{
			pWind->DrawLine(r_GfxInfo.x1 - UI.ConnectionDimensions, r_GfxInfo.y1 + (i*dist), r_GfxInfo.x1 + ArcHeight - 1, r_GfxInfo.y1 + i*dist);
		}
	}
	if (ptr != NULL)
	Interface->Register(GraphicsInfo(r_GfxInfo.x1 - UI.ConnectionDimensions, r_GfxInfo.y1, r_GfxInfo.x1, r_GfxInfo.y2), ((Gate*)ptr)->GetInputPins());
	pWind->SetPen(BLACK, 3);
	pWind->SetBrush(SKYBLUE);
	pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y1);
	pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);
	pWind->DrawArc(r_GfxInfo.x1 - ArcHeight, r_GfxInfo.y1, r_GfxInfo.x1 + ArcHeight, r_GfxInfo.y2, 270, 90);
	pWind->DrawArc(r_GfxInfo.x1, r_GfxInfo.y1 - 2, r_GfxInfo.x2 + iHeight, r_GfxInfo.y2 + 2, 270, 90);
	if (ptr != NULL)
	Interface->Register(GraphicsInfo(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2 + iHeight, r_GfxInfo.y2), ptr);

}

void Output::DrawOR2(GraphicsInfo r_GfxInfo, GridItem*ptr, bool selected)
{
	DrawOr(r_GfxInfo, ptr, selected);
}

void Output::DrawOR3(GraphicsInfo r_GfxInfo, GridItem*ptr, bool selected)
{
	DrawOr(r_GfxInfo, ptr, selected, false, true);
}

void Output::DrawNOR2(GraphicsInfo r_GfxInfo, GridItem*ptr, bool selected)
{
	DrawOr(r_GfxInfo, ptr, selected, true, false);
}

void Output::DrawNOR3(GraphicsInfo r_GfxInfo, GridItem*ptr, bool selected)
{
	DrawOr(r_GfxInfo, ptr, selected, true, true);
}

void Output::DrawOR2(Gate * ptr )
{
	DrawOR2(ptr->GetPosition(), ptr, ptr->GetState());
}

void Output::DrawOR3(Gate * ptr)
{
	DrawOR3(ptr->GetPosition(), ptr, ptr->GetState());
}

void Output::DrawNOR2(Gate * ptr)
{
	DrawNOR2(ptr->GetPosition(), ptr, ptr->GetState());
}

void Output::DrawNOR3(Gate * ptr)
{
	DrawNOR3(ptr->GetPosition(), ptr, ptr->GetState());
}

/*
////////////////////////////////////////XorGate///////////////////////////
*/
void Output::DrawXOR(GraphicsInfo r_GfxInfo, GridItem*ptr, bool selected, bool invert, bool connections) const
{
	r_GfxInfo.x2 = r_GfxInfo.x1 + UI.AllGateDimensions / 4;
	r_GfxInfo.y2 = r_GfxInfo.y1 + UI.AllGateDimensions / 2;
	r_GfxInfo.x1 -= UI.AllGateDimensions / 4;
	r_GfxInfo.y1 -= UI.AllGateDimensions / 2;
	int ArcHeight = (r_GfxInfo.x2 - r_GfxInfo.x1) / 2;
	int Midpoint = (r_GfxInfo.y2 - r_GfxInfo.y1) / 2;
	int iHeight = (r_GfxInfo.x2 - r_GfxInfo.x1);
	pWind->SetPen(BLACK, 3);
	if (!invert)
	{
		pWind->DrawLine(r_GfxInfo.x2 + iHeight, r_GfxInfo.y1 + Midpoint, r_GfxInfo.x2 + iHeight + 10, r_GfxInfo.y1 + Midpoint);
		if (ptr != NULL)
		Interface->Register(GraphicsInfo(r_GfxInfo.x2 + iHeight, r_GfxInfo.y1, r_GfxInfo.x2 + iHeight + 10, r_GfxInfo.y2), ((Gate*)ptr)->GetInputPins());
	}
	if (selected)
	{
		pWind->SetPen(SKYBLUE, 3);
		pWind->SetBrush(SKYBLUE);
		pWind->DrawRectangle(r_GfxInfo.x1 + ArcHeight, r_GfxInfo.y1 + 2, r_GfxInfo.x2 + 1, r_GfxInfo.y2 - 1, FILLED, 0, 0);
		pWind->SetPen(SKYBLUE, 3);
		pWind->SetBrush(SKYBLUE);
		pWind->DrawArc(r_GfxInfo.x1, r_GfxInfo.y1 + 1, r_GfxInfo.x2 + iHeight - 2, r_GfxInfo.y2 - 1, 270, 90, FILLED);
		pWind->SetPen(SKYBLUE, 1);
		for (int i = 0;i <= ArcHeight; i++)
		{
			pWind->DrawArc(r_GfxInfo.x1 - ArcHeight + i, r_GfxInfo.y1, r_GfxInfo.x1 + ArcHeight + i, r_GfxInfo.y2, 270, 90);
		}
	}
	if (invert)
	{
		pWind->SetPen(BLACK, 3);
		int y_Center = r_GfxInfo.y2 - Midpoint;
		int x_Center = r_GfxInfo.x2 + iHeight + 3;
		int Raduis = UI.InverterDimensions;
		if (selected)
			pWind->DrawCircle(x_Center - 1, y_Center, Raduis);
		else pWind->DrawCircle(x_Center - 1, y_Center, Raduis, FRAME);
		pWind->DrawLine(x_Center - 1 + Raduis, y_Center, x_Center + Raduis + 10, y_Center);
		if (ptr != NULL)
		{
			Interface->Register(GraphicsInfo(r_GfxInfo.x2 + iHeight + 2 * Raduis, r_GfxInfo.y1, x_Center + Raduis + 10, r_GfxInfo.y2), ((Gate*)ptr)->GetInputPins());
			Interface->Register(GraphicsInfo(r_GfxInfo.x2 + iHeight, r_GfxInfo.y1, r_GfxInfo.x2 + iHeight + 2 * Raduis, r_GfxInfo.y2), ptr);
		}
	}
	if (connections)
	{
		pWind->SetPen(BLACK, 3);
		int dist = (r_GfxInfo.y2 - r_GfxInfo.y1) / 4;
		for (size_t i = 1; i <= 3; i++)
		{
			pWind->DrawLine(r_GfxInfo.x1 - UI.ConnectionDimensions, r_GfxInfo.y1 + (i*dist), r_GfxInfo.x1 + ArcHeight - 1, r_GfxInfo.y1 + i*dist);

		}
	}
	else
	{
		pWind->SetPen(BLACK, 3);
		int dist = (r_GfxInfo.y2 - r_GfxInfo.y1) / 3;
		for (size_t i = 1; i < 3; i++)
		{
			pWind->DrawLine(r_GfxInfo.x1 - UI.ConnectionDimensions, r_GfxInfo.y1 + (i*dist), r_GfxInfo.x1 + ArcHeight - 1, r_GfxInfo.y1 + i*dist);
		}
	}
	if (ptr != NULL)
	Interface->Register(GraphicsInfo(r_GfxInfo.x1 - UI.ConnectionDimensions, r_GfxInfo.y1, r_GfxInfo.x1, r_GfxInfo.y2), &((Gate*)ptr)->GetOutputPin());
	int Taildistance = (r_GfxInfo.x2 - r_GfxInfo.x1) / 3;
	pWind->SetPen(BLACK, 3);
	pWind->SetBrush(SKYBLUE);
	pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y1);
	pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);
	pWind->DrawArc(r_GfxInfo.x1 - ArcHeight, r_GfxInfo.y1, r_GfxInfo.x1 + ArcHeight, r_GfxInfo.y2, 270, 90);
	pWind->DrawArc(r_GfxInfo.x1, r_GfxInfo.y1 - 2, r_GfxInfo.x2 + iHeight, r_GfxInfo.y2 + 2, 270, 90);
	pWind->DrawArc(r_GfxInfo.x1 - 2 * Taildistance, r_GfxInfo.y1, r_GfxInfo.x1, r_GfxInfo.y2, 270, 90);
	if (ptr != NULL)
	Interface->Register(GraphicsInfo(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2 + iHeight, r_GfxInfo.y2), ptr);


}

void Output::DrawXOR2(GraphicsInfo r_GfxInfo, GridItem*ptr, bool selected)
{
	DrawXOR(r_GfxInfo, ptr,selected);
}

void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, GridItem*ptr, bool selected)
{
	DrawXOR(r_GfxInfo, ptr, selected, true, false);
}

void Output::DrawXOR3(GraphicsInfo r_GfxInfo, GridItem*ptr, bool selected)
{
	DrawXOR(r_GfxInfo, ptr, selected, false, true);
}

void Output::DrawXNOR3(GraphicsInfo r_GfxInfo, GridItem*ptr, bool selected)
{
	DrawXOR(r_GfxInfo, ptr, selected, true, true);
}

void Output::DrawXOR2(Gate * ptr)
{
	DrawXOR2(ptr->GetPosition(), ptr, ptr->GetState());
}

void Output::DrawXNOR2(Gate * ptr)
{
	DrawXNOR2(ptr->GetPosition(), ptr, ptr->GetState());
}

void Output::DrawXOR3(Gate * ptr)
{
	DrawXOR3(ptr->GetPosition(), ptr, ptr->GetState());
}

void Output::DrawXNOR3(Gate * ptr)
{
	DrawXNOR3(ptr->GetPosition(), ptr, ptr->GetState());
}

/*
////////////////////////////////////////Buffer///////////////////////////
*/
void Output::DrawBuffer(GraphicsInfo r_GfxInfo, GridItem*ptr, bool selected, bool invert) const
{
	r_GfxInfo.x2 = r_GfxInfo.x1 + UI.BufferDimensions / 2;
	r_GfxInfo.x1 -= UI.BufferDimensions / 2;
	r_GfxInfo.y2 = r_GfxInfo.y1;
	r_GfxInfo.y1 -= UI.BufferDimensions / 2;
	int raduis = UI.InverterDimensions;
	pWind->SetPen(BLACK, 3);
	pWind->SetBrush(SKYBLUE);
	if (selected)
		pWind->DrawTriangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1, r_GfxInfo.y2 + UI.BufferDimensions / 2, r_GfxInfo.x2, r_GfxInfo.y2, FILLED);
	else pWind->DrawTriangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1, r_GfxInfo.y2 + UI.BufferDimensions / 2, r_GfxInfo.x2, r_GfxInfo.y2, FRAME);
	if (invert)
	{
		if (selected)
			pWind->DrawCircle(r_GfxInfo.x2 + raduis - 2, r_GfxInfo.y2, raduis, FILLED);
		else
			pWind->DrawCircle(r_GfxInfo.x2 + raduis - 2, r_GfxInfo.y2, raduis, FRAME);
		pWind->DrawLine(r_GfxInfo.x2 + raduis + 1, r_GfxInfo.y2, r_GfxInfo.x2 + raduis + UI.ConnectionDimensions + 1, r_GfxInfo.y2);
		if (ptr != NULL)
		{
			Interface->Register(GraphicsInfo(r_GfxInfo.x2, r_GfxInfo.y1, r_GfxInfo.x2 + raduis * 2, r_GfxInfo.y2 + UI.BufferDimensions / 2), ptr);
			Interface->Register(GraphicsInfo(r_GfxInfo.x2 + raduis * 2, r_GfxInfo.y1, r_GfxInfo.x2 + raduis * 2 + UI.ConnectionDimensions, r_GfxInfo.y2 + UI.BufferDimensions / 2), &((Gate*)ptr)->GetOutputPin());
		}
	}
	else
	{
		pWind->DrawLine(r_GfxInfo.x2 + -1, r_GfxInfo.y2, r_GfxInfo.x2 + UI.ConnectionDimensions - 1, r_GfxInfo.y2);
		if (ptr != NULL)
		Interface->Register(GraphicsInfo(r_GfxInfo.x2, r_GfxInfo.y1, r_GfxInfo.x2 + UI.ConnectionDimensions, r_GfxInfo.y1 + UI.BufferDimensions), &((Gate*)ptr)->GetOutputPin());
	}

	pWind->DrawLine(r_GfxInfo.x1 - UI.ConnectionDimensions, r_GfxInfo.y2, r_GfxInfo.x1, r_GfxInfo.y2);
	if (ptr != NULL)
	{
		Interface->Register(GraphicsInfo(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2 + UI.BufferDimensions / 2), ptr);
		Interface->Register(GraphicsInfo(r_GfxInfo.x1 - UI.ConnectionDimensions, r_GfxInfo.y1, r_GfxInfo.x1, r_GfxInfo.y2 + UI.BufferDimensions / 2), ((Gate*)ptr)->GetInputPins());
	}
}

void Output::DrawBuffer(GraphicsInfo r_GfxInfo, GridItem*ptr, bool selected)
{
	DrawBuffer(r_GfxInfo, ptr, selected, false);
}
void Output::DrawBuffer(Gate * ptr)
{
	DrawBuffer(ptr->GetPosition(), ptr, ptr->GetState());
}
void Output::DrawInverter(GraphicsInfo r_GfxInfo, GridItem*ptr, bool selected)
{
	DrawBuffer(r_GfxInfo, ptr, selected, true);
}
void Output::DrawInverter(Gate * ptr)
{
	DrawInverter(ptr->GetPosition(), ptr, ptr->GetState());
}
/*
////////////////////////////////////////Switch///////////////////////////
*/
void Output::DrawSwitch(GraphicsInfo r_GfxInfo, GridItem*ptr, bool ON, bool selected)
{
	r_GfxInfo.x2 = r_GfxInfo.x1 + UI.SwitchWidth / 2;
	r_GfxInfo.x1 -= UI.SwitchWidth / 2;
	r_GfxInfo.y2 = r_GfxInfo.y1 + UI.SwitchHeight / 2;
	r_GfxInfo.y1 -= UI.SwitchHeight / 2;
	pWind->SetPen(BLACK, 3);
	pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2, FRAME);
	pWind->DrawLine(r_GfxInfo.x1 + 10, r_GfxInfo.y1 + 1, r_GfxInfo.x1 + 10, r_GfxInfo.y2 - 2);
	pWind->SetBrush(GREY);
	pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + 3 + UI.SwitchWidth / 4, r_GfxInfo.y2);
	if (selected)
	{
		pWind->SetBrush(SKYBLUE);
		pWind->SetPen(SKYBLUE, 3);
		pWind->DrawRectangle(r_GfxInfo.x1 + 3 + UI.SwitchWidth / 4, r_GfxInfo.y1 + 3, r_GfxInfo.x2 - 3, r_GfxInfo.y2 - 3);
	}
	if (ON)
	{
		pWind->SetBrush(ROYALBLUE);
		pWind->SetPen(ROYALBLUE, 3);
		pWind->DrawRectangle(r_GfxInfo.x1 + 3, r_GfxInfo.y1 + 3, r_GfxInfo.x2 - 3, r_GfxInfo.y2 - 3, FILLED);
		pWind->SetPen(STEELBLUE, 3);
		pWind->SetBrush(STEELBLUE);
		pWind->DrawRectangle(r_GfxInfo.x2 - UI.SwitchWidth / 4, r_GfxInfo.y1 + 3, r_GfxInfo.x2 - 3, r_GfxInfo.y2 - 3, FILLED);
		pWind->SetPen(BLACK, 3);
		pWind->DrawLine(r_GfxInfo.x2 - UI.SwitchWidth / 4, r_GfxInfo.y1 + 1, r_GfxInfo.x2 - UI.SwitchWidth / 4, r_GfxInfo.y2 - 2);
	}
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(r_GfxInfo.x2, (r_GfxInfo.y2 + r_GfxInfo.y1) / 2, r_GfxInfo.x2 + UI.ConnectionDimensions, (r_GfxInfo.y2 + r_GfxInfo.y1) / 2);
	if (ptr != NULL)
	{
		Interface->Register(GraphicsInfo(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2), ptr);
		Interface->Register(GraphicsInfo(r_GfxInfo.x2, r_GfxInfo.y1, r_GfxInfo.x2 + UI.ConnectionDimensions, r_GfxInfo.y2), &((Gate*)ptr)->GetOutputPin());
	}
}
void Output::DrawSwitch(Gate * ptr)
{
	DrawSwitch(ptr->GetPosition(), ptr, ptr->GetState());
}
/*
////////////////////////////////////////Switch///////////////////////////
*/
void Output::DrawLED(GraphicsInfo r_GfxInfo, GridItem*ptr, bool selected, bool ON) const
{
	pWind->SetPen(BLACK, 3);
	int raduis = UI.LedDimensions * 4 / 7;
	r_GfxInfo.x2 = r_GfxInfo.x1 - 1.75*raduis + 3;
	r_GfxInfo.y2 = r_GfxInfo.y1 - 0.5*raduis;
	int dist = 10 * tan(22.5);
	if (ON)
	{
		pWind->SetBrush(LIGHTGOLDENRODYELLOW);
		pWind->DrawCircle(r_GfxInfo.x1 - dist + 2, r_GfxInfo.y1, raduis, FILLED);
	}
	else if (selected)
	{
		pWind->SetBrush(SKYBLUE);
		pWind->DrawCircle(r_GfxInfo.x1 - dist + 2, r_GfxInfo.y1, raduis, FILLED);
	}
	pWind->DrawCircle(r_GfxInfo.x1 - dist + 2, r_GfxInfo.y1, raduis, FRAME);
	pWind->DrawLine(r_GfxInfo.x2, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y1 + 0.5*raduis);
	pWind->DrawLine(r_GfxInfo.x2, r_GfxInfo.y2, r_GfxInfo.x2 + 0.75*raduis, r_GfxInfo.y2);
	pWind->DrawLine(r_GfxInfo.x2, r_GfxInfo.y1 + 0.5*raduis, r_GfxInfo.x2 + 0.75*raduis, r_GfxInfo.y1 + 0.5*raduis);
	pWind->DrawLine(r_GfxInfo.x2 - UI.ConnectionDimensions, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y1);
	if (selected && !ON)
	{
		pWind->SetBrush(SKYBLUE);
		pWind->SetPen(SKYBLUE, 3);
	}
	else
	{
		pWind->SetBrush(BLACK);
		pWind->SetPen(BLACK, 3);
	}
	pWind->DrawRectangle(r_GfxInfo.x2 + 2, r_GfxInfo.y2 + 2, r_GfxInfo.x2 + 0.75*raduis, r_GfxInfo.y1 + 0.5*raduis - 1);
	if (ptr != NULL)
	{
		Interface->Register(GraphicsInfo(r_GfxInfo.x2, r_GfxInfo.y1 - raduis, r_GfxInfo.x2 + UI.LedDimensions, r_GfxInfo.y1 + raduis), ptr);
		Interface->Register(GraphicsInfo(r_GfxInfo.x2 - UI.ConnectionDimensions, r_GfxInfo.y1 - raduis, r_GfxInfo.x2, r_GfxInfo.y1 + raduis), &((Gate*)ptr)->GetOutputPin());
	}
}

void Output::DrawLED(Gate * ptr)
{
	DrawLED(ptr->GetPosition(), ptr, ptr->GetState());
}

vector<pair<int,int> > Output::Connect(GraphicsInfo r_GfxInfo,  GridItem*ptr, bool selected)
{
	vector<pair<int, int> >Points = Interface->Connect(r_GfxInfo);
	DrawConnection(Points,ptr);
	return Points;
}

void Output::CreateTruthTable()
{
	int x, y;
	TruthTable=new window (UI.TruthTableWidth, UI.TruthTableHeight, UI.wx, UI.wy);
	TruthTable->SetPen(BLACK, 3);
	TruthTable->SetBrush(WHITE);
	TruthTable->ChangeTitle("TruthTable");
	for (int i = 0; i < 12; i++)
	{
		TruthTable->DrawLine(i*UI.TruthTableCellDimension, 0, i*UI.TruthTableCellDimension, UI.TruthTableHeight - 1);
		TruthTable->DrawLine(0, i*UI.TruthTableCellDimension, UI.TruthTableWidth - 1, i*UI.TruthTableCellDimension);
	}
	TruthTable->WaitMouseClick(x, y);
	TruthTable->~window();
}

//Destructor
Output::~Output()
{
	delete pWind;
	delete[] Toolbars;
}
