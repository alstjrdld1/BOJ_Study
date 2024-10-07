#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int H, Y;
	cin >> H >> Y;

	double money[11] = { 0 };
	money[0] = H;

	for (int i = 1; i <= 10; i++)
	{
		money[i] = int(money[i - 1] * 1.05);

		if (i >= 3)
		{
			money[i] = int(max(money[i], money[i - 3] * 1.2));
		}
		if (i >= 5)
		{
			money[i] = int(max(money[i], money[i - 5] * 1.35));
		}
	}
	
	cout << money[Y];
	

	return 0;
}