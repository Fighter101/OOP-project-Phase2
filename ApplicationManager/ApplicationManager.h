#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

//#include "Defs.h"
#include "..\GUI\Output.h"
#include "..\GUI\Input.h"
#include "..\Actions\Action.h"
#include "..\Components\Component.h"
#include"..\Clipboard\Clipboard.h"
//Main class that manages everything in the application.
class ApplicationManager
{

private:
	vector<Component*> ComponentList;

	Output* OutputInterface; //pointer to the Output Class Interface
	Input* InputInterface; //pointer to the Input Class Interface


private:
	Action* ActionCreator(ActionType);
	Clipboard clip;
	///<summary>
	///(0 Add) - (1 And) - (2 Or) - (3 XOR) - (4 DSGN) - (5 Sim) - (6 Gates)
	///</summary>
	bool Toolbars[7];
	bool valid; //0 invalid - 1 Valid
	bool sim;//0 if DSN - 1 if Sim
	Component* ptrTemp;
	void nullify(vector<Component*> x);
	void nullify(Component*x);
public:	
///////////////////////////////////////////
	int getCompNo();
	GridItem* CheckPoint(int &Cx, int &Cy);
	bool getValid();
	void setValid(bool x);
///////////////////////////////////////////
///<summary>
///(0 Add) - (1 And) - (2 Or) - (3 XOR) - (4 DSGN) - (5 Sim) - (6 Gates)
///</summary>
	void DrawToolBar(TOOLBARS x);
	vector<Component*> getClipboard();
	vector<Component*> getComponents();
	void setClipboard(vector<Component*>);
	void DeleteThis(vector<Component*>);
	void EraseThisBitch(Component*);
	vector<Component*> getSelected();
	Component* getTemp();

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