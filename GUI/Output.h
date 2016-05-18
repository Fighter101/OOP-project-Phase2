#pragma once
//#include "..\Defs.h"
#include "Input.h"
class Gate;
class ToolBar;
class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
	Graph *Interface;
	
	//ICons For Buttons
	GraphicsInfo DetermineState(GraphicsInfo,PressType State);
	GraphicsInfo MoveIcon(GraphicsInfo r_GfxInfo, PressType State);
	GraphicsInfo CopyIcon(GraphicsInfo r_GfxInfo, PressType State);
	GraphicsInfo PasteIcon(GraphicsInfo r_GfxInfo, PressType State);
	GraphicsInfo LabelIcon(GraphicsInfo r_GfxInfo, PressType State);
	GraphicsInfo EditIcon(GraphicsInfo r_GfxInfo, PressType State);
	GraphicsInfo DeleteIcon(GraphicsInfo r_GfxInfo, PressType State);
	GraphicsInfo AddIcon(GraphicsInfo r_GfxInfo, PressType State);
	GraphicsInfo ConnectIcon(GraphicsInfo r_GfxInfo, PressType State);
	GraphicsInfo UndoIcon(GraphicsInfo r_GfxInfo, PressType State);
	GraphicsInfo RedoIcon(GraphicsInfo r_GfxInfo, PressType State);
	GraphicsInfo SaveIcon(GraphicsInfo r_GfxInfo, PressType State);
	GraphicsInfo SelectIcon(GraphicsInfo r_GfxInfo, PressType State);
	GraphicsInfo ExitIcon(GraphicsInfo r_GfxInfo, PressType State);
	GraphicsInfo TruthTabelIcon(GraphicsInfo r_GfxInfo, PressType State);
	GraphicsInfo ValidationIcon(GraphicsInfo r_GfxInfo, PressType State);
	GraphicsInfo SimulateIcon(GraphicsInfo r_GfxInfo, PressType State);
	GraphicsInfo ProbeIcon(GraphicsInfo r_GfxInfo, PressType State);
	GraphicsInfo BeginSimulationIcon(GraphicsInfo r_GfxInfo, PressType State);
	GraphicsInfo ReturnDesign(GraphicsInfo r_GfxInfo, PressType State);	
	GraphicsInfo LoadICon(GraphicsInfo r_GfxInfo, PressType State);
	//Icons For Right CLick Bar
	GraphicsInfo MoveString(GraphicsInfo r_GfxInfo, PressType State);
	GraphicsInfo CutString(GraphicsInfo r_GfxInfo, PressType State);
	GraphicsInfo PasteString(GraphicsInfo r_GfxInfo, PressType State);
	GraphicsInfo CopyString(GraphicsInfo r_GfxInfo, PressType State);
	GraphicsInfo DeleteString(GraphicsInfo r_GfxInfo, PressType State);
	//AddToolbarICons //Gates
	GraphicsInfo AndIcon(GraphicsInfo r_GfxInfo,PressType State=Pressed);
	GraphicsInfo ORIcon(GraphicsInfo r_GfxInfo, PressType State=Pressed);
	GraphicsInfo XORIcon(GraphicsInfo r_GfxInfo, PressType State = Pressed);
	GraphicsInfo LEDIcon(GraphicsInfo r_GfxInfo, PressType State = Pressed);
	GraphicsInfo SwitchIcon(GraphicsInfo r_GfxInfo, PressType State = Pressed);
	GraphicsInfo BufferIcon(GraphicsInfo r_GfxInfo, PressType State = Pressed);
	GraphicsInfo InverterIcon(GraphicsInfo r_GfxInfo, PressType State = Pressed);

	//Icon Array
	GraphicsInfo (Output::*ButtonFunctions[32])(GraphicsInfo,  PressType State) = { &Output::MoveIcon,&Output::CopyIcon,&Output::PasteIcon,&Output::LabelIcon,&Output::EditIcon,&Output::DeleteIcon,&Output::AddIcon,&Output::ConnectIcon,&Output::SelectIcon,&Output::UndoIcon,&Output::RedoIcon,&Output::SaveIcon,&Output::LoadICon,&Output::BeginSimulationIcon,&Output::ExitIcon,&Output::TruthTabelIcon,&Output::ValidationIcon,&Output::SimulateIcon,&Output::ProbeIcon,&Output::ReturnDesign,&Output::MoveString,&Output::CutString,&Output::CopyString,&Output::PasteString,&Output::DeleteString,&Output::AndIcon,&Output::ORIcon,&Output::XORIcon,&Output::BufferIcon,&Output::InverterIcon,&Output::LEDIcon,&Output::SwitchIcon };
	ActionType ButtonActions[32] = { MOVE,COPY,PASTE,ADD_Label,EDIT_Label,DEL,ActionType::ADD,ADD_CONNECTION,SELECT,UNDO,REDO,SAVE,SIM_MODE,EXIT,Create_TruthTable,VALIDATE,Change_Switch,PROBE,MOVE,CUT,COPY,PASTE,DEL,ADD_AND,ADD_OR,ADD_XOR,ADD_Buff,ADD_INV,ADD_LED,ADD_Switch };
	ToolBar *Toolbars;
	void CreateToolBars();
	//Gates
	//And Gate
	void DrawAND(GraphicsInfo r_GfxInfo, GridItem*ptr, bool selected = false, bool invert = false, bool connections = false) const;

	void DrawAND2(GraphicsInfo r_GfxInfo, GridItem * ptr, bool selected);

	void DrawNAND2(GraphicsInfo r_GfxInfo, GridItem * ptr, bool selected);

	void DrawAND3(GraphicsInfo r_GfxInfo, GridItem * ptr, bool selected);

	void DrawNAND3(GraphicsInfo r_GfxInfo, GridItem * ptr, bool selected);
	/////////////////////////////////
	//OR Gate
	void DrawOr(GraphicsInfo r_GfxInfo, GridItem * ptr, bool selected, bool invert = false, bool connections = false) const;

	void DrawOR2(GraphicsInfo r_GfxInfo, GridItem * ptr, bool selected);

	void DrawOR3(GraphicsInfo r_GfxInfo, GridItem * ptr, bool selected);

	void DrawNOR2(GraphicsInfo r_GfxInfo, GridItem * ptr, bool selected);

	void DrawNOR3(GraphicsInfo r_GfxInfo, GridItem * ptr, bool selected);
	//////////////////////////////
	//Xor Gate
	void DrawXOR(GraphicsInfo r_GfxInfo, GridItem * ptr, bool selected, bool invert = false, bool connections = false) const;
	void DrawXOR2(GraphicsInfo r_GfxInfo, GridItem * ptr, bool selected);
	void DrawXNOR2(GraphicsInfo r_GfxInfo, GridItem * ptr, bool selected);
	void DrawXOR3(GraphicsInfo r_GfxInfo, GridItem * ptr, bool selected);
	void DrawXNOR3(GraphicsInfo r_GfxInfo, GridItem * ptr, bool selected);
	////////////////////////////////////////////////
	//Switch
	void DrawSwitch(GraphicsInfo r_GfxInfo, GridItem * ptr, bool selected, bool ON = false);
	////////////////////////////
	//Inverter&buffer
	void DrawBuffer(GraphicsInfo r_GfxInfo, GridItem * ptr, bool selected = false, bool invert = false) const;
	void DrawBuffer(GraphicsInfo r_GfxInfo, GridItem * ptr, bool selected);
	void DrawInverter(GraphicsInfo r_GfxInfo, GridItem*ptr, bool selected);
	//////////////////////////////
	//LED
	void DrawLED(GraphicsInfo r_GfxInfo, GridItem * ptr, bool selected, bool ON = false) const;
public:
	Output(); // Performs the Window Initialization
	Input* CreateInput() const; //creates a pointer to the Input object
	void ChangeTitle(string Title) const;
	void CreateDesignToolBar();	//Tool bar of the design mode
	void CreateSimulationToolBar() const;//Tool bar of the simulation mode
	void CreateStatusBar() const;	//Create Status bar
	void ClearStatusBar() const;		//Clears the status bar
	void ClearDrawingArea() const;	//Clears the drawing area
	window* CreateWind(int wd, int h, int x, int y) const; //Creates user interface window
	void PrintMsg(string msg) const;	//Print a message on Status bar
	//Button Drawing Function
	GraphicsInfo DrawButon(int index, GraphicsInfo r_GfxInfo, PressType State);
	ActionType GetReturnedAction(int index);
	void RegisterButton( GridItem*ptr);
	void EraseButton(GraphicsInfo r_GfxInfo);
	//Gate Drawing Functions
	//AndGate
	void CreateAddToolBar();
	void DrawAND2(Gate * ptr);
	void DrawNAND2(Gate * ptr);
	void DrawAND3(Gate * ptr);
	void DrawNAND3(Gate * ptr);
	void DrawOR2( Gate * ptr);
	void DrawOR3( Gate * ptr);
	void DrawNOR2( Gate * ptr);
	void DrawNOR3( Gate * ptr);
	void DrawXOR2( Gate * ptr);
	void DrawXNOR2( Gate * ptr);
	void DrawXOR3( Gate * ptr);
	void DrawXNOR3( Gate * ptr);
	void DrawInverter( Gate * ptr);
	void DrawBuffer( Gate * ptr);
	void DrawSwitch(Gate * ptr);
	void DrawLED(Gate * ptr);
	//Connection
	void DrawConnection(GraphicsInfo r_GfxInfo, bool selected = false) const;

	
	~Output();
};


