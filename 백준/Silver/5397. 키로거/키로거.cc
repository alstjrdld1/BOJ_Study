#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#include <deque>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	fastio;
	int T;
	cin >> T;

	for (int p = 0; p < T; p++)
	{
		string ipt; 
		deque<char> ans_left, ans_right;
		cin >> ipt;

		for (int i = 0; i < ipt.size(); i++)
		{
			if (ipt[i] == '<')
			{
				if (ans_left.size() > 0)
				{
					ans_right.push_front(ans_left.back());
					ans_left.pop_back(); 
				}
			}
			else if (ipt[i] == '>')
			{
				if (ans_right.size() > 0)
				{
					ans_left.push_back(ans_right.front());
					ans_right.pop_front();
				}
			}
			else if (ipt[i] == '-')
			{
				if (ans_left.size() > 0)
				{
					ans_left.pop_back();
				}
			}
			else
			{
				ans_left.push_back(ipt[i]);
			}
		}

		while (!ans_left.empty())
		{
			cout << ans_left.front();
			ans_left.pop_front();
		}

		while (!ans_right.empty())
		{
			cout << ans_right.front();
			ans_right.pop_front();
		}
		cout << "\n";
	}

	return 0;
}