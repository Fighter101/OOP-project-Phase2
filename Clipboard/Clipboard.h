#pragma once
#include<vector>
#include"..\Components\Component.h"
class Clipboard
{
	vector<Component*> List;


	//Multiple Clipboards can be done


public:
	void push(vector<Component*>);
	vector<Component*> pull();
	Clipboard();
	~Clipboard();
};

