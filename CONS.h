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
#define VOID ' '

struct Vector2 {
	int x;
	int y;
};

struct Player {
	std::string Name;
	Vector2 position;
	int lifes;
	int gold;
	float attk;
};

struct Item {
	std::string name;
	float attkbonus;
};