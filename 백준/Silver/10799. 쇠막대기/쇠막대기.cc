#include <stack>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string line;
	cin >> line;
	stack<char> st;

	int result = 0;

	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] == '(')
		{
			st.push(line[i]);
		}
		else if (line[i] == ')')
		{
			st.pop();
			if (line[i - 1] == ')')
			{
				result++;
			}
			else
			{
				result += st.size();
			}
		}
	}
	cout << result;
	return 0;
}