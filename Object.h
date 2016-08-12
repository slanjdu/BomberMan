#pragma once
#include<iostream>
using namespace std;

enum ObjectType
{
	ePlayer,
	eMonster,
	eBoss,
	eWall,
	eBox,
	eBomb,
	eItem
};

namespace Mapinfo
{
	const int Map_Height	= 19;
	const int Map_width		= 29;
}

class Object
{
private:
	ObjectType			type;
	Object*				drop;
	
	int					hp;
	int					x;
	int					y;
	int					frame;
	int					direction;
	int					BombNum;
	
	bool				dead;

public:

	void				SetType(ObjectType _type);
	void				SetHp(int _hp);
	void				SetPosition(int _y, int _x);
	void				SetFrame(int _frame);
	void				SetDirection(int _direction);
	void				SetDead(bool _dead);
	void				SetBombNum(int _bombnum);
	void				FrameIncrease();
	void				SetDrop(Object* drop);

	int					GetHp();
	int					GetX();
	int					GetY();
	int					GetFrame();
	int					GetDirection();
	int					GetBombNum();
	
	bool				GetDead();
	
	ObjectType			GetType();
	Object*				GetDrop();
	
	
	virtual void		PrintImage();
	virtual void		Update();
	
	Object();
	~Object();
};

