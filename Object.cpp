#include "Object.h"

void Object::SetType(ObjectType _type)
{
	type = _type;
}

void Object::SetHp(int _hp)
{
	hp = _hp;
}

void Object::SetPosition(int _y, int _x)
{
	y = _y;
	x = _x;
}

void Object::SetFrame(int _frame)
{
	frame = _frame;
}

void Object::SetDirection(int _direction)
{
	direction = _direction;
}

void Object::SetDead(bool _dead)
{
	dead = _dead;
}

void Object::SetBombNum(int _bombnum)
{
	BombNum = _bombnum;
}

void Object::FrameIncrease()
{
	SetFrame(GetFrame() + 1);
}

int Object::GetHp()
{
	return hp;
}

int Object::GetX()
{
	return x;
}

int Object::GetY()
{
	return y;
}

int Object::GetFrame()
{
	return frame;
}

int Object::GetDirection()
{
	return direction;
}

int Object::GetBombNum()
{
	return BombNum;
}

bool Object::GetDead()
{
	return dead;
}

ObjectType Object::GetType()
{
	return type;
}

void Object::PrintImage()
{
	cout << "　";
}

Object*	Object::GetDrop()
{
	return drop;
}

void Object::SetDrop(Object* _drop)
{
	drop = _drop;
}

void Object::Update()
{

}

Object::Object()
{
	SetFrame(0);
}


Object::~Object()
{
}
