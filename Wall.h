#pragma once
#include"Object.h"
#include<iostream>
using namespace std;

class Wall :public Object
{
public:
	void Update();
	void PrintImage();
	
	Wall(int _y,int _x);
	~Wall();
};

