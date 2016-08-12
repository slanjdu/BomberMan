#pragma once
#include"Object.h"
#include"GameManager.h"
class Monster : public Object
{
public:

	Monster(int _y, int _x, int _hp);
	~Monster();

	void		PrintImage();
	void		Move();
	void		Attack();
	void		Update();
};

