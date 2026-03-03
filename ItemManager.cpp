#pragma once
#include "ItemManager.h"

bool LoadItemsFromFile(const std::string& filename, std::vector<Item>& outItems)
{
	std::ifstream file(filename);
	if (!file.is_open())
	{
		return false;
	}

	std::string line;
	while (std::getline(file, line))
	{
		// Trim leading spaces
		size_t first = line.find_first_not_of(" \t\r\n");
		if (first == std::string::npos) continue; // línea vacía
		if (line[first] == '#' || line[first] == ';') continue; // comentario

		std::istringstream iss(line);
		Item it;
		std::string iconStr;

		// Intentamos leer name y attkbonus primero
		if (!(iss >> it.name >> it.attkbonus))
		{
			// línea inválida -> saltar
			continue;
		}

		// Intentamos leer icon y amount (opcional)
		if (iss >> iconStr)
		{
			it.icon = iconStr.empty() ? ' ' : iconStr[0];
			if (!(iss >> it.amount))
			{
				it.amount = 1;
			}
		}
		else
		{
			it.icon = ' ';
			it.amount = 1;
		}

		outItems.push_back(it);
	}

	return !outItems.empty();
}

Item GetRandomItem(const std::vector<Item>& items)
{
	if (items.empty()) return Item{};
	size_t idx = static_cast<size_t>(rand()) % items.size();
	return items[idx];
}


