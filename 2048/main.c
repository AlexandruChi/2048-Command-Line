#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../library/functions.h"

#if (_WIN16 || _Win32)
#define clear "cls"
#else
#define clear "clear"
#endif

int main(int argc, const char * argv[]) {
    int **game, i, j;
    char *move, value, *string;
    unsigned int randomSeed;
    _Bool isRunning=1, isFull, canMove, win=0, start=1, ok, ok2=0, ok3;
    game=(int**)malloc(4*sizeof(int*));
    if (!game) {
        fprintf(stderr, "\n\nInsuficient memory.\n\n");
        exit(EXIT_FAILURE);
    }
    for (i=0; i<4; i++) {
        game[i]=(int*)malloc(4*sizeof(int));
        if (!game[i]) {
            fprintf(stderr, "\n\nInsuficient memory.\n\n");
            exit(EXIT_FAILURE);
        }
    }
    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            game[i][j]=0;
        }
    }
    randomSeed=(unsigned int)time(NULL);
    srand(randomSeed);
    while (isRunning) {
        isFull=1;
        for (i=0; i<4; i++) {
            for (j=0; j<4; j++) {
                if (game[i][j]==2048) {
                    win=1;
                    break;
                } else if (!game[i][j]) {
                    isFull=0;
                }
            }
        }
        if (win) {
            break;
        }
        if (!isFull && !ok2) {
            do {
                i=rand()%4;
                j=rand()%4;
            } while (game[i][j]);
            game[i][j]=2;
            if (!(rand()%11)) {
                game[i][j]*=2;
            }
            if (start) {
                do {
                    i=rand()%4;
                    j=rand()%4;
                } while (game[i][j]);
                game[i][j]=2;
                if (!(rand()%11)) {
                    game[i][j]*=2;
                }
                start=0;
            }
        } else if (ok2) {
            ok2=0;
        }
        canMove=canMoveAnywhere(game);
        if (canMove) {
            ok=1;
            ok3=0;
            while (ok) {
                system(clear);
                printMap(game);
                if (ok3) {
                    printf("Move is not valid\n\n");
                }
                printf("Press wasd keys to move\n\n>");
                move=getNrString(2);
                value=0;
                if (strlen(move)==1) {
                    value=move[0];
                }
                switch (value) {
                    case 'w':
                    case 'W':
                        if (canMoveUp(game)) {
                            ok=0;
                            ok2=0;
                            ok3=0;
                            moveUp(game);
                        } else {
                            ok2=1;
                        }
                        break;
                    case 's':
                    case 'S':
                        if (canMoveDown(game)) {
                            ok=0;
                            ok2=0;
                            ok3=0;
                            moveDown(game);
                        } else {
                            ok2=1;
                        }
                        break;
                    case 'a':
                    case 'A':
                        if (canMoveLeft(game)) {
                            ok=0;
                            ok2=0;
                            ok3=0;
                            moveLeft(game);
                        } else {
                            ok2=1;
                        }
                        break;
                    case 'd':
                    case 'D':
                        if (canMoveRight(game)) {
                            ok=0;
                            ok2=0;
                            ok3=0;
                            moveRight(game);
                        } else {
                            ok2=1;
                        }
                        break;
                    default:
                        ok3=1;
                        ok2=0;
                        ok=1;
                        break;
                }
                free(move);
                move=0;
            }
        } else {
            isRunning=0;
        }
    }
    system(clear);
    if (win) {
        printf("\n       You won\n");
    } else {
        printf("\n       You lost\n");
    }
    printMap(game);
    for (i=0; i<4; i++) {
        free(game[i]);
        game[i]=0;
    }
    free(game);
    game=0;
    printf("Press enter to close ... ");
    string=getNrString(0);
    system(clear);
    return 0;
}
