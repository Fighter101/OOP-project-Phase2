
#include"GUI\UI_Info.h"
ostream & operator<<(ostream & Out, GraphicsInfo r_GfxInfo)
{
		Out << r_GfxInfo.x1 << " " << r_GfxInfo.y1;
		return Out;
}
const STATUS operator&(const STATUS a, const STATUS b)
{
	return (a == HIGH && b == HIGH) ? HIGH : LOW;
}

const STATUS operator|(const STATUS a, const STATUS b)
{
	return (a == HIGH || b == HIGH) ? HIGH : LOW;
}

const STATUS operator^(const STATUS a, const STATUS b)
{
	return (a != b) ? HIGH : LOW;
}

const STATUS operator~(const STATUS a)
{
	return ((a == HIGH) ? LOW : HIGH);
}
bool IsInDesign(GraphicsInfo r_GfxInfo)
{
	return (r_GfxInfo.x1 <UI.width - UI.GateItemWidth&&r_GfxInfo.x1>UI.GateItemWidth&&r_GfxInfo.y1 > UI.ToolBarHeight&&r_GfxInfo.y1 <UI.height- UI.StatusBarHeight);
}

GraphicsInfo GraphicsInfo::operator+(GraphicsInfo y)
{
	return GraphicsInfo(this->x1 + y.x1, this->y1 + y.y1);
}

GraphicsInfo GraphicsInfo::operator-(GraphicsInfo y)
{
	return GraphicsInfo(this->x1 - y.x1, this->y1 - y.y1);
}
