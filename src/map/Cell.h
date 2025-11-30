#ifndef CELL_H
#define CELL_H

// Represent a single cell of the map using enum or char and categorize it (wall, chest, door, free space, explorer, exit).

typedef enum {
    CELL_FREE,
    CELL_WALL,
    CELL_DOOR,
    CELL_CHEST,
    CELL_EXIT,
    CELL_EXPLORER
} CellType;

typedef struct {
    CellType type;
} Cell;

int cell_is_walkable(CellType type);

// converts a raw character from the map to our enum
CellType cell_from_char(char c);

// Converts the Enum back to a character
char cell_to_char(CellType type);

#endif
