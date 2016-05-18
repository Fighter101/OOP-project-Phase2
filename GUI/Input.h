#pragma once

//#include "..\CMUgraphicsLib\CMUgraphics.h"
//#include "UI_Info.h"
#include"..\Graph.h"

class Output;
class Input		//The application manager should have a pointer to this class
{
private:
	window *pWind;	//Pointer to the Graphics Window
	static Graph*Interface;
public:
	Input(window*);
	void GetPointClicked(int &, int &);	//Get coordinate where user clicks
	string GetSrting(Output*);		//Returns a string entered by the user
	static Graph*GetGraph();
	ActionType GetUserAction() const; //Reads the user click and maps it to an action

	~Input();
};
