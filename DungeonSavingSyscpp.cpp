#pragma once
#include "DungeonSavingSys.h"

void SaveMap(std::vector<std::vector<char >>& Dungeon, std::vector<std::vector<char >> DungeonSave, std::string Fichero)
{
	std::ofstream File;
	File.open(Fichero);
	if (!File.is_open())
	{
		std::cout << "Error al abrir, el archivo ya esta abierto!";
		exit(0);
	}

	for (int i = Dungeon.size() - 1; i >= 0; i--)
	{
		DungeonSave.push_back(Dungeon[i]);
		std::cout << "Se ha guardado el archivo.";
	}


	File.close();
}

void SaveGameData(std::string Fichero, std::string userName, Vector2 position, int lives, int gold, int attackPercentage) {
	std::ofstream File;
	File.open(Fichero);
	if (!File.is_open())
	{
		std::cout << "Error al abrir, el archivo ya esta abierto!";
		exit(0);
	}
	File << userName << "\n";
	File << position.y << "\n";
	File << position.x << "\n";
	File << lives << "\n";
	File << gold << "\n";
	File << attackPercentage << "\n";

	File.close();
}