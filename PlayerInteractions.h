#pragma once
#include "CONS.h"
#include "ItemManager.h"

// Print main menu options
void PrintMainmenu(int& MenuInput);

// Read player input during gameplay (automatically converts to lowercase)
void PlayerInput(char& InputChar);

// Handle chest: select an item from the items list and add it to the inventory (5 slots)
void ChestFound(Player& IPlayer, const std::vector<Item>& items, Item slots[5]);

// Start a combat: base 1/3 chance + sum of inventory attack bonuses
void StartCombat(Player& IPlayer, Item slots[5]);

// Handle all player interactions and obstacles. Inventory (5 slots) and items list are passed in.
void PlayerInteraction(std::vector<std::vector<char>>& Dungeon, std::vector<std::vector<char>>& DungeonSave, std::string Fichero, Player& IPlayer, char& InputChar, const std::vector<Item>& items, Item slots[5], bool& endRun);
