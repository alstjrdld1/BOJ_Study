#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int i = N; i>0; i--)
    {
        for (int blank = 0; blank < N-i; blank++)
        {
            cout << " ";
        }
        for(int star = 0; star < i; star++)
        {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}