#pragma once
#include"Object.h"
#include"GameManager.h"
class Bomb :public Object
{

private:
	const int count = 6;
	int bombframe;
public:
	
	Bomb(int _y, int _x, Object* drop);
	~Bomb();

	void Attack();
	void Update();
	void PrintImage();
};

