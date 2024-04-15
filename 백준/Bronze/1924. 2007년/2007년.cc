#include <iostream>
using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;

	int idx = 1;
	int days = y;
	while (true)
	{
		if (idx == x)
		{
			break;
		}

		if (idx == 4 || idx == 6 || idx == 9 || idx == 11)
		{
			days += 30;
		}
		else if (idx == 2)
		{
			days += 28;
		}
		else
		{
			days += 31;
		}
		idx++;
	}

	int rest = days % 7;
	switch (rest)
	{
	case(0):
		cout << "SUN";
		break;
	case(1): 
		cout << "MON";
		break;
	case(2):
		cout << "TUE";
		break;
	case(3):
		cout << "WED";
		break;
	case(4):
		cout << "THU";
		break;
	case(5):
		cout << "FRI";
		break;
	case(6):
		cout << "SAT";
		break;
	}

	return 0;
}