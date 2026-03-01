#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// # = PARED | P = PLAYER | E = ENEMY | C= CHESt
#define WALL '#'
#define PLAYER 'P'
#define ENEMY 'E'
#define CHEST 'C'
#define VOID '.'


struct Vector2 {
	unsigned int x;
	unsigned int y;
};

struct Player {
	std::string Name;
	Vector2 position;
	unsigned short lifes = 0;
	unsigned int  gold = 0;
	float attk = 0;
};

struct Item {
	std::string name;
	float attkbonus = 0;
};

struct Enemy {
	Vector2 Position;
};

