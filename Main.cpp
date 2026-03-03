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
	IPlayer.attk = 0; // mantenemos attk en 0; la probabilidad base es 1/3

	Item slots[5];
	// Inicializar slots
	for (size_t i = 0; i < 5; ++i)
	{
		slots[i].name = "";
		slots[i].attkbonus = 0.0f;
		slots[i].icon = ' ';
		slots[i].amount = 0;
	}

	// CARGA DE ITEMS DESDE fichero editable items.txt
	std::vector<Item> items;
	if (!LoadItemsFromFile("items.txt", items))
	{
		std::cout << "[WARNING] items.txt not found or empty. Chests will give only gold." << std::endl;
		system("pause");
	}

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

			// Pasamos la lista de items y el inventario (5 slots)
			PlayerInteraction(Dungeon, DungeonSave, "partida.dat", IPlayer, InputChar, items, slots);

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

	return 0;
}