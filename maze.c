#include "maze.h"

int main()
{
	initscr();
	scrollok(stdscr, TRUE);
	noecho();

	srand((unsigned int)time(NULL));
	
	
	menu();

	endwin();
	system("clear");
	return 0;
}

void input()
{
	int tmp_col, tmp_row;
	printw("input col: ");
	scanw("%d", &tmp_col);
	col = 1 + 2 * tmp_col;
	printw("input row: ");
	scanw("%d", &tmp_row);
	row = 1 + 2 * tmp_row;

	return;
}

void maze()
{
	
	//°ÑÇ½±ÚÐ´ÈëÊý×é
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (!(i % 2) && !(j % 2)) { maze_a[i][j] = '+'; }
			else if (!(i % 2) && j % 2) { maze_a[i][j] = '-'; }
			else if (i % 2 && !(j % 2)) { maze_a[i][j] = '|'; }
			else { maze_a[i][j] = ' '; }
		}
	}

	//Ëæ»úÉ¾³ýÃ¿Ò»ÅÅµÄÊúÇ½±Ú
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			int cat = rand() % 2;
			if (cat && maze_a[i][j] == '|' && j != 0 && j != row - 1)
			{
				maze_a[i][j] = ' ';
			}
		}
	}

	////¸ù¾ÝÊúÇ½±ÚÉ¾³ýºáÇ½±Ú
	//for (int i = 1; i < col - 2; i++)
	//{
	//	bool the_cat = false;
	//	for (int j = 1; j < row; j++)
	//	{
	//		int tmp_cat = rand() % 5;
	//		if (maze_a[i][j] == '|' && !the_cat)
	//		{
	//			maze_a[i + 1][j - 1] = ' ';
	//		}
	//		/*else if (!tmp_cat && maze_a[i][j] == '-')
	//		{
	//			maze_a[i][j] = ' ';
	//			the_cat = true;
	//		}*/
	//		
	//	}
	//}

	//////¸ù¾ÝÊúÇ½±ÚÉ¾³ýºáÇ½±Únew
	for (int i = 1; i < col - 2; i++)
	{
		bool the_cat = false;
		for (int j = 1 ; j < row; j++)
		{
			int tmp_cat = rand() % 5;
			
			if (maze_a[i][j] == '|' && !the_cat)
			{
				maze_a[i + 1][j - 1] = ' ';
			}
			else if (!tmp_cat && i % 2 == 1 && j % 2 == 0 && !the_cat)
			{
				the_cat = true;
				maze_a[i + 1][j - 1] = ' ';
			}
			if (maze_a[i][j] == '|')
			{
				the_cat = false;
			}
		}
	}

	//Ö±½ÓÉ¾³ý×îºóÒ»ÅÅÊúÇ½±Ú
	for (int j = 1; j < row - 1; j++)
	{
		//int rand_cat = rand() % 2;
		if (maze_a[col -2][j] == '|')
		{
			maze_a[col - 2][j] = ' ';
		}
	}

	print_maze();
	return;
}

void end()
{
	int i = 0, j = 0;
	while (i == 0 && j == 0)
	{
		i = rand() % ((col - 1) / 2);
		j = rand() % ((row - 1) / 2);
	}
	
	maze_a[(i * 2) + 1][(j * 2) + 1] = 'E';
}
                                     
void users()
{
	clear();
	int i = 1, j = 1;
	maze_a[i][j] = '@';
	print_maze();
	int ch;
	while (true)
	{
		
		ch = getch();
		if (ch == 'a' && maze_a[i][j - 1] == ' ')
		{
			maze_a[i][j] = ' ';
			j--;
		}
		else if (ch == 's' && maze_a[i + 1][j] == ' ')
		{
			maze_a[i][j] = ' ';
			i++;
		}
		else if (ch == 'w' && maze_a[i - 1][j] == ' ')
		{
			maze_a[i][j] = ' ';
			i--;
		}
		else if (ch == 'd' && maze_a[i][j + 1] == ' ')
		{
			maze_a[i][j] = ' ';
			j++;
		}

		else if (ch == 'a' && maze_a[i][j - 1] == 'E')
		{
			maze_a[i][j] = ' ';
			j--;
			maze_a[i][j] = '@';
			victory();
			break;
		}
		else if (ch == 's' && maze_a[i + 1][j] == 'E')
		{
			maze_a[i][j] = ' ';
			i++;
			maze_a[i][j] = '@';
			victory();
			break;
		}
		else if (ch == 'w' && maze_a[i - 1][j] == 'E')
		{
			maze_a[i][j] = ' ';
			i--;
			maze_a[i][j] = '@';
			victory();
			break;
		}
		else if (ch == 'd' && maze_a[i][j + 1] == 'E')
		{
			maze_a[i][j] = ' ';
			j++;
			maze_a[i][j] = '@';
			victory();
			break;
		}
		else if (ch == 'q')
		{
			clear();
			endwin();
			exit(0);
		}
		clear();
		maze_a[i][j] = '@';
		print_maze();
	}
	
	clear();
	
	if (col >= 5  && row > 9) print_maze();
	else the_victory();

	return;
}

void the_victory()
{
	clear();
	if(level_bool)printw("level %d\n", ((col / 2) + (row / 2) - 3));
	printw("+ - - - - - - - - - +\n");
	printw("|                   |\n");
	printw("|   v i c t o r y   |\n");
	printw("|                   |\n");
	printw("+ - - - - - - - - - +\n");
	return;
}

void victory()
{
	int i = col / 2;
	int j = row / 2;
	maze_a[i][j] = 't';
	maze_a[i][j - 1] = 'c';
	maze_a[i][j - 2] = 'i';
	maze_a[i][j - 3] = 'v';
	maze_a[i][j - 4] = ' ';
	maze_a[i][j + 1] = 'o';
	maze_a[i][j + 2] = 'r';
	maze_a[i][j + 3] = 'y';
	maze_a[i][j + 4] = ' ';

	maze_a[i - 2][j - 5] = '+';
	maze_a[i - 2][j + 5] = '+';
	maze_a[i + 2][j - 5] = '+';
	maze_a[i + 2][j + 5] = '+';

	i--;
	for (int x = j - 4; x <= j + 4; x++)
	{
		maze_a[i][x] = ' ';
	}
	i--;
	for (int x = j - 4; x <= j + 4; x++)
	{
		maze_a[i][x] = '-';
	}
	i += 3;
	for (int x = j - 4; x <= j + 4; x++)
	{
		maze_a[i][x] = ' ';
	}
	i++;
	for (int x = j - 4; x <= j + 4; x++)
	{
		maze_a[i][x] = '-';
	}

	for (int x = i - 1; x > i - 4; x--)
	{
		maze_a[x][j - 5] = '|';
	}
	for (int x = i - 1; x > i - 4; x--)
	{
		maze_a[x][j + 5] = '|';
	}
	
	
	return;
}
//1
//victory

void print_maze()
{

	if (level_bool)
	{
		printw("level %d\n", ((col / 2) + (row / 2) - 3));
	}
	
	
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			printw("%c ", maze_a[i][j]);
		}
		if(i == 1)printw("    +-------------------+");
		if(i == 2)printw("    |  input q is exit  |");
		if(i == 3)printw("    +-------------------+");
		printw("\n");
	}
	
	return;
}

void custom_mode()
{
	echo();
	int s;
	while (true)
	{
		input();
		maze();
		end();
		users();
		printw("next maze is enter key: ");
		s = getch();
		if (s != 10)
		{
			break;
		}
		clear();
	}
	return;
}

void menu()
{
	int s_menu;
	printw("+------menu------+\n");
	printw("|  1.Level Mode  |\n");
	printw("|  2.Custom Mode |\n");
	printw("|  3.Exit        |\n");
	printw("+----------------+\n");
	s_menu = getch();

	while (true)
	{
		if (s_menu == '1')
		{
			clear();
			level_mode();
			break;
		}
		else if (s_menu == '2')
		{
			clear();
			custom_mode();
			break;
		}
		else if (s_menu == '3')
		{
			clear();
			break;
		}
		else
		{
			printw("input error");
			getch();
			break;
		}
		
	}
	return;
	
}

void level_mode()
{
	level_bool = true;
	col = 5;
	row = 5;
	//int s_level_mode;
	int i = 1;
	while (true)
	{
		int cat = rand() % 3;
		maze();
		end();
		users();
		getch();
		clear();
		i++;
		if (!cat) col += 2;
		else row += 2;
	}
}