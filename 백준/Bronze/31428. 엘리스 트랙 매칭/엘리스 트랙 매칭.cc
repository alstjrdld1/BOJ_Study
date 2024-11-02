#include <map>
#include <iostream>
using namespace std;

int main()
{
	int N;
    map<char, int> trackMap;
    trackMap['C'] = 0;
    trackMap['S'] = 0;
    trackMap['I'] = 0;
    trackMap['A'] = 0;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        char inputChar;
        cin >> inputChar;
        trackMap[inputChar]++;
    }

    char helloBit;
    cin >> helloBit;

    cout << trackMap[helloBit];

	return 0;
}