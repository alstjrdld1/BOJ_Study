#include <set>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    set<string> mySet;
    for(int i = 0; i < words.size(); i++)
    {
        auto isFind = mySet.find(words[i]);
        if(isFind != mySet.end())
        {
            answer.push_back((i % n) + 1);
            answer.push_back((i / n) + 1);
            break;
        }
        if(i > 0)
        {
            if(words[i][0] != words[i-1][words[i-1].size() - 1])
            {
                answer.push_back((i % n) + 1);
                answer.push_back((i / n) + 1);
                break;
            }
        }
        mySet.insert(words[i]);
    }
    if(answer.size() == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}