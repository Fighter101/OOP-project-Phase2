#include "Clipboard.h"



void Clipboard::push(vector<Component*>x)
{
	List = x;
}

vector<Component*> Clipboard::pull()
{
	return vector<Component*>(List);
}

Clipboard::Clipboard()
{
}


Clipboard::~Clipboard()
{
}
