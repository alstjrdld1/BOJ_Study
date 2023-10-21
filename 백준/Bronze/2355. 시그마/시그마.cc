#include <iostream>
using namespace std;

int main()
{
    long long A, B;
    cin >> A >> B;

    if(A > B)
    {
        long long tmp = B;
        B = A;
        A = tmp;
    }

    long long sum = A + B;
    long long median = (A + B) / 2;

    sum = sum * ((B - A + 1) / 2);
    if ((B - A + 1) % 2 != 0)
    {
        sum += median;
    }

    cout << sum;

    return 0;
}