#include "Item.h"

void Item::PrintImage()
{
	GetFrame() % 2 == 1 ? printf("☆") : printf("★");
}

Item::Item(int _y, int _x, int _hp)
{
	SetType(eItem);
	SetPosition(_y, _x);
	SetHp(_hp);
	SetDead(false);
}

Item::~Item()
{
}

void Item::Update()
{
	FrameIncrease();
	if (GameManager::getInstance().GetAt(GetY(), GetX())->GetType() == ObjectType::ePlayer ||
		GameManager::getInstance().GetAt(GetY(), GetX())->GetType() == ObjectType::eMonster ||
		GameManager::getInstance().GetAt(GetY(), GetX())->GetType() == ObjectType::eBoss)
	{
		SetDead(true);

		if (GameManager::getInstance().GetAt(GetY(), GetX())->GetType() == ObjectType::ePlayer)
		{
			GameManager::getInstance().GetAt(GetY(), GetX())->SetBombNum(GameManager::getInstance().GetAt(GetY(), GetX())->GetBombNum() + 1);
		}

		else if(GameManager::getInstance().GetAt(GetY(), GetX())->GetType() == ObjectType::eMonster)
		{
			GameManager::getInstance().GetAt(GetY(), GetX())->SetBombNum(1);
		}
	}
}
