#include "Cell.h"

/*
Implement cell type utilities:
- Represent cell content using enums/chars
- Identify cell categories (wall, free, chest, door, explorer, exit)
- Helper functions for checking type
*/

int cell_is_walkable(CellType type) {
    return (type == CELL_FREE || type == CELL_EXIT);
}

CellType cell_from_char(char c) {
    switch (c)
    {
        case ' ': return CELL_FREE;
        case '*': return CELL_WALL;
        case '$': return CELL_DOOR;
        case 'B': return CELL_CHEST;
        case '@': return CELL_EXIT;
        case '#': return CELL_FREE;
        default: return CELL_FREE;
    }
}

char cell_to_char(CellType type) {
    switch (type) {
        case CELL_FREE: return ' ';
        case CELL_WALL: return '*';
        case CELL_DOOR: return '$';
        case CELL_CHEST: return 'B';
        case CELL_EXIT: return '@';
        case CELL_EXPLORER: return '#';
        default: return '?';
    }
}

