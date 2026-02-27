#include "CONS.h"
#include "DungeonMapManager.h"
#include "DungeonSavingSys.h"
#include "PlayerInteractions.h"


int main()
{

	std::vector<std::vector<char >> Dungeon;

	std::vector<std::vector<char >> DungeonSave;

	Player IPlayer;
	IPlayer.Name = 'O';
	IPlayer.position.x = 0;
	IPlayer.position.y = 0;
	IPlayer.lifes = 3;
	IPlayer.attk = 100 / 3;

	char InputChar = 'O';

	int MenuInput = 0;

	ReadMap(Dungeon, "Sala.csv");

	PrintMainmenu(MenuInput);

	if (MenuInput == 2)	ReadSaveData("partida.dat", IPlayer);

	StartDungeonMap(Dungeon, IPlayer);


	system("cls");

	do
	{

		PrintDungeonMap(Dungeon);


		PlayerInteraction(Dungeon, DungeonSave, "partida.dat", IPlayer, InputChar);


		system("cls");
	} while (IPlayer.lifes > 0);
	if (IPlayer.lifes == 0) std::cout << "YOU DIED" << std::endl;
	system("pause");
	system("cls");



	/// WIN CONDITION



	return 0;
}