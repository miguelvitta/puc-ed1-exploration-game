#ifndef MAP_LOADER_H
#define MAP_LOADER_H

// Handle reading the ASCII map file, creating the matrix, and initializing the board with all elements.

#include "Map.h"

Map* map_loader_load_from_file(const char *filename);

#endif
