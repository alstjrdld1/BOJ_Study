#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int n;
	cin >> n;

	int maxVal = 0;

	vector<int> cf;

	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;

		if (i == 0) {
			cf.push_back(number);
			maxVal = number;
		}
		else {
			int tmp = max(number, number + cf[i - 1]);
			cf.push_back(tmp);
			if (tmp > maxVal) {
				maxVal = tmp;
			}
		}
	}

	cout << maxVal;

	return 0;
}