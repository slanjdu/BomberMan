#include "Initialization.h"

void Initialization::Map_init()
{
	Wall_init();
	Box_init();
	Monster_init();
	Item_init();
}

void Initialization::Wall_init()
{
	for (int i = 0; i < Mapinfo::Map_Height; ++i)
	{
		for (int j = 0; j < Mapinfo::Map_width; ++j)
		{
			if ((i == 0 || i == Mapinfo::Map_Height - 1) ||
				(j == 0 || j == Mapinfo::Map_width - 1)  ||
				(i % 2 == 0 && j % 2 == 0))
			{
				GameManager::getInstance().AddObject(new Wall(i, j));
			}
		}
	}
}

void Initialization::Box_init()
{
	srand((unsigned int)time(NULL));

	for (int cnt = 0; cnt < Box_num; cnt++)
	{
		int y;
		int x;

		y = rand() % (Mapinfo::Map_Height - 2);
		x = rand() % (Mapinfo::Map_width - 2);

		if (GameManager::getInstance().GetAt(y, x) == NULL)
		{
			GameManager::getInstance().AddObject(new Box(y, x, 1));
		}

		else
		{
			cnt--;
		}
	}
}

void Initialization::Monster_init()
{
	srand((unsigned int)time(NULL));

	for (int cnt = 0; cnt < Monster_num; cnt++)
	{
		int y;
		int x;

		y = rand() % (Mapinfo::Map_Height - 2);
		x = rand() % (Mapinfo::Map_width - 2);

		if (GameManager::getInstance().GetAt(y, x) == NULL)
		{
			GameManager::getInstance().AddObject(new Monster(y, x, 1));
		}

		else
		{
			cnt--;
		}
	}
}

void Initialization::Item_init()
{
	srand((unsigned int)time(NULL));

	for (int cnt = 0; cnt < Item_num; cnt++)
	{
		int y;
		int x;

		y = rand() % (Mapinfo::Map_Height - 2);
		x = rand() % (Mapinfo::Map_width - 2);

		if (GameManager::getInstance().GetAt(y, x) == NULL)
		{
			GameManager::getInstance().AddObject(new Item(y, x, 1));
		}

		else
		{
			cnt--;
		}
	}
}

Initialization::Initialization()
{
}

Initialization::~Initialization()
{
}
