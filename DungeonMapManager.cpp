#pragma once
#include "DungeonMapManager.h"

void ReadMap(std::vector<std::vector<char >>& Dungeon, std::string Fichero)
{
	std::ifstream File;
	File.open(Fichero);
	if (!File.is_open())
	{
		std::cout << "Error al abrir";
		exit(0);
	}
	std::string Line;
	while (getline(File, Line))
	{
		std::vector<char> tmpLine;
		for (unsigned int i = 0; i < Line.size(); i++)
		{
			if (Line[i] == ';')	continue;

			else if (Line[i] == '.') tmpLine.push_back(' ');

			else tmpLine.push_back(Line[i]);

		}
		Dungeon.push_back(tmpLine);
	}
	File.close();
}

void StartDungeonMap(std::vector<std::vector<char >>& Dungeon, Player& IPlayer)
{
	bool playerGetted = false;
	for (int i = 0; i < Dungeon.size(); i++)
	{
		for (int j = 0; j < Dungeon[i].size(); j++)
		{
			if (Dungeon[i][j] == CHEST)
			{
				// CHESTS;
			}
			else if (Dungeon[i][j] == PLAYER && !playerGetted)
			{
				IPlayer.position.x = i;
				IPlayer.position.y = j;
				playerGetted = true;
			}
		}
		std::cout << std::endl;
	}
}

void PrintDungeonMap(std::vector<std::vector<char >>& Dungeon)
{
	for (int i = 0; i < Dungeon.size(); i++)
	{
		for (int j = 0; j < Dungeon[i].size(); j++)
		{
			std::cout << Dungeon[i][j];
		}
		std::cout << std::endl;
	}

}