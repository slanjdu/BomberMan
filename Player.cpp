#include "Player.h"

Player::Player(int _y, int _x, int _dir, int _hp,int _bombnum)
{
	SetType(ObjectType::ePlayer);
	SetPosition(_y, _x);
	SetDirection(_dir);
	SetHp(_hp);
	SetDead(false);
	SetBombNum(_bombnum);
}

Player::~Player()
{
}

void Player::PrintImage()
{
	switch (GetDirection())
	{
	case Direction::Up:
		if (GetFrame() % 2 == 1)
			printf("△");
		else
			printf("▲");
		break;

	case Direction::Down:
		if (GetFrame() % 2 == 1)
			printf("▽");
		else
			printf("▼");
		break;

	case Direction::Left:
		if (GetFrame() % 2 == 1)
			printf("◁");
		else
			printf("◀");
		break;

	case Direction::Right:
		if (GetFrame() % 2 == 1)
			printf("▷");
		else
			printf("▶");
		break;
	}
}

void Player::SetBomb(int _direction)
{
	int dy[] = { -1,1,0,0 }, dx[] = { 0, 0, -1, 1 };

	if (_direction == Direction::Up && GameManager::getInstance().GetAt(GetY() + dy[0], GetX() + dx[0]) == NULL&&
		GameManager::getInstance().GetAt(GetY(), GetX())->GetBombNum() > 0)
	{
		GameManager::getInstance().AddObject(new Bomb(GetY() + dy[0], GetX() + dx[0],this));
		GameManager::getInstance().GetAt(GetY(),GetX())->SetBombNum(GetBombNum() - 1);
	}

	else if (_direction == Direction::Down && GameManager::getInstance().GetAt(GetY() + dy[1], GetX() + dx[1]) == NULL&&
		GameManager::getInstance().GetAt(GetY(), GetX())->GetBombNum() > 0)
	{
		GameManager::getInstance().AddObject(new Bomb(GetY() + dy[1], GetX() + dx[1], this));
		GameManager::getInstance().GetAt(GetY(), GetX())->SetBombNum(GetBombNum() - 1);
	}

	else if (_direction == Direction::Left && GameManager::getInstance().GetAt(GetY() + dy[2], GetX() + dx[2]) == NULL&&
		GameManager::getInstance().GetAt(GetY(), GetX())->GetBombNum() > 0)
	{
		GameManager::getInstance().AddObject(new Bomb(GetY() + dy[2], GetX() + dx[2], this));
		GameManager::getInstance().GetAt(GetY(), GetX())->SetBombNum(GetBombNum() - 1);
	}

	else if (_direction == Direction::Right && GameManager::getInstance().GetAt(GetY() + dy[3], GetX() + dx[3]) == NULL
		&&GameManager::getInstance().GetAt(GetY(), GetX())->GetBombNum() > 0)
	{
		GameManager::getInstance().AddObject(new Bomb(GetY() + dy[3], GetX() + dx[3], this));
			GameManager::getInstance().GetAt(GetY(),GetX())->SetBombNum(GetBombNum() - 1);
	}
}

void Player::Update()
{
	int dy[] = { -1,1,0,0 }, dx[] = { 0, 0, -1, 1 };
	int getKey;
	getKey = _getch();
	switch (getKey)
	{
	case 'w':
		if ((GameManager::getInstance().GetAt(GetY() + dy[0], GetX() + dx[0]) == NULL) ||
			GameManager::getInstance().GetAt(GetY() + dy[0], GetX() + dx[0])->GetType() == ObjectType::eItem)
		{
			SetPosition(GetY() - 1, GetX());
		}

		SetDirection(Direction::Up);
		FrameIncrease();
		break;

	case 's':
		if ((GameManager::getInstance().GetAt(GetY() + dy[1], GetX() + dx[1]) == NULL) ||
			GameManager::getInstance().GetAt(GetY() + dy[1], GetX() + dx[1])->GetType() == ObjectType::eItem)
		{
			SetPosition(GetY() + 1, GetX());
		}

		SetDirection(Direction::Down);
		FrameIncrease();
		break;

	case 'a':
		if ((GameManager::getInstance().GetAt(GetY() + dy[2], GetX() + dx[2]) == NULL) ||
			GameManager::getInstance().GetAt(GetY() + dy[2], GetX() + dx[2])->GetType() == ObjectType::eItem)
		{
			SetPosition(GetY(), GetX() - 1);
		}

		SetDirection(Direction::Left);
		FrameIncrease();
		break;

	case 'd':
		if ((GameManager::getInstance().GetAt(GetY() + dy[3], GetX() + dx[3]) == NULL) ||
			GameManager::getInstance().GetAt(GetY() + dy[3], GetX() + dx[3])->GetType() == ObjectType::eItem)
		{
			SetPosition(GetY(), GetX() + 1);
		}

		SetDirection(Direction::Right);
		FrameIncrease();
		break;

	case '1':
		//폭탄설치
		SetBomb(GetDirection());
		FrameIncrease();
		break;
	case '2':
		FrameIncrease();
		break;
	default:	//다른 키를 누를경우 아무 동작도 하지 않도록 설정
		break;
	}
}
