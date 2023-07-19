#include <iostream>
using namespace std;

#define MOD 15746

int main() {

	int n;
	cin >> n;
	int dp[2];
	dp[0] = 1;
	dp[1] = 2;

	int result = 0;
	if (n == 1) {
		result = 1;
	}
	else if (n == 2) {
		result = 2;
	}
	else {
		for (int i = 3; i <= n; i++) {
			result = (dp[1] % MOD + dp[0] % MOD) % MOD;
			dp[0] = dp[1];
			dp[1] = result % MOD;
		}
	}

	cout << result % MOD;

	return 0;
}