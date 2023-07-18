#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {

	int N, K;
	cin >> N >> K;

	vector<int> dp(K + 1);
	vector<int> dpPrev(K + 1);

	for (int i = 1; i <= N; i++) {
		int w, v;
		cin >> w >> v;
		dpPrev = dp;
		for (int j = 1; j <= K; j++) {
			if ((j - w) >= 0) {
				dp[j] = max(dpPrev[j], dpPrev[j - w] + v);
			}
		}
	}

	cout << dp[K];

	return 0;
}