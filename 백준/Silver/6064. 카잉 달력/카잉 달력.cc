#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int gcd(int n1, int n2) {
	if (n2 % n1 == 0) {
		return n1;
	}
	else {
		return gcd(n2 % n1, n1);
	}
}

int lcm(int n1, int n2)
{
	return (n1 * n2) / gcd(n1, n2);
}

int main()
{
	fastio;
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		int maxNum = lcm(M, N);

		int result = -1;
		for (int day = x; day <= maxNum; day += M)
		{
			if ((day % N) == y)
			{
				result = day;
				break;
			}
			else if ((day % N) == 0 && N == y)
			{
				result = day;
				break;
			}

		}

		cout << result << "\n";
	}

	return 0;
}