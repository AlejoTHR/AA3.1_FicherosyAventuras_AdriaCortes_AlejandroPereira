#pragma once
#include "PlayerInteractions.h"
#include "DungeonSavingSys.h"



void PrintMainmenu(int& MenuInput)
{

	std::cout << "\t--||:: FILES & ADVENTURES ::||--\n" << "\t\t ::Main Menu::\n\n";

	std::cout << "\n1) New Game\n2) Continue Game\n3) Exit\n\n";
	std::cin >> MenuInput;

}

void PlayerInput(char& InputChar)
{
	std::cout << "MOVE [A / W / S / D] | SAV[E]| [Q]UIT" << std::endl;
	std::cin >> InputChar;
	// TRANSFORMS CHAR INTO LOWER CASE AUTOMATICALLY
	InputChar = (char)tolower(InputChar);

}


void ChestFound(Player& IPlayer)
{
	// IPlayer.attk += Item attkbonus;

}

void StartCombat(Player& IPlayer)
{
	srand(time(0));
	system("cls");

	float fightNumber = rand() % 3;

	std::cout << "_- You got into a fight! -_" << std::endl;

	if (fightNumber > IPlayer.attk)
	{
		IPlayer.lifes--;
		std::cout << "You lost the fight and lost a life..." << std::endl;
	}
	else
	{
		std::cout << "You won the fight!" << std::endl;
	}
	system("pause");

}

void PlayerInteraction(std::vector<std::vector<char>>& Dungeon, std::vector<std::vector<char>>& DungeonSave, std::string Fichero, Player& IPlayer, char& InputChar)
{
	// SEE PLAYER INPUT
	PlayerInput(InputChar);

	// LAST PLAYER'S POSITION
	Vector2 IPlayerLastPos = IPlayer.position;

	// INPUT CASES
	switch (InputChar)
	{
		// MOVES
	case 'w':
		IPlayer.position.x--;
		break;
	case 's':
		IPlayer.position.x++;
		break;
	case 'a':
		IPlayer.position.y--;
		break;
	case 'd':
		IPlayer.position.y++;
		break;

		// SAVE
	case 'e':
		SaveGameData(Fichero, IPlayer);
		break;

		// QUIT
	case 'q':

		break;
	}


	// OBSTACLES
	switch (Dungeon[IPlayer.position.x][IPlayer.position.y])
	{
	case WALL:
		IPlayer.position = IPlayerLastPos; // Player Steps Back
		break;

	case CHEST:
		ChestFound(IPlayer);

		break;
	case ENEMY:

		StartCombat(IPlayer);
		
		//IPlayer.lifes--;
		break;
	}

	// LAST POSTION TURNS BACK INTO "."
	Dungeon[IPlayerLastPos.x][IPlayerLastPos.y] = VOID;

	// NEXT STEP IS A "P" OR AN "X" IF DEATH
	Dungeon[IPlayer.position.x][IPlayer.position.y] = (IPlayer.lifes <= 0) ? 'X' : PLAYER;


}

