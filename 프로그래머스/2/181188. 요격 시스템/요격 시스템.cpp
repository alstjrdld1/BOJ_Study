#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(vector<int> &v1, vector<int> &v2){
  if(v1[1] == v2[1])
    return v1[0]<v2[0];
  else return v1[1]<v2[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end(), cmp);

    int end = 0;
    for (int i = 0; i < targets.size(); i++)
    {
        int s = targets[i][0];
        int e = targets[i][1];
            
        if(s >= end)
        {
            end = e;
            answer++;
        }
    }
    
    return answer;
}