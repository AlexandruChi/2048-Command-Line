#ifndef functions_h
#define functions_h

#include <stdlib.h>

#define MAP_TOP "*----*----*----*----*"
#define MAP_SIDE '|'

#define PRINT_1 "%3d "
#define PRINT_2 "%4d"

char *getNrString(int characterNumber);
void printMap(int **map);
_Bool canMoveAnywhere(int **map);
_Bool canMoveLeft(int **map);
_Bool canMoveRight(int **map);
_Bool canMoveUp(int **map);
_Bool canMoveDown(int **map);
void moveUp(int **map);
void moveDown(int **map);
void moveLeft(int **map);
void moveRight(int **map);

#endif
