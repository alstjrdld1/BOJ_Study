#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int result = n - 7;
	if (result <= 0)
	{
		int monthDay = m + 14 - n;
		result = m + 7;
		if (result > monthDay)
		{
			result = result - monthDay;
		}
	}

	cout << result;

	return 0;
}