#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int H, Y;
	cin >> H >> Y;

	double money[11] = { 0 };
	double interest[3] = { 1.05, 1.2, 1.35 };
	money[0] = H;

	for (int i = 1; i <= 10; i++)
	{
		vector<double> interests;
		interests.push_back(floor(money[i - 1] * interest[0]));

		if (i >= 3)
		{
			interests.push_back(floor(money[i - 3] * interest[1]));
		}
		if (i >= 5)
		{
			interests.push_back(floor(money[i - 5] * interest[2]));
		}
		money[i] = *max_element(interests.begin(), interests.end());
	}
	
	cout << money[Y];
	

	return 0;
}