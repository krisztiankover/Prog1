#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
using namespace std;

int main()
{
	int r = 0,c = 0;
	int xj = 0, xk = 0, yj = 0, yk = 0;

	initscr();
	curs_set(0);
	getmaxyx(stdscr,r,c);
	r = r * 2 - 1;
	c = c * 2 - 1;

	for(;;)
	{
		xj = (xj - 1) % c;
		xk = (xk + 1) % c;

		yj = (yj - 1) % r;
		yk = (yk + 1) % r;

		wclear(stdscr);

		for(int i = 0;i < c / 2;i++)
		{
			mvaddch(0,i,'-');
			mvaddch(r / 2,i,'-');
		}

		mvaddch (abs ((yj + (r - yk)) / 2),
				 abs ((xj + (c - xk)) / 2), 'X');
		refresh();
		usleep(100000);
	}
}