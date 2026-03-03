#pragma once
#include "CONS.h"
#include <vector>
#include <string>

// Carga ítems desde un fichero de texto.
// Formato por línea: <name> <attkbonus> <icon> <amount>
// - name: sin espacios
// - attkbonus: float (ej. 0.15)
// - icon: un carácter (si se omite se usa ' ')
// - amount: entero (si se omite se usa 1)
// Líneas vacías o que comiencen por '#' o ';' son ignoradas.
bool LoadItemsFromFile(const std::string& filename, std::vector<Item>& outItems);

// Devuelve un Item aleatorio (por valor). Si la lista está vacía, devuelve un Item por defecto.
Item GetRandomItem(const std::vector<Item>& items);


