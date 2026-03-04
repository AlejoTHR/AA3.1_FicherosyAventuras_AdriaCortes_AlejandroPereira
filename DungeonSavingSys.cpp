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


void LoadingUI(Player& IPlayer)
{
	// UI
	system("pause");
	system("cls");

	std::cout << std::endl << "Loaded Succesfuly" << std::endl << std::endl;

	system("pause");
	system("cls");

	std::cout << "\n\n\t" << IPlayer.Name << " HAS RETURNED TO THE DUNGEON" << std::endl << std::endl;
	std::cout << "  ::STATS::" << std::endl << std::endl;
	std::cout << "Gold : " << IPlayer.gold << " G" << std::endl;
	std::cout << "Lives Remaining : " << IPlayer.lifes << std::endl;
	std::cout << "Attack Power : " << IPlayer.attk << std::endl << std::endl;
	system("pause");
	system("cls");
}


void SaveGameData(std::string File, Player& IPlayer)
{
	std::cout << "SAVING..." << std::endl; // FEEDBACK

	Player TMPplayer; // TEMPORAL STORAGE PLAYER VARIABLE

	std::fstream FileBin;
	FileBin.open(File, std::ios::binary | std::ios::out); 
	if (!FileBin.is_open())
	{
		std::cout << "Error al abrir Archivo Binario";
		exit(0);
	}
	
	// STRNG NAME GETTER FUNCTION
	IPlayer.Name = UserInputName(IPlayer);


	////// PLAYER DATA
	//// BIN ORDER == GOLD / POS X / POS Y / LIFES / ATTK / NAME 

	// STORAGING PLAYER DATA BUT STRNG
	TMPplayer.gold = IPlayer.gold;
	TMPplayer.position.x = IPlayer.position.x;
	TMPplayer.position.y = IPlayer.position.y;
	TMPplayer.lifes = IPlayer.lifes;
	TMPplayer.attk = IPlayer.attk;
	
	// BIN GOLD
	FileBin.write(reinterpret_cast<char*>(&TMPplayer.gold), sizeof(TMPplayer.gold));

	// BIN POS X
	FileBin.write(reinterpret_cast<char*>(&TMPplayer.position.x), sizeof(TMPplayer.position.x));

	// BIN POS Y
	FileBin.write(reinterpret_cast<char*>(&TMPplayer.position.y), sizeof(TMPplayer.position.y));

	// BIN LIFES
	FileBin.write(reinterpret_cast<char*>(&TMPplayer.lifes), sizeof(TMPplayer.lifes));

	// BIN ATTK
	FileBin.write(reinterpret_cast<char*>(&TMPplayer.attk), sizeof(TMPplayer.attk));
	std::cout << IPlayer.attk;


	// I HATE STRNGERS >:O
	// BIN STRNG
	TMPplayer.Name = IPlayer.Name;
	// STRNG SIZE SAVING = STRING-TO-SAVE SIZE
	size_t NameBinsize = TMPplayer.Name.size();
	// SAVE STRNG SIZE
	FileBin.write(reinterpret_cast<char*>(&NameBinsize), sizeof(size_t));
	// SAVE STRNG CHAIN
	FileBin.write(TMPplayer.Name.c_str(), sizeof(char) * NameBinsize);
	////// PLAYER DATA

	FileBin.close();

	// FEEDBACK, EVERYTHING OK :D
	std::cout << "SAVED" << std::endl << std::endl;

	system("pause");
}

void ReadSaveData(std::string Fichero, Player& IPlayer, bool& playerGetted)
{
	std::cout << "Now Loading..." << std::endl << std::endl; // FEEDBACK

	std::fstream FileBin;
	FileBin.open(Fichero, std::ios::binary | std::ios::in);
	if (!FileBin.is_open())
	{
		std::cout << "Error al abrir Archivo Binario";
		exit(0);
	}

	////// PLAYER DATA READING PROCESS::
	Player TMPplayer;

	// BIN GOLD
	FileBin.read(reinterpret_cast<char*>(&TMPplayer.gold), sizeof(TMPplayer.gold));
	// BIN POS X
	FileBin.read(reinterpret_cast<char*>(&TMPplayer.position.x), sizeof(TMPplayer.position.x));
	// BIN POS Y
	FileBin.read(reinterpret_cast<char*>(&TMPplayer.position.y), sizeof(TMPplayer.position.y));
	// BIN LIFES
	FileBin.read(reinterpret_cast<char*>(&TMPplayer.lifes), sizeof(TMPplayer.lifes));
	// BIN LIFES
	FileBin.read(reinterpret_cast<char*>(&TMPplayer.attk), sizeof(TMPplayer.attk));
	// BIN STRNG (I HATE STRNGERS >:O
	// STRNG SIZE
	size_t NameBinsize;
	// READ STRNG SIZE
	FileBin.read(reinterpret_cast<char*>(&NameBinsize), sizeof(size_t));
	TMPplayer.Name.resize(NameBinsize);
	// STRNG SIZE RE-SIZE FOR LOADING
	FileBin.read(&TMPplayer.Name[0], sizeof(char) * NameBinsize);
	// LAST "END" CAHRACTER OF THE STRNG STRUCTURE
	TMPplayer.Name += '\0';
	////// PLAYER DATA

	FileBin.close();


	//DEBUGING OPTION
		//std::cout << TMPplayer.gold << " | " << TMPplayer.position.x << " | " << TMPplayer.position.y << " | " << TMPplayer.lifes << " | " << TMPplayer.Name<< std::endl << std::endl;
		//std::cout << IPlayer.gold << " | " << IPlayer.position.x << " | " << IPlayer.position.y << " | " << IPlayer.lifes << " | " << IPlayer.Name << std::endl << std::endl;
	//DEBUGING OPTION

	
	IPlayer.gold = TMPplayer.gold;
	IPlayer.position.x = TMPplayer.position.x;
	IPlayer.position.y = TMPplayer.position.y;
	IPlayer.lifes = TMPplayer.lifes;
	IPlayer.attk = TMPplayer.attk;
	IPlayer.Name = TMPplayer.Name;
	// LOADING SAVED DATA INTO PLAYER SYSTEM DATA
	playerGetted = true;

	// UI
	LoadingUI(IPlayer);

}