#pragma once
#include"..\GUI\Graph.h"
#include"..\GUI\Essentials.h"
class Output;
class Input		//The application manager should have a pointer to this class
{
private:
	window *pWind;	//Pointer to the Graphics Window
	static Graph*Interface;
public:
	Input(window*);
	//-1,-1 out of design area
	//-2,-2 clicked on something
	GridItem* GetPointClicked(int &, int &,Comps Component= _GATE_);	//Get coordinate where user clicks
	string GetString(Output*);		//Returns a string entered by the user
	static Graph*GetGraph();
	pair< ActionType,vector<GridItem*> > GetUserAction() const; //Reads the user click and maps it to an action
	void GetPoint(int &x, int &y);
	~Input();
};
