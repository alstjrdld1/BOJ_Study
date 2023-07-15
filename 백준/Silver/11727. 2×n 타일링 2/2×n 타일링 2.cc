#include <iostream>
#include <cstring>
using namespace std;

#define DIV 10007

int main(){

    int dp[1001];
    memset(dp, 0, sizeof(int) * 1001);

    int n;
    cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;

    for(int i = 3; i <= n; i++){
        dp[i] = ((dp[i-1] % DIV) + 2 * (dp[i-2] % DIV)) % DIV;
    }

    cout << dp[n] % DIV;

    return 0;
}