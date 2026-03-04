#pragma once
#include "PlayerInteractions.h"
#include "DungeonSavingSys.h"
#include "ItemManager.h"
#include <cstdlib>

// Print main menu and read selection
void PrintMainmenu(int& MenuInput)
{
	do
	{
		std::cout << "\t--||:: FILES & ADVENTURES ::||--\n" << "\t\t ::Main Menu::\n\n";
		std::cout << "\n1) New Game\n2) Continue Game\n3) Exit\n\n";
		std::cin >> MenuInput;
		system("cls");
	} while (MenuInput < 0 || MenuInput > 3);
}



// Display player stats
void MenuSTATS(Player& IPlayer)
{
	system("cls");
	std::cout << "--- STATS ---" << std::endl;
	std::cout << "Lifes = " << IPlayer.lifes << std::endl;
	std::cout << "Gold Obtained = " << IPlayer.gold << std::endl;
	std::cout << "Attk Value= " << IPlayer.attk << std::endl;
	std::cout << std::endl;
	system("pause");
}

// Read single-char player input and normalize to lowercase
void PlayerInput(char& InputChar)
{
	std::cout << "MOVE [A / W / S / D] | SAV[E]| [Q]UIT | S[T]ATS" << std::endl;
	std::cin >> InputChar;
	InputChar = (char)tolower(InputChar);
}

// Sum total attack bonus from inventory (5 slots)
static float SumInventoryBonus(const Item slots[5])
{
	float sum = 0.0f;
	for (size_t i = 0; i < 5; ++i)
	{
		if (!slots[i].name.empty())
		{
			sum += slots[i].attkbonus * static_cast<float>(slots[i].amount);
		}
	}
	return sum;
}

// Handle chest: grant gold and an item (stack or place in first empty slot). If inventory full, apply fallback bonus.
void ChestFound(Player& IPlayer, const std::vector<Item>& items, Item slots[5])
{
	system("cls");
	std::cout << "\t::: A CHEST WAS FOUND :::\n";

	int randGold = 10 + rand() % (100 - 10);

	IPlayer.gold += randGold;

	std::cout << "YOU FOUND : " << randGold << " G" << std::endl;
	if (!items.empty())
	{
		Item found = GetRandomItem(items);

		bool stacked = false;
		for (size_t i = 0; i < 5; ++i)
		{
			if (slots[i].name == found.name)
			{
				slots[i].amount += found.amount;
				stacked = true;
				break;
			}
		}

		if (!stacked)
		{
			bool placed = false;
			for (size_t i = 0; i < 5; ++i)
			{
				if (slots[i].name.empty())
				{
					slots[i] = found;
					placed = true;
					break;

				}

			}

			if (!placed)
			{
				// Inventory full: apply temporary bonus to player as fallback
				IPlayer.attk += found.attkbonus * found.amount;
				std::cout << "Inventory full. Applied temporary bonus instead." << std::endl;
			}

		}


		IPlayer.attk += found.attkbonus * found.amount;


		std::cout << "YOU OBTAINED ITEM: " << found.name << " (+" << found.attkbonus << " attack)";
		if (found.icon != ' ') std::cout << " icon: '" << found.icon << "'";
		std::cout << " x" << found.amount << std::endl;
	}
	else
	{
		std::cout << "No items available (items.txt missing or empty)." << std::endl;
	}

	system("pause");
	system("cls");
}

// Start combat using a simple rand() percentage comparison:
// winChance = 1/3 + inventory bonus (capped to 1.0). Compare against rand() % 100.
void StartCombat(Player& IPlayer, Item slots[5], unsigned int& EnemyCount, bool& Defeat)
{
	system("cls");

	float bonus = SumInventoryBonus(slots);
	float winChance = IPlayer.attk + bonus;
	if (winChance > 1.0f) winChance = 1.0f;

	int winPercent = static_cast<int>(winChance * 100.0f);
	int roll = rand() % 100; // 0..99

	std::cout << "_- You got into a fight! -_" << std::endl;
	std::cout << "Win chance = " << winChance << " (" << winPercent << "%)" << std::endl;

	if (roll > winPercent)
	{
		IPlayer.lifes--;
		std::cout << "You lost the fight and lost a life..." << std::endl;
		Defeat = true;
	}
	else
	{
		std::cout << "You won the fight!" << std::endl;
		EnemyCount--;
		Defeat = false;
	}
	system("pause");
}

void DungeonCleared(Player IPlayer, std::string File)
{
	std::cout << "\n\n\t\t YOU CLEARED THE DUNGEON" << std::endl;
	system("pause");
	system("cls");
	MenuSTATS(IPlayer);
	SaveGameData(File, IPlayer);;
	system("cls");
}

// Handle player input and world interactions; pass items and inventory (5 slots).
void PlayerInteraction(std::vector<std::vector<char>>& Dungeon, std::string File, Player& IPlayer, char& InputChar, const std::vector<Item>& items, Item slots[5], bool& endRun, unsigned int& EnemyCount, bool& Defeat)
{
	PlayerInput(InputChar);

	Vector2 IPlayerLastPos = IPlayer.position;

	switch (InputChar)
	{
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

	case 't':
		MenuSTATS(IPlayer);
		break;

	case 'e':
		SaveGameData(File, IPlayer);
		break;

	case 'q':
		endRun = true;
		system("cls");
		std::cout << "\n\n\t\tYou exited the Dungeon Safely..." << std::endl << std::endl;
		system("pause");
		break;
	}

	switch (Dungeon[IPlayer.position.x][IPlayer.position.y])
	{
	case WALL:
		IPlayer.position = IPlayerLastPos;
		break;

	case CHEST:
		ChestFound(IPlayer, items, slots);
		break;
	case ENEMY:
		StartCombat(IPlayer, slots, EnemyCount, Defeat);
		if (Defeat)
		{
			!Defeat;
			IPlayer.position = IPlayerLastPos;
		}
		break;
	}

	Dungeon[IPlayerLastPos.x][IPlayerLastPos.y] = VOID;
	Dungeon[IPlayer.position.x][IPlayer.position.y] = PLAYER;
}

