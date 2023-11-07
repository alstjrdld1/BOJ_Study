#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int currentNum = -1;
    for(int i = 0; i < arr.size(); i++)
    {
        if(currentNum != arr[i])
        {
            currentNum = arr[i];
            answer.push_back(currentNum);
        }
    }
    return answer;
}