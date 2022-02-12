#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

char *getNrString(int characterNumber) {
    char *a, b;
    int i=0;
    a=(char*)malloc(2*sizeof(char));
    if (!a) {
        fprintf(stderr, "\n\nInsuficient memory.\n\n");
        exit(EXIT_FAILURE);
    }
    do {
        b=getchar();
        if (i<characterNumber && b!='\n') {
            a[i]=b;
            a[i+1]='\0';
            a=(char*)realloc(a,(strlen(a)+1)*sizeof(char));
            i++;
        }
    } while (b!='\n');
    return a;
}

void printMap(int **map) {
    int i, j;
    char *print;
    printf("%s\n", MAP_TOP);
    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            printf("%c", MAP_SIDE);
            if (map[i][j]) {
                if (map[i][j]<100) {
                    print=PRINT_1;
                } else {
                    print=PRINT_2;
                }
                printf(print, map[i][j]);
            } else {
                printf("    ");
            }
        }
        printf("%c\n%s\n", MAP_SIDE, MAP_TOP);
    }
    printf("\n");
}

_Bool canMoveAnywhere(int **map) {
    _Bool canMove=canMoveLeft(map);
    if (canMove) {
        return 1;
    } else {
        canMove=canMoveRight(map);
        if (canMove) {
            return 1;
        } else {
            canMove=canMoveUp(map);
            if (canMove) {
                return 1;
            } else {
                canMove=canMoveDown(map);
                if (canMove) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

_Bool canMoveLeft(int **map) {
    int i, j;
    for (i=0; i<4; i++) {
        for (j=1; j<4; j++) {
            if (map[i][j]) {
                if (!map[i][j-1] || map[i][j-1]==map[i][j]) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

_Bool canMoveRight(int **map) {
    int i, j;
    for (i=0; i<4; i++) {
        for (j=0; j<3; j++) {
            if (map[i][j]) {
                if (!map[i][j+1] || map[i][j+1]==map[i][j]) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

_Bool canMoveUp(int **map) {
    int i, j;
    for (i=1; i<4; i++) {
        for (j=0; j<4; j++) {
            if (map[i][j]) {
                if (!map[i-1][j] || map[i-1][j]==map[i][j]) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

_Bool canMoveDown(int **map) {
    int i, j;
    for (i=0; i<3; i++) {
        for (j=0; j<4; j++) {
            if (map[i][j]) {
                if (!map[i+1][j] || map[i+1][j]==map[i][j]) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void moveUp(int **map) {
    int i, j, a, n;
    for (a=0; a<=2; a++) {
        for (i=1; i<4; i++) {
            for (j=0; j<4; j++) {
                if (a!=1) {
                    n=i;
                    while (n>0 && !map[n-1][j]) {
                        map[n-1][j]=map[n][j];
                        map[n][j]=0;
                        n--;
                    }
                } else {
                    if (map[i-1][j]==map[i][j]) {
                        map[i-1][j]*=2;
                        map[i][j]=0;
                    }
                }
            }
        }
    }
}

void moveDown(int **map) {
    int i, j, a, n;
    for (a=0; a<=2; a++) {
        for (i=2; i>=0; i--) {
            for (j=0; j<4; j++) {
                if (a!=1) {
                    n=i;
                    while (n<3 && !map[n+1][j]) {
                        map[n+1][j]=map[n][j];
                        map[n][j]=0;
                        n++;
                    }
                } else {
                    if (map[i+1][j]==map[i][j]) {
                        map[i+1][j]*=2;
                        map[i][j]=0;
                    }
                }
            }
        }
    }
}

void moveLeft(int **map) {
    int i, j, a, n;
    for (a=0; a<=2; a++) {
        for (j=1; j<4; j++) {
            for (i=0; i<4; i++) {
                if (a!=1) {
                    n=j;
                    while (n>0 && !map[i][n-1]) {
                        map[i][n-1]=map[i][n];
                        map[i][n]=0;
                        n--;
                    }
                } else {
                    if (map[i][j-1]==map[i][j]) {
                        map[i][j-1]*=2;
                        map[i][j]=0;
                    }
                }
            }
        }
    }
}

void moveRight(int **map) {
    int i, j, a, n;
    for (a=0; a<=2; a++) {
        for (j=2; j>=0; j--) {
            for (i=0; i<4; i++) {
                if (a!=1) {
                    n=j;
                    while (n<3 && !map[i][n+1]) {
                        map[i][n+1]=map[i][n];
                        map[i][n]=0;
                        n++;
                    }
                } else {
                    if (map[i][j+1]==map[i][j]) {
                        map[i][j+1]*=2;
                        map[i][j]=0;
                    }
                }
            }
        }
    }
}
