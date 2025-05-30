#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

#define MAX 100

int col, row;
bool level_bool = false;

char maze_a[MAX][MAX];

void input();
void maze();
void print_maze();
void users();
void end();
void victory();
void menu();
void level_mode();
void the_victory();