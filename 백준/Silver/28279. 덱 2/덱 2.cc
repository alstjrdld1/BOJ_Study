#include <iostream>
#include <deque>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
	fastio;

	deque<int> dQ;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int op;
		cin >> op;

		if (op == 1) {
			int x; 
			cin >> x; 
			dQ.push_front(x);
		}
		else if (op == 2) {
			int x;
			cin >> x;
			dQ.push_back(x);
		}
		else if (op == 5) {
			cout << dQ.size() << "\n";
		}
		else {
			if (dQ.empty()) {
				if (op == 6) cout << 1 << "\n";
				else cout << -1 << "\n";
			}
			else {
				if (op == 3) {
					cout << dQ.front() << "\n";
					dQ.pop_front();
				}
				else if (op == 4) {
					cout << dQ.back() << "\n";
					dQ.pop_back();
				}
				else if (op == 6) {
					cout << 0 << "\n";
				}
				else if (op == 7) {
					cout << dQ.front() << "\n";
				}
				else if (op == 8) {
					cout << dQ.back() << "\n";
				}
			}
		}
	}

	return 0;
}