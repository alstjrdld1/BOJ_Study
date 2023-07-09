#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	int red = 0;
	int green = 0;
	int blue = 0;

	for (int i = 0; i < N; i++) {
		int r, g, b;
		cin >> r >> g >> b;

		r = r + min(green, blue);
		g = g + min(red, blue);
		b = b + min(red, green);

		red = r;
		green = g;
		blue = b;
	}

	int minimum = min(red, green);
	minimum = min(minimum, blue);
	cout << minimum;

	return 0;
}