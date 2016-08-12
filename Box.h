#pragma once
#include"Object.h"
#include<iostream>
using namespace std;

class Box :public Object
{
public:
	void PrintImage();
	void Update();

	Box(int _y, int _x, int _hp);
	~Box();
};

