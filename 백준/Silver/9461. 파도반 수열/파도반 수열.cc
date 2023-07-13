#include <iostream>
#include <cstring>
using namespace std;

int main() {
	long long memo[101];
	memset(memo, 0, sizeof(long long) * 101);
	memo[1] = 1;
	memo[2] = 1;
	memo[3] = 1;
	memo[4] = 2;
	memo[5] = 2;
	memo[6] = 3;
	memo[7] = 4;
	memo[8] = 5;
	memo[9] = 7;
	memo[10] = 9;

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int n; 
		cin >> n;

		if(memo[n] == 0) {
			for (int j = 11; j <= n; j++) {
				memo[j] = memo[j - 1] + memo[j - 5];
			}
		}

		cout << memo[n] << "\n";
	}

	return 0;
}