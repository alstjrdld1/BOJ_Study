#include <iostream>
#include <string>
using namespace std;

int main()
{
	int alphabet[26] = { 0 };
	string input;
	cin >> input;
	for (int i = 0; i < input.length(); i++)
	{
		alphabet[input[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		cout << alphabet[i] << ' ';
	}

	return 0;
}