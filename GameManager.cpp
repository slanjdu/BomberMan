#include "GameManager.h"

GameManager & GameManager::getInstance()
{
	static GameManager instance;
	return instance;
}

void GameManager::AddObject(Object* obj)
{
	objectList.push_back(obj);
}

void GameManager::Print()
{
	system("cls");
	for (int i = 0;i < Mapinfo::Map_Height;++i)
	{
		for (int j = 0;j < Mapinfo::Map_width;++j)
		{
			if (GameManager::getInstance().GetAt(i, j) != NULL)
				GameManager::getInstance().GetAt(i, j)->PrintImage();
			else
				printf("　");
		}
		printf("\n");
	}
}


Object* GameManager::GetAt(int _y, int _x)
{
	for (list<Object*>::iterator iter = GameManager::getInstance().objectList.begin();iter != GameManager::getInstance().objectList.end();++iter)
	{
		if ((_y == (*iter)->GetY()) &&
			(_x == (*iter)->GetX()))
		{
			return (*iter);
		}
	}
	return NULL;
}

Object* GameManager::Find(ObjectType _type)
{
	for (list<Object*>::iterator iter = GameManager::getInstance().objectList.begin(); iter != GameManager::getInstance().objectList.end(); ++iter)
	{
		if (_type == (*iter)->GetType())
		{
			return (*iter);
		}
	}
	return NULL;
}

void GameManager::ReMove(int _y, int _x)
{
	for (list<Object*>::iterator iter = GameManager::getInstance().objectList.begin(); iter != GameManager::getInstance().objectList.end();++iter)
	{
		if ((*iter)->GetDead() == true)
		{
			GameManager::getInstance().objectList.remove(*iter);
			return;
		}
	}
}

void GameManager::Update()
{
	for (list<Object*>::iterator iter = GameManager::getInstance().objectList.begin(); iter != GameManager::getInstance().objectList.end(); ++iter)
	{
		(*iter)->Update();
	}

	for (int i = 0;i<Mapinfo::Map_Height;++i)
	{
		for (int j =0; j<Mapinfo::Map_width;++j)
		{
			GameManager::ReMove(i, j);
		}
	}
}

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}
