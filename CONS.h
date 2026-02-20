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

struct Vector2 {
	int x;
	int y;
};

struct Player {
	Vector2 position;
	int vidas;
	float attk;

};