#include "Header.h"

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


void LeerMapa(std::vector<std::vector<char >>& Dungeon, std::string Fichero)
{
	std::ifstream File;
	File.open(Fichero);
	if (!File.is_open())
	{
		std::cout << "Error al abrir";
		exit(0);
	}
	std::string Line;
	while (getline(File, Line))
	{
		std::vector<char> tmpLine;
		for (unsigned int i = 0; i < Line.size(); i++)
		{
			if (Line[i] == ';')	continue;

			else if (Line[i] == '.') tmpLine.push_back(' ');

			else tmpLine.push_back(Line[i]);

		}
		Dungeon.push_back(tmpLine);
	}
	File.close();
}

void IniciarDungeon(std::vector<std::vector<char >>& Dungeon, Player& IPlayer)
{
	bool playerGetted = false;
	for (int i = 0; i < Dungeon.size(); i++)
	{
		for (int j = 0; j < Dungeon[i].size(); j++)
		{
			if (Dungeon[i][j] == CHEST)
			{
				// CHESTS;
			}
			else if (Dungeon[i][j] == PLAYER && !playerGetted)
			{
				IPlayer.position.x = i;
				IPlayer.position.y = j;
				playerGetted = true;
			}
		}
		std::cout << std::endl;
	}
}

void ImprimirMapa(std::vector<std::vector<char >>& Dungeon)
{
	for (int i = 0; i < Dungeon.size(); i++)
	{
		for (int j = 0; j < Dungeon[i].size(); j++)
		{
			std::cout << Dungeon[i][j];
		}
		std::cout << std::endl;
	}

}

void MoverP(std::vector<std::vector<char>>& Dungeon, std::vector<std::vector<char>>& DungeonSave, Player& IPlayer)
{
	char InputChar;
	Vector2 IPlayerLastPos = IPlayer.position;

	std::cin >> InputChar;
	switch (InputChar)
	{
		// MOVES
	case 'W':
		IPlayer.position.x--;
		break;
	case 'S':
		IPlayer.position.x++;
		break;
	case 'A':
		IPlayer.position.y--;
		break;
	case 'D':
		IPlayer.position.y++;
		break;
		// SAVE
	case 'E':
		SaveMap(Dungeon, DungeonSave, "SaveMap.csv");
		break;
		// QUIT
	case 'Q':

		break;
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
		// SAVE
	case 'e':
		SaveMap(Dungeon, DungeonSave, "SaveMap.csv");
		break;
		// QUIT
	case 'q':

		break;
	}
	// OBSTACLES
	switch (Dungeon[IPlayer.position.x][IPlayer.position.y])
	{
	case WALL:
		IPlayer.position = IPlayerLastPos;
		break;
	case CHEST:
		/////////////

		break;
	case ENEMY:

		
		//IPlayer.vidas--;
		break;
	}


	Dungeon[IPlayerLastPos.x][IPlayerLastPos.y] = ' ';
	Dungeon[IPlayer.position.x][IPlayer.position.y] = (IPlayer.vidas <= 0) ? 'X' : PLAYER;
}

int main()
{
	std::vector<std::vector<char >> Dungeon;
	std::vector<std::vector<char >> DungeonSave;

	Player IPlayer;
	IPlayer.position.x = 0;
	IPlayer.position.y = 0;
	IPlayer.vidas = 3;
	IPlayer.attk = 100/3;

	LeerMapa(Dungeon, "TestDungeon.csv");
	IniciarDungeon(Dungeon, IPlayer);

	do
	{

		ImprimirMapa(Dungeon);
		std::cout << "MOVE [A / W / S / D] | SAV[E]| [Q]UIT" << std::endl;
		MoverP(Dungeon, DungeonSave, IPlayer);

		system("cls");
	} while (IPlayer.vidas > 0);

	/// if () std::cout << "YOU WIN" << std::endl;
	if (IPlayer.vidas == 0) std::cout << "YOU DIED" << std::endl;
	


	return 0;
}