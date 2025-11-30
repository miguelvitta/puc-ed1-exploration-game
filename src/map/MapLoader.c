#include "MapLoader.h"
#include <stdio.h>
#include <stdlib.h>

/*
Implement map loading from file:
- Read dimensions from first two lines
- Parse ASCII characters into the matrix
- Create entities based on symbols encountered
*/

Map* map_loader_load_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return NULL;
    }

    int rows, cols;
    
    if (fscanf(file, "%d", &cols) != 1 || fscanf(file, "%d", &rows) != 1) {
        fprintf(stderr, "Error: Invalid map file format (dimensions missing).\n");
        fclose(file);
        return NULL;
    }

    char buffer_char;
    while ((buffer_char = fgetc(file)) != '\n' && buffer_char != EOF);

    Map *map = map_create(rows, cols);
    if (map == NULL) {
        fclose(file);
        return NULL;
    }

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int ch = fgetc(file);

            if (ch == EOF) {
                break; 
            }

            if (ch == '\n') {
                c--;
                continue;
            }

            Cell *cell = map_get_cell(map, r, c);
            cell->type = cell_from_char((char)ch);
        }
    }

    fclose(file);
    return map;
}

