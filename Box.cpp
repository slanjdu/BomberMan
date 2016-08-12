#include "Box.h"

void Box::PrintImage()
{
	cout << "□";
}

void Box::Update()
{
}

Box::Box(int _y, int _x, int _hp)
{
	SetType(ObjectType::eBox);
	SetPosition(_y, _x);
	SetHp(_hp);
	SetDead(false);
}


Box::~Box()
{
}
