#include <iostream>
using namespace std;

int main() {

	int n;
	cin >> n;

	unsigned long long binary[2] = { 0, 1 };

	for (int i = 2; i <= n; i++) {
		unsigned long long tmp[2];
		tmp[0] = binary[0] + binary[1];
		tmp[1] = binary[0];

		binary[0] = tmp[0];
		binary[1] = tmp[1];

	}
	cout << binary[0] + binary[1];

	return 0;
}