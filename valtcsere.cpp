#include "iostream"
using namespace std;

int main()
{
	int x = 10, y = 20;
	
	cout << "x = " << x << ", y = " << y << endl;

	x = x + y; //x=30
	y = x - y; //y=10
	x = x - y; //x=20

	cout << "x = " << x << ", y = " << y << endl;
}