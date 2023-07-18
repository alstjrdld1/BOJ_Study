#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {

	int N, K;
	cin >> N >> K;

	vector<int> dp(K + 1);
	vector<int> dpPrev(K + 1);

	vector<int> w(N+1);
	vector<int> v(N+1);

	for (int i = 1; i <= N; i++) {
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= N; i++) {
		dpPrev = dp;
		for (int j = 1; j <= K; j++) {
			if ((j - w[i]) >= 0) {
				dp[j] = max(dpPrev[j], dpPrev[j - w[i]] + v[i]);
			}
		}
	}

	cout << dp[K];

	return 0;
}