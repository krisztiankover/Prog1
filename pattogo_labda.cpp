#include <unistd.h>
#include <iostream>
#include <ncurses.h>
using namespace std;

int main()
{
	int r,c,i=0,j=0,pi=0,pj=0;

	initscr();
	curs_set(0);
	mvaddch(i,j,'X');
	i++;
	j++;
	getmaxyx(stdscr,r,c);
	for(;;)
	{
		while(pi < i || i == 0)
		{
			while(pj < j || j == 0)
			{
				pi = i;
				pj = j;
				i++;
				j++;
				usleep(100000);
				werase(stdscr);
				for(int a = 0;a < c;a++)
				{
					mvaddch(0,a,'-');
					mvaddch(r-1,a,'-');
				}
				mvaddch(i,j,'X');
				refresh();
				break;
			}
			while(pj > j || j == c-1)
			{
				pi = i;
				pj = j;
				i++;
				j--;
				usleep(100000);
				werase(stdscr);
				for(int a = 0;a < c;a++)
				{
					mvaddch(0,a,'-');
					mvaddch(r-1,a,'-');
				}
				mvaddch(i,j,'X');
				refresh();
				break;
			}
			break;
		}
		while(pi > i || i == r-1)
		{
			while(pj < j || j == 0)
			{
				pi = i;
				pj = j;
				i--;
				j++;
				usleep(100000);
				werase(stdscr);
				for(int a = 0;a < c;a++)
				{
					mvaddch(0,a,'-');
					mvaddch(r-1,a,'-');
				}
				mvaddch(i,j,'X');
				refresh();
				break;
			}
			while(pj > j || j == c-1)
			{
				pi = i;
				pj = j;
				i--;
				j--;
				usleep(100000);
				werase(stdscr);
				for(int a = 0;a < c;a++)
				{
					mvaddch(0,a,'-');
					mvaddch(r-1,a,'-');
				}
				mvaddch(i,j,'X');
				refresh();
				break;
			}
			break;
		}
	}
	return 0;
}