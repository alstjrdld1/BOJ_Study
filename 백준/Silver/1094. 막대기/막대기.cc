#include <iostream>
using namespace std;

int main()
{
	int X;
	cin >> X;
	int sticks = 0;

	while (X > 1)
	{
		sticks += X % 2;
		X = X / 2;
	}
	sticks += X;
	cout << sticks;

	return 0;
}