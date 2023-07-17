#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {

	int n;
	cin >> n;

	int* benefit = new int[n+1];
	memset(benefit, 0, sizeof(int) * (n + 1));

	for (int i = 0; i < n; i++) {
		int t, p;
		cin >> t >> p;

		if (i + t <= n) {
			int tmp = max(p + benefit[i], benefit[i+t]);

			for (int j = i + t; j <= n; j++) {
				benefit[j] = max(benefit[j], tmp);
			}
		}
	}

	cout << benefit[n];

	return 0;
}