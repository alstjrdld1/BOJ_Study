#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main() {

	int N, K;
	cin >> N >> K;
	int** dp = new int* [N+1];
	for (int i = 0; i < N+1; i++) {
		dp[i] = new int[K+1];
		for (int j = 0; j < K + 1; j++) {
			dp[i][j] = 0;
		}
	}

	vector<int> w;
	vector<int> v;
	w.push_back(0);
	v.push_back(0);

	for (int i = 1; i <= N; i++) {
		int wi, vi;
		cin >> wi >> vi;
		w.push_back(wi);
		v.push_back(vi);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if ((j - w[i]) >= 0) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[N][K];

	return 0;
}