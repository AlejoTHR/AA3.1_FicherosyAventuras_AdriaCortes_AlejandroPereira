#pragma once
#include "CONS.h"

// READS A MAP DESIGN FROM AN EXTERNAL "DUNGEON MAP" FILE
void ReadMap(std::vector<std::vector<char >>& Dungeon, std::string Fichero);

// STARTS THE DUNGEON MAP PROPERTYS (CHESTS, ENEMYES, PLAYER POSITION, ETC...)
void StartDungeonMap(std::vector<std::vector<char >>& Dungeon, Player& IPlayer);

// PRINTS THE DUNGEON MAP
void PrintDungeonMap(std::vector<std::vector<char >>& Dungeon);




