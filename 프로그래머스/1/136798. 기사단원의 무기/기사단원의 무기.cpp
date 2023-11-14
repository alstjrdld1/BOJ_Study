#include <string>
#include <vector>

using namespace std;

int yakSuCount(int n)
{
    int count = 0;
    for(int i = 1; i * i <= n; i++)
    {
        if(i*i == n) count++;
        else if(n % i == 0) count += 2;
    }
    return count;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    for(int i = 1; i <= number; i++)
    {
        int yakSu = yakSuCount(i);
        if(yakSu <= limit)
        {
            answer += yakSu;
        }
        else if(yakSu > limit)
        {
            answer += power;
        }
    }
    return answer;
}