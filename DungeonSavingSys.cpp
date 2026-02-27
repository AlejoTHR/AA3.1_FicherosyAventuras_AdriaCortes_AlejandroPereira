#pragma once

#include "CONS.h"
#include "DungeonSavingSys.h"


std::string UserInputName(Player& IPlayer)
{
	// INPUT USER NAME
	std::cout << "Dungeoner Name?: ";
	std::cin >> IPlayer.Name;

	return IPlayer.Name;
}


void SaveGameData(std::string Fichero, Player& IPlayer)
{
	std::cout << "SAVING..." << std::endl;

	Player TMPplayer;


	std::fstream FileBin;
	FileBin.open(Fichero, std::ios::binary | std::ios::out);
	if (!FileBin.is_open())
	{
		std::cout << "Error al abrir Archivo Binario";
		exit(0);
	}
	
	// STRNG NAME GETTER FUNCTION
	IPlayer.Name = UserInputName(IPlayer);


	////// PLAYER DATA
	//// BIN ORDER == GOLD / POS X / POS Y / LIFES / NAME

	// STORAGING PLAYER DATA BUT STRNG
	TMPplayer.gold = IPlayer.gold;
	TMPplayer.position.x = IPlayer.position.x;
	TMPplayer.position.y = IPlayer.position.y;
	TMPplayer.lifes = IPlayer.lifes;
	
	// BIN GOLD
	FileBin.write(reinterpret_cast<char*>(&TMPplayer.gold), sizeof(TMPplayer.gold));

	// BIN POS X
	FileBin.write(reinterpret_cast<char*>(&TMPplayer.position.x), sizeof(TMPplayer.position.x));

	// BIN POS Y
	FileBin.write(reinterpret_cast<char*>(&TMPplayer.position.y), sizeof(TMPplayer.position.y));

	// BIN LIFES
	FileBin.write(reinterpret_cast<char*>(&TMPplayer.lifes), sizeof(TMPplayer.lifes));

	// I HATE STRNGERS
	// BIN STRNG

	TMPplayer.Name = IPlayer.Name;
	// STRNG SIZE
	size_t NameBinsize = TMPplayer.Name.size();
	// SAVE STRNG SIZE
	FileBin.write(reinterpret_cast<char*>(&NameBinsize), sizeof(size_t));
	// SAVE STRNG CHAIN
	FileBin.write(TMPplayer.Name.c_str(), sizeof(char) * NameBinsize);

	////// PLAYER DATA


	//// ENEMY DATA



	//// ENEMY DATA


	FileBin.close();

	// EVERYTHING OK :D
	std::cout << "SAVED" << std::endl << std::endl;

	system("pause");
}



void ReadSaveData(std::string Fichero, Player& IPlayer)
{
	std::cout << "Now Loading..." << std::endl << std::endl;

	std::fstream FileBin;
	FileBin.open(Fichero, std::ios::binary | std::ios::in);
	if (!FileBin.is_open())
	{
		std::cout << "Error al abrir Archivo Binario";
		exit(0);
	}

	////// PLAYER DATA
	
	Player TMPplayer;

	// BIN GOLD
	FileBin.read(reinterpret_cast<char*>(&TMPplayer.gold), sizeof(TMPplayer.gold));
	// BIN POS X
	FileBin.read(reinterpret_cast<char*>(&TMPplayer.position.x), sizeof(TMPplayer.position.x));
	// BIN POS Y
	FileBin.read(reinterpret_cast<char*>(&TMPplayer.position.y), sizeof(TMPplayer.position.y));
	// BIN LIFES
	FileBin.read(reinterpret_cast<char*>(&TMPplayer.lifes), sizeof(TMPplayer.lifes));
	size_t NameBinsize;
	// BIN STRNG
	FileBin.read(reinterpret_cast<char*>(&NameBinsize), sizeof(size_t));
	TMPplayer.Name.resize(NameBinsize);
	FileBin.read(&TMPplayer.Name[0], sizeof(char) * NameBinsize);
	TMPplayer.Name += '\0';
	
	////// PLAYER DATA

	FileBin.close();


	//DEBUGING OPTION
	
	//std::cout << TMPplayer.gold << " | " << TMPplayer.position.x << " | " << TMPplayer.position.y << " | " << TMPplayer.lifes << " | " << TMPplayer.Name<< std::endl << std::endl;
	//IPlayer.gold = TMPplayer.gold;
	//IPlayer.position.x = TMPplayer.position.x;
	//IPlayer.position.y = TMPplayer.position.y;
	//IPlayer.lifes = TMPplayer.lifes;
	//IPlayer.Name = TMPplayer.Name;
	//std::cout << IPlayer.gold << " | " << IPlayer.position.x << " | " << IPlayer.position.y << " | " << IPlayer.lifes << " | " << IPlayer.Name << std::endl << std::endl;

	std::cout << "Loaded" << std::endl;
	system("pause");
	system("cls");
}