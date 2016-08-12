#pragma once
#include"Object.h"
#include"GameManager.h"
#include"Bomb.h"
#include<string>
#include<conio.h>
using namespace std;

class Player : public Object
{
public:
	Player(int _y, int _x, int _dir, int _hp, int _bombnum);
	~Player();
	
	void		SetBomb(int _direction);

	void		PrintImage();
	void		Update();
};

enum Direction
{
	Up,
	Down,
	Left,
	Right
};
