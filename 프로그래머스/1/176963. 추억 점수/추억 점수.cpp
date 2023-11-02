#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> myMap;
    for (int i = 0; i < name.size(); i++)
    {
        myMap[name[i]] = yearning[i];
    }
    
    for(auto iter = photo.begin(); iter != photo.end(); iter++)
    {
        int point = 0;
        for(auto member = iter->begin(); member != iter->end(); member++)
        {
            if(myMap.find(*member) != myMap.end())
            {
                point += myMap[*member];
            }
        }
        answer.push_back(point);
    }
    return answer;
}