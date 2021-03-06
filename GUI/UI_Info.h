#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	MODE AppMode;		//Application Mode (design or simulation)
				
	static const int	width = 1000, height = 750,	//Window width and height
						wx = 15, wy = 15,			//Window starting coordinates
						StatusBarHeight = 50,	//Status Bar Height
						StatusBarWidth = 800,
						SatusBarStart = 100,
						ToolBarHeight = 80,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
						ToolItemWidth = 60,//Width of each item in toolbar menu
						Margain = 10,
						GateBarHeight = 60,
						PixelDenisty = 5,
						GridWidth = width / PixelDenisty + 1,
						GridHeight = height / PixelDenisty + 1,
						GateItemWidth = 100,
						TruthTableCellDimension = 60,
						TruthTableHeight = 660,
						TruthTableWidth = 720;

	color DrawColor;		//Drawing color
	color SelectColor;		//Highlighting color
	color ConnColor;		//Connector color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Back ground color


	//This should be calculated accurately because it will be used later to create connections between gates
	//For now, we will assume that rect width = 50 and height = 50
	static const int	AND2_Width = 50,		//AND2 Gate Image default width
						AND2_Height = 50,		//AND2 Gate Image default height
						AllGateDimensions = 40, //Dimensions of any gate
						InverterDimensions = 6,   //Dimensions for the inverter circle
						ConnectionDimensions = 10,
						BufferDimensions = 30,
						SwitchHeight = 20,
						SwitchWidth = 40,
						LedDimensions = 35;
	static const int	RightClickItemHeight = 30,
						RightClickItemWidth = 80;	
}UI;	//create a single global object UI

#endif