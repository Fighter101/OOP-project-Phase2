#include"Defs.H"
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