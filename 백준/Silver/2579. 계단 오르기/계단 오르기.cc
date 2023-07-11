#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {

	vector<pair<int, int>> stair;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int cost = 0;
		cin >> cost;

		if (i > 1) {
			int maxVal = max(stair[i - 2].first, stair[i - 2].second);
			stair.push_back({ cost + stair[i - 1].second, cost + maxVal });
		}
		else if(i == 1){
			stair.push_back({ cost + stair[0].first, cost });
		}
		else if (i == 0) {
			stair.push_back({ cost, 0 });
		}
	}

	cout << max(stair[n - 1].first, stair[n - 1].second);

	return 0;
}