#pragma once
#include "CONS.h"




// LOCATES SAVING FILE AND MAKES A SAVE OF THE PLAYER STATE
void SaveGameData(std::string Fichero, Player& IPlayer);

// LOCATES SAVING FILE AND READS BIN.dat FILE TO LOAD PLAYER STATE
void ReadSaveData(std::string Fichero, Player& IPlayer, bool& playerGetted);

// MERELY UI
void LoadingUI(Player& IPlayer);




