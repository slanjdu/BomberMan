#include<iostream>
#include"GameManager.h"
#include"Player.h"
#include"Monster.h"
#include"Bomb.h"
#include"Wall.h"
#include"Initialization.h"

int main()
{
	Initialization	initialization;
	//              Player(int _y, int _x, int _dir, int _hp, int _bombnum)
	Player			player(1, 1, 3, 1, 1);
	//				Boss(int _y, int _x, int _hp, int _bombcnt);
	Boss			boss(11, 11, 3, 1);
	
	//Add - Initialize
	GameManager::getInstance().AddObject(&player);
	GameManager::getInstance().AddObject(&boss);
	initialization.Map_init();

	//Print
	GameManager::getInstance().Print();

	while (1)
	{
		//Update
		GameManager::getInstance().Update();
		
		//Print
		GameManager::getInstance().Print();

		//종료조건
		if (player.GetDead() == true)
		{
			cout << "GameOver!" << '\n';
			break;
		}
		else if (boss.GetDead() == true)
		{
			cout << "Win!" << '\n';
			break;
		}
	}
	
	return 0;
}
