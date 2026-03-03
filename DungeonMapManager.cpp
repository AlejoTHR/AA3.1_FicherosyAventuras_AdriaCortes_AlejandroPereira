#pragma once
#include "DungeonMapManager.h"

void ReadMap(std::vector<std::vector<char >>& Dungeon, std::string Fichero, bool& playerGetted)
{
	std::ifstream File;
	File.open(Fichero);
	if (!File.is_open()) // CHECKS IF FILE CAN BE OPENED
	{
		std::cout << "[ERROR] The File could not be Opened";
		exit(0);
	}

	// TEMPORAL STRING VARIABLE FOR EVERY LINE READ
	std::string Line; 

	while (getline(File, Line))
	{	
		// VECTOR OF CHARS FOR THE TMP LINE
		std::vector<char> tmpLine; 

		for (unsigned int i = 0; i < Line.size(); i++)
		{
			if (Line[i] == ';')	continue; // IF ";" IS READED; DOES NOT READ IR

			else if (Line[i] == '.') tmpLine.push_back(VOID); // IF ":" IS READED, KEEPS IT

			// IF LOAD GAME IN MENU, DOES NOT REGISTERS THE "P" IN THE CSV FILE
			else if (playerGetted == true && Line[i] == PLAYER) tmpLine.push_back(VOID); 

			else tmpLine.push_back(Line[i]); // NOTHING WEIRD IN THE LINE; SAVES THE WHOLE LINE

		}
		Dungeon.push_back(tmpLine); // SAVES ALL READ LINES IN THE DUNGEON VECTOR TO PRINT LATER
	}
	
	File.close();
}

void StartDungeonMap(std::vector<std::vector<char >>& Dungeon, Player& IPlayer, bool playerGetted)
{

	for (int i = 0; i < Dungeon.size(); i++)
	{
		for (int j = 0; j < Dungeon[i].size(); j++) // FOR THE "X" AND "Y" AXIS IN THE VECTOR...
		{
			if (Dungeon[i][j] == PLAYER && !playerGetted) // IF NOT LOADED; "P" IN MAP IS PLAYER POSITION
			{
				IPlayer.position.x = i;
				IPlayer.position.y = j;
				playerGetted = true;
			}
			else if (playerGetted) // IF LOADED; LAST SAVED POSITION IS PLAYER POSITION
			{
				Dungeon[IPlayer.position.x][IPlayer.position.y] = PLAYER;
			}
		}
		std::cout << std::endl;
	}
}

void ViewSlots(Item slots[5]) {
	std::cout << "_- INVENTORY -_" << std::endl;

	// Mostrar iconos (preferible) y fallback al nombre si no hay icono
	for (size_t i = 0; i < 5; i++)
	{
		if (!slots[i].name.empty())
		{
			if (slots[i].icon != ' ' && slots[i].icon != '\0')
			{
				std::cout << "[" << slots[i].icon << "]";
			}
			else
			{
				std::cout << "[" << slots[i].name << "]";
			}
		}
		else
		{
			std::cout << "[ ]";
		}
	}
	std::cout << std::endl;

	// Mostrar cantidades debajo
	for (size_t i = 0; i < 5; i++)
	{
		if (!slots[i].name.empty())
			std::cout << " " << slots[i].amount << " ";
		else
			std::cout << " 0 ";
	}
	std::cout << std::endl << std::endl;
}

void PrintDungeonMap(std::vector<std::vector<char >>& Dungeon)
{
	std::cout << "_- DUNGEON -_" << std::endl;
	for (int i = 0; i < Dungeon.size(); i++)
	{
		for (int j = 0; j < Dungeon[i].size(); j++)// FOR THE "X" AND "Y" AXIS IN THE VECTOR...
		{
			std::cout << Dungeon[i][j]; // PRINTS ALL CHARACTERS IN THE DUNGEON VECTOR
		}
		std::cout << std::endl;
	}

}