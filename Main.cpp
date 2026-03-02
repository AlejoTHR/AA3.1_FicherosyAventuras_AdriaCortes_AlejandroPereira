#include "CONS.h"
#include "DungeonMapManager.h"
#include "DungeonSavingSys.h"
#include "PlayerInteractions.h"
#include "ItemManager.h"


int main()
{
	// FINAL DUNGEON
	std::vector<std::vector<char >> Dungeon;
	// DUNGEON SAVE VARIABLE
	std::vector<std::vector<char >> DungeonSave;

	// PLAYER STRUCT
	Player IPlayer;
	IPlayer.Name = 'O';
	IPlayer.position.x = 0;
	IPlayer.position.y = 0;
	IPlayer.lifes = 3;
	IPlayer.attk = 1;

	Item slots[3];

	// SUPORTING VARIABLES
	char InputChar = 'O';

	bool playerGetted = false;

	int MenuInput = 0;


	PrintMainmenu(MenuInput); // MAIN MENU UI

	if (MenuInput < 3)
	{
		if (MenuInput == 2)
		{
			ReadSaveData("partida.dat", IPlayer, playerGetted); // PLAYER GETTED = TRUE AND SKIPS MAP READING FOR P IN NEXT FUNCTION
		}
		ReadMap(Dungeon, "Sala.csv", playerGetted);

		StartDungeonMap(Dungeon, IPlayer, playerGetted);


		system("cls");

		do
		{
			ViewSlots(slots);
			PrintDungeonMap(Dungeon);


			PlayerInteraction(Dungeon, DungeonSave, "partida.dat", IPlayer, InputChar);


			system("cls");
		} while (IPlayer.lifes > 0);

		if (IPlayer.lifes == 0) std::cout << "YOU DIED" << std::endl;

		system("pause");
		system("cls");


	}
	else if (MenuInput == 3)
	{
		std::cout << "\n\n\t\tYou exited the Dungeon Safely..." << std::endl << std::endl;
	}
	



	/// WIN CONDITION



	return 0;
}