#include <iostream>
using namespace std;

int main() {

	int N;
	cin >> N;

	long long* A = new long long[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	long long B, C;
	cin >> B >> C;

	long long count = 0;

	for (int i = 0; i < N; i++) {
		A[i] = A[i] - B;
		count++;
		if (A[i] > 0) {
			count += (A[i] / C);
			if (A[i] % C != 0) {
				count++;
			}
		}
	}

	cout << count;
	return 0;
}