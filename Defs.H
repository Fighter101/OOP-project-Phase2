#ifndef CONST_H
#define CONST_H
//This header file contains some defenitions to be used all over the application
#include"GUI\Essentials.h"
//All possible actions
enum ActionType 
{
	ADD,
	ADD_Buff,			//Add 1-input Buffer gate
	ADD_INV,			//Add 1-input Inverter gate
	ADD_AND,
	ADD_OR,
	ADD_XOR,
	ADD_AND_GATE_2,		//Add 2-input AND gate
	ADD_OR_GATE_2,		//Add 2-input OR gate
	ADD_OR_GATE_3,
	ADD_NAND_GATE_2,	//Add 2-input NAND gate
	ADD_NAND_GATE_3,
	ADD_NOR_GATE_2,		//Add 2-input NOR gate
	ADD_XOR_GATE_2,		//Add 2-input XOR gate
	ADD_XNOR_GATE_2,	//Add 2-input XNOR gate
	ADD_XNOR_GATE_3,
	ADD_AND_GATE_3,		//Add 3-input AND gate
	ADD_NOR_GATE_3,		//Add 3-input NOR gate
	ADD_XOR_GATE_3,		//Add 3-input XOR gate
	ADD_Switch,			//Add Switch
	ADD_LED,			//Add LED
	ADD_CONNECTION,		//Add Wire Connection

	ADD_Label,			//Add Label to a Component, a Connection
	EDIT_Label,			//Edit Label of a Component, a Connection

	Create_TruthTable,	//Create Truth Table of the Circuit

	Change_Switch,		//Change Switch Status in Simulation Mode

	SELECT,		//Select a Component, a Connection
	DEL,		//Delete a Component, a Connection
	MOVE,		//Move a Component, a Connection
	COPY,
	CUT,
	PASTE,
	VALIDATE,
	SAVE,		//Save the whole Circuit to a file
	LOAD,		//Load a Circuit from a file
	PROBE,
	UNDO,		//Undo the last Action preformed
	REDO,		//Redo the last Action canceled

	DSN_MODE,	//Switch to Design mode
	SIM_MODE,	//Switch to Simulatiom mode

	EXIT,		//Exit the application
	CONNECT_TWO_PINS,
	STATUS_BAR,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar
	DSN_AREA,
	ADD_Right_ToolBar,
	MultiSELECT
};

//Possible Status for the pin
#ifndef _STATUS_H
#define _STATUS_H
enum STATUS
{
	LOW,
	HIGH
};

#endif // !_STATUS_H


enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION
};


enum DsgnMenuItem //The items of the design menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_AND2,		//AND gate item in menu
	ITM_OR2,		//OR gate item in menu
	
	ITM_EXIT,		//Exit item
	//TODO: Add more items names here
	
	ITM_DSN_CNT		//no. of design menu items ==> This should be the last line in this enum
	
};


enum SimMenuItem //The items of the simulation menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	ITM_SIM,	//Simulate menu item
	ITM_TRUTH,	//Truth table menu item
	
	//TODO:Add more items names here
	
	ITM_SIM_CNT		//no. of simulation menu items ==> This should be the last line in this enum
	
};

//Maximum number of input pins that can be connected to any output pin
#define MAX_CONNS 20

//assume fan out is 5 for now it can be read from the user or can be predefined as const
enum FANOUT
{
	AND2_FANOUT = 5	//Default fan out of 2-input AND gate
};

//A structure to contain drawing parameters for each component
//Each component occupies a rectangluar area so it needs 2 points to represent that area
//this structure can be extended if desired
struct GraphicsInfo
{
	int x1,y1, x2, y2;
	GraphicsInfo(){}
	GraphicsInfo(int x, int y)
	{
		x1 = x;
		y1 = y;
		x2 = x;
		y2 = y;
	}
	GraphicsInfo(int x1, int y1,int x2,int y2)
	{
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
	}
};
enum PressType {
	Normal,
	Hovered,
	Pressed
};
enum Orientation {
	Horizontal,
	Vertical
};
enum TOOLBARS
{
	DSGN,
	GATE,
	SIMU,
	GATERightClick,
	SWITCHRightClick,
	LEDRightClick,
	ADDBAR,
	ADDANDBAR,
	ADDORBAR,
	ADDXORBAR,
	TOOLBARCNT
};
const STATUS operator&(const STATUS a, const STATUS b);
const STATUS operator|(const STATUS a, const STATUS b);
const STATUS operator^(const STATUS a, const STATUS b);
const STATUS operator~(const STATUS a);
ostream &operator <<(ostream & Out, GraphicsInfo r_GfxInfo);
bool IsInDesign(GraphicsInfo r_GfxInfo);
enum Comps
{
	_GATE_,
	_BUFFER_,
	_SWITCH_,
};

#ifndef NULL
#define NULL 0
#endif

#endif