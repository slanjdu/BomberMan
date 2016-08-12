#include "Wall.h"

void Wall::PrintImage()
{
	cout << "■";
}

void Wall::Update()
{
}

Wall::Wall(int _y, int _x)
{
	SetPosition(_y, _x);
	SetType(ObjectType::eWall);
}

Wall::~Wall()
{
}
