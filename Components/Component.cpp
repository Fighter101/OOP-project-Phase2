#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;	
	m_Label = "No_Label";
}

void Component::SetPosition(GraphicsInfo r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;
}

Component::Component()
{
	m_Label = "No_Label";
}

string Component::GetLabel()
{
	return m_Label;
}

void Component::SetLabel(string r_label)
{
	m_Label = r_label;
}

Component::~Component()
{}