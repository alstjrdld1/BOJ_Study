#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#include <string>
#include <iostream>
using namespace std;

int main()
{
	fastio;
	string str, bomb, ans;

	cin >> str;
	cin >> bomb;

	int bombLength = bomb.length();

	string bombStack = "";

	for (int i = 0; i < str.length(); i++)
	{
		ans += str[i];
		if (str[i] == bomb.back())
		{
			bool bombFind = true;

			if (ans.size() < bombLength)
			{
				continue;
			}

			if (ans.substr(ans.size() - bombLength, bombLength) == bomb)
			{
				for (int idx = 0; idx < bombLength; idx++)
				{
					ans.pop_back();
				}
			}
		}
	}

	if (ans == "")
	{
		cout << "FRULA";
	}
	else
	{
		cout << ans;
	}

	return 0;
}