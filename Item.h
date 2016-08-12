#pragma once
#include"Object.h"
#include"GameManager.h"
#include"Player.h"
#include"Boss.h"
#include"Monster.h"

class Item : public Object
{
public:
	Item(int _y, int _x,int _hp);
	~Item();

	void Update();
	void PrintImage();
};

