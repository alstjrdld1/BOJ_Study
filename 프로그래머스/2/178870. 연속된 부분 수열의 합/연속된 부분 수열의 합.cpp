#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    vector<int> cummulative;
    cummulative.push_back(0);
    int cummul = 0;
    for(int i = 0; i < sequence.size(); i++)
    {
        cummul += sequence[i];
        cummulative.push_back(cummul);
    }
    
    int start = 1;
    int end = 1;
    
    while(end < cummulative.size())
    {
        int summation = cummulative[end] - cummulative[start-1];
        if(summation == k)
        {
            if(answer.size() > 0)
            {
                int prevCount = answer[1] - answer[0] + 1;
                int curCount = end - start + 1; 
                if (curCount < prevCount)
                {
                    answer.pop_back();
                    answer.pop_back();
                    answer.push_back(start-1);
                    answer.push_back(end-1);
                }
            }
            else
            {
                answer.push_back(start-1);
                answer.push_back(end-1);
            }
            end++;
        }
        else if (summation < k)
        {
            end++;
        }
        else if (summation > k)
        {
            start++;
        }
    }
    return answer;
}