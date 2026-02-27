#pragma once
#include "CONS.h"


// PRINTS MAIN MENU OPTIONS
void PrintMainmenu(int& MenuInput);

// READS PLAYER IPUT DURING GAMEPLAY
void PlayerInput(char& InputChar);

// READS ITEMS FILE AND SELECTS 1 RANDOMLY AND GRANTS A RANDOM AMOUNT OF GOLD
void ChestFound();

// ALL USER INTERACTION AND OBSTACLES 
void PlayerInteraction(std::vector<std::vector<char>>& Dungeon, std::vector<std::vector<char>>& DungeonSave, std::string Fichero, Player& IPlayer, char& InputChar);

