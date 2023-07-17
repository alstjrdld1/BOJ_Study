#include <iostream>
#include <cstring>
using namespace std;

#define MOD 1000000000

int main() {

	int n;
	cin >> n;

	unsigned long numbers[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	for (int i = 2; i <= n; i++) {
		unsigned long tmp[10];
		for (int num = 0; num < 10; num++) {
			if (num == 0) {
				tmp[num] = numbers[1] % MOD;
			}
			else if (num == 9) {
				tmp[num] = numbers[8] % MOD;
			}
			else {
				tmp[num] = (numbers[num - 1] + numbers[num + 1]) % MOD;
			}
		}

		memcpy(numbers, tmp, sizeof(unsigned long) * 10);

	}

	unsigned long sum = 0;

	for (int i = 0; i < 10; i++) {
		sum += numbers[i];
		sum %= MOD;
	}

	cout << sum % MOD;

	return 0;
}