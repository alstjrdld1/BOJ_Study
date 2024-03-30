#include <iostream>
#include <string>
using namespace std;

int main()
{
	int arr[10] = { 0 };
	int maxNum = 0;
	string input;
	cin >> input;
	
	for (int i = 0; i < input.length(); i++)
	{
		arr[input[i] - '0']++;
	}

	for (int i = 0; i < 10; i++)
	{
		if (i == 6 || i == 9)  continue;

		if (maxNum < arr[i])
		{
			maxNum = arr[i];
		}
	}

	int sixNine = (arr[6] + arr[9] + 1) / 2;

	if (maxNum >= sixNine)
	{
		cout << maxNum;
	}
	else if (maxNum < sixNine)
	{
		cout << sixNine;
	}

	return 0;
}