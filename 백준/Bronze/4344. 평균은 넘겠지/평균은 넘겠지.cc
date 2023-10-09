#include <iostream>
using namespace std;

int main()
{
	int C;
	cin >> C;

	for (int i = 0; i < C; i++)
	{
		int N;
		cin >> N;
		int sum = 0;

		int* points = new int[N];

		for (int j = 0; j < N; j++)
		{
			cin >> points[j];
			sum += points[j];
		}

		float avg = (float)sum / N;
		int overAvg = 0;

		for (int j = 0; j < N; j++)
		{
			if (points[j] > avg)
			{
				overAvg++;
			}
		}
		float acc = (float)overAvg / N;
		cout << fixed;
		cout.precision(3);
		cout << acc*100 << "%" << "\n";
	}

	return 0;
}