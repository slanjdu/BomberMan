#include "Bomb.h"

void Bomb::PrintImage()
{
	GetFrame() % 2 == 1 ? printf("◇") : printf("◆");
}

void Bomb::Attack()
{
	int dy[] = { 1,-1,0,0 }, dx[] = { 0, 0, 1, -1 };

	for (int i = 0; i < 4; ++i)
	{
		if (GameManager::getInstance().GetAt(GetY() + dy[i], GetX() + dx[i]) != NULL &&
			GameManager::getInstance().GetAt(GetY() + dy[i], GetX() + dx[i])->GetType() != ObjectType::eWall)
		{
			if (GameManager::getInstance().GetAt(GetY() + dy[i], GetX() + dx[i])->GetHp() == 1)
			{
				GameManager::getInstance().GetAt(GetY() + dy[i], GetX() + dx[i])->SetDead(true);
			}
			else
			{
				GameManager::getInstance().GetAt(GetY() + dy[i], GetX() + dx[i])->SetHp(GetHp() - 1);
			}
		}
	}
}

void Bomb::Update()
{
	FrameIncrease();
	if (bombframe + count == GetFrame())
	{
		Attack();
		GameManager::getInstance().GetAt(GetY(), GetX())->SetBombNum(GetBombNum() + 1);
		GetDrop()->SetBombNum(GetDrop()->GetBombNum() + 1);
		SetDead(true);
	}
}


Bomb::Bomb(int _y,int _x, Object* _drop)
{
	SetType(eBomb);
	SetPosition(_y, _x);
	SetDead(false);
	SetFrame(GetFrame());
	SetDrop(_drop);
	bombframe = GetFrame();
}


Bomb::~Bomb()
{
}
