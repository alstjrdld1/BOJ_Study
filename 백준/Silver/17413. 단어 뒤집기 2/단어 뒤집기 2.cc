#include <stack>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string ipt, out, inBrac;
	getline(cin, ipt);

	stack<char> st;

	for (int i = 0; i < ipt.length(); i++)
	{
		if (ipt[i] == ' ')
		{
			if (inBrac.length() > 0)
			{
				inBrac += ipt[i];
			}
			else
			{
				while (!st.empty())
				{
					out += st.top();
					st.pop();
				}
				out += ipt[i];
			}
		}
		else if (ipt[i] == '<')
		{
			inBrac = ipt[i];
			while (!st.empty())
			{
				out += st.top();
				st.pop();
			}
		}
		else if (ipt[i] == '>')
		{
			inBrac += ipt[i];
			out += inBrac;
			inBrac = "";
		}
		else
		{
			if (inBrac.length() > 0)
			{
				inBrac += ipt[i];
			}
			else
			{
				st.push(ipt[i]);
			}
		}
	}
	while (!st.empty())
	{
		out += st.top();
		st.pop();
	}
	
	cout << out;

	return 0;
}