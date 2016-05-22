#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

//#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include"Clipboard\Clipboard.h"
//Main class that manages everything in the application.
class ApplicationManager
{

private:
	vector<Component*> ComponentList;

	Output* OutputInterface; //pointer to the Output Class Interface
	Input* InputInterface; //pointer to the Input Class Interface


private:
	vector<Component*>MetaData;
	Action* ActionCreator(ActionType);
	Clipboard clip;
	///<summary>
	///(0 Add) - (1 And) - (2 Or) - (3 XOR) - (4 DSGN) - (5 Sim) - (6 Gates)
	///</summary>
	bool Toolbars[7];
public:	
	void CheckPoint(int &Cx, int &Cy);
	vector<Component*> getMetaData();
	vector<Component*> getClipboard();
	void setClipboard(vector<Component*>);
	void DeleteThis(vector<Component*>);

	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);

	//destructor
	~ApplicationManager();
};

#endif