#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int n;
	cin >> n;

	int maxVal = 0;
	int max3Prev = 0;
	vector<int> wine;
	vector<int> data;

	for (int i = 0; i < n; i++) {
		int wineAmount = 0;
		cin >> wineAmount;
		data.push_back(wineAmount);

		int w;
		if (i == 0) {
			w = wineAmount;
			wine.push_back(w);
		}
		else if (i == 1) {
			w = wine[0] + wineAmount;
			wine.push_back(w);
		}
		else if (i == 2) {
			max3Prev = wine[0];
			w = wineAmount + max(wine[0], data[1]);
			wine.push_back(w);
		}
		else {
			w = wineAmount + max(data[i - 1] + max3Prev, wine[i - 2]);
			if (max3Prev < wine[i - 2]) {
				max3Prev = wine[i - 2];
			}
			wine.push_back(w);
		}
		if (maxVal < w) {
			maxVal = w;
		}
	}

	cout << maxVal;

	return 0;
}