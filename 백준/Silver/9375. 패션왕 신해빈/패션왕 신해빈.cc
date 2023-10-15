#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		map<string, vector<string>> clothes;
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			string clothesName, part;
			cin >> clothesName >> part;
			if (clothes.find(part) != clothes.end())
			{
				clothes[part].push_back(clothesName);
			}
			else
			{
				vector<string> tmp;
				tmp.push_back(clothesName);
				clothes[part] = tmp;
			}
		}

		int combination = 1;
		for (auto iter = clothes.begin(); iter != clothes.end(); iter++)
		{
			combination *= (iter->second.size() + 1);
		}
		cout << combination - 1 << "\n";
	}

	return 0;
}