#pragma once
#include"Object.h"
#include"GameManager.h"

class Boss:public Object
{
public:

	Boss(int _y, int _x, int _hp, int _bombcnt);
	~Boss();

	void		Move();
	void		Attack();
	void		PrintImage();
	void		Update();
	
	
};

