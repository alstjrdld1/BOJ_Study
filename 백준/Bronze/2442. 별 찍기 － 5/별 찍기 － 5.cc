#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int blank = 0; blank < N-i; blank++)
        {
            cout << " ";
        }
        for (int star = 0; star < (2 * (i-1)) + 1; star++)
        {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}