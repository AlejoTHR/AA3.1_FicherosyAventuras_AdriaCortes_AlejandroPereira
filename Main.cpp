#include "CONS.h"
#include "DungeonMapManager.h"
#include "DungeonSavingSys.h"

void PlayerInteraction(std::vector<std::vector<char>>& Dungeon, std::vector<std::vector<char>>& DungeonSave, Player& IPlayer)
{
	char InputChar;
	Vector2 IPlayerLastPos = IPlayer.pos;

	std::cin >> InputChar;
	switch (InputChar)
	{
		// MOVES
	case 'W':
		IPlayer.pos.x--;
		break;
	case 'S':
		IPlayer.pos.x++;
		break;
	case 'A':
		IPlayer.pos.y--;
		break;
	case 'D':
		IPlayer.pos.y++;
		break;

	case 'w':
		IPlayer.pos.x--;
		break;
	case 's':
		IPlayer.pos.x++;
		break;
	case 'a':
		IPlayer.pos.y--;
		break;
	case 'd':
		IPlayer.pos.y++;
		break;


		// SAVE n QUIT
	case 'E':
		SaveMap(Dungeon, DungeonSave, "SaveMap.csv");
		break;

	case 'e':
		SaveMap(Dungeon, DungeonSave, "SaveMap.csv");
		break;
	}

	// OBSTACLES
	switch (Dungeon[IPlayer.pos.x][IPlayer.pos.y])
	{
	case WALL:
		IPlayer.pos = IPlayerLastPos;
		break;
	case CHEST:

		std::cout << std::endl << "YOU FOUND A CHEST AND GOT....." << std::endl;


		break;
	case ENEMY:

		
		//IPlayer.vidas--;
		break;
	}


	Dungeon[IPlayerLastPos.x][IPlayerLastPos.y] = ' ';
	Dungeon[IPlayer.pos.x][IPlayer.pos.y] = (IPlayer.lifes <= 0) ? 'X' : PLAYER;
}

int main()
{
	std::vector<std::vector<char >> Dungeon;
	std::vector<std::vector<char >> DungeonSave;

	Player IPlayer;
	IPlayer.pos.x = 0;
	IPlayer.pos.y = 0;
	IPlayer.lifes = 3;
	IPlayer.attk = 100/3;

	ReadMap(Dungeon, "TestDungeon.csv");
	StartDungeonMap(Dungeon, IPlayer);

	do
	{

		PrintDungeonMap(Dungeon);
		std::cout << "MOVE [A / W / S / D] | SAV[E]| [Q]UIT" << std::endl;
		PlayerInteraction(Dungeon, DungeonSave, IPlayer);

		system("cls");
	} while (IPlayer.lifes > 0);

	/// if () std::cout << "YOU WIN" << std::endl;
	if (IPlayer.lifes == 0) std::cout << "YOU DIED" << std::endl;
	


	return 0;
}