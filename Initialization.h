#pragma once
#include"Object.h"
#include"GameManager.h"
#include"Wall.h"
#include"Box.h"
#include"Monster.h"
#include"Boss.h"
#include"Item.h"
#include<time.h>
class Initialization :public Object
{
public:
	const int		Box_num = 20;
	const int		Monster_num = 10;
	const int		Item_num = 5;

	void			Map_init();
	void			Wall_init();
	void			Box_init();
	void			Monster_init();
	void			Item_init();

	Initialization();
	~Initialization();
};

