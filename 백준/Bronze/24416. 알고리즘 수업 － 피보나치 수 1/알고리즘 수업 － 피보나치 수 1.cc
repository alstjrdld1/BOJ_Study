#include <iostream>
using namespace std;

int f1Called = 1;

int fib(int n)
{
    if(n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        f1Called++;
        return (fib(n-1) + fib(n-2));
    }
}

int main()
{
    int N;
    cin >> N;

    fib(N);

    cout << f1Called << " " << N - 2;

    return 0;
}