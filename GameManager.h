#pragma once
#include"Object.h"
#include"Player.h"
#include<list>

class GameManager
{
public:
	
	list<Object*>		objectList;
	
	static GameManager&	getInstance();

	void				AddObject(Object* obj);
	void				ReMove(int _y, int _x);
	void				Print();
	
	Object*				GetAt(int _y, int _x);
	Object*				Find(ObjectType _type);
	void				Update();

	GameManager();
	~GameManager();
};

