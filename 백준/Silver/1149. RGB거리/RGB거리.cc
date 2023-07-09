#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> rx;
	vector<int> gx;
	vector<int> bx;

	for (int i = 0; i < N; i++) {
		int red, green, blue;
		cin >> red >> green >> blue;

		if (i == 0) {
			rx.push_back(red);
			gx.push_back(green);
			bx.push_back(blue);
		}
		else {
			rx.push_back(red + min(bx[i - 1], gx[i - 1]));
			gx.push_back(green + min(rx[i - 1], bx[i - 1]));
			bx.push_back(blue + min(rx[i - 1], gx[i - 1]));
		}
	}

	int minimum = min(rx[N - 1], gx[N - 1]);
	minimum = min(minimum, bx[N - 1]);
	cout << minimum;

	return 0;
}