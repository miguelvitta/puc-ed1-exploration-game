#include "Map.h"
#include <stdio.h>

/*
Implement the map matrix:
- Allocate, initialize, and free the board
- Provide getters/setters for cells
- Detect if movement to a cell is allowed
- Update map when chests/doors are removed
*/

Map* map_create(int rows, int cols) {
    if (rows <= 0 || cols <= 0) return NULL;

    Map *map = (Map *)malloc(sizeof(Map));

    if (map == NULL) {
        fprintf(stderr, "Error when allocatin memory for the map.\n");
        return NULL;
    }

    map->cols = cols;
    map->rows = rows;

    map->grid = (Cell **)malloc(rows * sizeof(Cell *));
    if (map->grid == NULL) {
        free(map);
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        map->grid[i] = (Cell *)malloc(cols * sizeof(Cell));

        if (map->grid[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(map->grid[j]);
            }
            free(map->grid);
            free(map);
            return NULL;
        }

        // By default every CELL will be free
        for (int j = 0; j < cols; j++) {
            map->grid[i][j].type = CELL_FREE;
        }
    }

    return map;
}


void map_free(Map *map) {
    if (map == NULL) return;

    if (map->grid != NULL) {
        for (int i = 0; i < map->rows; i++) {
            free(map->grid[i]);
        }

        free(map->grid);
    }

    free(map);
}

Cell* map_get_cell(Map *map, int row, int col) {
    if (!map_is_valid_coord(map, row, col)) {
        return NULL;
    }

    return &map->grid[row][col];
}

int map_is_valid_coord(Map *map, int row, int col) {
    if (map == NULL) return 0;

    return (row >= 0 && row < map->rows && col >= 0 && col < map->cols);
}

