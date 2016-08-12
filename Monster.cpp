#include "Monster.h"

void Monster::PrintImage()
{
	GetFrame() % 2 == 1 ? printf("○") : printf("●");
}

Monster::Monster(int _y, int _x, int _hp)
{
	SetType(eMonster);
	SetPosition(_y, _x);
	SetHp(_hp);
	SetDead(false);
}

Monster::~Monster()
{
}

void Monster::Move()
{
	int i;
	int r_bomb;
	int dy[] = { -1,1,0,0 }, dx[] = { 0, 0, -1, 1 };
	
	i = rand() % 4;
	r_bomb = rand() % 8;

	if (GameManager::getInstance().GetAt(GetY() + dy[i], GetX() + dx[i]) == NULL ||
		GameManager::getInstance().GetAt(GetY() + dy[i], GetX() + dx[i])->GetType() == ObjectType::eItem)
	{
		SetPosition(GetY() + dy[i], GetX() + dx[i]);
	}
	
	if (GetBombNum() == 1 && r_bomb == 1)
	{
		
		GameManager::getInstance().AddObject(new Bomb(GetY() + dy[0], GetX() + dx[0], this));
		GameManager::getInstance().GetAt(GetY(), GetX())->SetBombNum(GetBombNum() - 1);
	}
	FrameIncrease();
}

void Monster::Attack()
{
	int dy[] = { 1,-1,0,0 }, dx[] = { 0, 0, 1, -1 };

	for (int i = 0; i < 4; ++i)
	{
		if (GameManager::getInstance().GetAt(GetY() + dy[i], GetX() + dx[i]) != NULL &&
			GameManager::getInstance().GetAt(GetY() + dy[i], GetX() + dx[i])->GetType() == ObjectType::ePlayer)
		{
			GameManager::getInstance().GetAt(GetY() + dy[i], GetX() + dx[i])->SetHp(GetHp() - 1);
			
			if (GameManager::getInstance().GetAt(GetY() + dy[i], GetX() + dx[i])->GetHp() == 0)
			{
				GameManager::getInstance().GetAt(GetY() + dy[i], GetX() + dx[i])->SetDead(true);
			}
		}
	}
}

void Monster::Update()
{
	Move();
	Attack();
}
