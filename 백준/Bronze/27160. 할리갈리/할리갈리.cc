#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<string, int> halligalli;

	halligalli["STRAWBERRY"] = 0;
	halligalli["BANANA"] = 0;
	halligalli["LIME"] = 0;
	halligalli["PLUM"] = 0;

	int N, X;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string guail;
		int num;
		cin >> guail >> num;

		halligalli[guail] += num;
	}

	bool result = false;
	for (auto iter = halligalli.begin(); iter != halligalli.end(); iter++)
	{
		if (iter->second == 5)
		{
			result = true;
		}
	}
	
	if (result)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}