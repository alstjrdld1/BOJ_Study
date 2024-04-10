#include <iostream>
#include <deque>
using namespace std;

int main()
{
	deque<int> dq;
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		dq.push_back(i);
	}
	cout << "<";

	while (true)
	{
		for (int i = 0; i < K-1; i++)
		{
			dq.push_back(dq.front());
			dq.pop_front();
		}

		cout << dq.front();
		dq.pop_front();

		if (dq.empty())
		{
			break;
		}
		else
		{
			cout << ", ";
		}
	}
	cout << ">";
	return 0;
}