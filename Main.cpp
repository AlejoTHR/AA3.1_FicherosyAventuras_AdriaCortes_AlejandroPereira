#include "CONS.h"
#include "DungeonMapManager.h"
#include "DungeonSavingSys.h"

void PlayerInteraction(std::vector<std::vector<char>>& Dungeon, std::vector<std::vector<char>>& DungeonSave, Player& IPlayer)
{
	char InputChar;
	Vector2 IPlayerLastPos = IPlayer.position;

	std::cin >> InputChar;
	switch (InputChar)
	{
		// MOVES
	case 'W':
		IPlayer.position.x--;
		break;
	case 'S':
		IPlayer.position.x++;
		break;
	case 'A':
		IPlayer.position.y--;
		break;
	case 'D':
		IPlayer.position.y++;
		break;
		// SAVE
	case 'E':
		SaveMap(Dungeon, DungeonSave, "SaveMap.csv");
		break;
		// QUIT
	case 'Q':

		break;
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
		SaveMap(Dungeon, DungeonSave, "SaveMap.csv");
		break;
		// QUIT
	case 'q':

		break;
	}
	// OBSTACLES
	switch (Dungeon[IPlayer.position.x][IPlayer.position.y])
	{
	case WALL:
		IPlayer.position = IPlayerLastPos;
		break;
	case CHEST:
		/////////////

		break;
	case ENEMY:

		
		//IPlayer.vidas--;
		break;
	}


	Dungeon[IPlayerLastPos.x][IPlayerLastPos.y] = ' ';
	Dungeon[IPlayer.position.x][IPlayer.position.y] = (IPlayer.vidas <= 0) ? 'X' : PLAYER;
}

int main()
{
	std::vector<std::vector<char >> Dungeon;
	std::vector<std::vector<char >> DungeonSave;

	Player IPlayer;
	IPlayer.position.x = 0;
	IPlayer.position.y = 0;
	IPlayer.vidas = 3;
	IPlayer.attk = 100/3;

	ReadMap(Dungeon, "TestDungeon.csv");
	StartDungeonMap(Dungeon, IPlayer);

	do
	{

		PrintDungeonMap(Dungeon);
		std::cout << "MOVE [A / W / S / D] | SAV[E]| [Q]UIT" << std::endl;
		PlayerInteraction(Dungeon, DungeonSave, IPlayer);

		system("cls");
	} while (IPlayer.vidas > 0);

	/// if () std::cout << "YOU WIN" << std::endl;
	if (IPlayer.vidas == 0) std::cout << "YOU DIED" << std::endl;
	


	return 0;
}