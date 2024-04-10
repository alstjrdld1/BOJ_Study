#include <iostream>
using namespace std;

int main()
{
	long long a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;

	int sum = (a * a) % 10 + (b * b) % 10 + (c * c) % 10 + (d * d) % 10 + (e * e) % 10;

	cout << sum % 10;
}