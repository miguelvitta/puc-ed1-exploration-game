#ifndef MAP_H
#define MAP_H

// Represent the labyrinth matrix, allow reading/writing cells, validating movement, and updating the internal board state.

#include "Cell.h"
#include <stdlib.h>

typedef struct {
    int rows;
    int cols;
    Cell **grid;
} Map;

Map* map_create(int rows, int cols);

void map_free(Map *map);

// This gets a pointer so we can modify the cell
Cell* map_get_cell(Map *map, int row, int col);

int map_is_valid_coord(Map *map, int row, int col);

#endif
