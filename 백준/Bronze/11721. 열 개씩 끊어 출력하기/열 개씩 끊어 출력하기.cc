#include <string>
#include <iostream>
using namespace std;

int main()
{
	string str;
	cin >> str; 

	while (str.size() > 10)
	{
		cout << str.substr(0, 10) << "\n";
		str = str.substr(10, str.size() - 10);
	}
	cout << str;

	return 0;
}