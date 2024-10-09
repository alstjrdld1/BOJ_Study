#include <string>
#include <iostream>
using namespace std;

int main()
{
	int alphabet[26] = { 0 };
	int N;
	string inputStr;
	cin >> N;
	cin >> inputStr;
	for (int i = 0; i < N; i++)
	{
		alphabet[inputStr[i] - 'a']++;
	}

	int onlyOne = 0;
	for (int i = 0; i < 26; i++)
	{
		if ((alphabet[i] % 2) == 1)
		{
			onlyOne++;
		}
	}

	if (N % 2 == 1 && onlyOne == 1)
	{
		if (alphabet[inputStr[N / 2] - 'a'] % 2 == 1)
		{
			cout << "Yes";
		}
		else
		{
			cout << "No";
		}
	}
	else if (N % 2 == 0 && onlyOne == 0)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
	return 0;
}