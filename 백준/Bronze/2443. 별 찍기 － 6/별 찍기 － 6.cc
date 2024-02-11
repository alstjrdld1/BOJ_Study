#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int i = N; i > 0; i--)
    {
        for(int blank = N-i; blank >0; blank--)
        {
            cout << " ";
        }
        for(int star = 0; star < 2*(i-1) + 1; star++)
        {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}