#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	int n; 
	cin >> n;

	vector<vector<int>> triangle;

	for (int i = 0; i < n; i++) {
		vector<int> layer;
		if (i == 0) {
			int tmp;
			cin >> tmp;
			layer.push_back(tmp);
		}
		else {
			for (int j = 0; j <= i; j++) {
				int tmp;
				cin >> tmp;
				if (j == 0) {
					layer.push_back(tmp + triangle[i - 1][j]);
				}
				else if (j == i) {
					layer.push_back(tmp + triangle[i - 1][j - 1]);
				}
				else {
					layer.push_back(tmp + max(triangle[i-1][j-1], triangle[i-1][j]));
				}
			}
		}
		triangle.push_back(layer);
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < triangle[n - 1][i]) {
			max = triangle[n - 1][i];
		}
	}
	cout << max;
	return 0;
}