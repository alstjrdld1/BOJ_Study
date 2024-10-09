#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	vector<string> v;
	string tmp;
	int N;
	cin >> N;
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		for (int j = 0; j < v.size(); j++)
		{
			int inputLength = tmp.length();
			int targetLength = v[j].length();
			int shortLength = min(inputLength, targetLength);
			for (int k = 1; k <= shortLength; k++)
			{
				string head, tail;
				head = v[j].substr(0, k);
				tail = tmp.substr(inputLength - k, k);
				if (head == tail)
				{
					result++;
					break;
				}
				head = tmp.substr(0, k);
				tail = v[j].substr(targetLength - k, k);
				if (head == tail)
				{
					result++;
					break;
				}
			}
		}
		v.push_back(tmp);
	}

	cout << result;

	return 0;
}