#include <iostream>
#include <vector>
using namespace std;

int main() {

	int N;
	cin >> N;

	vector<int> cdf;
	vector<int> v;

	int result = 0;

	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;

		if (i == 0) {
			cdf.push_back(1);
			v.push_back(number);
		}
		else {
			v.push_back(number);
			int maxCdf = -1;

			for (int idx = i - 1; idx >= 0; idx--) {
				if (v[idx] < number) {
					if (cdf[idx] > maxCdf) {
						maxCdf = cdf[idx];
					}
				}
			}

			if (maxCdf == -1) {
				cdf.push_back(1);
			}
			else {
				cdf.push_back(maxCdf+1);
			}
		}

		if (cdf[i] > result) {
			result = cdf[i];
		}
	}

	cout << result;

	return 0;
}