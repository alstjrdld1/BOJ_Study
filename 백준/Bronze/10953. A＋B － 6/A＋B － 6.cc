#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string line;
		cin >> line;
		
		cout << (line[0] - '0') + (line[2] - '0') << "\n";
	}

	return 0;
}